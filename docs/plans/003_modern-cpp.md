# Plan 3: Modern C++ Enhancements

## Goal: Leverage modern C++ for better performance and safety without breaking changes

### 1. Constexpr Implementation
- Mark appropriate functions as `constexpr` where possible:
  - Constructors (scalar, copy, array, initializer_list)
  - Simple arithmetic operators (+, -, *, /) for scalar operations
  - Accessor methods (`len()`, `mag()` for zero-length vectors)
  - Comparison operators (`==`, `!=`)
- Focus on functions that can be evaluated at compile-time with constant expressions
- Example: `constexpr vec(float s) { /* ... */ }`

### 2. Noexcept Specification: 
- Skipped per user instruction

### 3. Concepts (C++20):
- Not implemented per user instruction
- No template constraints added

### 4. Aggregate Initialization Support (without std::array):
- Ensure trivial copyability and standard layout
- Maintain contiguous storage via existing array member (`T m[N]` in vec_data)
- Provide constexpr constructors that enable brace initialization:
  * `vec3 v = {1.0f, 2.0f, 3.0f};` 
  * `mat2 m = {{1.0f, 2.0f}, {3.0f, 4.0f}};`
- Key requirements:
  * No user-defined constructors that prevent aggregate initialization (but we need some - solution: rely on aggregate initialization for POD-like behavior while keeping necessary constructors)
  * Actually: Since we have constructors, true aggregate initialization isn't possible. Instead:
    - Ensure all data members are public (they're not currently - `m` is in base struct)
    - Alternative: Provide explicit conversion from std::array or initializer_list that acts like aggregate init
    - Better approach: Keep current initializer_list constructor but ensure it's constexpr and efficient
- Implementation plan:
  * Make `vec_data::m` accessible (change from private to public or add accessor)
  * Ensure constructors are constexpr where possible
  * Rely on existing `vec(std::initializer_list<T>)` constructor for brace initialization
  * Guarantee trivial copyability by removing virtual functions and ensuring standard layout
  * Example: After changes, `vec3 v{1.0f, 2.0f, 3.0f};` will work via initializer_list constructor
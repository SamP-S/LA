# Plan 1: API Design Improvements

## Goal: Enhance usability and consistency while maintaining implicit array access

### 1. Shorthand Naming Standardization
- [ ] Rename `length()` → `len()`
- [ ] Rename `Magnitude()` → `mag()`
- [ ] Rename `Normalise()` → `norm()`
- [ ] Keep corresponding setter/getter patterns consistent (e.g., `mag()` for magnitude calculation)
- [ ] Maintain implicit array access via `operator[]` - do not add named component accessors

### 2. Parameter Passing Optimization
- [ ] Small types (int, float, double, length_t): Pass by value
- [ ] Vector/matrix types: Pass by const reference to avoid unnecessary copies
- [ ] Return types: Return small types by value, larger objects by value (relying on NRVO/move semantics)
- [ ] Example: `vec operator+(const vec& v, float scalar)` not `vec operator+(vec v, const float& scalar)`

### 3. Const Correctness Application
- [ ] Add `const` qualifier to all member functions that do not modify object state
- [ ] Key functions to update: `len()`, `mag()`, `norm()`, `operator[]` (const version), all accessor methods
- [ ] Ensure operator overloads maintain proper const-correctness in both parameters and return types
- [ ] Example: `T operator[](int i) const` for read-only access
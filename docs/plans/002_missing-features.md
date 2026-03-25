# Plan 2: Missing Features Implementation

## Goal: Add essential 3D graphics mathematics functionality

### 1. Vector Operations Enhancements
- **Linear Interpolation (lerp)**: 
  - `vec<N,T> lerp(const vec<N,T>& a, const vec<N,T>& b, float t)`
  - Clamp t to [0,1] range optionally
- **Component-wise Min/Max**:
  - `vec<N,T> min(const vec<N,T>& a, const vec<N,T>& b)`
  - `vec<N,T> max(const vec<N,T>& a, const vec<N,T>& b)`
- **Clamping Functions**:
  - `vec<N,T> clamp(const vec<N,T>& v, const vec<N&T>& min, const vec<N&T>& max)`
  - Scalar clamp variant
- **Transpose Accessor**:
  - Add `.T()` method returning transposed vector/matrix (for matrices, actual transpose; for vectors, treats as row/column)
- **Reverse Accessor**:
  - Add `.rev()` method returning reversed component order
- **Zero-Vector Safety**:
  - Improve normalization to handle zero vectors gracefully (return zero vector or unit vector along axis)
  - Add safe division checks in all operations

### 2. Matrix Operations Extensions
- **Transform Decomposition**:
  - Extract translation, rotation (as quaternion or Euler angles), and scale from 4x4 transformation matrix
  - Functions: `decomposeTranslation(const mat4&)`, `decomposeRotation(const mat4&)`, `decomposeScale(const mat4&)`
- **Quaternion Support**:
  - Add `quat` struct with:
    * Constructors (from axis-angle, Euler angles, mat4)
    * Conversion to/from `mat4`
    * Interpolation (slerp, nlerp)
    * Basic operations (multiplication, normalization, conjugation)
    * Application to vectors (rotating vectors by quaternion)

### 3. Utility Functions: 
- None added per user specification
- Existing projection, dot, cross, magnitude functions remain unchanged
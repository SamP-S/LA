# Plan: Replace M_Assert with std::assert

## Status: Completed ✓

## Objective
Remove custom assertfunc implementation and replace with standard C++ assert from <cassert> (or <assert.h>).

## Changes Made

- [x] Replace M_Assert macro usage in `include/la/la.hpp`
  - Changed `M_Assert(Expr, Msg)` to `assert((Expr) && (Msg))`
  - Note: Uses short-circuit evaluation to include message with assert

- [x] Remove inclusion of "assertfunc.h" from `include/la/la.hpp`

- [x] Remove the files:
  - `include/la/assertfunc.h`
  - `src/assertfunc.cpp`

- [x] Verified <assert.h> remains included in la.hpp

- [x] Built and tested successfully

## Implementation Details

1. Edited `include/la/la.hpp`:
   - Replaced two occurrences of M_Assert (lines 503 and 507) with assert((Expr) && (Msg))
   - Removed #include "assertfunc.h"

2. Deleted assertfunc.h and assertfunc.cpp

3. No changes needed to CMakeLists.txt (source file removal handled by glob)

4. Verified <assert.h> is included (line 7)

## Testing
- Built successfully with ./compile.sh
- When NDEBUG is defined, assert is disabled (matching original M_Assert behavior)
- Assertions work correctly in debug builds

## Notes
- Used `assert((Expr) && (Msg))` idiom as requested
- In release builds (NDEBUG), assert is removed, so there is no overhead
- Message is included via short-circuit && operator
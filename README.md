# Pointer containers for C++

[![CMake tests](https://github.com/dk949/ptr-containers/actions/workflows/cmake-single-platform.yml/badge.svg?branch=trunk)](https://github.com/dk949/ptr-containers/actions/workflows/cmake-single-platform.yml)

Some containers to work with pointers. Useful for dynamic polymorphism.

Requires c++20 (mostly for concepts)

## Adding to a project

Not currently set up as a cmake pakcage.

1. `git clone https://github.com/dk949/ptr-containers` or `git submodule add https://github.com/dk949/ptr-containers`
2. add `add_subdirectory(ptr-containers)` to your `CMakeLists.txt`
    * _Note:_ You may need to add a binary directory (despite this being an
      interface library) to the `add_subdirectory` if the repo was cloned to a
      different directory than the one `CMakeLists.txt` is in.
3. link your target to the `ptr_containers` library.

## Containers available

* `ut::OwnPtrVec<T>`
    * A vector holding pointers to `T`
    * Provides various features which make it behave as if it holds values of
      type `T`. (such as being able to `push_back` non pointer values)
    * All information about pointer ownership is passed via `std::unique_ptr`
      except for pointers returned from `release*` functions.
    * Supports most of the `std::vector` API and parts of the `std::unique_ptr` API.
    * No allocator support (yet).
* `ut::PtrVecView<T>`
    * A light-weight, non-owning view of `ut::OwnPtrVec<T>`

See comments for further descriptions of individual functions.

## Testing

**Make sure to run the tests/fetch-catch2.sh script before running tests**

Tests can be enabled with the `PTR_CONTAINERS_BUILD_TESTS` cmake variable.

Tests can be ran with `./build/tests/tests` or `ctest --test-dir build/tests`
(using catch2 and ctest runners respectively).


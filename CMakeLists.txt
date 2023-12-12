cmake_minimum_required(VERSION 3.25)
project(ptr_containers
    VERSION 0.1.0
    DESCRIPTION "Some containers to work with pointers"
    HOMEPAGE_URL "https://github.com/dk949/ptr-containers"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PTR_CONTAINERS_TARGET ptr_containers)

add_subdirectory("include")
option(PTR_CONTAINERS_BUILD_TESTS "Should tests be build" NO)
if(PTR_CONTAINERS_BUILD_TESTS)
    add_subdirectory("tests")
endif()

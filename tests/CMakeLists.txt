set(TEST_NAME tests)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(catch2_install_dir "${CMAKE_SOURCE_DIR}/tests/Catch2-install")
list(APPEND CMAKE_PREFIX_PATH ${catch2_install_dir})

find_package(Catch2 3 REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/tests/*.cpp")

add_executable(${TEST_NAME} ${SOURCE_FILES})
target_link_libraries(${TEST_NAME} PRIVATE Catch2::Catch2WithMain)
target_link_libraries(${TEST_NAME} PRIVATE ptr_containers)

target_compile_options(${TEST_NAME} PRIVATE -fsanitize=address)
target_link_options(${TEST_NAME} PRIVATE -fsanitize=address)

include(CTest)
include(Catch)
catch_discover_tests(tests)

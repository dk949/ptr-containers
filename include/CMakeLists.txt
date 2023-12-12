message(STATUS "Adding ${PTR_CONTAINERS_TARGET} library. Adding ${CMAKE_CURRENT_SOURCE_DIR} include directory")
add_library(${PTR_CONTAINERS_TARGET} INTERFACE)
target_include_directories(${PTR_CONTAINERS_TARGET} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

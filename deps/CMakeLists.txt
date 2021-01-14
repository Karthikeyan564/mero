add_subdirectory(eigen)

set(ELEMENTS_BUILD_EXAMPLES OFF)

add_subdirectory(elements)

set(ELEMENTS_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/elements)
message(${ELEMENTS_ROOT})
add_subdirectory(hello_universe)
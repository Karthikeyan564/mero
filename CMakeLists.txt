cmake_minimum_required(VERSION 3.10)
project(mero)

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(deps)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(spike)



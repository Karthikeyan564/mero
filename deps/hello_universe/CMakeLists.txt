###############################################################################
#  Copyright (c) 2016-2020 Joel de Guzman
#
#  Distributed under the MIT License (https://opensource.org/licenses/MIT)
###############################################################################
cmake_minimum_required(VERSION 3.9.6...3.15.0)
project(HelloUniverse LANGUAGES C CXX)



# Make sure ELEMENTS_ROOT is an absolute path to add to the CMake module path
get_filename_component(ELEMENTS_ROOT "${ELEMENTS_ROOT}" ABSOLUTE)
set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${ELEMENTS_ROOT}/cmake")
# If we are building outside the project, you need to set ELEMENTS_ROOT:
   include(ElementsConfigCommon)
set(ELEMENTS_APP_PROJECT "HelloUniverse")
set(ELEMENTS_APP_TITLE "Hello Universe")


set(ELEMENTS_APP_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources/space.jpg)

include(ElementsConfigApp)

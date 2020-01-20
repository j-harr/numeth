cmake_minimum_required(VERSION 3.5...3.16)

set(This numeth)

project(${This} VERSION 1.0 LANGUAGES CXX)

set(ROOT_DIR "${PROJECT_SOURCE_DIR}")
set(INCLUDE_DIR "${ROOT_DIR}/include")


#----------------------------------------------------------
# General Settings
#----------------------------------------------------------

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON)

#----------------------------------------------------------
# General Build Settings
#----------------------------------------------------------

if (MSVC)
	add_compile_options(/W4 /WX)
else()
	add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

#----------------------------------------------------------
# Add Numeth Library
#----------------------------------------------------------

set(NUMETH_LIB numethlib)
add_library( ${NUMETH_LIB} "" )
target_include_directories( ${NUMETH_LIB} PRIVATE ${INCLUDE_DIR} )

#----------------------------------------------------------
# Add Source
#----------------------------------------------------------
add_subdirectory( src )
target_link_libraries( ${NUMETH_LIB} )

#----------------------------------------------------------
# Add Tests
#----------------------------------------------------------

enable_testing()
add_subdirectory(tests)

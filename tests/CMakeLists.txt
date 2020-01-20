cmake_minimum_required(VERSION 3.5...3.16)

#----------------------------------------------------------
# Create test executable
#----------------------------------------------------------

set(TEST_NAME all_tests)

add_executable( ${TEST_NAME} test_main.cpp )

# Include header files
target_include_directories( ${TEST_NAME} PRIVATE ${INCLUDE_DIR} )

# Add subdirectories
add_subdirectory( vector )
add_subdirectory( matrix )

#----------------------------------------------------------
# Include Catch Library
#----------------------------------------------------------

set(CATCH_INCLUDE_DIR ${ROOT_DIR}/extern/catch2)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# Link Catch Library
target_link_libraries( ${TEST_NAME} PRIVATE Catch )

add_test(NAME MyTests COMMAND ${TEST_NAME})

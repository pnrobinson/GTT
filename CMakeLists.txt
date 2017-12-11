cmake_minimum_required (VERSION 3.0.0)
project (fase)

#Options. Turn on with 'cmake -Dtest=ON
option(test "Build all tests." OFF)
set(PROJECT_NAME fase)
set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_STANDARD 11) ## use C++11

## Download and build gtest
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()


## Set up SeqAn
## Set this to the path for seqan
## for instance, if you have a directory called GIT in your home directory
## and you clone SeqAn into this directory
## $ git clone https://github.com/seqan/seqan.git
## then the cloned directory has a subdirectory called util/cmake
## and another subdirectory called include.
## Set the paths as follows (before calling find_package(SeqAn):
#CMAKE_PREFIX_PATH="/path/to/seqan/util/cmake"
#SEQAN_INCLUDE_PATH="/path/to/seqan/include"
## Alternatively, set this from the command line as described in the README.

# Search for zlib as a dependency for SeqAn.
find_package (ZLIB)

# Load the SeqAn module and fail if not found.
find_package (SeqAn REQUIRED)

## Set up unit testing with gtest
## need to call cmake -Dtest=ON ../.. from command line

if (test)
  if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
  endif (APPLE)
  # Prevent overriding the parent project's compiler/linker
  # settings on Windows
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

  # Add googletest directly to our build. This defines
  # the gtest and gtest_main targets.
  add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
    ${CMAKE_BINARY_DIR}/googletest-build)

  #add_subdirectory(${CMAKE_BINARY_DIR}/googletest-build)
  enable_testing()
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
  add_executable(runUnitTests test_sequence.cpp sequence.cpp)
  target_link_libraries(runUnitTests gtest gtest_main)
  #add_test(NAME runUnitTests COMMAND runUnitTests)

  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  #add_test(ResetsToZero2 gttest)
endif()


## Now set up the executable

include_directories(.)
  
set(TARGET project)
add_executable(fase main.cpp sequence.cpp)




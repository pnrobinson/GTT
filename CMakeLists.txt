cmake_minimum_required (VERSION 3.0.0)
project (fase)

#Options. Turn on with 'cmake -Dtest=ON
option(test "Build all tests." OFF)
set(PROJECT_NAME fase)
set(CMAKE_CXX_FLAGS "-g -Wall")

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



# EXCLUDE_FROM_ALL
# Now simply link against gtest or gtest_main as needed. Eg
#add_executable(my_gtest test_project1.cpp)
#target_link_libraries(my_gtest gtest_main)
#add_test(NAME example_test COMMAND my_gtest)


# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
#set(PROJECT_NAME gtt)
#project(${PROJECT_NAME})


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
    ${CMAKE_BINARY_DIR}/googletest-build
                )

  #add_subdirectory(${CMAKE_BINARY_DIR}/googletest-build)
  enable_testing()
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
  add_executable(runUnitTests test_project1.cpp)
  target_link_libraries(runUnitTests gtest gtest_main)
  add_test(NAME runUnitTests COMMAND runUnitTests)

  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  #add_test(ResetsToZero2 gttest)
endif()
  
set(TARGET project)
add_executable(fase main.cpp)


#set(GTEST_TARGET ${TARGET}_GTest)
#file(GLOB_RECURSE TESTS_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)



#add_executable(${TARGET} main.cpp)
#add_executable(${GTEST_TARGET} test_project1.cpp)
#add_dependencies(${GTEST_TARGET} gtest gtest_main )

#target_link_libraries(${GTEST_TARGET} gtest gtest_main)




#add_executable(gtt main.cpp)
# tests definition
#set(TARGET project)
#set(GTEST_TARGET ${TARGET}_GTest)
#file(GLOB_RECURSE TESTS_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

#add_executable(${GTEST_TARGET} ${TESTS_FILES})
#include_directories(
#  ${source}
#  ${source_dir}/include
#  ${PROJECT_SOURCE_DIR}/include
#)
#add_dependencies(${GTEST_TARGET} gtest)
#target_link_libraries(${GTEST_TARGET} 
#  ${TARGET}
## TODO OP should work but with something around ENABLE_EXPORTS
##  gtest gtest_main
#  ${binary_dir}/${CMAKE_STATIC_LIBRARY_PREFIX}gtest${CMAKE_STATIC_LIBRARY_SUFFIX}
#  ${binary_dir}/${CMAKE_STATIC_LIBRARY_PREFIX}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX}
#  pthread
#)



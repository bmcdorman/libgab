option(test "Build all tests." OFF) # makes boolean 'test' available

function(define_test TEST_NAME TEST_LOCATION)
    add_executable(test_${TEST_NAME} ${TEST_LOCATION})
    target_link_libraries(test_${TEST_NAME} gtest gtest_main gab)
    add_test(NAME test_${TEST_NAME} COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_${TEST_NAME})
    set_target_properties(test_${TEST_NAME} PROPERTIES
      COMPILE_DEFINITIONS GTEST_USE_OWN_TR1_TUPLE=1
      COMPILE_FLAGS -U__STRICT_ANSI__)
    message(${CMAKE_CURRENT_BINARY_DIR}/test_${TEST_NAME})
endfunction(define_test)

if (test)
  define_test(simulation simulation_test.cpp)
  define_test(simulation_2d simulation_2d_test.cpp)
endif(test)
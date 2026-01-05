add_executable(test_func
  test_func.c)
target_link_libraries(test_func PRIVATE
  ${PROJECT_NAME}_lib)
add_test(NAME test_func
  COMMAND test_func)

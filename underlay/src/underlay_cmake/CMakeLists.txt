cmake_minimum_required(VERSION 3.10)
project(underlay_cmake
  VERSION 1.1.0
  LANGUAGES C)

if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(BUILD_SHARED_LIBS ON CACHE BOOL "")

add_library(${PROJECT_NAME}_lib
  src/${PROJECT_NAME}_lib.c)
target_include_directories(${PROJECT_NAME}_lib PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include>")
set_target_properties(${PROJECT_NAME}_lib PROPERTIES
  OUTPUT_NAME ${PROJECT_NAME})

add_executable(${PROJECT_NAME}_exe
  src/${PROJECT_NAME}_exe.c)
target_link_libraries(${PROJECT_NAME}_exe PRIVATE
  ${PROJECT_NAME}_lib)
set_target_properties(${PROJECT_NAME}_exe PROPERTIES
  OUTPUT_NAME ${PROJECT_NAME})

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}_lib ${PROJECT_NAME}_exe
  EXPORT ${PROJECT_NAME})
install(
  DIRECTORY include/${PROJECT_NAME}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

include(CMakePackageConfigHelpers)
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in
  ${PROJECT_NAME}-config.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
write_basic_package_version_file(
  ${PROJECT_NAME}-config-version.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion)
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

export(
  EXPORT ${PROJECT_NAME}
  NAMESPACE ${PROJECT_NAME}::
  FILE ${PROJECT_NAME}-targets.cmake)

install(
  EXPORT ${PROJECT_NAME}
  NAMESPACE ${PROJECT_NAME}::
  FILE ${PROJECT_NAME}-targets.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(test)
endif()

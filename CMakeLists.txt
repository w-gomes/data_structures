cmake_minimum_required(VERSION 3.16)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

project(random LANGUAGES CXX)
include(cmake/standard_project_settings.cmake)
include(cmake/prevent_in_source_builds.cmake)
include(cmake/static_analyzers.cmake)

# add fmt library
find_package(fmt REQUIRED)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

# sanitizers
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# Link this 'library' to use the warnings specified in compiler_warnings.cmake
add_library(project_warnings INTERFACE)
include(cmake/compiler_warnings.cmake)
set_project_warnings(project_warnings)

set(sources src/main.cpp)

add_executable(${PROJECT_NAME} ${sources})

target_link_libraries(${PROJECT_NAME} 
  PRIVATE project_warnings
         project_options
         fmt::fmt-header-only
)

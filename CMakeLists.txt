cmake_minimum_required(VERSION 3.10)
project(myproject CXX)

# Pre-requisites:
# - CMake 3.10 or higher
# - Conan 1.55.0 or higher is installed and in the path (on my machine I may need to run `eval "$(pyenv init -)"` first)

option(WITH_CLI "Built command-line application" ON)
option(WITH_TESTS "Built unit-tests" ON)
option(WITH_BENCHMARKS "Built performance benchmarks" ON)
option(WITH_TOOLS "Built helper tools" ON)

# Download automatically, you can also just copy the conan.cmake file

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

add_definitions("-std=c++11")

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# conan_cmake_run(REQUIRES catch2/2.13.9
#                 BASIC_SETUP)

conan_cmake_configure(REQUIRES 
                        catch2/2.13.9 
                        celero/2.8.2
                      #  sqlitecpp/3.1.1
                      GENERATORS cmake_find_package_multi)


conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})


find_package(Catch2)
find_package(Celero)
#find_package(SQLiteCpp)

add_library(myproject STATIC
    myproject/lib/myproject.cpp
    )
target_include_directories(myproject PUBLIC myproject/include)
# target_link_libraries(myproject SQLiteCpp sqlite3)


if(WITH_CLI)
  add_executable(hello_myproject myproject/app/hello_myproject.cpp)
  target_link_libraries(hello_myproject
      myproject
      # pthread
      # dl
    )
endif()


if(WITH_TESTS)
  add_executable(test_myproject myproject/test/test_myproject.cpp)
  target_link_libraries(test_myproject 
      myproject
      Catch2::Catch2
    )

    enable_testing()
    add_test(NAME test_myproject COMMAND test_myproject)
endif()


if(WITH_BENCHMARKS)
  add_executable(benchmark_myproject myproject/benchmark/benchmark_myproject.cpp)
  target_link_libraries(benchmark_myproject 
      myproject
      celero
    )  
endif()


if(WITH_TOOLS)
  add_subdirectory(myproject/tools)
endif()

cmake_minimum_required(VERSION 3.10)
project(myproject_tool1 CXX)


list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/myproject/tools/tool1)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/myproject/tools/tool1)

conan_cmake_configure(REQUIRES 
                      sqlitecpp/3.1.1
                      GENERATORS cmake_find_package_multi)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})


find_package(SQLiteCpp)

add_executable(tool_sqlite_checker hello_sqlitecpp.cpp)
target_link_libraries(tool_sqlite_checker 
    myproject
    SQLiteCpp::SQLiteCpp 
    SQLite::SQLite)

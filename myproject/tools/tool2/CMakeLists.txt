cmake_minimum_required(VERSION 3.10)
project(myproject_tool2 CXX)


list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/myproject/tools/tool2)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/myproject/tools/tool2)

conan_cmake_configure(REQUIRES 
                      imgui/1.74
                      glfw/3.3.8
                      glew/2.1.0
                      IMPORTS "./res/bindings, imgui_impl_glfw.cpp -> ../bindings"
                      IMPORTS "./res/bindings, imgui_impl_glfw.h -> ../bindings"
                      IMPORTS "./res/bindings, imgui_impl_opengl3.cpp -> ../bindings"
                      IMPORTS "./res/bindings, imgui_impl_opengl3.h -> ../bindings"
                      
                      GENERATORS cmake_find_package_multi)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})


find_package(imgui)
find_package(glfw3)
find_package(GLEW)

add_executable(myproject_imgui 
    myproject_imgui.cpp
    ${CMAKE_BINARY_DIR}/myproject/tools/bindings/imgui_impl_glfw.cpp
    ${CMAKE_BINARY_DIR}/myproject/tools/bindings/imgui_impl_opengl3.cpp
    )
target_include_directories(myproject_imgui PRIVATE ${CMAKE_BINARY_DIR}/myproject/tools/bindings)
target_link_libraries(myproject_imgui 
    myproject
    imgui::imgui
    glfw::glfw
    GLEW::GLEW
    )

####编译请添加交叉编译选项，如下
####cmake -DCMAKE_TOOLCHAIN_FILE=/home/wsy/templates_for_study/mix/toolchain.cmake ..
cmake_minimum_required(VERSION 2.8.3)
project(svl_subscriber)

set(CMAKE_SYSROOT ${MDC_SDK}/sysroot/)

set(CMAKE_MODULE_PATH "/home/wsy/MDC/enviroment/install/tools_newer/MDC_tools_installed/MDC_Application_Visualizer-Ubuntu18-1.0.105.2/mviz_devel_kit/share/cmake/Modules;${CMAKE_MODULE_PATH}")
set(IS_MVIZDEVELKIT_EXISTS false)
foreach(path IN ITEMS ${CMAKE_MODULE_PATH})
    if(EXISTS ${path}/MvizDevelKit.cmake)
        set(IS_MVIZDEVELKIT_EXISTS true)
    endif()
endforeach()
if(NOT IS_MVIZDEVELKIT_EXISTS)
    message(FATAL_ERROR "Add the path of the directory where the \"MvizDevelKit.cmake\" file is located to the \"CMAKE_MODULE_PATH\" variable in this CMakeLists.txt file.\nExample path:\n /path/to/MDC_Application_Visualizer-Ubuntu18-x.x.x.x/mviz_devel_kit/share/cmake/Modules")
endif()

include(MvizDevelKit)

link_directories(${CMAKE_SYSROOT}/opt/ros/melodic/lib/)

add_executable(topic2mviz topic2mviz.cpp)

target_include_directories(topic2mviz
        PRIVATE
        ${CMAKE_SYSROOT}/opt/ros/melodic/include/
        /usr/local/MDC_Application_Visualizer-Ubuntu18-1.0.101.1/mviz_devel_kit/include/
        )

target_link_libraries(topic2mviz
        PRIVATE
        roscpp rostime rosconsole roscpp_serialization
        visual
        )


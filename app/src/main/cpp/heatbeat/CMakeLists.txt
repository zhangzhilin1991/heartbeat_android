cmake_minimum_required(VERSION 3.6)

# Enable C++11
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#set(OpenCV_DIR ../../../../../opencv/native/jni)
set(target heartbeat)
project(${target} CXX)

message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message("ANDROID_ABI = ${ANDROID_ABI}")

SET(ENV{PKG_CONFIG_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/boost_1_7_0/lib/armeabi-v7a/pkgconfig:${CMAKE_CURRENT_SOURCE_DIR}/openblas_0_3_8_dev/lib/armeabi-v7a/pkgconfig:${CMAKE_CURRENT_SOURCE_DIR}/numcpp/include/pkg-config)
#SET(ENV(LD_LIBRARY_PATH) ${CMAKE_CURRENT_SOURCE_DIR}/boost_1_7_0/lib/armeabi-v7a:${CMAKE_CURRENT_SOURCE_DIR}/openblas_0_3_8_dev/lib/armeabi-v7a)
#SET(ENV(LIBRARY_PATH) ${CMAKE_CURRENT_SOURCE_DIR}/boost_1_7_0/lib/armeabi-v7a:${CMAKE_CURRENT_SOURCE_DIR}/openblas_0_3_8_dev/lib/armeabi-v7a)

find_package(PkgConfig REQUIRED)
pkg_search_module(BOOST REQUIRED boost)
pkg_search_module(OPENBLAS REQUIRED openblas)
pkg_search_module(NUMCPP REQUIRED NumCpp)

MESSAGE(STATUS "BOOST_LIBRARY_DIRS: ${BOOST_LIBRARY_DIRS}")
MESSAGE(STATUS "BOOST_LIBRARY_DIRS: ${BOOST_LIBRARIES}")
MESSAGE(STATUS "ANDROID_OPENCV_COMPONENTS: ${ANDROID_OPENCV_COMPONENTS}")
MESSAGE(STATUS "OPENBLAS_LIBRARIES: ${OPENBLAS_LIBRARIES}")
MESSAGE(STATUS "OPENBLAS_LIBRARY_DIRS: ${OPENBLAS_LIBRARY_DIRS}")

#find boost
#set(Boost_NO_SYSTEM_PATHS ON)
#set(Boost_ADDITIONAL_VERSIONS "1.70.0")
#set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/boost_1_7_0")
#set(BOOST_INCLUDEDIR "${BOOST_ROOT}/include")
#set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib")
#find_package(Boost REQUIRED)
        #  regex
#        filesystem
#        system
#        )

#if(NOT Boost_FOUND)
#    message("未发现Boost")
#    return()
#endif()

#find_package(PkgConfig REQUIRED)

set(ANDROID_OPENCV_COMPONENTS "opencv_java" CACHE STRING "")
#message(STATUS "ANDROID_ABI=${ANDROID_ABI}")
find_package(OpenCV REQUIRED COMPONENTS ${ANDROID_OPENCV_COMPONENTS})

file(GLOB srcs *.cpp *.c)
file(GLOB hdrs *.hpp *.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR} ${OpenCV_INCLUDE_DIRS} ${OPENBLAS_INCLUDE_DIRS} ${NUMCPP_INCLUDE_DIRS} ${BOOST_INCLUDE_DIRS})

#add_subdirectory(rppgalgo)

#include_directories()
add_library( # Sets the name of the library.
        openblas

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        openblas

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${CMAKE_CURRENT_SOURCE_DIR}/${OPENBLAS_LIBRARY_DIRS}/${ANDROID_ABI}/libopenblas.a)

add_library( # Sets the name of the library.
        boost_sysytem

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        boost_sysytem

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${CMAKE_CURRENT_SOURCE_DIR}/${BOOST_LIBRARY_DIRS}/${ANDROID_ABI}/libboost_system.a)

add_library( # Sets the name of the library.
        boost_filesysytem

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        boost_filesysytem

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${CMAKE_CURRENT_SOURCE_DIR}/${BOOST_LIBRARY_DIRS}/${ANDROID_ABI}/libboost_filesystem.a)

add_library(${target} SHARED ${srcs} ${hdrs})
target_link_libraries(${target}
        ${ANDROID_OPENCV_COMPONENTS}
        openblas
        boost_sysytem
        boost_filesysytem
        )
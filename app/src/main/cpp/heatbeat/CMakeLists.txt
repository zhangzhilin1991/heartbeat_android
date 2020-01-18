# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

set (CMAKE_CXX_STANDARD 14)

#set opencv path
set(OPENCV_PATH ${CMAKE_CURRENT_SOURCE_DIR}/opencv_3_4_7)
#set numcpp path
set(NUMCPP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/numcpp)
#set openblas path
set(OPENBALS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/openblas_0_3_8_dev)
#set boost path
set(BOOST_PATH ${CMAKE_CURRENT_SOURCE_DIR}/boost_1_7_0)

include_directories(include ${OPENCV_PATH}/include ${OPENBALS_PATH}/include ${NUMCPP_PATH}/include ${BOOST_PATH}/include)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

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
        ${OPENBALS_PATH}/lib/${ANDROID_ABI}/libopenblas.a)

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
        ${BOOST_PATH}/lib/${ANDROID_ABI}/libboost_system.a)

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
        ${BOOST_PATH}/lib/${ANDROID_ABI}/libboost_filesystem.a)

#opencv dnn objectdetect core imgproc imgcodecs videoio highgui
add_library( # Sets the name of the library.
        opencv_dnn

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        opencv_dnn

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/lib/${ANDROID_ABI}/libopencv_dnn.a)

add_library( # Sets the name of the library.
        opencv_objectdetect

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        opencv_objectdetect

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/lib/${ANDROID_ABI}/libopencv_objdetect.a)

add_library( # Sets the name of the library.
        opencv_core

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        opencv_core

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/lib/${ANDROID_ABI}/libopencv_core.a)

add_library( # Sets the name of the library.
        opencv_imgproc

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        opencv_imgproc

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/lib/${ANDROID_ABI}/libopencv_imgproc.a)


add_library( # Sets the name of the library.
        opencv_imagecodes

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        opencv_imagecodes

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/lib/${ANDROID_ABI}/libopencv_imgcodecs.a)

add_library( # Sets the name of the library.
        opencv_videoio

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        opencv_videoio

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/lib/${ANDROID_ABI}/libopencv_videoio.a)

add_library( # Sets the name of the library.
        opencv_highgui

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        opencv_highgui

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/lib/${ANDROID_ABI}/libopencv_highgui.a)

#google::protobuf:
add_library( # Sets the name of the library.
        google_protobuf

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        google_protobuf

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/3rdparty/libs/${ANDROID_ABI}/liblibprotobuf.a)

#libtegra_hal.a
add_library( # Sets the name of the library.
        tegra_hal

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        tegra_hal

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/3rdparty/libs/${ANDROID_ABI}/libtegra_hal.a)

#libcpufeatures
add_library( # Sets the name of the library.
        cpu_features

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        cpu_features

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/3rdparty/libs/${ANDROID_ABI}/libcpufeatures.a)

#libIlmImf
add_library( # Sets the name of the library.
        ilm_imf

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        ilm_imf

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/3rdparty/libs/${ANDROID_ABI}/libIlmImf.a)

#liblibjasper
add_library( # Sets the name of the library.
        libjasper

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        libjasper

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/3rdparty/libs/${ANDROID_ABI}/liblibjasper.a)

#liblibjpeg-turbo
add_library( # Sets the name of the library.
        libjpeg-turbo

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        libjpeg-turbo

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/3rdparty/libs/${ANDROID_ABI}/liblibjpeg-turbo.a)

#liblibpng
add_library( # Sets the name of the library.
        libpng

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        libpng

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/3rdparty/libs/${ANDROID_ABI}/liblibpng.a)

#liblibtiff
add_library( # Sets the name of the library.
        libtiff

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        libtiff

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/3rdparty/libs/${ANDROID_ABI}/liblibtiff.a)

#liblibwebp
add_library( # Sets the name of the library.
        libwebp

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        libwebp

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/3rdparty/libs/${ANDROID_ABI}/liblibwebp.a)

#libittnotify
add_library( # Sets the name of the library.
        ittnotify

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        ittnotify

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/3rdparty/libs/${ANDROID_ABI}/libittnotify.a)

#libopencv_video
add_library( # Sets the name of the library.
        opencv_video

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        IMPORTED)

set_target_properties( # Specifies the target library.
        opencv_video

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${OPENCV_PATH}/lib/${ANDROID_ABI}/libopencv_video.a)

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(HeartBeat ${SOURCES} )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
set(opencv3rdLbs cpu_features ilm_imf ittnotify google_protobuf tegra_hal libjasper libjpeg-turbo libpng libtiff libwebp)

target_link_libraries( # Specifies the target library.
        HeartBeat

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        m
        z
        openblas
        boost_sysytem
        boost_filesysytem
        opencv_dnn
        opencv_objectdetect
        opencv_video
        opencv_videoio
        opencv_imgproc
        #opencv_highgui
        opencv_imagecodes
        opencv_core
        ${opencv3rdLbs}
        #cpu_features
        )
project(atk)
cmake_minimum_required(VERSION 3.14.0)

if (WIN32) # NOTE: Needs testing for optional AntTweakBar

  set(INCLUDE_DIRS
     .
     external/include)

  set(LIBRARY_DIRS libsrc)

  set(CMAKE_CXX_STANDARD 11) 
  set(CMAKE_CXX_FLAGS 
     "/wd4018 /wd4244 /wd4305 
     /D_CRT_SECURE_NO_WARNINGS 
     /D_CRT_NONSTDC_NO_DEPRECATE 
     /D NOMINMAX /DGLEW_STATIC
     /EHsc")

  set(VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
  set(CMAKE_EXE_LINKER_FLAGS "/NODEFAULTLIB:\"MSVCRT\" /NODEFAULTLIB:\"LIBCMT\"")

  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
  set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

elseif (APPLE)

  set(CMAKE_MACOSX_RPATH 1)
  set(CMAKE_CXX_FLAGS "-Wall -Wno-deprecated-declarations -Wno-reorder-ctor -Wno-unused-function -Wno-unused-variable -g -stdlib=libc++ -std=c++14")
  set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
  add_definitions(-DAPPLE)

  set(INCLUDE_DIRS
    .
    /System/Library/Frameworks
    /usr/local/include
    )

  set(LIBRARY_DIRS
    libsrc/
    )

elseif (UNIX)

  set(CMAKE_CXX_FLAGS "-Wall -g -std=c++14 -Wno-comment -Wno-sign-compare -Wno-unused-function -Wno-reorder") 
  set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

  set(INCLUDE_DIRS
    external/include
    .
    )

  set(LIBRARY_DIRS
    /usr/X11R6/lib
    /usr/local/lib
    external/lib
    libsrc
    )

  add_definitions(-DUNIX)

endif()

include_directories(${INCLUDE_DIRS})
link_directories(${LIBRARY_DIRS})
add_subdirectory(atk)

add_executable(example example.cpp)
target_link_libraries(example  atk ${LIBS})

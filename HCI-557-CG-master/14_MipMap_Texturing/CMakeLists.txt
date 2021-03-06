# Main cmake file
# Mipmap Texture example
# Rafael Radkowski, rafael@iastate.edu
# Iowa State University
# ME/CS/CprE 557 Computer Graphics, Fall 2015

cmake_minimum_required(VERSION 2.6)

# Main project name is ARMaker
project(HCI557_Mipmap_Texture)


set(CFILE_PATH  "${CMAKE_SOURCE_DIR}/../SDK/cmake/")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/" ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../SDK/cmake/")

message(STATUS "Source directory ${CMAKE_SOURCE_DIR}")
message(STATUS "SDK directory ${CMAKE_SOURCE_DIR}/../SDK")


# Find packages
FIND_PACKAGE(GLEW REQUIRED)
FIND_PACKAGE(Glm REQUIRED)
FIND_PACKAGE(glfw3 REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)


# Include dirs
include_directories(${GLEW_INCLUDE_DIR})
include_directories(${GLFW3_INCLUDE_DIR})
include_directories(${GLM_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/../gl_common/)

# Add all files to the configuration
	file(GLOB HCI557_Mipmap_Texture_SRC
	main_mipmap_texture.cpp
    ../gl_common/HCI557Common.cpp
    ../gl_common/HCI557Common.h
	../gl_common/controls.cpp
    ../gl_common/controls.h
	../gl_common/CoordSystem.cpp
    ../gl_common/CoordSystem.h
	../gl_common/GLObject.h
   	../gl_common/GLObject.cpp
    ../gl_common/GLSphere.cpp
    ../gl_common/GLSphere.h
    ../gl_common/Shaders.h
    ../gl_common/Shaders.cpp
    ../gl_common/Plane3D.h
    ../gl_common/Plane3D.cpp
    ../gl_common/Texture.h
    ../gl_common/Texture.cpp
    ../gl_common/HCI557Datatypes.h
    ../gl_common/GLAppearanceBase.h
    ../gl_common/GLAppearance.h
    ../gl_common/GLAppearance.cpp
    ../gl_common/camera.h
	../gl_common/camera.cpp
    ../gl_common/GLObjects3D.h
)

set(HCI557_RES
	../data/shaders/mipmap_texture.fs
	../data/shaders/mipmap_texture.vs
)


#----
# SRC Groups
source_group(Resources FILES ${HCI557_RES})


# Create an executable
add_executable(HCI557_Mipmap_Texture ${HCI557_Mipmap_Texture_SRC})


# Add link directories
# Note required for this project
link_directories(/usr/bin)
link_directories(/usr/include/GL)
link_directories(/usr/include/GLFW)


# Add libraries
target_link_libraries(HCI557_Mipmap_Texture ${GLEW_LIBRARY} ${GLFW3_LIBRARY} ${OPENGL_LIBRARIES} ${OPENGL_LIBRARIES} )

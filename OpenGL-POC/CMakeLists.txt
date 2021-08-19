project(OpenGLPOC)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CXX_FLAGS "-Wall")

include_directories(
        /usr/local/include)

set(OPENGL_LIBS -L/usr/local/lib
        -lglfw3 -lrt -lm -lXrandr
        -lXrender -lXi -lXfixes
        -lXxf86vm -lXext -lX11
        -lpthread -lxcb -lXau -lXdmcp -lGLEW -lGLU -lglut -lGL)

#add_executable(app src/hello_world.cpp)
#target_link_libraries(app ${OPENGL_LIBS})

add_executable(app1 src/blender_rendering.cpp src/blender_rendering.cpp)
target_link_libraries(app1 ${OPENGL_LIBS})



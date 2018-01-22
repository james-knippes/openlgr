cmake_minimum_required(VERSION 3.1)
project(OpenLGR)

option(USE_VM "Use hardware virtualization backend for Unicorn-Engine" OFF)


set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(Unicorn REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OpenAL REQUIRED)

include_directories(SYSTEM
  ${LIBUNICORN_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${GLEW_INCLUDE_DIRS}
  ${SDL2_INCLUDE_DIR}
  ${OPENAL_INCLUDE_DIR}
)

add_executable(openlgr
  main.c
  emulation.c
  export.c
  shader.c

  dll/kernel32.c

  com/a3d.c
  com/dplay.c
)

if(USE_VM)
  target_compile_definitions(openlgr PUBLIC -DUC_KVM)
  target_sources(openlgr PUBLIC
    uc_kvm.c
  )
else()
  target_link_libraries(openlgr
    ${LIBUNICORN_LIBRARY}
  )
endif()

target_link_libraries(openlgr
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES}
  ${SDL2_LIBRARY}
  ${OPENAL_LIBRARY}
  -lm
)

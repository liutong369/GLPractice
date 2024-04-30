cmake_minimum_required(VERSION 3.22)

project(gl_main)

if (NOT CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR}/output)
endif ()

set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(OPEN_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/open_source)

find_package(glfw3 REQUIRED)

add_executable(${PROJECT_NAME}
    ${SRC_DIR}/main.cpp
    ${OPEN_SRC_DIR}/glad/src/glad.c
)

target_compile_options(${PROJECT_NAME} PRIVATE -g -O2)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${OPEN_SRC_DIR}/glfw/include
    ${OPEN_SRC_DIR}/glad/include
)

# target_link_options(${PROJECT_NAME} PRIVATE )
target_link_libraries(${PROJECT_NAME} glfw3dll opengl32)
target_link_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_INSTALL_PREFIX}/glfw/lib/
)
 
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(FILES ${CMAKE_INSTALL_PREFIX}/glfw/bin/glfw3.dll DESTINATION bin)

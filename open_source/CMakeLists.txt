# open source build

#compile glfw
add_custom_target(glfw3_build
    COMMAND cmake ${OPEN_SRC_DIR}/glfw -B ${CMAKE_CURRENT_BINARY_DIR}/glfw3 -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}/glfw3
                -DBUILD_SHARED_LIBS=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G "Unix Makefiles" 
    COMMAND make -j${PROCESSOR_NUM} -C ${CMAKE_CURRENT_BINARY_DIR}/glfw3
    COMMAND make install -C ${CMAKE_CURRENT_BINARY_DIR}/glfw3
    WORKING_DIRECTORY ${OPEN_SRC_DIR}/glfw
)

find_package(glfw3)
if (glfw3_FOUND)
    message(STATUS ">>>>>>>>>>>>>> find_package find glfw3 >>>>>>>>>>>>>>")
    target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
    install(FILES ${CMAKE_INSTALL_PREFIX}/glfw3/bin/glfw3.dll DESTINATION bin)
else ()
    add_dependencies(${PROJECT_NAME} glfw3_build)
    target_link_libraries(${PROJECT_NAME} PUBLIC glfw3dll)
    target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_INSTALL_PREFIX}/glfw3/lib/)
    install(FILES ${CMAKE_INSTALL_PREFIX}/glfw3/bin/glfw3.dll DESTINATION bin)
endif()


#compile glad
set(GLAD_OBJ glad_obj)
add_library(${GLAD_OBJ} OBJECT ${OPEN_SRC_DIR}/glad/src/glad.c)
target_include_directories(${GLAD_OBJ} PRIVATE ${OPEN_SRC_DIR}/glad/include)
target_link_libraries(${PROJECT_NAME} PRIVATE $<TARGET_OBJECTS:${GLAD_OBJ}>)

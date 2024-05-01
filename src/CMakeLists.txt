# compile
add_library(${PROJECT_NAME}_obj OBJECT
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/init.cpp
)

target_include_directories(${PROJECT_NAME}_obj PRIVATE
    ${OPEN_SRC_DIR}/glfw/include
    ${OPEN_SRC_DIR}/glad/include
)

target_compile_options(${PROJECT_NAME}_obj PRIVATE -g -D_FORTIFY_SOURCE=2 -O2 -Wall -fstack-protector-strong)
# target_compile_definitions(${PROJECT_NAME}_obj PRIVATE)


# link
add_executable(${PROJECT_NAME} $<TARGET_OBJECTS:${PROJECT_NAME}_obj>)
target_link_libraries(${PROJECT_NAME} PUBLIC opengl32)
# target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,relro,-z,now -Wl,-z,noexecstack)


# install
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

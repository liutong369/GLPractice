#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "log.h"
#include "init.h"


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    // 渲染 render
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();   
}

int main()
{
    InitLog();
    InitGlfw();
    if (!InitGlad()) {
        glfwTerminate();
        return -1;
    }

    GLFWwindow *window = glfwGetCurrentContext();
    while(!glfwWindowShouldClose(window)) {
        processInput(window);
    }

    glfwTerminate(); // glfw: terminate, clearing all previously allocated GLFW resources.

    std::cout << "bye bye..." << std::endl;
    return 0;
}
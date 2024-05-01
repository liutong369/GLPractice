#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "log.h"


void InitGlfw(void) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__ // macos
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    LOG_INFO("glfw version: %s", glfwGetVersionString());
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
static void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

bool InitGlad(void) {
    GLFWwindow* window = glfwCreateWindow(1280, 960, "Main Window", NULL, NULL);
    if (window == nullptr) {
        LOG_ERR("Failed to create GLFW window");
        return false;
    }
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG_ERR("Failed to initialize GLAD.");
        return false;
    }
    if (glGetString == nullptr) {
        LOG_ERR("glGetString function is null.");
        return false;
    }

	const GLubyte *vendor = glGetString(GL_VENDOR); //返回负责当前OpenGL实现厂商的名字
	const GLubyte *renderer = glGetString(GL_RENDERER); //返回一个渲染器标识符，通常是个硬件平台
	const GLubyte *openGLVersion = glGetString(GL_VERSION); //返回当前OpenGL实现的版本号
	
    const GLubyte nullStr[] = "null";
    LOG_INFO("OpenGL的实现厂商：%s", (vendor != nullptr) ? vendor : nullStr);
	LOG_INFO("渲染器：%s", (renderer != nullptr) ? renderer : nullStr);
	LOG_INFO("OpenGL实现的版本号：%s", (openGLVersion != nullptr) ? openGLVersion : nullStr);

    return true;
}

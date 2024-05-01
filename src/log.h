#pragma once

#include <cstdio>
#include <string>
#include "GLFW/glfw3.h"

#define LOG_ERR(fmt, ...) printf("%s:%s():%d [ERROR] " fmt "\n", __GLFILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...) printf("%s:%s():%d [INFO] " fmt "\n", __GLFILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

inline void InitLog(void) {
    glfwSetErrorCallback(
        [](int error_code, const char *description) -> void {
            LOG_ERR("glfw error callback print: errcode:[%d], message:(%s).",
                error_code, (description != nullptr) ? description : "null");
        }
    );
}
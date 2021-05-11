#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main()
{
    if(!glfwInit()) {
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }

    glfwDefaultWindowHints();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello OpenGL and GLFW", NULL, NULL);
    if(window == NULL) {
        cout << "Failed to open GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    do {
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while(glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

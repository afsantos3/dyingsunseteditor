#include <stdio.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main() {
  glfwSetErrorCallback(error_callback);

  if (!glfwInit())
  {
    return -1;
  }

  GLFWwindow* window = glfwCreateWindow(640, 480, "Dying Sun Set Editor", NULL, NULL);
  if (!window)
  {
      // Window or OpenGL context creation failed
  }
  while(!glfwWindowShouldClose(window))
  {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
}
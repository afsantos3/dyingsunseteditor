#include <iostream>
#include <GLFW/glfw3.h>
#include <vulkan.h>

#include <dyingsunseteditorConfig.h>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main(int argc, char* argv[]) {
  std::cout << argv[0] << "Version " 
    << dyingsunseteditor_VERSION_MAJOR << "." 
    << dyingsunseteditor_VERSION_MINOR << "." 
    << dyingsunseteditor_VERSION_PATCH << std::endl;
  
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
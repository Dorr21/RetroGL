#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>


void render()
{
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
    glEnd();
}

void setGLFWSettings()
{
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_ALPHA_BITS, 8);
    
    glfwWindowHint(GLFW_ACCUM_RED_BITS, 8);
    glfwWindowHint(GLFW_ACCUM_GREEN_BITS, 8);
    glfwWindowHint(GLFW_ACCUM_BLUE_BITS, 8);
    glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, 8);

    glfwWindowHint(GLFW_DEPTH_BITS, 24);

    glfwWindowHint(GLFW_STENCIL_BITS, 24);

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_FALSE);
}

int main(int argc, char *argv[])
{
    if (!glfwInit()) return -1;

    setGLFWSettings();

    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Example", NULL, NULL);
    if (!window) 
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		printf("Error: %s", glewGetErrorString(err));
		glfwTerminate();
		return -1;
	}

    while (!glfwWindowShouldClose(window)) 
    {
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}

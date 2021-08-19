//
// Created by sajith on 8/14/21.
//

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    // Initialize GLEW and create a GLFW window object (640x480)
    GLFWwindow *window;
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }
    window = glfwCreateWindow(640, 480, "Simple GLFW Demo", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    // Define a loop that terminates when the window is closed.

    while (!glfwWindowShouldClose(window))
    {
        // Set up the viewport (using the width and height of the window) and clear the screen buffer.
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = (float) width / (float) height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        // Set up the camera matrix.
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Draw a rotating triangle and set a different color(red, green, and blue channels) for each vertex(x,y, and z)
        // of the triangle.
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();

        // Swap the frond and back buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Release the memory and terminate the GLFW library
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
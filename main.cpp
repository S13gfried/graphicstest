// Graphic dependencies
#include "glew.h" //Provides ways to access hardware and get functions to in
#include "glfw3.h"

#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WINDOW_TITLE "a fucking triangle"

int main(void)
{
    //initialize GLFW
    assert(glfwInit()); 
    //initialize GLEW
    assert(glewInit() == GLEW_OK);

   //create window context
    GLFWwindow* appWindow;
 
    appWindow = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if(!appWindow)
    {
        glfwTerminate();
        assert(0); //goofy ahh
    }

    //select the window we've just initialized
    glfwMakeContextCurrent(appWindow);

    //the following loop runs until the user closes the window.
    while(!glfwWindowShouldClose(appWindow))
    {
        //clear the window
        glClear(GL_COLOR_BUFFER_BIT);

        //enter triangle mode
        glBegin(GL_TRIANGLES);
        //specify vertices
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glEnd();

        glfwSwapBuffers(appWindow);

        glfwPollEvents();
    }

    //terminate
    glfwTerminate();
    return 0;
}
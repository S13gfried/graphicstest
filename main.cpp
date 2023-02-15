// Graphic dependencies
//#include <GL/glew.h>  //Provides ways to access hardware and get functions to in
//#include <GLFW/glfw3.h>
#include <GL/glut.h>

#include <assert.h>
#include <errno.h>

#include <iostream>
#include <stdexcept>

#include "geometry.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WINDOW_TITLE "BUERAK 4: THE SILENCE OF THE HOUSES"

void renderRectange(rectangleP)
{

}

void display()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_TRIANGLES);

  glVertex2f(-1.5, -1.5);
  glVertex2f(1.5, -1.5);
  glVertex2f(0.0, 1.5);

  glEnd();
  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition(100, 100);

  glutCreateWindow(WINDOW_TITLE);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
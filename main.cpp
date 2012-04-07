#include "GL/freeglut.h"
#include "GL/gl.h"
#include "GL/glu.h"

float WinWid = 400.0;
float WinHei = 400.0;

float rot = 0.0;

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glutWireCube(20);
    
    glutSwapBuffers();
}

void Timer(int v) {
    glutPostRedisplay();
    glutTimerFunc(100, Timer, 0);
    Draw();
}

void Initsialaize() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0 , 3, 1.0, 400.0);
    //glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0, 0.0, -40.0);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Lesson 14");
    
    glutDisplayFunc(Draw);
    glutTimerFunc(100, Timer, 0);
    Initsialaize();
    glutMainLoop();
    
    return 0;
}
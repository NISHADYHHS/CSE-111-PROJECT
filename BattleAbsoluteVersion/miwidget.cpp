#include "miwidget.h"

miwidget::miwidget(QWidget *parent) : QOpenGLWidget(parent){}

void miwidget::initializeGL()
{
    glClearColor(0.59, 1, 0.59, 1); //define blue color as background color
}
void miwidget::resizeGL(int w, int h)
{
}

void  miwidget::makeGrass(float p1, float p2, float p3){

    glBegin(GL_TRIANGLES);
    glVertex3f(p1 ,-0.7, 0);
    glVertex3f(p2, -0.9, 0);
    glVertex3f(p3 , -0.9, 0);
    glEnd();
}
void miwidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0.39,0);
    glBegin(GL_TRIANGLES);
    float one = -0.95;
    float two  = -1;
    float three =  -0.9;

    for(float x = 0; x < 1.95; x += 0.05){

         makeGrass(one + x,two + x , three + x);
    }
   // makeGrass(-0.95,-1, -0.9);
   /* */
   /* glBegin(GL_TRIANGLES);
    glVertex3f(-0.90 ,-0.7, 0);
    glVertex3f(-0.95, -0.9, 0);
    glVertex3f(-0.85 , -0.9, 0);
    glEnd();*/
}

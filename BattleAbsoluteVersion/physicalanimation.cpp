#include "physicalanimation.h"

float one1 = -0.2;
int times1 = 0;
bool start1 = false;
PhysicalAnimation::PhysicalAnimation(QWidget *parent) : QOpenGLWidget(parent){

    timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),SLOT(paintGL()));
    timer->start(1000);
}
PhysicalAnimation::~PhysicalAnimation(){
    delete timer;
}

void PhysicalAnimation::initializeGL()
{
    glClearColor(0.59, 1, 0.59, 1); //define blue color as background color

}

void PhysicalAnimation::resizeGL(int width, int height)
{

}

void PhysicalAnimation::animate(){
    // qDebug()<< "somethingshould happen now";

    if(one1 < 1)
    {
        one1 += 0.01;
    }
    else
    {
        one1 = 0.8;
        times1++;

    }
    update();
}

void PhysicalAnimation::animate2(){
    // qDebug()<< "somethingshould happen now";

    if(one1 > 0.3)
    {
        one1 -= 0.1;
    }
    else
    {
        one1 =  -0.8;
        times1++;
        start1 = false;
    }
    update();
}


void PhysicalAnimation::startit(){
    start1 = true;
    times1 = 0;
    paintGL();
}
void PhysicalAnimation::stopit(){
    start1 = false;
}

void PhysicalAnimation::paintGL()
{

    if(times1 < 1 && start1 == true){
        glColor3f(1,0,1);
        qDebug() << "working";
        glBegin(GL_TRIANGLES);
        glVertex3f(0.8,0.7 +(1.5* (one1- 1.5)) , 0);
        glVertex3f(0.8- 0.05,0.9 +(1.5* (one1- 1.5))   , 0);
        glVertex3f(0.8 + 0.05, 0.9 +(1.5* (one1-1.5)) , 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(0.8,-0.7 -(1.5* (one1-1.5)), 0);
        glVertex3f(0.8- 0.05,-0.9 -(1.5* (one1-1.5)) , 0);
        glVertex3f(0.8 + 0.05, -0.9 -(1.5* (one1-1.5)), 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(0.8 + (one1 - 0.8) ,-0.7 -(1.5* (0.8-1.5)), 0);
        glVertex3f(0.8- 0.05+ (one1 - 0.8),-0.9 -(1.5* (0.8-1.5)) , 0);
        glVertex3f(0.8 + 0.05+ (one1 - 0.8), -0.9 -(1.5* (0.8-1.5)), 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(0.8 - (one1 - 0.8) ,-0.7 -(1.5* (0.8-1.5)), 0);
        glVertex3f(0.8- 0.05- (one1 - 0.8),-0.9 -(1.5* (0.8-1.5)) , 0);
        glVertex3f(0.8 + 0.05- (one1 - 0.8), -0.9 -(1.5* (0.8-1.5)), 0);
        glEnd();
        animate();
    }else{
        if(start1){
            glColor3f(1,0,1);
            qDebug() << "working";
            glBegin(GL_TRIANGLES);
            glVertex3f(0.8,0.7 +(1.5* (one1- 1.5)) , 0);
            glVertex3f(0.8- 0.05,0.9 +(1.5* (one1- 1.5))   , 0);
            glVertex3f(0.8 + 0.05, 0.9 +(1.5* (one1-1.5)) , 0);
            glEnd();
            glBegin(GL_TRIANGLES);
            glVertex3f(0.8,-0.7 -(1.5* (one1-1.5)), 0);
            glVertex3f(0.8- 0.05,-0.9 -(1.5* (one1-1.5)) , 0);
            glVertex3f(0.8 + 0.05, -0.9 -(1.5* (one1-1.5)), 0);
            glEnd();
            glBegin(GL_TRIANGLES);
            glVertex3f(0.8 + (one1 - 0.8) ,-0.7 -(1.5* (0.8-1.5)), 0);
            glVertex3f(0.8- 0.05+ (one1 - 0.8),-0.9 -(1.5* (0.8-1.5)) , 0);
            glVertex3f(0.8 + 0.05+ (one1 - 0.8), -0.9 -(1.5* (0.8-1.5)), 0);
            glEnd();
            glBegin(GL_TRIANGLES);
            glVertex3f(0.8 - (one1 - 0.8) ,-0.7 -(1.5* (0.8-1.5)), 0);
            glVertex3f(0.8- 0.05- (one1 - 0.8),-0.9 -(1.5* (0.8-1.5)) , 0);
            glVertex3f(0.8 + 0.05- (one1 - 0.8), -0.9 -(1.5* (0.8-1.5)), 0);
            glEnd();
            animate2();
        }
    }





}

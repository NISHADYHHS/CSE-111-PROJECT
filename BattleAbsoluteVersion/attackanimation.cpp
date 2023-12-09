#include "attackanimation.h"


float one = -0.75;
int times = 0;
bool start = false;
AttackAnimation::AttackAnimation(QWidget *parent) : QOpenGLWidget(parent){

    timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),SLOT(paintGL()));
    timer->start(1000);
}
AttackAnimation::~AttackAnimation(){
    delete timer;
}

void AttackAnimation::initializeGL()
{
    glClearColor(0.59, 1, 0.59, 1); //define blue color as background color //define blue color as background color

}

void AttackAnimation::resizeGL(int width, int height)
{

}

void AttackAnimation::animate(){
   // qDebug()<< "somethingshould happen now";

        if(one < 2)
        {
            one += 0.03;
        }
        else
        {
            one = 0.8;
            times++;

        }
        update();
    }

void AttackAnimation::animate2(){
    // qDebug()<< "somethingshould happen now";

    if(one > 0.3)
    {
        one -= 0.04;
    }
    else
    {
        one =  -0.8;
        times++;
        start = false;
    }
    update();
}

int AttackAnimation::getTimes(){

    return times;
}
void AttackAnimation::startit(){
    start = true;
    times = 0;
    paintGL();
}
void AttackAnimation::stopit(){
    start = false;
}

void AttackAnimation::paintGL()
{

    if(times < 1 && start == true){
       glColor3f(1,0,0);
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.10 - 0.80,-1.2 +(1.5* one)- 0.10, 0);
        glVertex3f(one +0.1- 0.10- 0.80,-1.15 +(1.5* one) - 0.10, 0);
        glVertex3f(one+0.065- 0.10- 0.80, -1.3 +(1.5* one)- 0.10, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.05- 0.80,-1.2 +(1.5* one)- 0.05, 0);
        glVertex3f(one +0.1- 0.05- 0.80,-1.15 +(1.5* one) - 0.05, 0);
        glVertex3f(one+0.065- 0.05- 0.80, -1.3 +(1.5* one)- 0.05, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.15- 0.80,-1.2 +(1.5* one)- 0.15, 0);
        glVertex3f(one +0.1- 0.15- 0.80,-1.15 +(1.5* one) - 0.15, 0);
        glVertex3f(one+0.065- 0.15- 0.80, -1.3 +(1.5* one)- 0.15, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.20- 0.80,-1.2 +(1.5* one)- 0.20, 0);
        glVertex3f(one +0.1- 0.20- 0.80,-1.15 +(1.5* one) - 0.20, 0);
        glVertex3f(one+0.065- 0.20- 0.80, -1.3 +(1.5* one)- 0.20, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.25- 0.80,-1.2 +(1.5* one)- 0.25, 0);
        glVertex3f(one +0.1- 0.25- 0.80,-1.15 +(1.5* one) - 0.25, 0);
        glVertex3f(one+0.065- 0.25- 0.80, -1.3 +(1.5* one)- 0.25, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.30- 0.80,-1.2 +(1.5* one)- 0.30, 0);
        glVertex3f(one +0.1- 0.30- 0.80,-1.15 +(1.5* one) - 0.30, 0);
        glVertex3f(one+0.065- 0.30- 0.80, -1.3 +(1.5* one)- 0.30, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.35- 0.80,-1.2 +(1.5* one)- 0.35, 0);
        glVertex3f(one +0.1- 0.35- 0.80,-1.15 +(1.5* one) - 0.35, 0);
        glVertex3f(one+0.065- 0.35- 0.80, -1.3 +(1.5* one)- 0.35, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.40- 0.80,-1.2 +(1.5* one)- 0.40, 0);
        glVertex3f(one +0.1- 0.40- 0.80,-1.15 +(1.5* one) - 0.40, 0);
        glVertex3f(one+0.065- 0.40- 0.80, -1.3 +(1.5* one)- 0.40, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.45- 0.80,-1.2 +(1.5* one)- 0.45, 0);
        glVertex3f(one +0.1- 0.45- 0.80,-1.15 +(1.5* one) - 0.45, 0);
        glVertex3f(one+0.065- 0.45- 0.80, -1.3 +(1.5* one)- 0.45, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.50- 0.80,-1.2 +(1.5* one)- 0.50, 0);
        glVertex3f(one +0.1- 0.50- 0.80,-1.15 +(1.5* one) - 0.50, 0);
        glVertex3f(one+0.065- 0.50- 0.80, -1.3 +(1.5* one)- 0.50, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.55- 0.80,-1.2 +(1.5* one)- 0.55, 0);
        glVertex3f(one +0.1- 0.55- 0.80,-1.15 +(1.5* one) - 0.55, 0);
        glVertex3f(one+0.065- 0.55- 0.80, -1.3 +(1.5* one)- 0.55, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.60- 0.80,-1.2 +(1.5* one)- 0.60, 0);
        glVertex3f(one +0.1- 0.60- 0.80,-1.15 +(1.5* one) - 0.60, 0);
        glVertex3f(one+0.065- 0.60- 0.80, -1.3 +(1.5* one)- 0.60, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.65- 0.80,-1.2 +(1.5* one)- 0.65, 0);
        glVertex3f(one +0.1- 0.65- 0.80,-1.15 +(1.5* one) - 0.65, 0);
        glVertex3f(one+0.065- 0.65- 0.80, -1.3 +(1.5* one)- 0.65, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.7- 0.80,-1.2 +(1.5* one)-0.7, 0);
        glVertex3f(one +0.1- 0.7- 0.80,-1.15 +(1.5* one) - 0.7, 0);
        glVertex3f(one+0.065- 0.7- 0.80, -1.3 +(1.5* one)- 0.7, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(one - 0.75- 0.80,-1.2 +(1.5* one)- 0.75, 0);
        glVertex3f(one +0.1- 0.75- 0.80,-1.15 +(1.5* one) - 0.75, 0);
        glVertex3f(one+0.065- 0.75- 0.80, -1.3 +(1.5* one)- 0.75, 0);
        glEnd();



            animate();
    }else{
        if(start){
            glColor3f(1,0,1);
            glBegin(GL_TRIANGLES);
            glVertex3f(0.47,1.2 +(1.5* (one- 1.5)) , 0);
            glVertex3f(0.47- 0.05,1.4 +(1.5* (one- 1.5))   , 0);
            glVertex3f(0.47 + 0.05, 1.4+(1.5* (one-1.5)) , 0);
            glEnd();
            glBegin(GL_TRIANGLES);
            glVertex3f(0.47,-0.5  -(1.5* (one-1.5)), 0);
            glVertex3f(0.47- 0.05,-0.7 -(1.5* (one-1.5)) , 0);
            glVertex3f(0.47 + 0.05, -0.7 -(1.5* (one-1.5)), 0);
            glEnd();
            glBegin(GL_TRIANGLES);
            glVertex3f(0.47 + (one - 0.8) ,-0.5 -(1.5* (0.8-1.5)), 0);
            glVertex3f(0.47- 0.05+ (one - 0.8),-0.7 -(1.5* (0.8-1.5)) , 0);
            glVertex3f(0.47 + 0.05+ (one - 0.8), -0.7 -(1.5* (0.8-1.5)), 0);
            glEnd();
            glBegin(GL_TRIANGLES);
            glVertex3f(0.47 - (one - 0.8) ,-0.5 -(1.5* (0.8-1.5)), 0);
            glVertex3f(0.47- 0.05- (one - 0.8),-0.7 -(1.5* (0.8-1.5)) , 0);
            glVertex3f(0.47 + 0.05- (one - 0.8), -0.7 -(1.5* (0.8-1.5)), 0);
            glEnd();
            animate2();
        }
    }





}

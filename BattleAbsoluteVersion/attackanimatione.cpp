#include "attackanimatione.h"



float onee= 1.2;
int timese= 0;
bool starte= false;
AttackAnimationE::AttackAnimationE(QWidget *parent) : QOpenGLWidget(parent){

    timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),SLOT(paintGL()));
    timer->start(1000);
}
AttackAnimationE::~AttackAnimationE(){
    delete timer;
}

void AttackAnimationE::initializeGL()
{
    glClearColor(0.59, 1, 0.59, 1); //define blue color as background color
}

void AttackAnimationE::resizeGL(int width, int height)
{

}

void AttackAnimationE::animate(){
    // qDebug()<< "somethingshould happen now";

    if(onee> 0.3)
    {
        onee-= 0.03;
    }
    else
    {
        onee=  0.3;
        timese++;
    }
    update();
}

void AttackAnimationE::animate2(){
    // qDebug()<< "somethingshould happen now";

    if(onee < 0.8)
    {
        onee+= 0.01;
    }
    else
    {
        onee=  0.8;
        timese++;
        starte= false;
    }
    update();
}

int AttackAnimationE::getTimes(){

    return timese;
}
void AttackAnimationE::startit(){
    starte= true;
    timese= 0;
    paintGL();
}
void AttackAnimationE::stopit(){
    starte= false;
}

void AttackAnimationE::paintGL()
{

    if(timese< 1 && starte== true){
        glColor3f(1,0,0);
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.10 - 0.80,-1.2 +(1.5* onee)- 0.10, 0);
        glVertex3f(onee +0.1- 0.10- 0.80,-1.15 +(1.5* onee) - 0.10, 0);
        glVertex3f(onee+0.065- 0.10- 0.80, -1.3 +(1.5* onee)- 0.10, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.05- 0.80,-1.2 +(1.5* onee)- 0.05, 0);
        glVertex3f(onee +0.1- 0.05- 0.80,-1.15 +(1.5* onee) - 0.05, 0);
        glVertex3f(onee+0.065- 0.05- 0.80, -1.3 +(1.5* onee)- 0.05, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.15- 0.80,-1.2 +(1.5* onee)- 0.15, 0);
        glVertex3f(onee +0.1- 0.15- 0.80,-1.15 +(1.5* onee) - 0.15, 0);
        glVertex3f(onee+0.065- 0.15- 0.80, -1.3 +(1.5* onee)- 0.15, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.20- 0.80,-1.2 +(1.5* onee)- 0.20, 0);
        glVertex3f(onee +0.1- 0.20- 0.80,-1.15 +(1.5* onee) - 0.20, 0);
        glVertex3f(onee+0.065- 0.20- 0.80, -1.3 +(1.5* onee)- 0.20, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.25- 0.80,-1.2 +(1.5* onee)- 0.25, 0);
        glVertex3f(onee +0.1- 0.25- 0.80,-1.15 +(1.5* onee) - 0.25, 0);
        glVertex3f(onee+0.065- 0.25- 0.80, -1.3 +(1.5* onee)- 0.25, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.30- 0.80,-1.2 +(1.5* onee)- 0.30, 0);
        glVertex3f(onee +0.1- 0.30- 0.80,-1.15 +(1.5* onee) - 0.30, 0);
        glVertex3f(onee+0.065- 0.30- 0.80, -1.3 +(1.5* onee)- 0.30, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.35- 0.80,-1.2 +(1.5* onee)- 0.35, 0);
        glVertex3f(onee +0.1- 0.35- 0.80,-1.15 +(1.5* onee) - 0.35, 0);
        glVertex3f(onee+0.065- 0.35- 0.80, -1.3 +(1.5* onee)- 0.35, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.40- 0.80,-1.2 +(1.5* onee)- 0.40, 0);
        glVertex3f(onee +0.1- 0.40- 0.80,-1.15 +(1.5* onee) - 0.40, 0);
        glVertex3f(onee+0.065- 0.40- 0.80, -1.3 +(1.5* onee)- 0.40, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.45- 0.80,-1.2 +(1.5* onee)- 0.45, 0);
        glVertex3f(onee +0.1- 0.45- 0.80,-1.15 +(1.5* onee) - 0.45, 0);
        glVertex3f(onee+0.065- 0.45- 0.80, -1.3 +(1.5* onee)- 0.45, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.50- 0.80,-1.2 +(1.5* onee)- 0.50, 0);
        glVertex3f(onee +0.1- 0.50- 0.80,-1.15 +(1.5* onee) - 0.50, 0);
        glVertex3f(onee+0.065- 0.50- 0.80, -1.3 +(1.5* onee)- 0.50, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.55- 0.80,-1.2 +(1.5* onee)- 0.55, 0);
        glVertex3f(onee +0.1- 0.55- 0.80,-1.15 +(1.5* onee) - 0.55, 0);
        glVertex3f(onee+0.065- 0.55- 0.80, -1.3 +(1.5* onee)- 0.55, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.60- 0.80,-1.2 +(1.5* onee)- 0.60, 0);
        glVertex3f(onee +0.1- 0.60- 0.80,-1.15 +(1.5* onee) - 0.60, 0);
        glVertex3f(onee+0.065- 0.60- 0.80, -1.3 +(1.5* onee)- 0.60, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.65- 0.80,-1.2 +(1.5* onee)- 0.65, 0);
        glVertex3f(onee +0.1- 0.65- 0.80,-1.15 +(1.5* onee) - 0.65, 0);
        glVertex3f(onee+0.065- 0.65- 0.80, -1.3 +(1.5* onee)- 0.65, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.7- 0.80,-1.2 +(1.5* onee)-0.7, 0);
        glVertex3f(onee +0.1- 0.7- 0.80,-1.15 +(1.5* onee) - 0.7, 0);
        glVertex3f(onee+0.065- 0.7- 0.80, -1.3 +(1.5* onee)- 0.7, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.75- 0.80,-1.2 +(1.5* onee)- 0.75, 0);
        glVertex3f(onee +0.1- 0.75- 0.80,-1.15 +(1.5* onee) - 0.75, 0);
        glVertex3f(onee+0.065- 0.75- 0.80, -1.3 +(1.5* onee)- 0.75, 0);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.8- 0.80,-1.2 +(1.5* onee)-  0.80, 0);
        glVertex3f(onee +0.1- 0.8- 0.80,-1.15 +(1.5* onee) -  0.80, 0);
        glVertex3f(onee+0.065- 0.8- 0.80, -1.3 +(1.5* onee)-  0.80, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.85- 0.80,-1.2 +(1.5* onee)-  0.85, 0);
        glVertex3f(onee +0.1- 0.85- 0.80,-1.15 +(1.5* onee) -  0.85, 0);
        glVertex3f(onee+0.065- 0.85- 0.80, -1.3 +(1.5* onee)-  0.85, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.9- 0.80,-1.2 +(1.5* onee)-  0.9, 0);
        glVertex3f(onee +0.1- 0.9- 0.80,-1.15 +(1.5* onee) -  0.9, 0);
        glVertex3f(onee+0.065- 0.9- 0.80, -1.3 +(1.5* onee)-  0.9, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 0.95- 0.80,-1.2 +(1.5* onee)-  0.95, 0);
        glVertex3f(onee +0.1- 0.95- 0.80,-1.15 +(1.5* onee) -  0.95, 0);
        glVertex3f(onee+0.065- 0.95- 0.80, -1.3 +(1.5* onee)-  0.95, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(onee - 1.0- 0.80,-1.2 +(1.5* onee)-  1.0, 0);
        glVertex3f(onee +0.1- 1.0- 0.80,-1.15 +(1.5* onee) -  1.0, 0);
        glVertex3f(onee+0.065- 1.0- 0.80, -1.3 +(1.5* onee)-  1.0, 0);
        glEnd();




        animate();
    }else{
        if(starte){
            glColor3f(1,0,1);
            glBegin(GL_TRIANGLES);
            glVertex3f(-0.6,1.7 +(1.5* (onee- 1.5)) , 0);
            glVertex3f(-0.6- 0.05,1.5 +(1.5* (onee- 1.5))   , 0);
            glVertex3f(-0.6 + 0.05, 1.5 +(1.5* (onee-1.5)) , 0);
            glEnd();
            glBegin(GL_TRIANGLES);
            glVertex3f(-0.6,0.7 -(1.5* (onee-1.5)), 0);
            glVertex3f(-0.6- 0.05,0.5 -(1.5* (onee-1.5)) , 0);
            glVertex3f(-0.6 + 0.05, 0.5 -(1.5* (onee-1.5)), 0);
            glEnd();/*
            glBegin(GL_TRIANGLES);
            glVertex3f(0.3 + (onee- 0.8) ,-0.7 -(1.5* (0.8-1.5)), 0);
            glVertex3f(0.3- 0.05+ (onee- 0.8),-0.9 -(1.5* (0.8-1.5)) , 0);
            glVertex3f(0.3 + 0.05+ (onee- 0.8), -0.9 -(1.5* (0.8-1.5)), 0);
            glEnd();
            glBegin(GL_TRIANGLES);
            glVertex3f(0.3 - (onee- 0.8) ,-0.7 -(1.5* (0.8-1.5)), 0);
            glVertex3f(0.3- 0.05- (onee- 0.8),-0.9 -(1.5* (0.8-1.5)) , 0);
            glVertex3f(0.3 + 0.05- (onee- 0.8), -0.9 -(1.5* (0.8-1.5)), 0);
            glEnd();*/
            animate2();
        }
    }





}

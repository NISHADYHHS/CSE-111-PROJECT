#include "typebackground.h"

TypeBackground::TypeBackground(QWidget *parent) : QOpenGLWidget(parent){}

void TypeBackground::initializeGL()
{

    glClearColor(0, 0, 0, 1);

}
void TypeBackground::resizeGL(int w, int h)
{
}

void TypeBackground::setType(QString tyt){

    type = tyt;
    qDebug()<< getType();
   // initializeGL();

}

QString TypeBackground::getType(){
    return type;
}

void TypeBackground::paintGL()
{

    if(getType() == "Electric")
        glClearColor(0.93, 0.8, 0, 1);
    else if(getType() == "Grass")
        glClearColor(0.19, 0.8, 0.19, 1);
    else if(getType() == "Fire")
        glClearColor(0.9, 0.38, 0, 1);
    else if(type.toStdString() == "Water")
        glClearColor(0.11, 0.44, 1, 1);
    else if(getType() == "Ground")
        glClearColor(0.58, 0.29, 0, 1);
    else if(getType() == "Rock")
        glClearColor(0.66, 0.6, 0.52, 1);
    else if(getType() == "Steel")
        glClearColor(0.75, 0.75, 0.75, 1);
    else if(getType() == "Normal")
        glClearColor(1, 1, 1, 1);
    else if(getType() == "Fighting")
        glClearColor(0.85, 0.17, 0.26, 1);
    else if(getType() == "Psychic")
        glClearColor(0.85, 0.44, 0.84, 1);
    else if(getType() == "Dark")
        glClearColor(0, 0.25, 0.25, 1);
    else if(getType() == "Ghost")
        glClearColor(0.4, 0.15, 0.37, 1);
    else if(getType() == "Bug")
        glClearColor(0.5, 0.5, 0, 1);
    else if(getType() == "Poison")
        glClearColor(0.54, 0.17, 0.88, 1);
    else if(getType() == "Dragon")
        glClearColor(0.45, 0.35, 0.8, 1);
    else if(getType() == "Ice")
        glClearColor(0.725, 0.95, 1, 1);

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0.39,0);


}


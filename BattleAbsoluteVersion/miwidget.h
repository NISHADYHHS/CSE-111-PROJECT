#ifndef MIWIDGET_H
#define MIWIDGET_H

#include <QOpenGLWidget>
#include <QWidget>
#include <QtOpenGL>


class miwidget: public QOpenGLWidget
{
public:
    miwidget(QWidget *parent = 0);
    void initializeGL();//reimplementando las funciones virtuales
    void resizeGL(int w, int h);
    void paintGL();
    void makeGrass(float pt, float p2, float p3);
};

#endif // MIWIDGET_H

#ifndef PHYSICALANIMATION_H
#define PHYSICALANIMATION_H

#include <QOpenGLWidget>
#include <QWidget>
#include <QtOpenGL>
#include <QTimer>


class PhysicalAnimation: public QOpenGLWidget
{

public:
    PhysicalAnimation(QWidget *parent = 0);
    void initializeGL();//reimplementando las funciones virtuales
    void resizeGL(int w, int h);
    void paintGL();
    ~PhysicalAnimation();
    void startit();
    void stopit();
private:
    QTimer *timer;

public slots:
    void animate();
    void animate2();



};

#endif // PHYSICALANIMATION_H

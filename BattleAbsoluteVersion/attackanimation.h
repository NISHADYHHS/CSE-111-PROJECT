#ifndef ATTACKANIMATION_H
#define ATTACKANIMATION_H



#include <QOpenGLWidget>
#include <QWidget>
#include <QtOpenGL>
#include <QTimer>


class AttackAnimation: public QOpenGLWidget
{

public:
    AttackAnimation(QWidget *parent = 0);
    void initializeGL();//reimplementando las funciones virtuales
    void resizeGL(int w, int h);
    void paintGL();
    ~AttackAnimation();
    void startit();
    void stopit();
    int getTimes();
private:
    QTimer *timer;

public slots:
    void animate();
    void animate2();



};




#endif // ATTACKANIMATION_H

#ifndef ATTACKANIMATIONE_H
#define ATTACKANIMATIONE_H
#include <QOpenGLWidget>
#include <QWidget>
#include <QtOpenGL>
#include <QTimer>

class AttackAnimationE: public QOpenGLWidget
{

public:
    AttackAnimationE(QWidget *parent = 0);
    void initializeGL();//reimplementando las funciones virtuales
    void resizeGL(int w, int h);
    void paintGL();
    ~AttackAnimationE();
    void startit();
    void stopit();
    int getTimes();
private:
    QTimer *timer;

public slots:
    void animate();
    void animate2();



};


#endif // ATTACKANIMATIONE_H

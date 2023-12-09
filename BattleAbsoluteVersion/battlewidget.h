#ifndef TYPEBACKGROUND_H
#define TYPEBACKGROUND_H

#include <QOpenGLWidget>
#include <QWidget>
#include <QtOpenGL>


class BattleWidget: public QOpenGLWidget
{
public:
    BattleWidget(QWidget *parent = 0);
    void initializeGL();//reimplementando las funciones virtuales
    void resizeGL(int w, int h);
    void paintGL();
    void DrawEllipse(float radiusX, float radiusY);

private:
};
#endif // TYPEBACKGROUND_H

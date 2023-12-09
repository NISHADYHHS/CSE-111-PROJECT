#ifndef TYPEBACKGROUND_H
#define TYPEBACKGROUND_H

#include <QOpenGLWidget>
#include <QWidget>
#include <QtOpenGL>


class TypeBackground: public QOpenGLWidget
{
public:
    TypeBackground(QWidget *parent = 0);
    void initializeGL();//reimplementando las funciones virtuales
    void resizeGL(int w, int h);
    void paintGL();
    void setType(QString t);
    QString getType();
private:
    QString type;
};
#endif // TYPEBACKGROUND_H

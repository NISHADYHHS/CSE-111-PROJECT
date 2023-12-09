#include "battlewidget.h"

BattleWidget::BattleWidget(QWidget *parent) : QOpenGLWidget(parent){}

void BattleWidget::initializeGL()
{

    glClearColor(0, 0, 0, 1);

}
void BattleWidget::resizeGL(int w, int h)
{
}
void BattleWidget::DrawEllipse(float radiusX, float radiusY)
{
    int i;

    glBegin(GL_LINE_LOOP);

    for(i=0;i<360;i++)
    {
        float rad = i* (3.16159/180);
        glVertex2f(cos(rad)*radiusX,
                   sin(rad)*radiusY);
    }

    glEnd();
}

void BattleWidget::paintGL()
{



    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    DrawEllipse(3,4);

}


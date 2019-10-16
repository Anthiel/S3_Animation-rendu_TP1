#ifndef SMOKE_H
#define SMOKE_H

#include "puff.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>

class Smoke
{
public:
    Smoke(QVector3D vec, float timeInterval);
    void animate(float dt);
    void display(QOpenGLShaderProgram *program_particule);
    void move(float dx, float dy);


    QVector3D pos;
    std::list<Puff> puffsList;
    float timeInterval;
    float elapsedTime;
    QVector3D color;

};

#endif // SMOKE_H

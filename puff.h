#ifndef PUFF_H
#define PUFF_H

#include <QVector3D>
#include <QOpenGLShaderProgram>

#include <QOpenGLBuffer>
#include <cmath>


class Puff
{
public:
    Puff();
    Puff(QVector3D position, QVector3D direction, float size, float lifeTimeLeft);

    void animate(float dt);
    void display(QOpenGLShaderProgram *program_particule);






    QVector3D position,direction;
    float size,lifeTimeLeft,initialLifeTime;
    QMatrix4x4 modelMatrixParticule;
};

#endif // PUFF_H

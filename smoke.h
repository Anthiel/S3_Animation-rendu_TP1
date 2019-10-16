#ifndef SMOKE_H
#define SMOKE_H

#include "puff.h"
#include <QVector3D>


class Smoke
{
public:
    Smoke(QVector3D vec, float timeInterval);
    void animate(float dt);
    void display();


    QVector3D pos;
    std::list<Puff> puffsList;
    float timeInterval;
    float elapsedTime;

};

#endif // SMOKE_H

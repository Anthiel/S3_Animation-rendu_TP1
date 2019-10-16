#ifndef PUFF_H
#define PUFF_H

#include <QVector3D>


class Puff
{
public:
    Puff();
    Puff(QVector3D position, QVector3D direction, float size, float lifeTimeLeft);

    void animate(float dt);
    void display();






    QVector3D position,direction;
    float size,lifeTimeLeft;
};

#endif // PUFF_H

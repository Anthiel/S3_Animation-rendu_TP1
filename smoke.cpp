#include "smoke.h"
#include <QVector3D>
#include "puff.h"

Smoke::Smoke(QVector3D vec, float timeInterval)
{
    this->timeInterval = timeInterval;
    this->pos = vec;
    this->elapsedTime = 0.0f;
}

void Smoke::animate(float dt){
    elapsedTime += dt;

    if(elapsedTime>timeInterval){
        elapsedTime = 0.0f;
        int tempsRandom = 5 + (rand() % static_cast<int>(8 - 5 + 1));
        int sizeRandom = 1 + (rand() % static_cast<int>(5 - 1 + 1));
        QVector3D direction(0.0, 1.0, 0.0);
        Puff newPuff(pos, direction, static_cast<float>(sizeRandom), static_cast<float>(tempsRandom));
        puffsList.push_back(newPuff);
    }

    std::list<Puff>::iterator i = puffsList.begin();
    while( i != puffsList.end() )
    {
        if( i->lifeTimeLeft <= 0 )
        i = puffsList.erase(i);
        else
        i++;
    }

    std::list<Puff>::iterator j = puffsList.begin();
    while( j != puffsList.end() )
    {
        j->animate(dt);
    }
}

void Smoke::display(){

}

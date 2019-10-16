#include "smoke.h"
#include <QVector3D>
#include "puff.h"

Smoke::Smoke(QVector3D vec, float timeInterval)
{
    this->timeInterval = timeInterval;
    this->pos = vec;
    this->elapsedTime = 0.0f;
    this->color= QVector3D(40/255.0,0/255.0,200/255.0);
}

void Smoke::animate(float dt){
    elapsedTime += dt;

    if(elapsedTime>timeInterval){
        elapsedTime -= timeInterval;        //pas de perte de temps sauf si gros lag > à timeInterval
        int sizeRandom = 1 + (rand() % static_cast<int>(5 - 1 + 1));
        puffsList.push_back(Puff(pos,QVector3D(0.0, 1.0, 0.0) , 1, 5 + (rand() % (8-5+1))));
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
        j++;
    }
}

void Smoke::move(float dx, float dy){
    pos+=QVector3D(dx,0,dy);
}

void Smoke::display(QOpenGLShaderProgram *program_particule){
    std::list<Puff>::iterator j = puffsList.begin();
    while( j != puffsList.end() )
    {
        program_particule->setUniformValue("colorModifier",    color );
        j->display(program_particule);
        j++;
    }
}

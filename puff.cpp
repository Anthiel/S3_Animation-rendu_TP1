#include "puff.h"

Puff::Puff()
{
    this->position={0,0,0};
    this->direction={0,0,0};
    this->size=1;
    this->lifeTimeLeft=0;
}


Puff::Puff(QVector3D position, QVector3D direction, float size, float lifeTimeLeft)
{
    this->position=position;
    this->direction=direction;
    this->size=size;
    this->lifeTimeLeft=lifeTimeLeft;
}

void Puff::animate(float dt)
{
    this->lifeTimeLeft-=dt;
    if(this->lifeTimeLeft>0){
        this->position+=dt*direction;
    }
}

void Puff::display(QOpenGLShaderProgram *program_particule){
    modelMatrixParticule.translate(position);
    program_particule->setUniformValue("modelMatrix", modelMatrixParticule);
    program_particule->setUniformValue("particleSize", size);
}

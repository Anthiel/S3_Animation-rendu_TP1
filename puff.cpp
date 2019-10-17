#include "puff.h"
#include <QDebug>
Puff::Puff()
{
    this->position={0,0,0};
    this->direction={0,0,0};
    this->size=1;
    this->lifeTimeLeft=0;
    this->initialLifeTime=lifeTimeLeft;
}


Puff::Puff(QVector3D position, QVector3D direction, float size, float lifeTimeLeft)
{
    this->position=position;
    this->direction=direction;
    this->size=size;
    this->lifeTimeLeft=lifeTimeLeft;
    this->initialLifeTime=lifeTimeLeft;
}

void Puff::animate(float dt)
{
    this->lifeTimeLeft-=dt;
    if(this->lifeTimeLeft>0){
        this->position+=dt*direction;
    }
}

void Puff::display(QOpenGLShaderProgram *program_particule){
    modelMatrixParticule.setToIdentity();
    modelMatrixParticule.translate(position);
    program_particule->setUniformValue("modelMatrix", modelMatrixParticule);
    program_particule->setUniformValue("particleSize", size);
    program_particule->setUniformValue("lifeTimeSize", (float) std::min(initialLifeTime/((double) sqrt(lifeTimeLeft+1)),(double) 2*initialLifeTime) );
    program_particule->setUniformValue("lifeTimeOpacity", (float) std::max(lifeTimeLeft/initialLifeTime -0.2, 0.0) );
    int state=((initialLifeTime-lifeTimeLeft)/initialLifeTime)*16;
    qDebug() << "state" << state ;
    program_particule->setUniformValue("state", state);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

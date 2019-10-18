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
    program_particule->setUniformValue("lifeTimeSize", (float) 1+5*(initialLifeTime-lifeTimeLeft)/initialLifeTime );
    program_particule->setUniformValue("lifeTimeOpacity", (float) std::max(std::min(lifeTimeLeft/initialLifeTime, (initialLifeTime-lifeTimeLeft)*2/initialLifeTime), 0.0f));
    int state=((int)(lifeTimeLeft*25))%16;
    int state_x=state%4;
    int state_y=state/4;
//    qDebug() << "state" << state ;
    program_particule->setUniformValue("state_x",(float) state_x);
    program_particule->setUniformValue("state_y",(float) state_y);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

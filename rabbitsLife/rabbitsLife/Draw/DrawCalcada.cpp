//
//  DrawCalcada.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawCalcada {
    
//public
public: void calcadas(){
    glColor3f(0.191, 0, 0.255);
    glBegin(GL_QUADS);
        calcadaInferior();
        calcadaSuperior();
    glEnd();
}

//private
private: void calcadaInferior(){
    glVertex2f(1, 10);//Ponto A
    glVertex2f(50, 10);//Ponto B
    glVertex2f(50, 5);//Ponto C
    glVertex2f(1, 5);//Ponto D
}

private: void calcadaSuperior(){
    glVertex2f(1, 30);//Ponto A
    glVertex2f(50, 30);//Ponto B
    glVertex2f(50, 35);//Ponto C
    glVertex2f(1, 35);//Ponto D
}
};

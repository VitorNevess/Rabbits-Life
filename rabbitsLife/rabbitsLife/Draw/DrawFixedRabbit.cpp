//
//  DrawFixedRabbit.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawFixedRabbit {
    
//public
public: void fixedRabbit(){
    glBegin(GL_QUADS);
        glColor3f(1, 0.204, 0.229);
        rabbitEar();
    
        glColor3f(0.51, 1, 1);
        rabbitHead();
    
        glColor3f(1, 1, 1);
        rabbitTooth();
    glEnd();
}

//private
private:void rabbitEar(){
    //Esquerda
    glVertex2d(2, 3);//Ponto A
    glVertex2d(3, 3);//Ponto B
    glVertex2d(3, 5);//Ponto C
    glVertex2d(2, 5);//Ponto D
    //Direita
    glVertex2d(5, 3);//Ponto A
    glVertex2d(6, 3);//Ponto B
    glVertex2d(6, 5);//Ponto C
    glVertex2d(5, 5);//Ponto D
}

private: void rabbitHead(){
    glVertex2f(2, 1);//Ponto A
    glVertex2d(6, 1);//Ponto B
    glVertex2d(6, 3);//Ponto C
    glVertex2d(2, 3);//Ponto E
}

private: void rabbitTooth(){
    glVertex2f(3, 1);//Ponto A
    glVertex2d(5, 1);//Ponto B
    glVertex2d(5, 2);//Ponto C
    glVertex2d(3, 2);//Ponto E
}
};

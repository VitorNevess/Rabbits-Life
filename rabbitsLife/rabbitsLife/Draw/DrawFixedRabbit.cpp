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
public: void fixedRabbit(int x, bool isDied, bool isVictory){
    glBegin(GL_QUADS);
        if (isVictory)
            glColor3f(0.8, 0.498039, 0.196078);
        else if (isDied)
            glColor3f(0.752941, 0.752941, 0.752941);
        else
            glColor3f(1, 0.204, 0.229);
        rabbitEar(x);
    
        if (isVictory)
            glColor3f(1, 1, 0);
        else if (isDied)
            glColor3f(0.329412, 0.329412, 0.329412);
        else
            glColor3f(0.51, 1, 1);
        rabbitHead(x);
    
        glColor3f(1, 1, 1);
        rabbitTooth(x);
    glEnd();
}

//private
private:void rabbitEar(int x){
    //Esquerda
    glVertex2d(x, 3);//Ponto A
    glVertex2d(x+1, 3);//Ponto B
    glVertex2d(x+1, 5);//Ponto C
    glVertex2d(x, 5);//Ponto D
    //Direita
    glVertex2d(x+3, 3);//Ponto A
    glVertex2d(x+4, 3);//Ponto B
    glVertex2d(x+4, 5);//Ponto C
    glVertex2d(x+3, 5);//Ponto D
}

private: void rabbitHead(int x){
    glVertex2f(x, 1);//Ponto A
    glVertex2d(x+4, 1);//Ponto B
    glVertex2d(x+4, 3);//Ponto C
    glVertex2d(x, 3);//Ponto E
}

private: void rabbitTooth(int x){
    glVertex2f(x+1, 1);//Ponto A
    glVertex2d(x+3, 1);//Ponto B
    glVertex2d(x+3, 2);//Ponto C
    glVertex2d(x+1, 2);//Ponto E
}
};

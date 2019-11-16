//
//  DrawRabbit.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 16/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawRabbit {
    
public:
    float xCloser = 0;//mais perto
    float xFurther = 0;//mais longe
    float yHigher = 0;//mais alto
    float yLower = 0;//mais baixo

//public
public: void rabbit(float x, float y){
    glBegin(GL_QUADS);
        glColor3f(1, 0.204, 0.229);
        rabbitEar(x,y);
    
        glColor3f(0.51, 1, 1);
        rabbitHead(x,y);
    
        glColor3f(1, 1, 1);
        rabbitTooth(x,y);
    glEnd();
}

//private
private:void rabbitEar(float x, float y){
    //Esquerda
    glVertex2d(x+21, y+3);//Ponto A
    glVertex2d(x+22, y+3);//Ponto B
    glVertex2d(x+22, y+5);//Ponto C
    glVertex2d(x+21, y+5);//Ponto D
    //Direita
    glVertex2d(x+24, y+3);//Ponto A
    glVertex2d(x+25, y+3);//Ponto B
    glVertex2d(x+25, y+5);//Ponto C
    glVertex2d(x+24, y+5);//Ponto D
    
    yHigher = y+4;
}

private: void rabbitHead(float x, float y){
    glVertex2f(x+21, y+1);//Ponto A
    glVertex2d(x+25, y+1);//Ponto B
    glVertex2d(x+25, y+3);//Ponto C
    glVertex2d(x+21, y+3);//Ponto E
    
    xCloser = x+21;
    xFurther = x+25;
    yLower = y+1;
}

private: void rabbitTooth(float x, float y){
    glVertex2f(x+22, y+1);//Ponto A
    glVertex2d(x+24, y+1);//Ponto B
    glVertex2d(x+24, y+2);//Ponto C
    glVertex2d(x+22, y+2);//Ponto E
}
};

//
//  DrawCarRed.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawCarRed {
    
//public
public:
    float xCloser = 0;//mais perto
    float xFurther = 0;//mais longe

public: void car(int x){
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        carRed(x);
    glEnd();
   
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
        wheelsCar(x);
    glEnd();
}

private: void carRed(int x){
    glVertex2f(x+1,11);//Ponto A
    glVertex2f(x+5,11);//Ponto B
    glVertex2f(x+5,14);//Ponto C
    glVertex2f(x+1,14);//Ponto D
    
    xCloser = x+1;
    xFurther = x+4;
}

private: void wheelsCar(int x){
    glVertex2f(x+2,11);//Roda 1
    glVertex2f(x+4,11);//Roda 2
    glVertex2f(x+4,14);//Roda 3
    glVertex2f(x+2,14);//Roda 4
}
};

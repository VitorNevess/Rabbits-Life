//
//  DrawCarRed.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include "DrawCarRed.h"

//private:
//    DrawCarRed();
    
//public:
//    static DrawCarRed *instance;
//    //static DrawCarRed* getInstance();
//    float xCloser = 0;//mais perto
//    float xFurther = 0;//mais longe
    
//public
//public:
DrawCarRed *getInstance() {
    if (!DrawCarRed::instance)
        DrawCarRed::instance = new DrawCarRed;
    return DrawCarRed::instance;
}
    
//public:
void DrawCarRed::car(int x){
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        DrawCarRed::carRed(x);
    glEnd();
   
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
        DrawCarRed::wheelsCar(x);
    glEnd();
}

//private
//private:
void DrawCarRed::carRed(int x){
    glVertex2f(x+1,11);//Ponto A
    glVertex2f(x+5,11);//Ponto B
    glVertex2f(x+5,14);//Ponto C
    glVertex2f(x+1,14);//Ponto D
    
    xCloser = x+1;
    xFurther = x+14;
}

//private:
void DrawCarRed::wheelsCar(int x){
    glVertex2f(x+2,11);//Roda 1
    glVertex2f(x+4,11);//Roda 2
    glVertex2f(x+4,14);//Roda 3
    glVertex2f(x+2,14);//Roda 4
}


DrawCarRed *DrawCarRed::instance = 0;

//DrawCarRed* DrawCarRed::getInstance()
//{
//    static DrawCarRed instance;
//
//    return &instance;
//}

//
//  DrawFox.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 14/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawFox {

//public
public:
    float xCloser = 0;//mais perto
    float xFurther = 0;//mais longe
    
public: void foxOne(int x){
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_QUADS);
        body(x);
        head(x);
        legs(x);
        tail(x);
    glEnd();
}
     
//private
private: void body(int x){
    glVertex2f(x+1,36);//Ponto A
    glVertex2f(x+5,36);//Ponto B
    glVertex2f(x+5,38);//Ponto C
    glVertex2f(x+1,38);//Ponto D
}

private: void head(int x){
    glVertex2f(x+3,39);//Ponto A
    glVertex2f(x+5,39);//Ponto B
    glVertex2f(x+5,38);//Ponto C
    glVertex2f(x+3,38);//Ponto D
}

private: void legs(int x){
    //primeira perna
    glVertex2f(x+1,36);//Ponto A
    glVertex2f(x+2,36);//Ponto B
    glVertex2f(x+2,35.5);//Ponto C
    glVertex2f(x+1,35.5);//Ponto D
    
    //primeira perna
    glVertex2f(x+4,36);//Ponto A
    glVertex2f(x+5,36);//Ponto B
    glVertex2f(x+5,35.5);//Ponto C
    glVertex2f(x+4,35.5);//Ponto D

    xFurther = x+5;
}

private: void tail(int x){
    glVertex2f(x+0.5,38);//Ponto A
    glVertex2f(x+1,38);//Ponto B
    glVertex2f(x+1,37.5);//Ponto C
    glVertex2f(x+0.5,37.5);//Ponto D
    
    xCloser = x+1;
}
};

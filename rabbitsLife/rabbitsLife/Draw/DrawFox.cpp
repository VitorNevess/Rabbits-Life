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
public: void foxOne(int x1){
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_QUADS);
        body(x1);
        head(x1);
        legs(x1);
        tail(x1);
    glEnd();
}
     
//private
private: void body(int x1){
    glVertex2f(x1+1,36);//Ponto A
    glVertex2f(x1+5,36);//Ponto B
    glVertex2f(x1+5,38);//Ponto C
    glVertex2f(x1+1,38);//Ponto D
}

private: void head(int x1){
    glVertex2f(x1+3,39);//Ponto A
    glVertex2f(x1+5,39);//Ponto B
    glVertex2f(x1+5,38);//Ponto C
    glVertex2f(x1+3,38);//Ponto D
}

private: void legs(int x1){
    //primeira perna
    glVertex2f(x1+1,36);//Ponto A
    glVertex2f(x1+2,36);//Ponto B
    glVertex2f(x1+2,35.5);//Ponto C
    glVertex2f(x1+1,35.5);//Ponto D
    
    //primeira perna
    glVertex2f(x1+4,36);//Ponto A
    glVertex2f(x1+5,36);//Ponto B
    glVertex2f(x1+5,35.5);//Ponto C
    glVertex2f(x1+4,35.5);//Ponto D
}

private: void tail(int x1){
    glVertex2f(x1+0.5,38);//Ponto A
    glVertex2f(x1+1,38);//Ponto B
    glVertex2f(x1+1,37.5);//Ponto C
    glVertex2f(x1+0.5,37.5);//Ponto D
}
};

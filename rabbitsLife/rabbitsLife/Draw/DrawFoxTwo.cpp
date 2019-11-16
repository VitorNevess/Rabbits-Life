//
//  DrawFoxTwo.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 14/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawFoxTwo {

//public
public: void foxTwo(int x1){
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
    glVertex2f(x1+1,41);//Ponto A
    glVertex2f(x1+5,41);//Ponto B
    glVertex2f(x1+5,43);//Ponto C
    glVertex2f(x1+1,43);//Ponto D
}

private: void head(int x1){
    glVertex2f(x1+3,44);//Ponto A
    glVertex2f(x1+5,44);//Ponto B
    glVertex2f(x1+5,43);//Ponto C
    glVertex2f(x1+3,43);//Ponto D
}

private: void legs(int x1){
    //primeira perna
    glVertex2f(x1+1,41);//Ponto A
    glVertex2f(x1+2,41);//Ponto B
    glVertex2f(x1+2,40.5);//Ponto C
    glVertex2f(x1+1,40.5);//Ponto D
    
    //primeira perna
    glVertex2f(x1+4,41);//Ponto A
    glVertex2f(x1+5,41);//Ponto B
    glVertex2f(x1+5,40.5);//Ponto C
    glVertex2f(x1+4,40.5);//Ponto D
}

private: void tail(int x1){
    glVertex2f(x1+0.5,43);//Ponto A
    glVertex2f(x1+1,43);//Ponto B
    glVertex2f(x1+1,42.5);//Ponto C
    glVertex2f(x1+0.5,42.5);//Ponto D
}
};

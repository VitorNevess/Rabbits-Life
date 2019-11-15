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
public:
    float xCloser = 0;//mais perto
    float xFurther = 0;//mais longe
    
public: void foxTwo(int x){
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
    glVertex2f(x+1,41);//Ponto A
    glVertex2f(x+5,41);//Ponto B
    glVertex2f(x+5,43);//Ponto C
    glVertex2f(x+1,43);//Ponto D
}

private: void head(int x){
    glVertex2f(x+3,44);//Ponto A
    glVertex2f(x+5,44);//Ponto B
    glVertex2f(x+5,43);//Ponto C
    glVertex2f(x+3,43);//Ponto D
}

private: void legs(int x){
    //primeira perna
    glVertex2f(x+1,41);//Ponto A
    glVertex2f(x+2,41);//Ponto B
    glVertex2f(x+2,40.5);//Ponto C
    glVertex2f(x+1,40.5);//Ponto D
    
    //primeira perna
    glVertex2f(x+4,41);//Ponto A
    glVertex2f(x+5,41);//Ponto B
    glVertex2f(x+5,40.5);//Ponto C
    glVertex2f(x+4,40.5);//Ponto D
    
    xFurther = x+5;
}

private: void tail(int x){
    glVertex2f(x+0.5,43);//Ponto A
    glVertex2f(x+1,43);//Ponto B
    glVertex2f(x+1,42.5);//Ponto C
    glVertex2f(x+0.5,42.5);//Ponto D
    
    xCloser = x+1;
}
};

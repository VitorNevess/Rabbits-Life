//
//  DrawTruck.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawTruck {
    
//public
public:
    float xCloser = 0;//mais perto
    float xFurther = 0;//mais longe
    
public: void truck(int x){
    glColor3f(0.8,0.8,1);
    glBegin(GL_QUADS);
        truckOne(x);
    glEnd();
    
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
        wheels(x);
    glEnd();
}

//private
private: void truckOne(int x){//CAMINHAO
    //FRENTE
    glVertex2f(x+1,16);//Ponto A
    glVertex2f(x+3,16);//Ponto B
    glVertex2f(x+3,18);//Ponto C
    glVertex2f(x+1,18);//Ponto D
    
    //TRASEIRA
    glVertex2f(x+2.5,16);//Ponto A
    glVertex2f(x+5,16);//Ponto B
    glVertex2f(x+5,19);//Ponto C
    glVertex2f(x+2.5,19);//Ponto D
    
    xCloser = x+1;
    xFurther = x+5;
}

private: void wheels(int x){
    glVertex2f(x+2,16);//Ponto A
    glVertex2f(x+4,16);//Ponto A
}
};

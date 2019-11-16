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
public: void truck(int x1){
    glColor3f(0.8,0.8,1);
    glBegin(GL_QUADS);
        truckOne(x1);
    glEnd();
    
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
        wheels(x1);
    glEnd();
}

//private
private: void truckOne(int x1){//CAMINHAO
    //FRENTE
    glVertex2f(x1+1,16);//Ponto A
    glVertex2f(x1+3,16);//Ponto B
    glVertex2f(x1+3,18);//Ponto C
    glVertex2f(x1+1,18);//Ponto D
    
    //TRASEIRA
    glVertex2f(x1+2.5,16);//Ponto A
    glVertex2f(x1+5,16);//Ponto B
    glVertex2f(x1+5,19);//Ponto C
    glVertex2f(x1+2.5,19);//Ponto D
}

private: void wheels(int x1){
    glVertex2f(x1+2,16);//Ponto A
    glVertex2f(x1+4,16);//Ponto A
}
};

//
//  DrawTruckYellow.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawTruckYellow {
    
//public
public: void truckYellow(int x1){
    glColor3f(1,1,0);
    glBegin(GL_QUADS);
        _truckYellow(x1);
    glEnd();
    
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
        wheelsTruckYellow(x1);
    glEnd();
}

//private
private: void _truckYellow(int x1){
    //CAMINHAO FRENTE
    glVertex2f(x1+1,26);//Ponto A
    glVertex2f(x1+3,26);//Ponto B
    glVertex2f(x1+3,28);//Ponto C
    glVertex2f(x1+1,28);//Ponto D
    
    //CAMINHAO TRASEIRA
    glVertex2f(x1+2.5,26);//Ponto A
    glVertex2f(x1+5,26);//Ponto B
    glVertex2f(x1+5,29);//Ponto C
    glVertex2f(x1+2.5,29);//Ponto D
}

private: void wheelsTruckYellow(int x1){
    glVertex2f(x1+2,26);//Ponto A
    glVertex2f(x1+4,26);//Ponto A
}
};

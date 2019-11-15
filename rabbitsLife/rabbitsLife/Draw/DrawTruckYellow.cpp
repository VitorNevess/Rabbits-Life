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
public:
    float xCloser = 0;//mais perto
    float xFurther = 0;//mais longe
    
public: void truckYellow(int x){
    glColor3f(1,1,0);
    glBegin(GL_QUADS);
        _truckYellow(x);
    glEnd();
    
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
        wheelsTruckYellow(x);
    glEnd();
}

//private
private: void _truckYellow(int x){
    //CAMINHAO FRENTE
    glVertex2f(x+1,26);//Ponto A
    glVertex2f(x+3,26);//Ponto B
    glVertex2f(x+3,28);//Ponto C
    glVertex2f(x+1,28);//Ponto D
    
    //CAMINHAO TRASEIRA
    glVertex2f(x+2.5,26);//Ponto A
    glVertex2f(x+5,26);//Ponto B
    glVertex2f(x+5,29);//Ponto C
    glVertex2f(x+2.5,29);//Ponto D
    
    xCloser = x+1;
    xFurther = x+5;
}

private: void wheelsTruckYellow(int x){
    glVertex2f(x+2,26);//Ponto A
    glVertex2f(x+4,26);//Ponto A
}
};

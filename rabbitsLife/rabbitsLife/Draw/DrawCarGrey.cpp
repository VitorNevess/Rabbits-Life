//
//  DrawCarGrey.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawCarGrey {
    
//public
public: void carGrey(int x1){
    glColor3f(0.15,0.15,0.15);
    glBegin(GL_QUADS);
        _carGrey(x1);
    glEnd();
    
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
        wheelsCarGrey(x1);
    glEnd();
}
     
 //private
 private: void _carGrey(int x1){
     glVertex2f(x1+1,21);//Ponto A
     glVertex2f(x1+5,21);//Ponto B
     glVertex2f(x1+5,24);//Ponto C
     glVertex2f(x1+1,24);//Ponto D
 }
 
 private: void wheelsCarGrey(int x1){
     glVertex2f(x1+2,21);//Roda 1
     glVertex2f(x1+4,21);//Roda 2
     glVertex2f(x1+4,24);//Roda 3
     glVertex2f(x1+2,24);//Roda 4
 }  
};

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
public:
    float xCloser = 0;//mais perto
    float xFurther = 0;//mais longe
    
public: void carGrey(int x){
    glColor3f(0.15,0.15,0.15);
    glBegin(GL_QUADS);
        _carGrey(x);
    glEnd();
    
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
        wheelsCarGrey(x);
    glEnd();
}
     
 //private
 private: void _carGrey(int x){
     glVertex2f(x+1,21);//Ponto A
     glVertex2f(x+5,21);//Ponto B
     glVertex2f(x+5,24);//Ponto C
     glVertex2f(x+1,24);//Ponto D
     
     xCloser = x+1;
     xFurther = x+5;
 }
 
 private: void wheelsCarGrey(int x){
     glVertex2f(x+2,21);//Roda 1
     glVertex2f(x+4,21);//Roda 2
     glVertex2f(x+4,24);//Roda 3
     glVertex2f(x+2,24);//Roda 4
 }  
};

//
//  DrawForest.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawForest {
    
//public
public: void forest(){
    glColor3f(0,1,0);
    glBegin(GL_QUADS);
        bush();
    glEnd();
}

//private
private: void bush(){
    glVertex2f(1, 30);//Ponto A
    glVertex2f(50, 30);//Ponto B
    glVertex2f(50, 50);//Ponto C
    glVertex2f(1, 50);//Ponto D
}
};

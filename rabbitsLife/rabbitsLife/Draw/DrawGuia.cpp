//
//  DrawGuia.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawGuia {
    
//public
public: void guias(){
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        guiaInferior();
        guiaSuperior();
    glEnd();
}

//private
private: void guiaSuperior(){
    glVertex2f(1, 30);//Ponto A
    glVertex2f(50, 30);//Ponto B
}
    
private: void guiaInferior(){
    glVertex2f(1, 10);//Ponto A
    glVertex2f(50, 10);//Ponto B
}
};

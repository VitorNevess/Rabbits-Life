//
//  DrawTrunk.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawTrunk {
    
//TRONCOS
public: void trunk(){
    glColor3f(0.160,0.82,0.45);
    glBegin(GL_QUADS);
        treeTrunks();
    glEnd();
}

//TRONCOS
private: void treeTrunks(){
    for (int x = 0; x <= 50; x+=10) {
        glVertex2f(x, 45);//Ponto A
        glVertex2f(x-5, 45);//Ponto B
        glVertex2f(x-5, 50);//Ponto C
        glVertex2f(x, 50);//Ponto D
    }
}
};

//
//  DrawFaixa.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

class DrawFaixa {
    
//public
public: void faixas(){
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        faixaOne();
        faixaTwo();
        faixaThree();
    glEnd();
}

//private
private: void faixaOne(){
    for (int x = 1; x <= 50; x+=3) {
        glVertex2f(x, 15);
        glVertex2f(x-2, 15);
    }
}

private: void faixaTwo(){
    for (int x = 1; x <= 50; x+=3) {
        glVertex2f(x, 20);
        glVertex2f(x-2, 20);
    }
}

private: void faixaThree(){
    for (int x = 1; x <= 50; x+=3) {
        glVertex2f(x, 25);
        glVertex2f(x-2, 25);
    }
}
};

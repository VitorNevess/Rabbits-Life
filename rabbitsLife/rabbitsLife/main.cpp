//
//  main.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <iostream>
#include "Draw/DesenhaObjects.cpp"

using namespace std;

    //Properties
    float speed = 1;
    float x1Fox = 1;
    float xstepFox = 0.9;
    float x1FoxTwo = 1;
    float xstepFoxTwo = 1;
    float x1TruckYellow = 45;
    float xstepTruckYellow = 0.2;
    float x1CarGrey = 1;
    float xstepCarGrey = 1;
    float x1Truck = 45;
    float xstepTruck = 0.9;
    float x1CarRed = 1;
    float xstepCarRed = 1;
    float xRabbit = 5;
    float yRabbit = 5;
    float xDistancia = 5;
    float yDistancia = 5;
    //Posicao do coelho
    float xCloser = 0;//mais perto
    float xFurther = 0;//mais longe
    float yHigher = 0;//mais alto
    float yLower = 0;//mais baixo

    //Objects
    DesenhaObjects * desenhaObjects;

void setSpeed(){
    xstepFox = 0.9 * speed;
    xstepFoxTwo = 1 * speed;
    xstepTruckYellow = 0.2 * speed;
    xstepCarGrey = 1 * speed;
    xstepTruck = 0.9 * speed;
    xstepCarRed = 1 * speed;
}

void teclaEspecial(int tecla, int x, int y){
    if(tecla == GLUT_KEY_RIGHT){
        if (xRabbit >= -20 && xRabbit < 25)
            xRabbit += xDistancia;
        //cout << "X1 RIGHT:" << xRabbit << endl;
    }else if (tecla == GLUT_KEY_LEFT){
        if (xRabbit > -20 && xRabbit <= 25)
            xRabbit -= xDistancia;
        //cout << "X1 LEFT:" << xRabbit << endl;
    }else if(tecla == GLUT_KEY_UP){
        if (yRabbit >= 0 && yRabbit < 45)
            yRabbit += yDistancia;
        //cout << "Y1 UP:" << yRabbit << endl;
    }else if (tecla == GLUT_KEY_DOWN){
        if (yRabbit > 0 && yRabbit <= 45)
            yRabbit -= yDistancia;
        //cout << "Y1 DOWN:" << yRabbit << endl;
    }
    
    cout << "X mais longe: " << desenhaObjects->drawRabbit->xFurther << endl;
    cout << "X mais perto: " << desenhaObjects->drawRabbit->xCloser << endl;
    cout << "Y mais alto: " << desenhaObjects->drawRabbit->yHigher << endl;
    cout << "Y mais baixo: " << desenhaObjects->drawRabbit->yLower << endl;
    cout << endl;
    
    //manda executar o desenho varias vezes
    glutPostRedisplay();
}

void teclado(unsigned char tecla, int x, int y){
    
    float _speed = 1;
    
    //VELOCIDADE
    if(tecla == 49){
        _speed = 1;
    }else if(tecla == 50){
        _speed = 2;
    }else if(tecla == 51){
        _speed = 3;
    }else if(tecla == 52){
        _speed = 4;
    }else if(tecla == 53){
        _speed = 5;
    }else if(tecla == 54){
        _speed = 6;
    }else if(tecla == 55){
        _speed = 7;
    }else if(tecla == 56){
        _speed = 8;
    }
    
    //COELHO
    if(tecla == 97 || tecla == 65){//a A
        if (xRabbit > -20 && xRabbit <= 25)
            xRabbit -= xDistancia;
    }else if(tecla == 100 || tecla == 68){//d D
        if (xRabbit >= -20 && xRabbit < 25)
            xRabbit += xDistancia;
    }else if(tecla == 119 || tecla == 87){//w W
        if (yRabbit >= 0 && yRabbit < 45)
            yRabbit += yDistancia;
    }else if(tecla == 115 || tecla == 83){//s S
        if (yRabbit > 0 && yRabbit <= 45)
            yRabbit -= yDistancia;
    }
    
    if (_speed != speed){
        speed = _speed;
        setSpeed();
    }
    glutPostRedisplay();
//    cout << "Velocidade atual:" << speed << endl;
//    cout << "X coelho:" << xRabbit << endl;
//    cout << "Y coelho:" << yRabbit << endl;
}

void desenha(){
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();//le a matriz de visualizacao
    //tamanho do plano cartesiano
    gluOrtho2D(1, 50, 1, 50);
    
    //aumenta largura da linha
    glLineWidth(3);
    //aumenta tamanho do ponto
    glPointSize(5);
    
    desenhaObjects->showDrawings(xRabbit, yRabbit, x1Fox, x1FoxTwo, x1TruckYellow, x1CarGrey, x1Truck ,x1CarRed);
    
    glutSwapBuffers();//ativa e exibe o desenho
}

void Anima(int value){
    xCloser = desenhaObjects->drawRabbit->xCloser;
    xFurther = desenhaObjects->drawRabbit->xFurther;
    yHigher = desenhaObjects->drawRabbit->yHigher;
    yLower = desenhaObjects->drawRabbit->yLower;
    
    //COLISAO 1
    if (yLower >= 10 && yLower <= 15 &&
        yHigher >= 10 && yHigher <= 15){//primeira faixa
        cout << "esta dentro da faixa" << endl;
    }
    
    //RAPOSA 1
    if (x1Fox < 0 || x1Fox > 45)
        xstepFox = -xstepFox;
    x1Fox += xstepFox;
    
    //RAPOSA 2
    if (x1FoxTwo < 0 || x1FoxTwo > 45)
        xstepFoxTwo = -xstepFoxTwo;
    x1FoxTwo += xstepFoxTwo;
    
    //CAMINHAO AMARELO
    if (x1TruckYellow < -5 || x1TruckYellow > 45)
        x1TruckYellow = 45;
    x1TruckYellow -= xstepTruckYellow;
    
    //CARRO CINZA
    if (x1CarGrey < 0 || x1CarGrey > 50)
        x1CarGrey = 0;
    x1CarGrey += xstepCarGrey;
    
    //CAMINHAO ROXO
    if (x1Truck < 0 || x1Truck > 45)
        xstepTruck = -xstepTruck;
    x1Truck += xstepTruck;
    
    //CARRO VERMELHO
    if (x1CarRed < 0 || x1CarRed > 45)
        xstepCarRed = -xstepCarRed;
    x1CarRed += xstepCarRed;
    
    glutPostRedisplay();
    glutTimerFunc(15,Anima, 1);//velocidade do objeto é aumentada
    //precisa fazer 2 if comparando 
}

int main(int argc, char* argv[]){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rabbit's Life");
    //inicializa Objects
    desenhaObjects = new DesenhaObjects();
    glutDisplayFunc(desenha);
    glutSpecialFunc(teclaEspecial);
    glutKeyboardFunc(teclado);
    glutTimerFunc(15,Anima, 5);
    glutMainLoop();
    
    return 0;
}

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
    bool rabbitDied[3] = {false, false, false};
    bool rabbitVictory[3] = {false, false, false};
    int tentativas = 0;
    int pontos = 0;
    int countDied = 0;
    bool isDied = false;
    int countVictory = 0;
    bool isVictory = false;
    float speed = 1;
    float x1Fox = 1;
    float xstepFox = 0.9;
    float x1FoxTwo = 1;
    float xstepFoxTwo = 1;
    float x1TruckYellow = 45;
    float xstepTruckYellow = 0.7;
    float x1CarGrey = 1;
    float xstepCarGrey = 1;
    float x1Truck = 45;
    float xstepTruck = 0.9;
    float x1CarRed = 1;
    float xstepCarRed = 1;
    int xFixedRabbit = 2;
    float xRabbit = 5;
    float yRabbit = 5;
    float xDistancia = 5;
    float yDistancia = 5;
    //Posicao do coelho
    float xCloser = 0;
    float xFurther = 0;
    float yHigher = 0;
    float yLower = 0;
    //Posicao carro vermelho
    float xCarRedCloser = 0;
    float xCarRedFurther = 0;
    //Posicao caminhao roxo
    float xTruckCloser = 0;
    float xTruckFurther = 0;
    //Posicao carro cinza
    float xCarGreyCloser = 0;
    float xCarGreyFurther = 0;
    //Posicao caminhao amarelo
    float xTruckYellowCloser = 0;
    float xTruckYellowFurther = 0;
    //Posicao raposa 1
    float xFoxCloser = 0;
    float xFoxFurther = 0;
    //Posicao raposa 2
    float xFoxTwoCloser = 0;
    float xFoxTwoFurther = 0;

    DesenhaObjects * desenhaObjects;

void setSpeed(){
    xstepFox = 0.9 * speed;
    xstepFoxTwo = 1 * speed;
    xstepTruckYellow = 0.7 * speed;
    xstepCarGrey = 1 * speed;
    xstepTruck = 0.9 * speed;
    xstepCarRed = 1 * speed;
}

void teclaEspecial(int tecla, int x, int y){
    if (tentativas >= 3)
        return;
    
    if(tecla == GLUT_KEY_RIGHT){
        if (xRabbit >= -20 && xRabbit < 25)
            xRabbit += xDistancia;
    }else if (tecla == GLUT_KEY_LEFT){
        if (xRabbit > -20 && xRabbit <= 25)
            xRabbit -= xDistancia;
    }else if(tecla == GLUT_KEY_UP){
        if (yRabbit >= 5 && yRabbit < 45)
            yRabbit += yDistancia;
    }else if (tecla == GLUT_KEY_DOWN){
        if (yRabbit > 5 && yRabbit <= 45)
            yRabbit -= yDistancia;
    }
    
    //manda executar o desenho varias vezes
    glutPostRedisplay();
}

void teclado(unsigned char tecla, int x, int y){
    if (tentativas >= 3)
        return;
    
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
}

//DERROTA E VITORIA
void gameOver(bool isVictory){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glRasterPos2f(23, 25);
    char* p;
    if (isVictory)
        p = (char*) "Parabens voce venceu!!!";
    else
        p = (char*) "Voce Perdeu!!!";
    while (*p != '\0'){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
    }
    //glutSwapBuffers();
}

void verificaDiedTentativas(bool isDied){
    if (tentativas == 1)
        rabbitDied[0] = isDied;
    else if (tentativas == 2)
        rabbitDied[1] = isDied;
    else if (tentativas == 3)
        rabbitDied[2] = isDied;
}

void verificaVictoryTentativas(bool isVictory){
    if (tentativas == 1)
        rabbitVictory[0] = isVictory;
    else if (tentativas == 2)
        rabbitVictory[1] = isVictory;
    else if (tentativas == 3)
        rabbitVictory[2] = isVictory;
}

void setDied(){
    tentativas += 1;
    pontos -= 1;
    countDied += 1;
    verificaDiedTentativas(isDied);
    isDied = false;
}

void setVictory(){
    tentativas += 1;
    pontos += 1;
    countVictory += 1;
    verificaVictoryTentativas(isVictory);
    isVictory = false;
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
    
    desenhaObjects->showDrawings(x1Fox, x1FoxTwo, x1TruckYellow, x1CarGrey, x1Truck ,x1CarRed);
    
    //MORTE
    if (isDied && countDied == 0)
        setDied();
    if (isDied && countDied >= 0 && countDied <= 1)
        setDied();
    if (isDied && countDied >= 1 && countDied <= 2)
        setDied();
    
    if (!(countDied == 0))
        desenhaObjects->showDrawingRabbit(-15, 45, true, false);
    if (!(countDied <= 1))
        desenhaObjects->showDrawingRabbit(-5, 45, true, false);
    if (!(countDied <= 2))
        desenhaObjects->showDrawingRabbit(5, 45, true, false);
    
    //VITORIA
    if (isVictory && countVictory == 0)
        setVictory();
    if (isVictory && countVictory >= 0 && countVictory <= 1)
        setVictory();
    if (isVictory && countVictory >= 1 && countVictory <= 2)
        setVictory();
    
    if (!(countVictory == 0))
        desenhaObjects->showDrawingRabbit(25, 45, false, true);
    if (!(countVictory <= 1))
        desenhaObjects->showDrawingRabbit(15, 45, false, true);
    if (!(countVictory <= 2))
        desenhaObjects->showDrawingRabbit(5, 45, false, true);
    
    desenhaObjects->showDrawingFixedRabbit(xFixedRabbit, rabbitDied[0], rabbitVictory[0]);
    desenhaObjects->showDrawingFixedRabbit(xFixedRabbit+6, rabbitDied[1], rabbitVictory[1]);
    desenhaObjects->showDrawingFixedRabbit(xFixedRabbit+12, rabbitDied[2], rabbitVictory[2]);
    
    if (!isDied && !isVictory)
        desenhaObjects->showDrawingRabbit(xRabbit, yRabbit, false, false);
    
    if (tentativas >= 3 && pontos >= 1)
        gameOver(true);
    else if(tentativas >= 3 && pontos < 1)
        gameOver(false);
    
    glutSwapBuffers();//ativa e exibe o desenho
}

void bateu(){
    isDied = true;
    xRabbit = 5;
    yRabbit = 5;
}

void colisoes(){
    //Carro vermelho
    if (yLower >= 10 && yLower <= 15 &&
        yHigher >= 10 && yHigher <= 15){//primeira faixa
        
        if(xFurther == xCarRedCloser ||
           xCloser == xCarRedFurther)
            bateu();
    }
    
    //Caminhao roxo
    if (yLower >= 15 && yLower <= 20 &&
        yHigher >= 15 && yHigher <= 20){//segunda faixa
        
        if(xFurther == xTruckCloser ||
           xCloser == xTruckFurther)
            bateu();
        
    }
    
    //Carro cinza
    if (yLower >= 20 && yLower <= 25 &&
        yHigher >= 20 && yHigher <= 25){//terceira faixa
        
        if(xFurther == xCarGreyCloser ||
           xCloser == xCarGreyFurther)
            bateu();
        
    }
    
    //Caminhao amarelo
    if (yLower >= 25 && yLower <= 30 &&
        yHigher >= 25 && yHigher <= 30){//quarta faixa
        
        if(xFurther == xTruckYellowCloser ||
           xCloser == xTruckYellowFurther)
            bateu();
        
    }
    
    //primeira raposa
    if (yLower >= 35 && yLower <= 40 &&
        yHigher >= 35 && yHigher <= 40){
        
        if(xFurther == xFoxCloser ||
           xCloser == xFoxFurther)
            bateu();
        
    }
    
    //segunda raposa
    if (yLower >= 40 && yLower <= 45 &&
        yHigher >= 40 && yHigher <= 45){
        
        if(xFurther == xFoxTwoCloser ||
           xCloser == xFoxTwoFurther)
            bateu();
        
    }
}

void chegou(){
    isVictory = true;
    xRabbit = 5;
    yRabbit = 5;
}

void crossedRabbit(){
    if (yLower >= 45 && yLower <= 50 &&
        yHigher >= 45 && yHigher <= 50){
        
        //1° tronco
//        if(xFurther <= 10 && xFurther >= 5 &&
//           xCloser >= 5 && xCloser <= 10)
//            chegou();
        
        //2° tronco
//        if(xFurther <= 20 && xFurther >= 15 &&
//           xCloser >= 15 && xCloser <= 20)
//            chegou();
        
        //3° tronco
        if(xFurther <= 30 && xFurther >= 25 &&
           xCloser >= 25 && xCloser <= 30)
            chegou();
        
        //4° tronco
        if(xFurther <= 40 && xFurther >= 35 &&
           xCloser >= 35 && xCloser <= 40)
            chegou();
        
        //5° tronco
        if(xFurther <= 50 && xFurther >= 45 &&
           xCloser >= 45 && xCloser <= 50)
            chegou();
    }
}

void Anima(int value){
    xCloser = desenhaObjects->drawRabbit->xCloser;
    xFurther = desenhaObjects->drawRabbit->xFurther;
    yHigher = desenhaObjects->drawRabbit->yHigher;
    yLower = desenhaObjects->drawRabbit->yLower;
    
    //carro vermelho
    xCarRedCloser = desenhaObjects->drawCarRed->xCloser;
    xCarRedFurther = desenhaObjects->drawCarRed->xFurther;
    //caminhao roxo
    xTruckCloser = desenhaObjects->drawTruck->xCloser;
    xTruckFurther = desenhaObjects->drawTruck->xFurther;
    //carro cinza
    xCarGreyCloser = desenhaObjects->drawCarGrey->xCloser;
    xCarGreyFurther = desenhaObjects->drawCarGrey->xFurther;
    //caminhao amarelo
    xTruckYellowCloser = desenhaObjects->drawTruckYellow->xCloser;
    xTruckYellowFurther = desenhaObjects->drawTruckYellow->xFurther;
    //raposa 1
    xFoxCloser = desenhaObjects->drawFox->xCloser;
    xFoxFurther = desenhaObjects->drawFox->xFurther;
    //raposa 2
    xFoxTwoCloser = desenhaObjects->drawFoxTwo->xCloser;
    xFoxTwoFurther = desenhaObjects->drawFoxTwo->xFurther;
    
    //Colisoes
    colisoes();
    //coelho chegou no tronco
    crossedRabbit();
    
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
}

int main(int argc, char* argv[]){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
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

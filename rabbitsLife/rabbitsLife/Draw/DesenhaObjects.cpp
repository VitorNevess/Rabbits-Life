//
//  DesenhaObjects.cpp
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 13/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include "DrawForest.cpp"
#include "DrawTrunk.cpp"
#include "DrawTruck.cpp"
#include "DrawTruckYellow.cpp"
#include "DrawCarRed.cpp"
#include "DrawCarGrey.cpp"
#include "DrawGuia.cpp"
#include "DrawFaixa.cpp"
#include "DrawCalcada.cpp"
#include "DrawFixedRabbit.cpp"
#include "DrawRabbit.cpp"
#include "DrawFox.cpp"
#include "DrawFoxTwo.cpp"

class DesenhaObjects {
    
public:
    DrawFixedRabbit * drawFixedRabbit = new DrawFixedRabbit();
    DrawRabbit * drawRabbit = new DrawRabbit();
    DrawTruck * drawTruck = new DrawTruck();
    DrawTruckYellow * drawTruckYellow = new DrawTruckYellow();
    DrawCarRed* drawCarRed = new DrawCarRed();
    DrawCarGrey * drawCarGrey = new DrawCarGrey();
    DrawFox * drawFox = new DrawFox();
    DrawFoxTwo * drawFoxTwo = new DrawFoxTwo();
    
private:
    DrawForest * drawForest = new DrawForest();
    DrawTrunk * drawTrunk = new DrawTrunk();
    DrawGuia * drawGuia = new DrawGuia();
    DrawFaixa * drawFaixa = new DrawFaixa();
    DrawCalcada * drawCalcada = new DrawCalcada();
    
public: void showDrawings(int x1Fox, int x1FoxTwo, int x1TruckYellow, int x1CarGrey, int x1Truck ,int x1CarRed){
    drawForest->forest();
    drawTrunk->trunk();
    drawTruck->truck(x1Truck);
    drawTruckYellow->truckYellow(x1TruckYellow);
    drawCarRed->car(x1CarRed);
    drawCarGrey->carGrey(x1CarGrey);
    drawGuia->guias();
    drawFaixa->faixas();
    drawCalcada->calcadas();
    drawFox->foxOne(x1Fox);
    drawFoxTwo->foxTwo(x1FoxTwo);
}
    
public: void showDrawingRabbit(int xRabbit, int yRabbit, bool isDied, bool isVictory){
    drawRabbit->rabbit(xRabbit, yRabbit, isDied, isVictory);
};
    
public: void showDrawingFixedRabbit(int x, bool isDied, bool isVictory){
    drawFixedRabbit->fixedRabbit(x, isDied, isVictory);
};
};

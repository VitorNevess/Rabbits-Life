//
//  DrawCarRed.h
//  rabbitsLife
//
//  Created by joao.vitor.f.naves on 20/10/19.
//  Copyright © 2019 vitor.neves. All rights reserved.
//

#ifndef DrawCarRed_h
#define DrawCarRed_h
//arrumar o singleton das classes draw
class DrawCarRed {
    
private:
    //DrawCarRed();
    void wheelsCar(int x);
    
public:
    static DrawCarRed *instance;
    //static DrawCarRed* getInstance();
    float xCloser = 0;//mais perto
    float xFurther = 0;//mais longe
    static DrawCarRed *getInstance();
    void carRed(int x);
    void car(int x);

};

#endif /* DrawCarRed_h */

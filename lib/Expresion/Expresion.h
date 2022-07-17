#ifndef __EXPRESION_H__
#define __EXPRESION_H__



// struct Estado{
//     int matriz[5][6];
// }amargado[5][6] = {{20,0,0,0,0,0},
//                     {20,0,0,0,0,0},
//                     {20,0,0,0,0,0},
//                     {20,0,0,0,0,0},
//                     {20,0,0,0,0,0}};

// struct Estado{
//     uint8_t matriz[5][6];
// };


class Expresion
{
private:
    /* data */
public:
    Expresion(/* args */);
    ~Expresion();
  

    const uint8_t mosqueado[7][5]= 
    {{50,   0, 44, 40,  0},   // parpadoSuperiorIz
     {50,  40, 40, 40, 10},   // ojoIz
     {50,  80, 44, 20, 10},   // parpadoInferiorIz
     {110,  0, 44, 40,  0},   // parpadoSuperiorDr
     {110, 40, 40, 40, 10},   // ojoDr
     {110, 80, 44, 20, 10},   // parpadoInferiorDr
     {80, 100, 30, 10,  4}};  // boca

    const uint8_t sorprendido[7][5]= 
    {{50,   0, 44, 0,  0},   // parpadoSuperiorIz
     {50,  40, 40, 40, 10},   // ojoIz
     {50,  80, 44, 20, 10},   // parpadoInferiorIz
     {110,  0, 44, 0,  0},   // parpadoSuperiorDr
     {110, 40, 40, 40, 10},   // ojoDr
     {110, 80, 44, 20, 10},   // parpadoInferiorDr
     {80, 100, 30, 30,  4}};  // boca

    const uint8_t risa[7][5]= 
    {{50,   0, 44, 0,  0},   // parpadoSuperiorIz
     {50,  60, 40, 40, 10},   // ojoIz
     {50,  80, 44, 35, 10},   // parpadoInferiorIz
     {110,  0, 44, 0,  0},   // parpadoSuperiorDr
     {110, 60, 40, 40, 10},   // ojoDr
     {110, 80, 44, 35, 10},   // parpadoInferiorDr
     {80, 100, 30, 30,  4}};  // boca

    const uint8_t miraDerecha[7][5]= 
    {{50,   0, 44, 0,  0},   // parpadoSuperiorIz
     {80,  40, 35, 35, 10},   // ojoIz
     {50,  80, 44, 10, 10},   // parpadoInferiorIz
     {110,  0, 44, 0,  0},   // parpadoSuperiorDr
     {130, 40, 45, 45, 10},   // ojoDr
     {110, 80, 44, 10, 10},   // parpadoInferiorDr
     {100, 100, 25, 10, 4}};  // boca

    const uint8_t miraIzquierda[7][5]= 
    {{50,   0, 44, 0,  0},   // parpadoSuperiorIz
     {30,  40, 45, 45, 10},   // ojoIz
     {50,  80, 44, 10, 10},   // parpadoInferiorIz
     {110,  0, 44, 0,  0},   // parpadoSuperiorDr
     {80, 40, 35, 35, 10},   // ojoDr
     {110, 80, 44, 10, 10},   // parpadoInferiorDr
     {60, 100, 25, 10, 4}};  // boca



};

Expresion::Expresion(/* args */)
{
    
}

Expresion::~Expresion()
{
}







#endif // __EXPRESION_H__
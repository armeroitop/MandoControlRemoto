#ifndef __CARA_H__
#define __CARA_H__

#include <TFT_eSPI.h>                 // Hardware-specific library+
#include <Expresion.h>

TFT_eSPI    tft = TFT_eSPI();         // Invoke library
TFT_eSprite img = TFT_eSprite(&tft);  // Sprite class


struct Organo
{
    uint8_t x, y, ancho, alto, radio;
};

enum estadoAnimo {mosqueado, sorprendido, feliz, triste, enfadado, risa, miraDerecha, miraIzquierda};

class Cara
{
private:
    /* data */
public:

    Organo parpadoSuperiorIz, ojoIz, parpadoInferiorIz, 
           parpadoSuperiorDr, ojoDr, parpadoInferiorDr, 
           boca;
    Expresion expresion;    
    
    Cara(/* args */);
    ~Cara();
    void setup();
    void update();

    void cargarExpresion(const uint8_t expresion[7][5]); 
    void renderizarCara();

    estadoAnimo animo;

};



Cara::Cara(/* args */)
{   
    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);

    img.setColorDepth(8);
    img.createSprite(160, 128);
    img.fillSprite(TFT_BLACK);
    animo = estadoAnimo::risa;
}

Cara::~Cara()
{
}

void Cara::setup()
{
   
}

void Cara::update()
{
    switch (animo)
    {
        case estadoAnimo::mosqueado :
            cargarExpresion(expresion.mosqueado);
            animo = estadoAnimo::sorprendido;
            break;
        case estadoAnimo::sorprendido :
            cargarExpresion(expresion.sorprendido);
            animo = estadoAnimo::risa;
            break;
        case estadoAnimo::risa :
            cargarExpresion(expresion.risa);
            animo = estadoAnimo::miraDerecha;
            break;
        case estadoAnimo::miraDerecha :
            cargarExpresion(expresion.miraDerecha);
            animo = estadoAnimo::miraIzquierda;
            break;
        case estadoAnimo::miraIzquierda :
            cargarExpresion(expresion.miraIzquierda);
            animo = estadoAnimo::mosqueado;
            break;
        
        default:
            break;
    }
    
    renderizarCara();

    delay(1500);
    
    
}

void Cara::cargarExpresion(const uint8_t expresion[7][5])
{
    //*******************OJO IZQUIERDO***************
    parpadoSuperiorIz.x     = expresion[0][0];
    parpadoSuperiorIz.y     = expresion[0][1];
    parpadoSuperiorIz.ancho = expresion[0][2];
    parpadoSuperiorIz.alto  = expresion[0][3];
    parpadoSuperiorIz.radio = expresion[0][4];

    ojoIz.x     = expresion[1][0];
    ojoIz.y     = expresion[1][1];
    ojoIz.ancho = expresion[1][2];
    ojoIz.alto  = expresion[1][3];
    ojoIz.radio = expresion[1][4];

    parpadoInferiorIz.x     = expresion[2][0];
    parpadoInferiorIz.y     = expresion[2][1];
    parpadoInferiorIz.ancho = expresion[2][2];
    parpadoInferiorIz.alto  = expresion[2][3];
    parpadoInferiorIz.radio = expresion[2][4];


    //*******************OJO DERECHO***************
    parpadoSuperiorDr.x     = expresion[3][0];
    parpadoSuperiorDr.y     = expresion[3][1];
    parpadoSuperiorDr.ancho = expresion[3][2];
    parpadoSuperiorDr.alto  = expresion[3][3];
    parpadoSuperiorDr.radio = expresion[3][4];

    ojoDr.x     = expresion[4][0];
    ojoDr.y     = expresion[4][1];
    ojoDr.ancho = expresion[4][2];
    ojoDr.alto  = expresion[4][3];
    ojoDr.radio = expresion[4][4];

    parpadoInferiorDr.x     = expresion[5][0];
    parpadoInferiorDr.y     = expresion[5][1];
    parpadoInferiorDr.ancho = expresion[5][2];
    parpadoInferiorDr.alto  = expresion[5][3];
    parpadoInferiorDr.radio = expresion[5][4];

    //*******************BOCA***************
    boca.x     = expresion[6][0];
    boca.y     = expresion[6][1];
    boca.ancho = expresion[6][2];
    boca.alto  = expresion[6][3];
    boca.radio = expresion[6][4];
 
}

void Cara::renderizarCara()
{
    img.fillSprite(TFT_BLACK);
    //*****OJO IZQUIERDO*****    
    //Ajustamos Y y X para solo pasar los paramotros como si fuera el centro del ojo
    ojoIz.x -= ojoIz.ancho/2;
    ojoIz.y -= ojoIz.alto/2;
    img.fillRoundRect(ojoIz.x, ojoIz.y, ojoIz.ancho, ojoIz.alto, ojoIz.radio, TFT_GREENYELLOW); // ojo iz 

    parpadoSuperiorIz.x = ojoIz.x - 2;
    img.fillRoundRect(parpadoSuperiorIz.x, parpadoSuperiorIz.y, parpadoSuperiorIz.ancho, parpadoSuperiorIz.alto, parpadoSuperiorIz.radio, TFT_BLACK); // parpado superior iz

    parpadoInferiorIz.x = ojoIz.x - 2;
    parpadoInferiorIz.y -= parpadoInferiorIz.alto;
    img.fillRoundRect(parpadoInferiorIz.x, parpadoInferiorIz.y, parpadoInferiorIz.ancho, parpadoInferiorIz.alto, parpadoInferiorIz.radio, TFT_BLACK); // parpado inferior iz
   
    //*****OJO DERECHO*****    
    ojoDr.x -= ojoDr.ancho/2;
    ojoDr.y -= ojoDr.alto/2;
    img.fillRoundRect(ojoDr.x, ojoDr.y, ojoDr.ancho, ojoDr.alto, ojoDr.radio, TFT_GREENYELLOW); // ojo dr  

    parpadoSuperiorDr.x = ojoDr.x - 2;
    img.fillRoundRect(parpadoSuperiorDr.x, parpadoSuperiorDr.y, parpadoSuperiorDr.ancho, parpadoSuperiorDr.alto, parpadoSuperiorDr.radio, TFT_BLACK); // parpado superior dr

    parpadoInferiorDr.x = ojoDr.x - 2;
    parpadoInferiorDr.y -= parpadoInferiorDr.alto;
    img.fillRoundRect(parpadoInferiorDr.x, parpadoInferiorDr.y, parpadoInferiorDr.ancho, parpadoInferiorDr.alto, parpadoInferiorDr.radio, TFT_BLACK); // parpado inferior dr
    
    //*****BOCA*****
    boca.x -= boca.ancho/2;
    boca.y -= boca.alto/2;
    img.fillRoundRect(boca.x, boca.y, boca.ancho, boca.alto, boca.radio, TFT_GREENYELLOW); // BOCA    
 

    img.pushSprite(0,0);
}




#endif // __CARA_H__
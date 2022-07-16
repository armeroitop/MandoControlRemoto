#ifndef __CARA_H__
#define __CARA_H__

#include <TFT_eSPI.h>                 // Hardware-specific library

TFT_eSPI    tft = TFT_eSPI();         // Invoke library

TFT_eSprite img = TFT_eSprite(&tft);  // Sprite class

struct Organo
{
    int x, y, ancho, alto, radio;
};


class Cara
{
private:
    /* data */
public:

    Organo ojoIz, ojoDr, parpadoInferiorIz, parpadoInferiorDr, boca;
    
    Cara(/* args */);
    ~Cara();
    void setup();
    void update();
};

Cara::Cara(/* args */)
{
    ojoIz.x = 30;
    ojoIz.y = 20;
    ojoIz.ancho = 40;
    ojoIz.alto = 40;
    ojoIz.radio = 10;

    parpadoInferiorIz.x = 28;
    parpadoInferiorIz.y = 52;
    parpadoInferiorIz.ancho = 44;
    parpadoInferiorIz.alto = 25;
    parpadoInferiorIz.radio = 10;

    
    ojoDr.x = 90;
    ojoDr.y = 20;
    ojoDr.ancho = 40;
    ojoDr.alto = 40;
    ojoDr.radio = 10;

    parpadoInferiorDr.x = 88;
    parpadoInferiorDr.y = 52;
    parpadoInferiorDr.ancho = 44;
    parpadoInferiorDr.alto = 25;
    parpadoInferiorDr.radio = 10;


    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);

    img.setColorDepth(8);
    img.createSprite(160, 128);
    img.fillSprite(TFT_BLACK);

}

Cara::~Cara()
{
}

void Cara::setup()
{
    
}

void Cara::update()
{
    img.fillRoundRect(40,90,75,10,4,TFT_GREENYELLOW); // BOCA

    

    img.fillRoundRect(ojoIz.x, ojoIz.y, ojoIz.ancho, ojoIz.alto, ojoIz.radio, TFT_GREENYELLOW); // ojo iz       
    img.fillRoundRect(parpadoInferiorIz.x, parpadoInferiorIz.y, parpadoInferiorIz.ancho, parpadoInferiorIz.alto, parpadoInferiorIz.radio, TFT_BLACK); // parpado inferior iz
    
    img.fillRoundRect(ojoDr.x, ojoDr.y, ojoDr.ancho, ojoDr.alto, ojoDr.radio, TFT_GREENYELLOW); // ojo dr  
    img.fillRoundRect(parpadoInferiorDr.x, parpadoInferiorDr.y, parpadoInferiorDr.ancho, parpadoInferiorDr.alto, parpadoInferiorDr.radio, TFT_BLACK); // parpado inferior dr
    
    
 

    img.pushSprite(0,0);
}


#endif // __CARA_H__
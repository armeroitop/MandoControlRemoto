#ifndef __PANTALLA_H__
#define __PANTALLA_H__

#include <TFT_eSPI.h>                 // Hardware-specific library+
#include <Control.h>


TFT_eSPI    tft         = TFT_eSPI();         // Invoke library
TFT_eSprite background  = TFT_eSprite(&tft);  // Sprite class
TFT_eSprite textoSprite = TFT_eSprite(&tft);  // Sprite class

Control *p_control = new Control();

class Pantalla
{
private:
    /* data */
public:
    Pantalla(/* args */);
    ~Pantalla();
    void setup();
    void update();
};

Pantalla::Pantalla(/* args */)
{
    tft.begin();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);

    background.setColorDepth(8);
    background.createSprite(160, 128);
    textoSprite.createSprite(80,20);
    textoSprite.setTextColor(TFT_WHITE,TFT_BLACK);
    textoSprite.setTextDatum(2);
    
    pinMode(25, INPUT);
}

Pantalla::~Pantalla()
{
   
}

void Pantalla::setup()
{
    
}

void Pantalla::update()
{
    p_control->update();

    background.fillSprite(TFT_BLACK);
    //Valor CANAL x Izq
    textoSprite.drawString(String(p_control->ch1_x),30,0,2);
    textoSprite.pushToSprite(&background,50,30,TFT_BLACK);
    textoSprite.fillSprite(TFT_BLACK);

    //Valor CANAL y Izq
    textoSprite.drawString(String(p_control->ch1_y),30,0,2);
    textoSprite.pushToSprite(&background,50,50,TFT_BLACK);
    textoSprite.fillSprite(TFT_BLACK);

    //Valor CANAL Boton Izq
    //textoSprite.drawString(String(analogRead(36)),80,0,2);    
    textoSprite.drawNumber(p_control->ch1_btn,30,0,2); 
    textoSprite.pushToSprite(&background,50,70,TFT_BLACK);
    textoSprite.fillSprite(TFT_BLACK);

    //Valor CANAL x Drc
    textoSprite.drawString(String(p_control->ch2_x),80,0,2);
    textoSprite.pushToSprite(&background,50,30,TFT_BLACK);
    textoSprite.fillSprite(TFT_BLACK);

    //Valor CANAL y Drc
    textoSprite.drawString(String(p_control->ch2_y),80,0,2);
    textoSprite.pushToSprite(&background,50,50,TFT_BLACK);
    textoSprite.fillSprite(TFT_BLACK);

    //Valor CANAL Boton Drc
    //textoSprite.drawString(String(digitalRead(25)),80,0,2);    
    textoSprite.drawNumber(p_control->ch2_btn,80,0,2); 
    textoSprite.pushToSprite(&background,50,70,TFT_BLACK);
    textoSprite.fillSprite(TFT_BLACK);


    

    background.pushSprite(0,0);
    Serial.println(analogRead(36));
}


#endif // __PANTALLA_H__
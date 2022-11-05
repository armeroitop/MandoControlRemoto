//#include <Cara.h>
//#include <Ruedas.h>

#include <Pantalla.h>
#include <Control.h>
//#include <Antena.h>

//Cara *p_cara = new Cara();
//Control *p_control = new Control();
Pantalla *p_pantalla = new Pantalla();
//Antena *p_antena = new Antena();

void setup(void)
{
    Serial.begin(9600);
    //p_antena->setup();
}

void loop() 
{
    //p_control->update();
    p_pantalla->update();
    //p_ruedas->update();
    //p_cara->update();    
    //p_antena->update();
}

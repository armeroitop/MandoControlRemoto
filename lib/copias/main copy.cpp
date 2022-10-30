#include <Cara.h>
#include <Ruedas.h>
#include <Antena.h>

Cara *p_cara = new Cara();
Ruedas *p_ruedas = new Ruedas();
Antena *p_antena = new Antena();

void setup(void)
{
  //p_ruedas->setup();
  p_antena->setup();
}

void loop() 
{
    //p_ruedas->update();
   // p_cara->update();    
    p_antena->update();
}

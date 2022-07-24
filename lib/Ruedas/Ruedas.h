#ifndef __RUEDAS_H__
#define __RUEDAS_H__

class Ruedas
{
private:
    /* data */
public:

    // Motor A
    const int ENA = 25;
    const int IN1 = 12;
    const int IN2 = 14;

    // setting PWM properties
    const int freq = 5000;
    const int canalMotorA = 0;
    const int resolution = 8;

    Ruedas(/* args */);
    ~Ruedas();
    void setup();
    void update();
    void adelante();
};

Ruedas::Ruedas(/* args */)
{
}

Ruedas::~Ruedas()
{
}

void Ruedas::setup()
{
    // Declaramos todos los pines como salidas
    //pinMode (ENA, OUTPUT);

     // configure LED PWM functionalitites
    ledcSetup(canalMotorA, freq, resolution);
    ledcAttachPin(ENA, canalMotorA);
   
    pinMode (IN1, OUTPUT);
    pinMode (IN2, OUTPUT);
    
}

void Ruedas::update()
{
    adelante();    
}

void Ruedas::adelante()
{
    //Direccion motor A
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    //digitalWrite (ENA, HIGH);

    //analogWrite (ENA, 128); //Velocidad motor A
    ledcWrite(canalMotorA, 255);
   
}




#endif // __RUEDAS_H__
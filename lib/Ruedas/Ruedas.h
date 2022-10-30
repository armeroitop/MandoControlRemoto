#ifndef __RUEDAS_H__
#define __RUEDAS_H__

class Ruedas
{
private:
    /* data */
public:

    // Motor A
    const int ENA = 25;
    const int IN1 = 14;
    const int IN2 = 27;
   
    // Encoder Motor A
    const int S1 = 34;
    const int S2 = 35;

    // Motor B
    const int ENB = 33;
    const int IN3 = 13;
    const int IN4 = 12;

    // Encoder Motor B
    const int S3 = 39;
    const int S4 = 36;

    // setting PWM properties
    const int freq = 5000;
    const int canalMotorA = 1;
    const int canalMotorB = 0;
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
    ledcSetup(canalMotorB, freq, resolution);
    ledcAttachPin(ENB, canalMotorB);
   
    pinMode (IN3, OUTPUT);
    pinMode (IN4, OUTPUT);
    

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
    //Direccion motor B
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, LOW);
    //digitalWrite (ENA, HIGH);

    //analogWrite (ENA, 128); //Velocidad motor A
    ledcWrite(canalMotorB, 200); 


    //Direccion motor A
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    ledcWrite(canalMotorA, 200); 

}




#endif // __RUEDAS_H__
#ifndef __CONTROL_H__
#define __CONTROL_H__

class Control
{
private:
    /* data */
public:
    Control(/* args */);
    ~Control();
    const int   pin_ch1_x   = 35,
                pin_ch1_y   = 32,
                pin_ch1_btn = 33,
                pin_ch2_x   = 34,
                pin_ch2_y   = 39,
                pin_ch2_btn = 25;
    int ch1_x,
        ch1_y,
        ch1_btn,
        ch2_x,
        ch2_y,
        ch2_btn;
    bool estadoBtn1=false, 
         estadoBtn2=false;    

    void setup();
    void update();
};

Control::Control(/* args */)
{
    ch1_x   = 0;
    ch1_y   = 0;
    ch1_btn = 0;
    ch2_x   = 0;
    ch2_y   = 0;
    ch2_btn = 0;
    pinMode(pin_ch1_btn, INPUT);
    pinMode(pin_ch2_btn, INPUT);
}

Control::~Control()
{
}

void Control::setup()
{
    
}

void Control::update()
{
    ch1_x   = analogRead(pin_ch1_x);
    ch1_y   = analogRead(pin_ch1_y);

    if (digitalRead(pin_ch1_btn)){
        ch1_btn = 0;
    }else{
        ch1_btn = 1;
    }  
    
    ch2_x   = analogRead(pin_ch2_x);
    ch2_y   = analogRead(pin_ch2_y);   
    
        
    if (digitalRead(pin_ch2_btn)){
        ch2_btn = 0;
    }else{
        ch2_btn = 1;
    }    


    //Serial.println(analogRead(33));
    // Serial.println(analogRead(32));
    // Serial.println(digitalRead(35));
    // Serial.println("------------");
}


#endif // __CONTROL_H__
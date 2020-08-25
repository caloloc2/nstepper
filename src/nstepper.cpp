/*
nstepper.cpp - Library to control
stepper motors.
Created by Carlos Mino, Nibemi 2020
*/
#include "nstepper.h"

nstepper::nstepper(float rev, int ena, int dir, int step, bool signo){
    pinMode(ena, OUTPUT);
    pinMode(dir, OUTPUT);
    pinMode(step, OUTPUT);
    _enable = ena;
    _direction = dir;
    _step = step;
    _rev = rev;
    _signo = signo;
}

void nstepper::velocidad(long rpm){    
    _delay = 60L * 1000L * 1000L / _rev / rpm;    
}

void nstepper::habilitar(){
    if (_signo){
        digitalWrite(_enable, HIGH);
    }else{
        digitalWrite(_enable, LOW);
    }
}

void nstepper::deshabilitar(){
    if (_signo){
        digitalWrite(_enable, LOW);
    }else{
        digitalWrite(_enable, HIGH);
    }
}

void nstepper::direccion(int opcion){
    if (opcion==0){ // horario        
        if (_signo){
            digitalWrite(_direction, LOW);
        }else{
            digitalWrite(_direction, HIGH);
        }
    }else{ // antihorario
        if (_signo){
            digitalWrite(_direction, HIGH);
        }else{
            digitalWrite(_direction, LOW);
        }
    }
}

void nstepper::adelante(){
    if (_signo){
        digitalWrite(_step, LOW);;
        delayMicroseconds(_delay);
        digitalWrite(_step, HIGH);
        delayMicroseconds(_delay);
    }else{
        digitalWrite(_step, HIGH);
        delayMicroseconds(_delay);
        digitalWrite(_step, LOW);
        delayMicroseconds(_delay);
    }
}

void nstepper::atras(){
    if (_signo){
        digitalWrite(_step, LOW);
        delayMicroseconds(_delay);
        digitalWrite(_step, HIGH);
        delayMicroseconds(_delay);
    }else{
        digitalWrite(_step, HIGH);
        delayMicroseconds(_delay);
        digitalWrite(_step, LOW);
        delayMicroseconds(_delay);
    }
}
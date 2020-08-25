/*
nstepper.h - Library to control
stepper motors.
Created by Carlos Mino, Nibemi 2020
*/
#ifndef nstepper_h
#define nstepper_h
#include "Arduino.h"

class nstepper{
    public:
        nstepper(float rev, int ena, int dir, int step, bool signo);      
        void habilitar();
        void deshabilitar();
        void direccion(int opcion);
        void adelante();
        void atras();
        void velocidad(long rpm);
    private:
        int _enable;
        int _direction;
        int _step;
        float _rev;
        bool _signo;
        long _delay;
};

#endif
// Instancia nstepper (numero_pasos, pin_enable, pin_direccion, pin_step, false(0), true(1)
#include <nstepper.h>
nstepper motor(6400, 7, 8, 9, false);

void setup() {
  // put your setup code here, to run once:
  motor.habilitar();
  motor.direccion(1);

  motor.velocidad(250);
}

void loop() {
  // put your main code here, to run repeatedly: 
  motor.adelante();
}

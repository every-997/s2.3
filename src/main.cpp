#include <mbed.h>

DigitalOut green(LED_GREEN);
void  on(void) { green.write(0); }
void off(void) { green.write(1); }

Ticker  pit;
unsigned int period = 10; //this is the time between flashes
unsigned int duration = 5; //this is how long the led is on for 
void centisecond(void) {
   static unsigned int cs=0;
   cs = (cs+1) % period ;

   if( cs<duration )  on();
   else              off();
}

int main(void) {
  pit.attach_us(centisecond, 10000);

  while(1) {}

}

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <mc9s08se8.h>

void delay(void);

void main(void) {
  EnableInterrupts;
  /* include your code here */
  RTCMOD = 0x00;
  RTCSC =0x1F;
  PTCDD_PTCDD0 = 1;
  PTCD_PTCD0 = 1;

  for(;;) {
    __RESET_WATCHDOG();	/* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

void interrupt 25 Vrtc_ISR(void){
	RTCSC_RTIF=1;
	PTCD_PTCD0 = PTCD_PTCD0^1;
}

void delay(void){
	//RTCSC =0x1F;
	while(RTCSC_RTIF != 1){
	    	__RESET_WATCHDOG();
	    }
	RTCSC_RTIF = 1;
}

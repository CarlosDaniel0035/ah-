#include <xc.h>
#include "config.h"


void timer2_init (void)
{
    INTCONbits.GIE = 0;
    T2CONbits.T2CKPS = 00;
    T2CONbits.TOUTPS = 0000;
    TMR2 = 256-156;
    contador = 0;
    t2seg = 10000;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;           
}
void __interrupt() ossada(void)
{
    if(INTCONbits.PEIE)
    {
        INTCONbits.PEIE = 0;
        TMR2 = 256-156;
        --t2seg;
        if(t2seg == 0)
        {
            t2seg = 10000;
            ++contador;
        }
        
    }
}
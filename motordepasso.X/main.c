#include <xc.h>
#include "config.h"
#include "motorpasso.h"
#include "delay.h"
#include "display.h"


#define  S1   PORTDbits.RD0
#define  S2   PORTDbits.RD1
#define  S3   PORTDbits.RD2 

void main (void)  
{
    
    int estado = 0;
    motorpasso_init();
    dispLCD_init();
    timer2_init();
    
    while( 1 )
    {
        switch(estado)
        {
            case 0:
                estado = 1;
                break;
            case 1:
                dispLCD(0,0,"Contador:          ");
                if (S1 == 1)
                    estado = 2;
                if (S2 == 1)
                    estado = 3;
                if (S3 == 1)
                    estado = 5;
                break;
            case 2: 
                
                motorpasso(48, 100);
                if (S2 ==1)
                    estado = 4;
                break;
            case 3:
                motorantpasso(48, 100);
                if (S2 == 1)
                    estado = 4;
                break;
            case 4:
                if(S2 == 0)
                    estado = 1;
                break;
            case 5:
                motormeiopasso(30, 1000);
                break;
                
        }
    }
    return;
}

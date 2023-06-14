/*    ************includes***************   */
#include"MCAL_interrupt_manager.h"
#include"MCAL_Interrupt_config.h"


/* **************interrupt manager implemtation *************** */
#if PRIORITY_LEVELS == ENABLE
void __interrupt() InterruptManagerHigh(void){
    
    if((INTCONbits.INT0IE == 1) && (INTCONbits.INT0IF == 1)){
        ISR_INT0();
    }
    else{/*Do Nothing*/}
    
    
    if((INTCON3bits.INT1IE == 1) && (INTCON3bits.INT1IF == 1)){
        ISR_INT1();
    }
    else{/*Do Nothing*/}
    
    if((INTCON3bits.INT2IE == 1) && (INTCON3bits.INT2IF == 1)){
        ISR_INT2();
    }
    else{/*Do Nothing*/}

    


}

void __interrupt(low_priority) InterruptManagerLow(void){
    
    if((INTCON3bits.INT1IE == 1) && (INTCON3bits.INT1IF == 1)){
        ISR_INT1();
    }
    else{/*Do Nothing*/}
    
    if((INTCON3bits.INT2IE == 1) && (INTCON3bits.INT2IF == 1)){
        ISR_INT2();
    }
    else{/*Do Nothing*/}


}
#else

void __interrupt() InterruptManager(void){
    
    if((INTCONbits.INT0IE == 1) && (INTCONbits.INT0IF == 1)){
        ISR_INT0();
    }
    else{/*Do Nothing*/}
    
    
    if((INTCON3bits.INT1IE == 1) && (INTCON3bits.INT1IF == 1)){
        ISR_INT1();
    }
    else{/*Do Nothing*/}
    
    if((INTCON3bits.INT2IE == 1) && (INTCON3bits.INT2IF == 1)){
        ISR_INT2();
    }
    else{/*Do Nothing*/}


}


#endif
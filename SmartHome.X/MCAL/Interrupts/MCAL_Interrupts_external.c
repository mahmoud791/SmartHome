#include"MCAL_Interrupts_external.h"




/*  *********************** Interfaces implementation ***********************    */

StdReturnType Init_Ext_INT0(Ext_INT0_t * int0_obj){
    StdReturnType ret = E_OK;
    if(NULL == int0_obj){
        ret = E_NOT_OK;
    }
    else{
        
        //Disable INT0
        INTCONbits.INT0IE = 0;
      
        
        //Clear the interrupt flage
        INTCONbits.INT0IF = 0;
        
        
        // configrue the pin as input
        pin_config_t int0_pin = {
            .direction= GPIO_DIRECTION_INPUT,
            .logic = GPIO_LOW,
            .port = PORTB_INDEX,
            .pin = GPIO_PIN0,
        };
        ret  = gpio_pin_direction_intialize(&int0_obj);
        
        
        
        // configure interrupt edge
        
        
        
        //set the interrupt handler
 
#if PRIORITY_LEVELS == ENABLE
        //set the priority (Not applicaple for INT0)
        
        // set GIEH or GIEL bits depending on priority (in case of INT0, set GIEH only)
#else
        // set GIE bit
#endif

       //enable the interrupt
        
        
    }
    return ret;

}


StdReturnType Init_Ext_INT1(Ext_INT1_t * int1_obj){
    StdReturnType ret = E_OK;
    if(NULL == int1_obj){
        ret = E_NOT_OK;
    }
    else{
        //Disable INT1
        
        //Clear the interrupt flage
        
        // configrue the pin as input
        
        
        
        // configure interrupt edge
        
        //set the interrupt handler
 
#if PRIORITY_LEVELS == ENABLE
        //set the priority (Not applicaple for INT0)
        
        // set GIEH or GIEL bits depending on priority (in case of INT0, set GIEH only)
#else
        // set GIE bit
#endif

       //enable the interrupt
        
               
    }
    return ret;

}


StdReturnType Init_Ext_INT2(Ext_INT2_t * int2_obj){
    StdReturnType ret = E_OK;
    if(NULL == int2_obj){
        ret = E_NOT_OK;
    }
    else{
        //Disable INT2
        
        //Clear the interrupt flage
        
        // configrue the pin as input
        
        
        
        // configure interrupt edge
        
        //set the interrupt handler
 
#if PRIORITY_LEVELS == ENABLE
        //set the priority (Not applicaple for INT0)
        
        // set GIEH or GIEL bits depending on priority (in case of INT0, set GIEH only)
#else
        // set GIE bit
#endif

       //enable the interrupt
        
                
    }
    return ret;

}

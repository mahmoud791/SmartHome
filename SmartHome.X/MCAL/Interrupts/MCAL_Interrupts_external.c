/*  *************              Includes   ********************            **********/
#include"MCAL_Interrupts_external.h"

/******************************Global varaibles***************************************/
static void (*InterruptHandler_INT0) (void) = NULL;
static void (*InterruptHandler_INT1) (void) = NULL;
static void (*InterruptHandler_INT2) (void) = NULL;










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

       
        ret  = gpio_pin_direction_intialize(&int0_pin);
        
        
        
        // configure interrupt edge
        INTCON2bits.INTEDG0 = int0_obj->edge;
        
        
        
        //set the interrupt handler
        InterruptHandler_INT0 = int0_obj->interrupt_handler;
        
 
#if PRIORITY_LEVELS == ENABLE
        // enable priority levels by setting IPEN bit high
        RCONbits.IPEN = 1;
        //set the priority (Not applicaple for INT0)
        
        // set GIEH or GIEL bits depending on priority (in case of INT0, set GIEH only)
        INTCONbits.GIEH = 1;
        
#else
        // set GIE bit
        INTCONbits.GIE = 1;
#endif

       //enable the interrupt
        INTCONbits.INT0IE =1;
        
        
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
        INTCON3bits.INT1E = 0;
        
        
        //Clear the interrupt flage
        INTCON3bits.INT1IF=0;
        
        // configrue the pin as input
        pin_config_t int1_pin = {
            .direction= GPIO_DIRECTION_INPUT,
            .logic = GPIO_LOW,
            .port = PORTB_INDEX,
            .pin = GPIO_PIN1,
        };
        
        ret  = gpio_pin_direction_intialize(&int1_pin);
        
        
        // configure interrupt edge
        INTCON2bits.INTEDG1 = int1_obj->edge;
        
        
        //set the interrupt handler
        InterruptHandler_INT1 = int1_obj->interrupt_handler;
 
#if PRIORITY_LEVELS == ENABLE
        // enable priority levels by setting IPEN bit high
        RCONbits.IPEN = 1;
        
        //set the priority (Not applicaple for INT0)
        INTCON3bits.INT1IP = int1_obj->priority;
        
        // set GIEH or GIEL bits depending on priority (in case of INT0, set GIEH only)
        if(int1_obj->priority == HIGH_PRIORITY) INTCONbits.GIEH =1;
        else if (int1_obj->priority == LOW_PRIORITY) INTCONbits.GIEL =1;
        else { ret = E_NOT_OK; /*Invalid priority*/}
#else
        // set GIE bit
        INTCONbits.GIE = 1;
#endif

       //enable the interrupt
       INTCON3bits.INT1IE =1;
               
    }
    return ret;

}


StdReturnType Init_Ext_INT2(Ext_INT2_t * int2_obj){
    StdReturnType ret = E_OK;
    if(NULL == int2_obj){
        ret = E_NOT_OK;
    }
    else{
        //Disable INT1
        INTCON3bits.INT2IE = 0;
        
        
        //Clear the interrupt flage
        INTCON3bits.INT2IF=0;
        
        // configrue the pin as input
        pin_config_t int2_pin = {
            .direction= GPIO_DIRECTION_INPUT,
            .logic = GPIO_LOW,
            .port = PORTB_INDEX,
            .pin = GPIO_PIN2,
        };
        
        ret  = gpio_pin_direction_intialize(&int2_pin);
        
        
        // configure interrupt edge
        INTCON2bits.INTEDG2 = int2_obj->edge;
        
        
        //set the interrupt handler
        InterruptHandler_INT2 = int2_obj->interrupt_handler;
 
#if PRIORITY_LEVELS == ENABLE
        // enable priority levels by setting IPEN bit high
        RCONbits.IPEN = 1;
        
        //set the priority (Not applicaple for INT0)
        INTCON3bits.INT2IP = int2_obj->priority;
        
        // set GIEH or GIEL bits depending on priority (in case of INT0, set GIEH only)
        
        if(int2_obj->priority == HIGH_PRIORITY) INTCONbits.GIEH =1;
        else if (int2_obj->priority == LOW_PRIORITY) INTCONbits.GIEL =1;
        else { ret = E_NOT_OK; /*Invalid priority*/}
#else
        // set GIE bit
        INTCONbits.GIE = 1;
#endif

       //enable the interrupt
       INTCON3bits.INT2IE =1;
               
    }
    return ret;

}

/******************* Interrupt service Rotines implemtation***********************/

void ISR_INT0(void){
    //clear int0 flag
    INTCONbits.INT0IF = 0;
    /*
     future code here
    */
    
    // fire interrupt handler
    if(InterruptHandler_INT0)InterruptHandler_INT0();
    
}

void ISR_INT1(void){
    //clear int1 flag
    INTCON3bits.INT1IF=0;
    /*
     future code here
    */
    
    // fire interrupt handler
    if(InterruptHandler_INT1)InterruptHandler_INT1();
    
}


void ISR_INT2(void){
    //clear int2 flag
    INTCON3bits.INT2IF=0;
    /*
     future code here
    */
    
    // fire interrupt handler
    if(InterruptHandler_INT2)InterruptHandler_INT2();
    
}
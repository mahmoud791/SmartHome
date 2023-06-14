
/*******************INCLUDES****************************/
#include "APP_init.h"


/***********       Functions Declarations     *******/
static void interruptHandler_ExtInt0(void);





/**********Data definitions*********/
static uint8_t cnt = 1;

led_config_t led1 = {
    .led_port = PORTD_INDEX,
    .led_pin_index = GPIO_PIN0

};
Ext_INT0_t ExtInt0 = {
    .edge = RISING_EDGE,
    .interrupt_handler = interruptHandler_ExtInt0
};



/***********       Functions Definitions      *******/
static void interruptHandler_ExtInt0(void){
    uint8_t i;
    
    for(i=0;i<=cnt;i++){
        led_on(&led1);
        __delay_ms(500);
        led_off(&led1);
        __delay_ms(500);
    }
    
    if(cnt>=10)cnt=1;
    else cnt++;
   
}

StdReturnType app_init(void){
   StdReturnType ret = E_OK;
   
   ret = led_init(&led1);
   ret = Init_Ext_INT0(&ExtInt0);
    
    
   return ret;
}








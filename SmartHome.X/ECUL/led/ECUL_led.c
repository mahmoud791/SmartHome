#include"ECUL_led.h"


StdReturnType led_init(const led_config_t *led){
    
    StdReturnType ret = E_OK;
    if(led->led_port > PORT_MAX_NUMBER-1 ||
       led->led_pin_index >  PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
       pin_config_t led_pin = {
       .direction = GPIO_DIRECTION_OUTPUT,
       .logic = GPIO_LOW,
       .pin = led->led_pin_index,
       .port = led->led_port
       };
       
       gpio_pin_intialize(&led_pin); 
    }
    
    return ret;
}



StdReturnType led_on(const led_config_t *led){
    
    StdReturnType ret = E_OK;
    if(led->led_port > PORT_MAX_NUMBER-1 ||
       led->led_pin_index >  PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t led_pin = {
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic = GPIO_LOW,
        .pin = led->led_pin_index,
        .port = led->led_port
        };
        ret = gpio_set_pin_high(&led_pin);
    }
    
    return ret;
    
    
}


StdReturnType led_off(const led_config_t *led){
    
    StdReturnType ret = E_OK;
    if(led->led_port > PORT_MAX_NUMBER-1 ||
       led->led_pin_index >  PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t led_pin = {
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic = GPIO_LOW,
        .pin = led->led_pin_index,
        .port = led->led_port
        };
        ret = gpio_set_pin_low(&led_pin);
    }
    
    return ret;
    
    
    
    
}


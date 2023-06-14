
/***********Includes***********/
#include"MCAL_GPIO.h"

/***********Macros***********/


/***********Global Variables***********/
/* Reference to the Data Direction Control Registers */
volatile uint8_t *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/* Reference to the Data Latch Register (Read and Write to Data Latch) */
volatile uint8_t *lat_registers[]  = {&LATA , &LATB , &LATC , &LATD , &LATE};
/* Reference to the Port Status Register  */
volatile uint8_t *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};


/***********Functions implementation***********/


/**
 * @brief Initialize the direction of a specific pin @ref direction_t
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

StdReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config){
    StdReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        switch(_pin_config->direction){
            case GPIO_DIRECTION_OUTPUT :
                CLEAR_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT :
                SET_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}


/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @param direction_status
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action 
 */

StdReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status){
    StdReturnType ret = E_OK;
    if(NULL == _pin_config || NULL == direction_status || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *direction_status = READ_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}


/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @param logic
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

StdReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic){
    StdReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        switch(logic){
            case GPIO_LOW :
                CLEAR_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_HIGH :
                SET_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}



/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
StdReturnType gpio_set_pin_high(const pin_config_t *_pin_config){
    StdReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        SET_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;

}


/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
StdReturnType gpio_set_pin_low(const pin_config_t *_pin_config){
    StdReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        CLEAR_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}

/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @param logic
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

StdReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic){
    StdReturnType ret = E_OK;
    if(NULL == _pin_config || NULL == logic || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *logic = READ_BIT(*port_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}


/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

StdReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config){
    StdReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        TOGGLE_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}






/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

StdReturnType gpio_pin_intialize(const pin_config_t *_pin_config){
    StdReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_intialize(_pin_config);
        ret = gpio_pin_write_logic(_pin_config, _pin_config->logic);
    }
    return ret;
}

#if GPIO_PORT_MODE == ENABLE
/**
 * 
 * @param port
 * @param direction
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

StdReturnType gpio_port_direction_intialize(port_index_t port, uint8_t direction){
    StdReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *tris_registers[port] = direction;
    }
    return ret;
}


/**
 * 
 * @param port
 * @param direction_status
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

StdReturnType gpio_port_get_direction_status(port_index_t port, uint8_t *direction_status){
    StdReturnType ret = E_OK;
    if((NULL == direction_status) && (port > PORT_MAX_NUMBER-1)){
        ret = E_NOT_OK;
    }
    else{
        *direction_status = *tris_registers[port];
    }
    return ret;
}


/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

StdReturnType gpio_port_write_logic(port_index_t port, uint8_t logic){
    StdReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *lat_registers[port] = logic;
    }
    return ret;
}


/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

StdReturnType gpio_port_read_logic(port_index_t port, uint8_t *logic){
    StdReturnType ret = E_OK;
    if((NULL == logic) && (port > PORT_MAX_NUMBER-1)){
        ret = E_NOT_OK;
    }
    else{
        *logic = *lat_registers[port];
    }
    return ret;
}


/**
 * 
 * @param port
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

StdReturnType gpio_port_toggle_logic(port_index_t port){
    StdReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *lat_registers[port] ^= PORTC_MASK;
    }
    return ret;
}
#endif
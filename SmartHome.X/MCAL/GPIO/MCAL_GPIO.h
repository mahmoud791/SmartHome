/* 
 * File:   MCAL_GPIO.h
 * Author: sacri
 *
 * Created on June 13, 2023, 9:24 PM
 */

#ifndef MCAL_GPIO_H
#define	MCAL_GPIO_H
/***********Includes***********/
#include"../PIC18_config.h"
#include"MCAL_GPIO_config.h"
/***********Macros***********/

#define BIT_MASK  (uint8_t)1

#define PORT_PIN_MAX_NUMBER  8
#define PORT_MAX_NUMBER      5

#define PORTC_MASK           0xFF



/***********Function like Macros***********/
#define HWREG8(_X)     (*((volatile uint8 *)(_X)))

#define SET_BIT(REG, BIT_POSN)     (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)   (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)  (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG, BIT_POSN)    ((REG >> BIT_POSN) & BIT_MASK)


/***********Data type declarations***********/

typedef enum{
    GPIO_LOW = 0,
    GPIO_HIGH
}logic_t;

typedef enum{
    GPIO_DIRECTION_OUTPUT = 0,
    GPIO_DIRECTION_INPUT
}direction_t;

typedef enum{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}pin_index_t;

typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct{
    uint8_t port : 3;      
    uint8_t pin : 3;       
    uint8_t direction : 1; 
    uint8_t logic : 1;     
}pin_config_t;

/***********Interfaces***********/
    
StdReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config);
StdReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status);
StdReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic);
StdReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic);
StdReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);
StdReturnType gpio_pin_intialize(const pin_config_t *_pin_config);
StdReturnType gpio_set_pin_high(const pin_config_t *_pin_config);
StdReturnType gpio_set_pin_low(const pin_config_t *_pin_config);


#if GPIO_PORT_MODE == ENABLE
StdReturnType gpio_port_direction_intialize(port_index_t port, uint8_t direction);
StdReturnType gpio_port_get_direction_status(port_index_t port, uint8_t *direction_status);
StdReturnType gpio_port_write_logic(port_index_t port, uint8_t logic);
StdReturnType gpio_port_read_logic(port_index_t port, uint8_t *logic);
StdReturnType gpio_port_toggle_logic(port_index_t port);

#endif

#endif	/* MCAL_GPIO_H */


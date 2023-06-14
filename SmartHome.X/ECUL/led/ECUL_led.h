/* 
 * File:   ECUL_led.h
 * Author: sacri
 *
 * Created on June 14, 2023, 6:28 PM
 */

#ifndef ECUL_LED_H
#define	ECUL_LED_H

/*        *********Includes***************        */
#include"../../MCAL/GPIO/MCAL_GPIO.h"


/************     DataTypes declarations  ********/
typedef struct{
    uint8_t led_port :3;
    uint8_t led_pin_index :3;

}led_config_t;

/*********       Function declarations    *********/
StdReturnType led_init(const led_config_t *led);
StdReturnType led_on(const led_config_t *led);
StdReturnType led_off(const led_config_t *led);

#endif	/* ECUL_LED_H */


/* 
 * File:   MCAL_Interrupts_external.h
 * Author: sacri
 *
 * Created on June 13, 2023, 10:08 PM
 */

#ifndef MCAL_INTERRUPTS_EXTERNAL_H
#define	MCAL_INTERRUPTS_EXTERNAL_H

/*   ******************     Includes  *********************       */
#include"../PIC18_config.h"
#include"MCAL_Interrupt_config.h"


/**********   Data types Declarations ***********************     */
typedef enum {
    FALLING_EDGE = 0,
    RISING_EDGE
}Edge_select;

typedef enum {
    LOW_PRIORITY = 0,
    HIGH_PRIORITY
}Priority_select;


typedef struct{
    void (*interrupt_handler) (void);
    Edge_select edge;
}Ext_INT0_t;


typedef struct{
    void (*interrupt_handler) (void);
    Edge_select edge;
    Priority_select priority;
}Ext_INT1_t;

typedef struct{
    void (*interrupt_handler) (void);
    Edge_select edge;
    Priority_select priority;
}Ext_INT2_t;




/*  *********************** Interfaces ***********************    */
StdReturnType Init_Ext_INT0(Ext_INT0_t * int0_obj);
StdReturnType Init_Ext_INT1(Ext_INT1_t * int1_obj);
StdReturnType Init_Ext_INT2(Ext_INT2_t * int2_obj);



#endif	/* MCAL_INTERRUPTS_EXTERNAL_H */


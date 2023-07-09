
/************************INCLUDES************************************/
#include "UserInterfaces.h"
/*******************************************************************/



/****************** GLOBAL variables***************************/
extern chr_lcd_4bit_t lcd1;
extern keypad_t keypad1;
void (*interfaceHandler)(void) = NULL;
uint8 samefunctionFlage = 1;
/*******************************************************************/



/******************Functions implementaions***************************/
void mainUI (){
    interfaceHandler = homeUI;
    while(1){
        interfaceHandler();
    }
}



void homeUI(){
    Std_ReturnType ret = E_NOT_OK;
    if(!samefunctionFlage)ret = lcd_4bit_clear(&lcd1);
    
    
    volatile uint8 keypad_val = 0;
    ret = lcd_4bit_send_string_pos(&lcd1, 1, 4, "Welcome Home");
    ret = lcd_4bit_send_string_pos(&lcd1, 4, 1, "Settings:#");
    ret = keypad_get_value(&keypad1, &keypad_val);
    
    if('#'==keypad_val){
        interfaceHandler = passwordUI;
        samefunctionFlage = 0;
    }
    else{
        interfaceHandler = homeUI;
        samefunctionFlage = 1;
    }
    
}



void settingsUI(void){
    Std_ReturnType ret = E_NOT_OK;
    if(!samefunctionFlage)ret = lcd_4bit_clear(&lcd1);
    
    volatile uint8 keypad_val = 0;
    ret = lcd_4bit_send_string_pos(&lcd1, 1, 4, "Settings");
    ret = lcd_4bit_send_string_pos(&lcd1, 4, 1, "back:*");
    ret = keypad_get_value(&keypad1, &keypad_val);
    if('*'==keypad_val){
        interfaceHandler = homeUI;
        samefunctionFlage = 0;
    }
    else{
        interfaceHandler = settingsUI;
        samefunctionFlage = 1;
    }

}


void passwordUI(){
    
    uint8 password[4] = {0},rpassword[4] = {'3','5','2','4'},i = 0,errFlage = 0;
     
    
    Std_ReturnType ret = E_NOT_OK;
    ret = lcd_4bit_clear(&lcd1);
    ret = lcd_4bit_send_string_pos(&lcd1, 1, 1, "Enter Password:");
    ret = lcd_4bit_send_string_pos(&lcd1, 4, 1, "back:*");
    for(i=0;i<4;i++){
        __delay_ms(180);
       ret = keypad_get_value(&keypad1, &(password[i]));
       ret = lcd_4bit_send_char_data_pos(&lcd1,1, 16+i, 'X');
       if(password[i] != rpassword[i])errFlage =1;
    }
    
    if(errFlage){
        ret = lcd_4bit_clear(&lcd1);
        ret = lcd_4bit_send_string_pos(&lcd1, 1, 4, "Wrong Password");
        __delay_ms(1500);
        interfaceHandler = homeUI;  
    }
    else{
        
        interfaceHandler = settingsUI;
    
    }
    
    


}

/*******************************************************************/
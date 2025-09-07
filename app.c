#include <stdio.h>
#include <string.h>
#include "led.h"


void app(Led_t *led, char *input){
    
    char *token;
    int led_check = 0;
    int on = 0;
    int off = 0;
    int help = 0;
    int status = 0;
    int exit = 0;
    token = strtok(input, " \n");

    while(token != NULL)
    {

        if(strcmp(token, "led") == 0)
        {
            led_check = 1;
        }
        if(strcmp(token, "on") == 0)
        {
            on = 1;
        }
        if(strcmp(token, "off") == 0)
        {
            off = 1;
        }
        if(strcmp(token, "status") == 0)
        {
            status = 1;
        }
        if(strcmp(token, "help") == 0)
        {
            help = 1;
        }
        if(strcmp(token, "exit") == 0)
        {
            exit = 1;
        }

        token = strtok(NULL, " \n");        
    }

    if(((led_check == 1) && (on == 1)) || ((led_check == 1) && (off == 1)) || status == 1 || help == 1 || exit == 1)
    {
        if(help == 1)
        {
            printf("Type [led on,led off] to turn led on or off\nType [status] to see led status\nType [exit] to quit program\n");
        }

        switch(led->state)
        {   

        case LED_OFF:
        {
            if((led_check == 1) && (on == 1))
            {
                led->state = LED_ON;
            }
            if((led_check == 1) && (off == 1))
            {
                printf("Not Done! led is already off!\n");
            }

            if(status == 1)
            {
                printf("Led is off ! \n");
            }

        }
        break;


        case LED_ON:
        {
            if((led_check == 1) && (off == 1))
            {
                led->state = LED_OFF;
            }
            if((led_check == 1) && (on == 1))
            {
                printf("Not Done! led is already on!\n");
            }
            if(status == 1)
            {
                printf("Led is on ! \n");
            }
            
        }
        break;

        }


    }
    else
    {
        printf("invalid cpmmand\n");
    }

    
}
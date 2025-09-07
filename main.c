#include <stdio.h>
#include <string.h>
#include "led.h"
#include "app.h"

int main()
{
    Led_t led;
    char input[40]; 
    memset(input, 0, sizeof(input));

    Led_init(&led);

    printf(">");
    while(strcmp(input, "exit") != 0)
    {
        fgets(input, sizeof(input), stdin);
        app(&led, input);
    }
    

    return 0;
}
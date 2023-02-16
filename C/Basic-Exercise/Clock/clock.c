#include "clock.h"
#include <stdio.h>
#include <string.h>

/*
typedef struct {
   char text[MAX_STR_LEN];
} clock_t;
*/
// Expected: "08:00"
clock_t clock_create(int hour, int minute)
{
    
    hour += minute/60;
    minute %= 60;
    if(minute < 0){
        minute += 60;
        hour -= 1;
    }
    hour %= 24;
    if(hour < 0){
        hour += 24;
    }
    clock_t clock;
    sprintf(clock.text, "%02d:%02d", hour, minute);
    
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
    int hour = 0;
    int minute = 0;

    // Extraer la hora y los minutos actuales del reloj
    sscanf(clock.text, "%d:%d", &hour, &minute);

    // Agregar los minutos al reloj
    minute += minute_add;

    // Calcular la nueva hora y los minutos
    hour += minute / 60;
    minute = minute % 60;

    // Ajustar la hora si es necesario
    hour = hour % 24;

    // Crear un nuevo reloj con la hora y los minutos actualizados
    return clock_create(hour, minute);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    int hour = 0;
    int minute = 0;

    // Extraer la hora y los minutos actuales del reloj
    sscanf(clock.text, "%d:%d", &hour, &minute);

    // Restar los minutos al reloj
    minute -= minute_subtract;

    // Calcular la nueva hora y los minutos
    if (minute < 0)
    {
        minute += 60;
        hour--;
    }
    if (hour < 0)
    {
        hour += 24;
    }

    // Crear un nuevo reloj con la hora y los minutos actualizados
    return clock_create(hour, minute);
}

bool clock_is_equal(clock_t a, clock_t b)
{

    // Comparar las cadenas de caracteres de los dos relojes
    if (strcmp(a.text, b.text) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
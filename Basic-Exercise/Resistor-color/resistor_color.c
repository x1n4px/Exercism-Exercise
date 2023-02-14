#include "resistor_color.h"

static resistor_band_t resistor_band_array[] = 
{BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};


int color_code(resistor_band_t color){
     if ((color >= BLACK) && (color <= WHITE))
      return resistor_band_array[color];
   else
      return 0xFF;
}

const resistor_band_t * colors(void){
    return &resistor_band_array[0];
}

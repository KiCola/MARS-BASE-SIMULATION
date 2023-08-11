#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>

typedef struct energy
{
    int sun_e;
    int nuclear_e;
    int wind_e;
    int geothermal_e;
}ENERGY;

void energy();
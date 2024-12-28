#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "weather_utils.h"

int mintemp(WeatherTable a){
    int min = a[0][0][0]._min_temp;
    for(unsigned int año = 0; año < YEARS ; año++)
    {
     for (unsigned int mes = 0; mes < MONTHS; mes++)
     {
        for (unsigned int dia = 0; dia < DAYS; dia++)
        {
            if (min > a[año][mes][dia]._min_temp)
            {
                min = a[año][mes][dia]._min_temp;
            }
        }
     }
    }
    return min;
}

void maxtemp_por_año(WeatherTable a, int output[YEARS]){
    for (unsigned int año = 0; año < YEARS; año++)
    {
        int maxtemp = a[0][0][0]._max_temp;
        for (unsigned int mes = 0; mes < MONTHS; mes++)
        {
            for (unsigned int dia = 0; dia < DAYS; dia++)
            {
                if (maxtemp < a[año][mes][dia]._max_temp)
                {
                    maxtemp = a[año][mes][dia]._max_temp;
                }
                
            }
            
        }
        output[año] = maxtemp;
    }
}
void maxprec(WeatherTable a, int output[YEARS]){
    month_t maxmes;
    int precmax;
    for (unsigned int año = 0; año < YEARS; año++)
    {
        int maxprec = 0;
        maxmes = january;
        for (unsigned int mes = 0; mes < MONTHS; mes++)
        {
            precmax = 0;
            for (unsigned int dia = 0; dia < DAYS; dia++)
            { 
                precmax = precmax + a[año][mes][dia]._rainfall;  
            }
            if (maxprec < precmax)
            {
                maxprec = precmax;
                maxmes = mes;
            }
        }
        output[año] = maxmes;
    }
}
void array_dump2(int a[], int length){
    fprintf(stdout, "%u\n", length);
    for (int i = 0u; i < length; ++i) {
        fprintf(stdout, "%i", a[i]);
        if (i < length - 1) {
            fprintf(stdout, " ");
        } else {
            fprintf(stdout, "\n");
        }
    }
}
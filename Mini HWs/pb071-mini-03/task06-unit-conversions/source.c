#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 03: Unit conversions
 * ---------------
 * Author: Erik Moravec
 * Email:  xmoravec@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Your task is to implement a few very simple functions that will be used
 * for conversion between metric and imperial units.
 * Always implement conversion function for both directions!
 *
 * All functions take one float as an argument and all (except print_float)
 * return value of type float.
 * Do not forget to uncomment lines in the main() function once you are done!
 * Do not edit the main() function in other manner than uncommenting
 */

/*
 * Conversion 1: Temperature
 * temperature in °C = (5 / 9) * (temperature in °F - 32)
 */

float fahrenheit_to_celsius(float temperature){
    return (5 / 9) * (temperature - 32 );
}

float celsius_to_fahrenheit(float temperature){
    return (temperature) * (9 / 5) + 32;
}

/*
 * Conversion 2: Weight
 * 1 kg = 2,205 pounds
 */

float kilograms_to_pounds(float weight){
    return weight * 2.205;
}

float pounds_to_kilograms(float weight){
    return weight / 2.205;
}

/*
 * Conversion 3: Length
 * 1 km = 0,6214 mile
 */

float kilometres_to_miles(float distance){
    return distance * 0.6214;
}

float miles_to_kilometres(float distance){
    return distance / 0.6214;
}

/*
 * Conversion 4: Length vol. 2
 * 1 m = 3,281 feet
 */

float meters_to_feet(float lenght){
    return lenght * 3.281;
}

float feet_to_meters(float lenght){
    return lenght / 3.281;
}

/*
 * Function 5: print_float
 * Prints a float (and a newline) on the output with
 * six floating-point numbers precision (default for printf).
 */

void print_float(float number){
    printf("%lf", number);
    printf("\n");
}

int main(void)
{
    
    print_float(celsius_to_fahrenheit(58));
    print_float(fahrenheit_to_celsius(celsius_to_fahrenheit(0)));
    print_float(kilograms_to_pounds(5));
    print_float(pounds_to_kilograms(384));
    print_float(kilometres_to_miles(476));
    print_float(miles_to_kilometres(25));
    print_float(meters_to_feet(feet_to_meters(89)));
    print_float(feet_to_meters(22));
    
    return 0;
}

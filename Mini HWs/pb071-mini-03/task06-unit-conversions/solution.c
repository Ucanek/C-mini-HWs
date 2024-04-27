#include <stdio.h>
#include <stdlib.h>

/**
 * unit-conversions
 *
 * \author Erik Moravec
 */

/*
 * It is better to use global constants for conversion here, because
 * they do not change during program execution, and it is easier
 * to check (and eventually edit) them.
 * Note: The const keyword assures that variable is never modified
 * during execution. You will learn about it later.
 * Note: The constants are defined as doubles for better precision.
 * If defined as floats, the results are different (try for yourself).
 */

const double KILOGRAM_TO_POUNDS = 2.205;
const double KILOMETER_TO_MILES = 0.6214;
const double METER_TO_FEET = 3.281;

float fahrenheit_to_celsius(float f)
{
    return (5.0 / 9.0) * (f - 32);
}

float celsius_to_fahrenheit(float c)
{
    return (9.0 / 5.0) * c + 32;
}

float kilograms_to_pounds(float kg)
{
    return kg * KILOGRAM_TO_POUNDS;
}

float pounds_to_kilograms(float pounds)
{
    return pounds / KILOGRAM_TO_POUNDS;
}

float kilometres_to_miles(float km)
{
    return km * KILOMETER_TO_MILES;
}

float miles_to_kilometres(float miles)
{
    return miles / KILOMETER_TO_MILES;
}

float meters_to_feet(float m)
{
    return m * METER_TO_FEET;
}

float feet_to_meters(float ft)
{
    return ft / METER_TO_FEET;
}

void print_float(float num)
{
    printf("%f\n", num);
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

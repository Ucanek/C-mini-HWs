#include <stdio.h>
#include <stdlib.h>

/**
 * vectors
 *
 * \author Adam Považanec
 */

/*
 * Note that the structure with vector3 alias does not have a name.
 */

typedef struct
{
    int x;
    int y;
    int z;
} vector3;

vector3 add(vector3 a, vector3 b)
{
    vector3 new_vec = {
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z
    };
    return new_vec;
}

vector3 multiply(vector3 a, int b)
{
    vector3 new_vec = {
        .x = a.x * b,
        .y = a.y * b,
        .z = a.z * b
    };
    return new_vec;
}

int dot(vector3 a, vector3 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

vector3 cross(vector3 a, vector3 b)
{
    vector3 new_vec = {
        .x = (a.y * b.z) - (a.z * b.y),
        .y = (a.z * b.x) - (a.x * b.z),
        .z = (a.x * b.y) - (a.y * b.x)
    };
    return new_vec;
}

vector3 load_vector(char vi)
{
    vector3 ret;
    printf("Please insert vector %c (x, y, z):\n", vi);
    if (scanf("%d %d %d", &ret.x, &ret.y, &ret.z) != 3) {
        fprintf(stderr, "Reading error\n");
    }

    return ret;
}

void print_vector(vector3 vec, char operation[])
{
    printf("Resulting vector (%s): ", operation);
    printf("%d %d %d\n", vec.x, vec.y, vec.z);
}

int main(void)
{
    vector3 a = load_vector('A');
    vector3 b = load_vector('B');

    print_vector(add(a, b), "addition");
    print_vector(multiply(a, 2), "multiplication");
    printf("Resulting vector (dot product): %d\n", dot(a, b));
    print_vector(cross(a, b), "cross product");

    return EXIT_SUCCESS;
}

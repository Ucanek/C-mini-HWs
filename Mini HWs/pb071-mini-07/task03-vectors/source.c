#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 07: Vectors
 * ---------------
 * Author: Adam Považanec 
 * Email:  469045@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to implement some basic operations with vectors - addition,
 * multiplication by a constant, dot product and cross product.
 * If you forgot how to work with vectors you can find information here:
 * https://www.3dgep.com/3d-math-primer-for-game-programmers-vector-operations/
 *
 * There is a defined structure 'vector3', which represents vectors in 
 * 3-dimensional space.
 *
 * Do not modify input vectors, create new ones.
 * 
 * Do not change anything else except functions add, multiply, dot and cross.
 *
 * You can do your own testing with compiled binary, just follow the
 * instructions after executing it.
 */

typedef struct
{
    int x;
    int y;
    int z;
} vector3;

vector3 add(vector3 a, vector3 b)
{
    vector3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    
    return result;
}

vector3 multiply(vector3 a, int b)
{
    vector3 result;
    result.x = a.x * b;
    result.y = a.y * b;
    result.z = a.z * b;

    return result;
}

int dot(vector3 a, vector3 b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

vector3 cross(vector3 a, vector3 b)
{
    vector3 result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;

    return result;
}

vector3 load_vector(char vi)
{
    vector3 ret = {0, 0, 0};
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

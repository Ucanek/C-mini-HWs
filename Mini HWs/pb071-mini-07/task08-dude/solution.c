#include <stdio.h>
#include <stdlib.h>

/**
 * dude
 *
 * \author Jakub Horváth
 */

/*
 * Just a lot of enums - note that naming their items with prefix makes those
 * items very recognizable to which enum they belong.
 */

typedef enum hair_types
{
    HAIR_SPIKY,
    HAIR_MOHAWK,
    HAIR_MESSY
} hair;

typedef enum face_types
{
    FACE_BORED,    // (¬_¬)
    FACE_CONFUSED, // (°_o)
    FACE_EYESROLL, // (◔_◔)
    FACE_HAPPY     // (^_^)
} face;

typedef enum shirt_types
{
    SHIRT_CASUAL,
    SHIRT_FORMAL,
    SHIRT_NUDE
} shirt;

typedef struct attributes
{
    hair hair;
    shirt shirt;
    face face;
} person;

void print_dude(person p)
{
    switch (p.hair) {
    case HAIR_MESSY:
        printf("    \\|/ \n");
        break;
    case HAIR_MOHAWK:
        printf("    /|\\ \n");
        break;
    case HAIR_SPIKY:
        printf("    ||| \n");
        break;
    default:
        break;
    }

    switch (p.face) {
    case FACE_BORED:
        printf("   (¬_¬)\n");
        break;
    case FACE_HAPPY:
        printf("   (^_^)\n");
        break;
    case FACE_EYESROLL:
        printf("   (◔_◔)\n");
        break;
    case FACE_CONFUSED:
        printf("   (°_o)\n");
        break;
    default:
        break;
    }

    switch (p.shirt) {
    case SHIRT_FORMAL:
        printf("   /|||\\ \n");
        printf("  / ||| \\ \n");
        break;
    case SHIRT_NUDE:
        printf("   /| |\\ \n");
        printf("  / |.| \\ \n");
        break;
    case SHIRT_CASUAL:
        printf("   /| |\\ \n");
        printf("  / | | \\ \n");
        break;
    default:
        break;
    }

    printf("    | |\n");
    printf("   _| |_\n");
}

int main(void)
{
    // Task:
    
    person p;
    p.face = FACE_HAPPY;
    p.hair = HAIR_SPIKY;
    p.shirt = SHIRT_CASUAL;

    print_dude(p);

    return EXIT_SUCCESS;
}

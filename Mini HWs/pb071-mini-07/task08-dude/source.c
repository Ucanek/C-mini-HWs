#include <stdio.h>
#include <stdlib.h>

/* Minihomework 07: Build your dude
 * ---------------
 * Author: Jakub Horváth
 * Email:  456438@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ----------------------------------------------------------------------------
 *
 * Your task is to create a structure representing dude. You will also need
 * to create enumerations representing hair, shirt and face.
 *
 * The features required for each enum are stated in corresponding TODO. Do not
 * forget to copy with coding style when naming enum items.
 *
 * Finally, implement the task in main function.
 *
 * For print use provided function 'print_dude'
 *
 * Do not change anything else except lines starting with the TODO.
 */

/* TODO hair enum with items {messy, spiked, mohawk} here */
typedef enum hair_types{
    HAIR_MESSY,
    HAIR_MOHAWK,
    HAIR_SPIKY
} hair;

/* TODO face enum with items {bored, confused, eyesroll, happy} here */
typedef enum face_types{
    FACE_BORED,
    FACE_CONFUSED,
    FACE_EYESROLL,
    FACE_HAPPY
} face;

/* TODO shirt enum with items {casual, formal, nude} here */
typedef enum shirt_types{
    SHIRT_CASUAL,
    SHIRT_FORMAL,
    SHIRT_NUDE
} shirt;

/* TODO struct representing person here */
typedef struct attributes{
    hair hair;
    face face;
    shirt shirt;
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
    // Task: Create a person with spiky hair with a happy face wearing a casual
    // shirt (will be used for automatic tests) and print him.
    // Also, feel free to make your custom dude :).

    /* TODO your code here */
    person p;
    p.hair = HAIR_SPIKY;
    p.face = FACE_HAPPY;
    p.shirt = SHIRT_CASUAL;
    print_dude(p);

    return EXIT_SUCCESS;
}

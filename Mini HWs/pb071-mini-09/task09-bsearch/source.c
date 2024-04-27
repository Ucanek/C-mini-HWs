#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Minihomework 09: bsearch
 * ----------------------------------------------------------------------------
 * Author: Ondřej Metelka
 * Email:  514098@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * In this exercise your task is to use the 'bsearch' function from <stdlib.h>
 * to find similar movie characters.
 *
 * Each character has a name, race and the movie it appeared in (see the
 * 'character' struct). For each of the latter two attributes, you need to implement
 * a comparing function (if the two given instances have the attribute of the
 * same value, return 0, positive if the first is bigger, negative otherwise).
 *
 * Finally, complete the main function with calls to your implemented code.
 */

enum race
{
    RACE_HUMAN = 0,
    RACE_MAGIC_CREATURE = 1,
    RACE_UNKNOWN = 2
};


 typedef struct
{
    char name[128];
    enum race race;
    char movie[128];
} character;

/* TODO compare_race function here */
/* TODO compare_movie function here */

void print_name(character *ch1)
{
    if ch1 == NULL {
        puts("Nobody in here\n");
    } else {
        printf("%s\n", ch1->name);
    }
}

int main(void)
{
    character harry = { "Harry Potter", RACE_HUMAN, "Harry Potter" };
    character et = { "E.T.", RACE_UNKNOWN, "E.T. Extraterrestrial" };
    character dobby = { "Dobby", RACE_MAGIC_CREATURE, "Harry Potter" };
    character aragorn = { "Aragorn", RACE_HUMAN, "Lord of the rings" };
    character balrog = { "Balrog", RACE_UNKNOWN, "Lord of the rings" };
    character donkey = { "Donkey", RACE_MAGIC_CREATURE, "Shrek" };
    character fiona1 = { "Fiona", RACE_HUMAN, "Shrek" };
    character fiona2 = { "Fiona", RACE_UNKNOWN, "Shrek" };

    character race_sorted[4] = { harry, aragorn, donkey, fiona2 };

    character *found = (character *) bsearch(/* TODO search for character of the same race as balrog */);
    print_name(found);

    found = (character *) bsearch(/* TODO search for character of the same race as fiona1 */);
    print_name(found);

    character movie_sorted[5] = { et, dobby, harry, balrog, donkey };

    found = (character *) bsearch(/* TODO search for character from the same movie as aragorn */);
    print_name(found);

    found = (character *) bsearch(/* TODO search for character from the same movie as fiona2 */);
    print_name(found);

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * bsearch
 *
 * \author Ondřej Metelka
 */

/*
 * Same as in qsort, the algorithm as well as complexity is implementation
 * defined (so it does not even have to be binary search).
 */

enum race
{
    RACE_HUMAN = 0,
    RACE_MAGIC_CREATURE = 1,
    RACE_UNKNOWN = 2
};


typedef struct
{
    const char name[128];
    enum race race;
    const char movie[128];
} character;

int compare_race(const void *ch1, const void *ch2)
{
    return ((character *) ch1)->race - ((character *) ch2)->race;
}

int compare_movie(const void *ch1, const void *ch2)
{
    return strcmp(((character *) ch1)->movie, ((character *) ch2)->movie);
}

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

    character *found = (character *) bsearch(&balrog, race_sorted, 4, sizeof(character), &compare_race);
    print_name(found);

    found = (character *) bsearch(&fiona1, race_sorted, 4, sizeof(character), &compare_race);
    print_name(found);

    character movie_sorted[5] = { et, dobby, harry, balrog, donkey };

    found = (character *) bsearch(&aragorn, movie_sorted, 5, sizeof(character), &compare_movie);
    print_name(found);

    found = (character *) bsearch(&fiona2, movie_sorted, 5, sizeof(character), &compare_movie);
    print_name(found);

    return EXIT_SUCCESS;
}

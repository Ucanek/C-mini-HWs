#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Minihomework 07: Family Tree
 * ---------------
 * Author: Jakub Horváth
 * Email:  456438@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ----------------------------------------------------------------------------
 *
 * In this task, you will be working with family relations using struct
 * references and dynamic allocation.
 *
 * First, create a type called "name_string" which will  be of type char*.
 *
 * Then complete the tasks described in the main() function.
 *
 * You will work with struct attribute referencing and dynamic de/allocation
 * of struct objects.
 *
 * Do not change anything else except main function (lines with TODO)
 */

typedef char* name_string;

typedef struct member_struct
{
    name_string name;
    struct member_struct *married_to;
    struct member_struct *child1;
    struct member_struct *child2;
    struct member_struct *mother;
    struct member_struct *father;
} family_member;

family_member *create_eve(void);
void dealloc(family_member *person);
void dfs_dealloc(family_member *person);
void ignac_check(family_member *eve);

int main(void)
{
    family_member *eve = create_eve();

    // Task 1: Print the name of the family member who is the father of the
    // person that Eve's child2 is married to. The correct answer is "Martin".
    printf("%s\n", eve->child2->married_to->father->name);

    // Task 2: Print the name of the child of the person who Eve is married to.
    // The correct answer is "Ivana".

    printf("%s\n", eve->married_to->child1->name);

    // Task 3: Give a new child1 to the child1 of eve. His name should be
    // "Ignac". This means allocate a new object and a name_string attribute.
    // Assign the required relations and use strcpy to assign the name

    eve->child1->child1 = malloc(sizeof(family_member));
    eve->child1->child1->name = malloc(10);
    strcpy(eve->child1->child1->name, "Ignac");

    ignac_check(eve);

    // Task 4: Free (only) the memory that you have allocated for Ignac.

    free(eve->child1->child1);
    free(eve->child1->child1->name);

    dealloc(eve);
    return EXIT_SUCCESS;
}

void dealloc(family_member *person)
{
    free(person->child2->married_to->father->name);
    free(person->child2->married_to->father);
    free(person->child2->married_to->name);
    free(person->child2->married_to);
    free(person->married_to->name);
    free(person->married_to);
    person->child1->child1 = NULL;
    dfs_dealloc(person);
}

void dfs_dealloc(family_member *person)
{
    if (person->child1 != NULL) {
        dfs_dealloc(person->child1);
    }
    if (person->child2 != NULL) {
        dfs_dealloc(person->child2);
    }
    free(person->name);
    free(person);
}

family_member *create_eve(void)
{
    family_member *eve = malloc(sizeof(family_member));
    family_member *jozef = malloc(sizeof(family_member));
    family_member *ivana = malloc(sizeof(family_member));
    family_member *jano = malloc(sizeof(family_member));
    family_member *zuzana = malloc(sizeof(family_member));
    family_member *peter = malloc(sizeof(family_member));
    family_member *martin = malloc(sizeof(family_member));

    eve->name = malloc(10);
    strcpy(eve->name, "Eva");
    eve->married_to = jozef;
    eve->child1 = ivana;
    eve->child2 = jano;
    eve->father = NULL;
    eve->mother = NULL;

    jozef->name = malloc(10);
    strcpy(jozef->name, "Jozef");
    jozef->married_to = eve;
    jozef->child1 = ivana;
    jozef->child2 = jano;
    jozef->father = NULL;
    jozef->mother = NULL;

    ivana->name = malloc(10);
    strcpy(ivana->name, "Ivana");
    ivana->father = jozef;
    ivana->mother = eve;
    ivana->child1 = NULL;
    ivana->child2 = NULL;
    ivana->married_to = NULL;

    jano->name = malloc(10);
    strcpy(jano->name, "Jano");
    jano->mother = eve;
    jano->father = jozef;
    jano->child1 = peter;
    jano->married_to = zuzana;
    jano->child2 = NULL;

    zuzana->name = malloc(10);
    strcpy(zuzana->name, "Zuzana");
    zuzana->father = martin;
    zuzana->child1 = peter;
    zuzana->married_to = jano;
    zuzana->child2 = NULL;
    zuzana->mother = NULL;

    martin->name = malloc(10);
    strcpy(martin->name, "Martin");
    martin->child1 = zuzana;
    martin->child2 = NULL;
    martin->father = NULL;
    martin->mother = NULL;
    martin->married_to = NULL;

    peter->name = malloc(10);
    strcpy(peter->name, "Peter");
    peter->mother = zuzana;
    peter->father = jano;
    peter->child1 = NULL;
    peter->child2 = NULL;
    peter->married_to = NULL;

    return eve;
}

void ignac_check(family_member *eve)
{
    if (eve->child1->child1 == NULL) {
        printf("NOK\n");
        return;
    }
    if (strcmp(eve->child1->child1->name, "Ignac") != 0) {
        printf("NOK\n");
        return;
    }
    printf("OK\n");
}

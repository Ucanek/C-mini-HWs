#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * qsort
 *
 * \author Martin Piatka <445597@mail.muni.cz>
 */

/*
 * Although the function is named qsort by Quicksort algorithm, the real
 * sorting algorithm it uses depends on implementation and its complexity
 * nor type is guaranteed.
 */

struct person
{
    char name[128];
    int age;
    int height;
};

int compare_age(const void *a, const void *b)
{
    const struct person *p1 = (struct person *) a;
    const struct person *p2 = (struct person *) b;
    return p1->age - p2->age;
}

int compare_height(const void *a, const void *b)
{
    const struct person *p1 = (struct person *) a;
    const struct person *p2 = (struct person *) b;
    return p1->height - p2->height;
}

int compare_name(const void *a, const void *b)
{
    const struct person *p1 = (struct person *) a;
    const struct person *p2 = (struct person *) b;
    return strcmp(p1->name, p2->name);
}

void sort(struct person *array,
        size_t count,
        int (*comparator)(const void *, const void *))
{
    qsort(array, count, sizeof(struct person), comparator);
}

/*
 * This array contains the mapping between the string parameter given on the
 * command line and corresponding compare function
 */
const struct
{
    const char *const type;
    int (*comparator)(const void *, const void *);
} COMPARATOR_FUNCTIONS[3] = {
    { "age", compare_age },
    { "name", compare_name },
    { "height", compare_height }
};

/*
 * This function searches for the corresponding compare function in
 * the COMPARATOR_FUNCTIONS array. If it doesn't find anything it returns NULL
 */
int (*get_comparator_function(const char *const type))(const void *, const void *)
{
    for (size_t i = 0; i < sizeof(COMPARATOR_FUNCTIONS) / sizeof(COMPARATOR_FUNCTIONS[0]); i++) {
        if (strcmp(COMPARATOR_FUNCTIONS[i].type, type) == 0) {
            return COMPARATOR_FUNCTIONS[i].comparator;
        }
    }

    return NULL;
}

/*
 * The main function takes care of input and output. It uses the get_comparator_function
 * function to find the compare function. Then it calls the sort function
 * which you have to implement.
 */
int main(int argc, char **argv)
{
    size_t count;

    if (argc != 2) {
        fprintf(stderr, "Invalid parameter!\n");
        return EXIT_SUCCESS; //Tests require return code 0
    }

    int (*comparator)(const void *, const void *) = get_comparator_function(argv[1]);
    if (!comparator) {
        fprintf(stderr, "Invalid parameter!\n");
        return EXIT_SUCCESS; //Tests require return code 0
    }

    if (scanf(" %zu", &count) != 1) {
        fprintf(stderr, "Invalid input!\n");
        return EXIT_SUCCESS; //Tests require return code 0
    }

    struct person *array = malloc(count * sizeof(struct person));
    if (!array) {
        fprintf(stderr, "Malloc failed!\n");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < count; i++) {
        if (scanf(" %127s", array[i].name) != 1 || scanf(" %d", &array[i].age) != 1
                || scanf(" %d", &array[i].height) != 1) {
            fprintf(stderr, "Read failed!\n");
            return EXIT_FAILURE;
        }
    }

    sort(array, count, comparator);

    for (size_t i = 0; i < count; i++) {
        printf("Name: %s\n", array[i].name);
        printf("Height: %d\n", array[i].height);
        printf("Age: %d\n", array[i].age);
        putchar('\n');
    }

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Structured students
 *
 * \author Peter Navrátil
 */

/*
 * The greatest portion of the code contains checking the input.
 */

enum sex_t
{
    male,
    female
};

typedef struct student_info
{
    unsigned uco;
    enum sex_t sex;
    bool is_repeating;
} student_info_t;

typedef struct subject_statistics
{
    unsigned male_students;
    unsigned female_students;
    unsigned repeating_students;
} subject_statistics_t;

student_info_t *get_input(int count)
{
    student_info_t *students = malloc(count * sizeof(student_info_t));
    int i;
    for (i = 0; i < count; i++) {
        students[i].uco = 0;
        students[i].sex = male;
        students[i].is_repeating = false;
        if (scanf(" %d", &students[i].uco) != 1) {
            fprintf(stderr, "Reading error\n");
            return students;
        }

        char sex;
        if (scanf(" %c", &sex) != 1) {
            fprintf(stderr, "Reading error\n");
            return students;
        }
        if (sex == 'M') {
            students[i].sex = male;
        } else {
            students[i].sex = female;
        }

        char is_repeating;
        if (scanf(" %c", &is_repeating) != 1) {
            fprintf(stderr, "Reading error\n");
            return students;
        }
        if (is_repeating == 'T') {
            students[i].is_repeating = true;
        } else {
            students[i].is_repeating = false;
        }
    }
    return students;
}

subject_statistics_t aggregate(student_info_t *students, int count)
{
    subject_statistics_t stats = { 0, 0, 0 };
    int i;
    for (i = 0; i < count; i++) {
        if (students[i].sex == male) {
            stats.male_students++;
        } else {
            stats.female_students++;
        }
        if (students[i].is_repeating) {
            stats.repeating_students++;
        }
    }
    return stats;
}

void pretty_print(subject_statistics_t stats)
{
    printf("Subject code: PB071\n");
    printf("The number of male students: %d\n", stats.male_students);
    printf("The number of female students: %d\n", stats.female_students);
    printf("The number of repeating students: %d\n", stats.repeating_students);
}

int main(void)
{
    int count;
    if (scanf(" %d", &count) != 1) {
        fprintf(stderr, "Reading error\n");
        return EXIT_FAILURE;
    }

    student_info_t *students = get_input(count);
    subject_statistics_t stats = aggregate(students, count);

    pretty_print(stats);
    free(students);

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 07: Structured students
 * ---------------
 * Author: Peter Navrátil
 * Email:  445700@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ----------------------------------------------------------------------------
 *
 * Your assignment in this task is to create a simple program that will
 * collect and aggregate info about N students.
 *
 * Firstly, you have to parse the input file into student_info structs
 * with get_input function.
 *
 * Afterward you need to count the number of males, females and repeating
 * students with aggregate function. You should save this info into
 * subject_statistics struct.
 *
 * Statistics will then be printed out by pretty_print function.
 *
 * The input file is structured as follows:
 *  - first line contains only 1 number N, representing how many students are
 *    going to be processed.
 *  - next lines contain info about N students (each value on separate line):
 *    - uco (unsigned int)
 *    - sex (one char 'M' or 'F'), you should use the provided enum sex_t
 *    - whether the student is repeating (one char 'T' or 'F')
 *
 * Example:
 *   2
 *   445700
 *   M
 *   F
 *   999999
 *   F
 *   T
 *
 * - Output for this example should be:
 *   "Subject code: PB071\n"
 *   "The number of male students: 1\n"
 *   "The number of female students: 1\n"
 *   "The number of repeating students: 1\n"
 *
 * You can (have to) modify all functions and structs marked with TODO
 */

enum sex_t
{
    male,
    female
};

typedef struct student_info
{
    unsigned int uco;
    char sex;
    char repeating;
} student_info_t;

typedef struct subject_statistics
{
    int male_students;
    int female_students;
    int repeating_students;
} subject_statistics_t;

student_info_t *get_input(int count)
{
    student_info_t *students = malloc(count * sizeof(student_info_t));
    if (students == NULL){
        return NULL;
    }

    for (int i = 0; i < count; i++){
        scanf("%u", &students[i].uco);

        scanf(" %c", &students[i].sex);
        if (students[i].sex != 'M' && students[i].sex != 'F'){
            return NULL;
        }

        scanf(" %c", &students[i].repeating);
        if (students[i].repeating != 'T' && students[i].repeating != 'F'){
            return NULL;
        }
    }

    return students;
}

subject_statistics_t aggregate(student_info_t *students, int count)
{
    subject_statistics_t stats = {0, 0, 0};

    for (int i = 0; i < count; i++){
        if (students[i].sex == 'M'){
            stats.male_students++;
        }
        if (students[i].sex == 'F'){
            stats.female_students++;
        }
        if (students[i].repeating == 'T'){
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
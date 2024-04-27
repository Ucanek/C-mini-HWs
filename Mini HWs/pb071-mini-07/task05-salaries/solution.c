#include <stdio.h>
#include <stdlib.h>

/**
 * salaries
 *
 * \author Adam Považanec
 */

/*
 * If you want to store an array (of not fixed size) in structure, the best
 * way how to do it is to dynamically allocate the space for array and store
 * only the pointer.
 */

typedef struct employee
{
    unsigned hourly_salary;
    unsigned reported_hours;
} employee_t;

typedef struct timesheet
{
    size_t employees_num;
    employee_t *employee_report;
} timesheet_t;

size_t calculate_salaries(const timesheet_t *timesheet)
{
    size_t total = 0;
    for (unsigned i = 0; i < timesheet->employees_num; ++i) {
        size_t current_salary = timesheet->employee_report[i].hourly_salary
                * timesheet->employee_report[i].reported_hours;
        total += (current_salary > 10000) ? (unsigned) (current_salary * 0.85) : current_salary;
    }
    return total;
}

timesheet_t load_timesheet()
{
    timesheet_t timesheet = {.employees_num = 0, .employee_report = NULL};
    printf("Please insert amount of records:\n");
    if (scanf("%zu", &timesheet.employees_num) != 1) {
        fprintf(stderr, "Reading error\n");
        return timesheet;
    }
    timesheet.employee_report = calloc(timesheet.employees_num, sizeof(employee_t));

    printf("Now please insert %zu record(s):\n", timesheet.employees_num);
    for (size_t i = 0; i < timesheet.employees_num; ++i) {
        if (scanf("%u %u", &timesheet.employee_report[i].hourly_salary,
                    &timesheet.employee_report[i].reported_hours) != 2) {
            fprintf(stderr, "Reading error\n");
            return timesheet;
        }
    }

    return timesheet;
}

int main(void)
{
    timesheet_t timesheet = load_timesheet();
    printf("The total sum of salaries: %zu\n", calculate_salaries(&timesheet));
    free(timesheet.employee_report);

    return EXIT_SUCCESS;
}

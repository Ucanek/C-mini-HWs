#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 07: Calculating salaries
 * ---------------
 * Author: Adam Považanec
 * Email:  469045@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ----------------------------------------------------------------------------
 *
 * Your task is to implement function 'calculate_salaries' which calculates
 * the total sum of salaries the company has to pay out to its employees.
 * The function takes timesheet_t struct, which contains a number of employees 
 * and an array of employees' time reports (struct employee_t - contains hourly 
 * salary + reported hours).
 * 
 * Rules:
 *      - if an employee earned 10 000 or less that month, he gets the whole
 *          amount (count the whole amount)
 *      - if an employee earned more than 10 000 that month, he pays 15% tax
 *          (count whole amount - 15%)
 * 
 * There is 'load_timesheet' function provided for you which loads the
 * timesheet from stdin.
 * 
 * The input has the following structure:
 *      <number of employees>
 *      <hourly salary> <hours>
 *      <hourly salary> <hours>
 *      ...
 * 
 * So for example, if we want to load a timesheet with 2 employees (first has
 * hourly salary 10 and worked 2 hours, second has salary 250 and worked 180
 * hours), the input has to have the following structure:
 * 
 *      2
 *      10 2
 *      250 180
 *
 *      and the total sum of salaries will be (10*2) + 0,85*(250*180) = 38450
 *
 * If the salary after extracting tax is not an integer, convert it and ignore
 * the floating-point part (this is not clean and NEVER do it in homeworks,
 * but it makes the implementation easier).
 *
 * You can do your own testing with compiled binary, just follow the
 * instructions after executing it.
 *
 * Do not change anything else except function calculate_salaries.
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
    int sum_salaries = 0;
    for (int i = 0; i < timesheet->employees_num; i++){
        int total_salary = timesheet->employee_report[i].hourly_salary * timesheet->employee_report[i].reported_hours;
        if (total_salary > 10000){
            total_salary = total_salary * 0,85;
        }
        sum_salaries += total_salary;
    }
    return sum_salaries;
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

#include <stdio.h>
#include <string.h>

// Define maximum number of employees
#define MAX_EMPLOYEES 100

// Employee structure definition
struct Employee {
    char name[100];
    int empId;
    float salary;
    char jobTitle[100];
};

// Function to add an employee
void addEmployee(struct Employee employees[], int *numEmployees) {
    if (*numEmployees >= MAX_EMPLOYEES) {
        printf("Maximum number of employees reached!\n");
        return;
    }

    struct Employee emp;
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    printf("Enter Employee ID: ");
    scanf("%d", &emp.empId);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);
    printf("Enter Employee Job Title: ");
    scanf("%s", emp.jobTitle);

    employees[*numEmployees] = emp;
    (*numEmployees)++;

    printf("Employee Added Successfully!\n");
}

// Function to view employee details
void viewEmployees(struct Employee employees[], int numEmployees) {
    if (numEmployees == 0) {
        printf("No employees found!\n");
        return;
    }

    printf("Employee Details:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee ID: %d\n", employees[i].empId);
        printf("Name: %s\n", employees[i].name);
        printf("Salary: Rs%.2f\n", employees[i].salary);
        printf("Job Title: %s\n", employees[i].jobTitle);
        printf("---------------------------\n");
    }
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;
    int choice;

    do {
        printf("Employee Management System\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &numEmployees);
                break;
            case 2:
                viewEmployees(employees, numEmployees);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

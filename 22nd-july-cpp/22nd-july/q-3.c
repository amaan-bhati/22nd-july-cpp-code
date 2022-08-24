#include <stdio.h>
#include <stdlib.h>

//Structure to contain all the data members of a Employee
struct employee {
    int id;
    char name[50];
    int age;
    float basicSalary, grossSalary;
};

//Function to take input of each employee
void input(struct employee *e) {
    printf("\nEnter employee id : ");
    scanf("%d",&(e->id));
    printf("\nEnter name : ");
    scanf("%*c%[^\n]%*c",&(e->name));
    printf("\nEnter age : ");
    scanf("%d",&(e->age));
    printf("\nEnter Basic Salary : ");
    scanf("%f",&(e->basicSalary));
}

//Function to calculate Gross Salary of each employee
void calculateGrossSalary(struct employee *e, int n) {
    for(int i = 0; i < n; i++){
        float basicSalary = (e+i)->basicSalary;
        (e+i)->grossSalary =  basicSalary + 0.8*basicSalary + 0.1*basicSalary;
    }
}

//Function to display the details of all the employees in tabular format
void display(struct employee *e, int n) {
    printf("\n\n====================================================================================");
    printf("\n%-10s%-15s%-5s%20s%30s","ID","Name","Age","Basic Salary","Gross Salary");
    printf("\n====================================================================================\n");
    for(int i = 0; i < n; i++){
        printf("\n%-5d%-20s%-5d%20f%30f",(e+i)->id,(e+i)->name,(e+i)->age,(e+i)->basicSalary,(e+i)->grossSalary);
    }
}


int main() {
    
    struct employee *e;
    int n;
    printf("Enter total number of employees: ");
    scanf("%d",&n);

    e = (struct employee *) malloc(n*sizeof(struct employee));
    for(int i=0;i<n;i++)
        input(e+i);

    calculateGrossSalary(e,n);
    display(e,n);

    return 0;
}
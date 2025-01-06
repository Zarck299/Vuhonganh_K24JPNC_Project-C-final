#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
    int choice;
    int count = 0;
    int choiceAdmin;
    int currentLength;
    Student students[1000];
    Teacher teacher[1000];
    while(1){
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
    }
        switch (choice) {
            case 1:
                printf("\nYou chose Admin.\n");
                menuAdmin();
                break;
            case 2:
                printf("\nYou chose Student.\n");
                menuStudents(students, &count);
                break;
            case 3:
                printf("\nYou chose Teacher.\n");
                menuTeacher(teacher, &count);
                break;
            case 0:
                printf("\nExiting the Program...\n");
                break;
            default:
                printf("\nError!! Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}


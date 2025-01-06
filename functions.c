#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <string.h>
//logic ham functions.h
void displayMenu(){
	system("cls");
    printf("\t***Student Management System Using C***\n");
    printf("CHOOSE YOUR ROLE\n");
    printf("=========================\n");
    printf("[1] Admin.\n");
    printf("[2] Students.\n");
    printf("[3] Teacher.\n");
    printf("[0] Exit the Program.\n");
    printf("=========================\n");
    printf("\nEnter The Choice: ");
}
// Menu Admin
void menuAdmin(){
	system("cls");
	int choiceAdmin;
	printf("\n***Student Management System Using C***\n");
	printf("		Menu\n");
	printf("=================================\n");
	printf("[1]: Students management.\n");
	printf("[2]: ClassRooms managemment.\n");
	printf("[3]: Teacher management.\n");
	printf("[4]: User Guideline.\n");
	printf("[5]: About Us.\n");
	printf("[0]: Menu \n");
	printf("Enter The Choice: ");
	scanf("%d", &choiceAdmin);
	getchar();
}
// Menu chon che do
void chooseYourmode(Student students[],int *choiceAdmin,int *count,int currentLength){
	system("cls");
	do{
		menuStudents(students, count);
		scanf("%d",&choiceAdmin);
		getchar();
		switch(*choiceAdmin){
			case 1:
				displayStudents(students,count);
				break;
			case 2:	
				addStudents(students,count);
				break;
			case 3:
				searchStudentByName(students,count);
				break;
			case 4: 
				editStudents(students,&currentLength);
				break;
			case 5: 
				deleteStudents(students,&currentLength); 
				break;
			case 6:
				sortStudentsByName(students,&currentLength);
				break;
			case 0:
				break;
			default:
				printf("Lua chon khong hop le. Vui long chon lai\n");
				break;
		}	
	}while(*choiceAdmin!=0);
}
// Ham in ra danh sach sinh vien
void displayStudents(Student students[], int *count) { 
    system("cls");
	if (*count == 0) {
        printf("\nNo students in the list.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    printf("\t----------*** All Students ***----------\n");
    printf("|==========|====================|=============================|====================|=============|\n");
    printf("|    ID    |        Name        |            Email            |        Phone       |  No. Course |\n");
    printf("|==========|====================|=============================|====================|=============|\n");
    int i;
    for (i = 0; i < *count; i++) {
        printf("| %-8d | %-18s | %-27s | %-18s | %-11d |\n", 
               students[i].studentId, 
               students[i].name, 
               students[i].email,
               students[i].phoneNumber, 
               students[i].noOfcourse);
    }
    printf("|==========|====================|=============================|====================|=============|\n");
    printf("\t----------------------------------------\n");
}
// Ham them sinh vien vao danh sach co san
void addStudents(Student students[], int *count) {
    system("cls");
	if (*count >= 100) {
        printf("\nStudent list is full. Cannot add more students.\n");
        return;
    }
    printf("\nEnter New Student ID: ");
    scanf("%d", &students[*count].studentId);
    getchar(); // Clear newline left by scanf
    printf("Enter New Student Name: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0'; // Remove newline

    printf("Enter New Student Email: ");
    fgets(students[*count].email, sizeof(students[*count].email), stdin);
    students[*count].email[strcspn(students[*count].email, "\n")] = '\0'; // Remove newline

    printf("Enter New Student Phone: ");
    fgets(students[*count].phoneNumber, sizeof(students[*count].phoneNumber), stdin);
    students[*count].phoneNumber[strcspn(students[*count].phoneNumber, "\n")] = '\0'; // Remove newline

    printf("Enter Number of Courses: ");
    scanf("%d", &students[*count].noOfcourse); // Use scanf for integers
    getchar(); // Clear newline left by scanf

    (*count)++;
    printf("\nNew student added successfully!\n");
}
// Ham ket thuc 
void end(){
	system("cls");
	printf("---------Thank you---------");
	printf("---------See you soon---------");
}
// Menu Student
void menuStudents(Student students[], int *count) {
    system("cls");
	int choice;
    int currentLength;
	do {
        printf("\n*** Student Management System Using C ***\n");
        printf("\t\tStudent Menu\n");
        printf("==============================\n");
        printf("[1]: Show all students.\n");
        printf("[2]: Add a new student.\n");
        printf("[3]: Search a student.\n");
        printf("[4]: Edit a student.\n");
        printf("[5]: Delete a student.\n");
        printf("[6]: Sort students by name.\n");
        printf("[0]: Exit Menu.\n");
        printf("==============================\n");
        printf("Enter The Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayStudents(students, count);
                break;
            case 2:
                addStudents(students, count);
                break;
            case 3:
                searchStudentByName(students,count);
                break;
            case 4:
                editStudents(students,&currentLength);
                break;
            case 5:
                deleteStudents(students,&currentLength);
                break;
            case 6:
                sortStudentsByName(students,&currentLength);
                break;
            case 0:
                printf("Exiting Student Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}
//Sua thong tin sinh vien
void editStudents(Student students[], int *currentLength){
	system("cls");
	if (*currentLength == 0) {
        printf("Student list emty. Nothing to correct.\n");
        return;
    }
    int id, i, valid;
    char input[100]; // Bien lu tru du lieu nhap
    printf("Enter the Student's ID that need to edit: ");
    scanf("%d", &id);
    getchar();
//Tim sinh vien theo id
    int found = -1;
    for (i = 0; i < *currentLength; i++) {
        if (students[i].studentId == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Can not find student with ID: %d\n", id);
        return;
    }
    printf("\nStudent's information:\n");
    printf("ID: %d\n", students[found].studentId);
    printf("Name: %s\n", students[found].name);
    printf("Phone number: %s\n", students[found].phoneNumber);
    printf("Email: %s\n", students[found].email);
    printf("Password: %s\n", students[found].password);
    printf("\nEnter the new student's informations (Enter 0 to pass):\n");
// Nhap ten
    do {
        printf("Name (Enter 0 to pass): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "0") == 0) {
            break;
        }
        valid = 1;
        for (i = 0; input[i] != '\0'; i++) {
            if (!isalpha(input[i]) && !isspace(input[i])) {
                valid = 0;
                printf("ERROR. Enter again (only the anphabet and space).\n");
                break;
            }
        }
        if (valid) {
            strcpy(students[found].name, input);
        }
    } while (!valid);
	// nhap sdt
    do {
        printf("Phone number (Enter 0 to pass): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "0") == 0) {
            break;
        }

        valid = 1;
        int len = strlen(input);
        if (len < 10 || len > 11) {
            valid = 0;
            printf("Invalid phone number. Enter again(10-11 character).\n");
        } else {
            for (i = 0; i < len; i++) {
                if (!isdigit(input[i])) {
                    valid = 0;
                    printf("Phone number only include number. Enter again.\n");
                    break;
                }
            }
        }

        if (valid) {
            strcpy(students[found].phoneNumber, input);
        }
    } while (!valid);

    // nhap email
    do {
        printf("Enter Email (Enter 0 to pass): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "0") == 0) {
            break;
        }
        valid = 1;
        char *at = strchr(input, '@');
        char *dot = strrchr(input, '.');
        if (!at || !dot || at > dot) {
            valid = 0;
            printf("Email invalid. Enter again (format x@y.z).\n");
        }

        if (valid) {
            strcpy(students[found].email, input);
        }
    } while (!valid);
    // nhap pass
    printf("Enter Password (Enter 0 to pass): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strcmp(input, "0") != 0) {
        strcpy(students[found].password, input);
    }

    printf("\n*** Student Updated Successfully ****\n");
}
// xoa student 
void deleteStudents(Student students[], int *currentLength){
    system("cls");
	if (*currentLength == 0) {
        printf("Student list is emty. Can not delete.\n");
        return;
    }
    int id, i, found = -1;
    char confirm;
    printf("Enter ID of the student you want to delete: ");
    scanf("%d", &id);
    getchar();
    // tim vi tri id
    for (i = 0; i < *currentLength; i++) {
        if (students[i].studentId == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Can not find student with this ID: %d\n", id);
        return;
    }
    // hien thi thong tin student muon xoa
    printf("Student information you want to delete:\n");
    printf("ID: %d\n", students[found].studentId);
    printf("Name: %s\n", students[found].name);
    printf("Phone number: %s\n", students[found].phoneNumber);
    printf("Email: %s\n", students[found].email);
    printf("No.course: %d\n", students[found].noOfcourse);
    printf("\nAre you sure to delete this student? (y/n): ");
    scanf(" %c", &confirm);
    getchar(); // xoa ki tu'\n'
    if (confirm == 'y' || confirm == 'Y') {
        // dong y xoa student
        for (i = found; i < *currentLength - 1; i++) {
            students[i] = students[i + 1];
        }
        // giam so luong danh sach
        (*currentLength)--;
        printf("Student with ID: %d delete completed.\n", id);
    } else {
        printf("Delete cancel.\n");
    }
}
// Ham tim student
void searchStudentByName(Student students[], int *currentLength) {
    system("cls");
	if (*currentLength == 0) {
        printf("Emty list.\n");
        return;
    }
    printf("check %d",*currentLength);
    char searchName[50];
    getchar();
    printf("Enter information: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Loai bo '\n'
	
    printf("\nResult: \"%s\"\n", searchName);
    printf("|==========|====================|==============================|====================|=============|\n");
    printf("|%-10s|%-20s|%-30s|%-20s|%-13s|\n", "ID", "Name", "Email", "Phone", "NO.Course");
    printf("|==========|====================|==============================|====================|=============|\n");
    int found = 0; // Bien co ktra xem co student k
    int i;
    for (i = 0; i < *currentLength; i++) {
        // Su dung strstr() de kiem tra chuoi co trong danh khong
        if (strstr(students[i].name, searchName) !=NULL) {
            found = 1; // danh dau neu tim thay student
            printf("|%-10d|%-20s|%-30s|%-20s|%-13d|\n", 
                   students[i].studentId, 
                   students[i].name, 
                   students[i].email, 
                   students[i].phoneNumber, 
                   students[i].noOfcourse);
            printf("|==========|====================|==============================|====================|=============|\n");
        }
    }
    if (found!=1) {
        printf("Can not find: \"%s\"\n", searchName);
    }
}
// Sap xep student theo ten
void sortStudentsByName(Student students[], int *currentLength) {
    system("cls");
	if (*currentLength == 0) {
        printf("Emty list.\n");
        return;
    }
    int choice;
    printf("Choose:\n");
    printf("1. Increasing by name\n");
    printf("2. Decreasing by name\n");
    printf("Enter choose (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Xoa ki tu '\n'
    if (choice != 1 && choice != 2) {
        printf("ERROR.\n");
        return;
    }
    // logic sap xep
    int i,j;
    for (i = 0; i < *currentLength - 1; i++) {
        for (j = i + 1; j < *currentLength; j++) {
            int compare = strcmp(students[i].name, students[j].name);
            if ((choice == 1 && compare > 0) || (choice == 2 && compare < 0)) {
                // hoan doi 2 sinh vien
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("**** Sort Successfully \n");
}
// Menu login
void loginAdmin(const char email[], const char password[]) {
    system("cls");
	char mail[50]; 
    char pass[50];
    int attempt = 0;
    const int maxAttempt = 3;
    
    while (attempt < maxAttempt){
    	printf("======= Admin Login =======\n");
        printf("Email: ");
        fgets(mail, sizeof(mail), stdin);
        mail[strcspn(mail, "\n")] = '\0';
        printf("Password: ");
        fgets(pass, sizeof(pass), stdin);
        pass[strcspn(pass, "\n")] = '\0'; 
        printf("===========================\n");
        
        if (strcmp(mail, email) == 0 && strcmp(pass, password) == 0) {
            printf("Login successfully!\n");
            break;
        } else if (strcmp(mail, email) != 0) {
            printf("Incorrect Email. Enter again.\n");
        }else{
        	printf("Incorrect password. Enter again.\n");
		}
		
		attempt++;
		if (attempt == maxAttempt){
			printf("Too many failure attempt. Exiting...\n");
			exit(1);
		}
		printf("Attempt remaining: %d\n", maxAttempt - attempt);
	}
}
// Tai tep file
void loadDataFromFile(Student students[],const char *Studentdata) {
    FILE *file = fopen(Studentdata, "r+");
    if (file == NULL) {
        printf("Failed to open file for loading.\n");
        return;
    }
    int studentsCount = 0;
    fread(&studentsCount, sizeof(int), 1, file);
    fread(students, sizeof(Student), studentsCount, file);
    fclose(file);
    printf("Data loaded successfully from '%s'.\n", Studentdata);
    system("cls");
}
// Luu du lieu
void saveDataToFile(Student students[],const char *Studentdata) {
    FILE *file = fopen(Studentdata, "a+");
    if (file == NULL) {
        printf("Failed to open file for saving.\n");
        return;
    }
    int studentsCount = 0;
    fwrite(&studentsCount, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), studentsCount, file);
    fclose(file);
    printf("Data saved successfully to '%s'.\n", Studentdata);
    system("cls");
}
//Menu Teacher
void menuTeacher(Teacher teacher[], int *count) {
    system("cls");
	int choice;
    int currentLength;
	do {
        printf("\n*** Student Management System Using C ***\n");
        printf("\t\tStudent Menu\n");
        printf("==============================\n");
        printf("[1]: Show all teacher.\n");
        printf("[2]: Add a new teacher.\n");
        printf("[3]: Search a teacher.\n");
        printf("[4]: Edit a teacher.\n");
        printf("[5]: Delete a teacher.\n");
        printf("[6]: Sort teachers by name.\n");
        printf("[0]: Exit Menu.\n");
        printf("==============================\n");
        printf("Enter The Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayTeacher(teacher, count);
                break;
            case 2:
                addTeacher(teacher, count);
                break;
            case 3:
                searchTeacherByName(teacher,count);
                break;
            case 4:
                editTeacher(teacher,&currentLength);
                break;
            case 5:
                deleteTeacher(teacher,&currentLength);
                break;
            case 6:
                sortTeacherByName(teacher,&currentLength);
                break;
            case 0:
                printf("Exiting Teacher Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}
//Ham them giao vien
void addTeacher(Teacher teacher[], int *count) {
    system("cls");
	if (*count >= 100) {
        printf("\nTeacher list is full. Cannot add more teacher.\n");
        return;
    }
    printf("\nEnter New Teacher ID: ");
    scanf("%d", &teacher[*count].teacherId);
    getchar(); // Clear newline left by scanf
    printf("Enter New Teacher Name: ");
    fgets(teacher[*count].name, sizeof(teacher[*count].name), stdin);
    teacher[*count].name[strcspn(teacher[*count].name, "\n")] = '\0'; 
    printf("Enter New Teacher Email: ");
    fgets(teacher[*count].email, sizeof(teacher[*count].email), stdin);
    teacher[*count].email[strcspn(teacher[*count].email, "\n")] = '\0';
    printf("Enter New Teacher Phone: ");
    fgets(teacher[*count].phoneNumber, sizeof(teacher[*count].phoneNumber), stdin);
    teacher[*count].phoneNumber[strcspn(teacher[*count].phoneNumber, "\n")] = '\0';
    printf("Enter Number of Courses: ");
    scanf("%d", &teacher[*count].noOfcourse); // Use scanf for integers
    getchar(); // Clear newline left by scanf
    (*count)++;
    printf("\nNew teacher added successfully!\n");
}
//Ham in ra danh sach giao vien
void displayTeacher(Teacher teacher[], int *count){ 
    system("cls");
	if (*count == 0) {
        printf("\nNo teacher in the list.\n");
        return;
    }

    printf("\n--- Teacher List ---\n");
    printf("\t----------*** All Students ***----------\n");
    printf("|==========|====================|=============================|====================|=============|\n");
    printf("|    ID    |        Name        |            Email            |        Phone       |  No. Course |\n");
    printf("|==========|====================|=============================|====================|=============|\n");
    int i;
    for (i = 0; i < *count; i++) {
        printf("| %-8d | %-18s | %-27s | %-18s | %-11d |\n", 
               teacher[i].teacherId, 
               teacher[i].name, 
               teacher[i].email,
               teacher[i].phoneNumber, 
               teacher[i].noOfcourse);
    }
    printf("|==========|====================|=============================|====================|=============|\n");
    printf("\t----------------------------------------\n");
}
//Ham sua thong tin giao vien
void editTeacher(Teacher teacher[], int *currentLength){
	system("cls");
	if (*currentLength == 0) {
        printf("Teacher list emty. Nothing to correct.\n");
        return;
    }
    int id, i, valid;
    char input[100]; // Bien lu tru du lieu nhap
    printf("Enter the Teacher's ID that need to edit: ");
    scanf("%d", &id);
    getchar();
//Tim theo id
    int found = -1;
    for (i = 0; i < *currentLength; i++) {
        if (teacher[i].teacherId == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Can not find student with ID: %d\n", id);
        return;
    }
    printf("\nTeacher's information:\n");
    printf("ID: %d\n", teacher[found].teacherId);
    printf("Name: %s\n", teacher[found].name);
    printf("Phone number: %s\n", teacher[found].phoneNumber);
    printf("Email: %s\n", teacher[found].email);
    printf("Password: %s\n", teacher[found].password);
    printf("\nEnter the new student's informations (Enter 0 to pass):\n");
// Nhap ten
    do {
        printf("Name (Enter 0 to pass): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "0") == 0) {
            break;
        }
        valid = 1;
        for (i = 0; input[i] != '\0'; i++) {
            if (!isalpha(input[i]) && !isspace(input[i])) {
                valid = 0;
                printf("ERROR. Enter again (only the anphabet and space).\n");
                break;
            }
        }
        if (valid) {
            strcpy(teacher[found].name, input);
        }
    } while (!valid);
	// nhap sdt
    do {
        printf("Phone number (Enter 0 to pass): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "0") == 0) {
            break;
        }

        valid = 1;
        int len = strlen(input);
        if (len < 10 || len > 11) {
            valid = 0;
            printf("Invalid phone number. Enter again(10-11 character).\n");
        } else {
            for (i = 0; i < len; i++) {
                if (!isdigit(input[i])) {
                    valid = 0;
                    printf("Phone number only include number. Enter again.\n");
                    break;
                }
            }
        }

        if (valid) {
            strcpy(teacher[found].phoneNumber, input);
        }
    } while (!valid);

    // nhap email
    do {
        printf("Enter Email (Enter 0 to pass): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "0") == 0) {
            break;
        }
        valid = 1;
        char *at = strchr(input, '@');
        char *dot = strrchr(input, '.');
        if (!at || !dot || at > dot) {
            valid = 0;
            printf("Email invalid. Enter again (format x@y.z).\n");
        }

        if (valid) {
            strcpy(teacher[found].email, input);
        }
    } while (!valid);
    // nhap pass
    printf("Enter Password (Enter 0 to pass): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strcmp(input, "0") != 0) {
        strcpy(teacher[found].password, input);
    }

    printf("\n*** Teacher Updated Successfully ****\n");
}
//Ham xoa giao vien
void deleteTeacher(Teacher teacher[], int *currentLength){
    system("cls");
	if (*currentLength == 0) {
        printf("Teacher list is emty. Can not delete.\n");
        return;
    }
    int id, i, found = -1;
    char confirm;
    printf("Enter ID of the teacher you want to delete: ");
    scanf("%d", &id);
    getchar();
    // tim vi tri id
    for (i = 0; i < *currentLength; i++) {
        if (teacher[i].teacherId == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Can not find teacher with this ID: %d\n", id);
        return;
    }
    // hien thi thong tin student muon xoa
    printf("Teacher information you want to delete:\n");
    printf("ID: %d\n", teacher[found].teacherId);
    printf("Name: %s\n", teacher[found].name);
    printf("Phone number: %s\n", teacher[found].phoneNumber);
    printf("Email: %s\n", teacher[found].email);
    printf("No.course: %d\n", teacher[found].noOfcourse);
    printf("\nAre you sure to delete this teacher? (y/n): ");
    scanf(" %c", &confirm);
    getchar(); // xoa ki tu'\n'
    if (confirm == 'y' || confirm == 'Y') {
        // dong y xoa student
        for (i = found; i < *currentLength - 1; i++) {
            teacher[i] = teacher[i + 1];
        }
        // giam so luong danh sach
        (*currentLength)--;
        printf("Teacher with ID: %d delete completed.\n", id);
    } else {
        printf("Delete cancel.\n");
    }
}
//Ham tim giao vien
void searchTeacherByName(Teacher teacher[], int *currentLength) {
    system("cls");
	if (*currentLength == 0) {
        printf("Emty list.\n");
        return;
    }
    printf("check %d",*currentLength);
    char searchName[50];
    getchar();
    printf("Enter information: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Loai bo '\n'
	
    printf("\nResult: \"%s\"\n", searchName);
    printf("|==========|====================|==============================|====================|=============|\n");
    printf("|%-10s|%-20s|%-30s|%-20s|%-13s|\n", "ID", "Name", "Email", "Phone", "NO.Course");
    printf("|==========|====================|==============================|====================|=============|\n");
    int found = 0; // Bien co ktra xem co teacher k
    int i;
    for (i = 0; i < *currentLength; i++) {
        // Su dung strstr() de kiem tra chuoi co trong danh khong
        if (strstr(teacher[i].name, searchName) !=NULL) {
            found = 1; // danh dau neu tim thay student
            printf("|%-10d|%-20s|%-30s|%-20s|%-13d|\n", 
                   teacher[i].teacherId, 
                   teacher[i].name, 
                   teacher[i].email, 
                   teacher[i].phoneNumber, 
                   teacher[i].noOfcourse);
            printf("|==========|====================|==============================|====================|=============|\n");
        }
    }
    if (found!=1) {
        printf("Can not find: \"%s\"\n", searchName);
    }
}
//Ham sap xep giao vien
void sortTeacherByName(Teacher teacher[], int *currentLength) {
    system("cls");
	if (*currentLength == 0) {
        printf("Emty list.\n");
        return;
    }
    int choice;
    printf("Choose:\n");
    printf("1. Increasing by name\n");
    printf("2. Decreasing by name\n");
    printf("Enter choose (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Xoa ki tu '\n'
    if (choice != 1 && choice != 2) {
        printf("ERROR.\n");
        return;
    }
    // logic sap xep
    int i,j;
    for (i = 0; i < *currentLength - 1; i++) {
        for (j = i + 1; j < *currentLength; j++) {
            int compare = strcmp(teacher[i].name, teacher[j].name);
            if ((choice == 1 && compare > 0) || (choice == 2 && compare < 0)) {
                // hoan doi 2 sinh vien
                Teacher temp = teacher[i];
                teacher[i] = teacher[j];
                teacher[j] = temp;
            }
        }
    }
    printf("**** Sort Successfully \n");
}

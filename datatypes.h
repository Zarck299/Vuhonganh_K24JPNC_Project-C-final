#include <stdbool.h>	// Khai bao nguyen mau ham
typedef struct Date{
	int day,month,year;
} Date;
typedef struct Student{
	int studentId;//cho id phai tu tang dan
	int age[10];
	char classroomId[10];
	char name[20];
	struct Date dateOfBirth;
	char email[15];
	char phoneNumber[20];
	char password[20];
	int noOfcourse;
} Student;
typedef struct Teacher{
	int teacherId;
	char classroomId[10];
	char name[20];
	struct Date dateOfBirth;
	bool gender;
	char email[30];
	char phoneNumber[20];
	int noOfcourse;
	char password[20];
} Teacher;

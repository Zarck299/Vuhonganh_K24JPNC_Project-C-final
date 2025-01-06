#include "datatypes.h"
//nguyen mau ham functions.h
void displayMenu();
void displayStudents(Student students[], int *count);
void addStudents(Student students[], int *count);
void end();
void menuAdmin();
void menuStudents(Student students[], int *count);
void editStudents(Student students[], int *currentLength);
void deleteStudents(Student students[], int *currentLength);
void searchStudentByName(Student students[], int *currentLength);
void sortStudentsByName(Student students[], int *currentLength);
void loginAdmin(const char email[], const char password[]);
void chooseYourrole(Student students[],int *choiceAdmin,int *Length);
void loadDataFromFile(Student students[],const char *filename);
void saveDataToFile(Student students[],const char *filename);
void displayTeacher(Teacher teacher[], int *count);
void addTeacher(Teacher teacher[], int *count);
void menuTeacher(Teacher teacher[], int *count);
void editTeacher(Teacher teacher[], int *currentLength);
void deleteTeacher(Teacher teacher[], int *currentLength);
void searchTeacherByName(Teacher teacher[], int *currentLength);
void sortTeacherByName(Teacher teacher[], int *currentLength);


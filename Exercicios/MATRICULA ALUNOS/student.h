
#define MAX_NAME 50
#define MAX_NUMBER_ID 8
#define MAX_CHAR_SUBJECTS 50
#define MAX_COURSE 50


struct date{
    int day;
    int month;
    int year;
}; typedef struct date Date;


struct student{
    char id[MAX_NUMBER_ID];
    char name[MAX_NAME];
    Date date;
    char course[MAX_COURSE];
    int numDiscipline;
    char** discipline;
}; typedef struct student Student;



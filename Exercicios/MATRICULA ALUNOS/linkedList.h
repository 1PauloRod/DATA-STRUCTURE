#include <stdio.h>
#include <stdlib.h>
#include "student.h" 
#include <string.h>

struct node{ 
    Student student;
    struct node* next;
}; typedef struct node Node;


Node* initialize_student_list();
void insert_student(Node** list, Student student);
Student* search_student(Node** list, const char* student_name);
void update_student(Node** list, const char* student_id);
void remove_student(Node** list, const char* id_student);
void display_students(Node** list);
void free_student_list(Node** list);
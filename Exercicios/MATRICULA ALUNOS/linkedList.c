#include "linkedList.h"

Node* initialize_student_list(){
    return NULL;
}

void insert_student(Node** list, Student student){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) exit(1);

    new_node->student = student;
    new_node->next = *list;
    *list = new_node;
    return ; 
}

Student* search_student(Node** list, const char* student_name){      
    for (Node* t = *list; t != NULL; t = t->next){
        if (strcmp(t->student.name, student_name) == 0){
            return &(t->student);
        } 
    }
    return NULL;
}  

void update_student(Node** list, const char* student_id){
    int option;
    char new_name[50];
    char new_course[50];
    char temp;
    Date new_date;
    for (Node* t = *list; t != NULL; t = t->next){
        if (strcmp(t->student.id, student_id) == 0){
            printf("Qual que voce gostaria de alterar? \n\n");
            printf("0 - Nome\n");
            printf("1 - Curso\n");
            printf("2 - Data Nascimento\n");
            printf("->");
            scanf("%d", &option);
            switch (option){
                case 0:
                    printf("Qual o novo nome? ");
                    scanf("%c",&temp); // limpar o buffer
                    scanf(" %[^\n]", new_name);
                    strcpy(t->student.name, new_name);
                    break;
                case 1:
                    printf("Qual o novo curso? ");
                    scanf("%c",&temp); // limpar o buffer
                    scanf(" %[^\n]", new_course);
                    strcpy(t->student.course, new_course);
                    break;
                case 2:
                    printf("Qual a nova data? \n");
                    printf("   ->Dia:");
                    scanf("%d", &new_date.day);
                    printf("   ->Mes:");
                    scanf("%d", &new_date.month);
                    printf("   ->Ano:");
                    scanf("%d", &new_date.year);
                    t->student.date = new_date;
                    break;
            }           
        }
    }
    return ;
}

void remove_student(Node** list, const char* student_id){
    Node* prev = NULL;
    Node* aux = *list;

    if (strcmp(aux->student.id, student_id) == 0){
        *list = aux->next;
        return ;
    }
    for (Node* t = aux->next; t != NULL; t = t->next){
        prev = aux;
        if (strcmp(t->student.id, student_id) == 0){
            prev->next = t->next;
            *list = prev;
            return ;
        }
    }
    return ;
}

void display_students(Node** list){

    for (Node* t = *list; t != NULL; t = t->next){
        printf("Nome: %s\n", t->student.name);
        printf("Data Nascimento: %d/%d/%d\n", t->student.date.day, t->student.date.month, t->student.date.year);
        printf("Matricula: %s\n", t->student.id);
        printf("Curso: %s\n", t->student.course);
        printf("Disciplinas: %d\n", t->student.numDiscipline);
        for (int i = 0; i < t->student.numDiscipline; i++){
            printf("   -> %s\n", t->student.discipline[i]);
        }
        printf("\n");
    }
    printf("--------------X---------------");
    printf("\n\n");
}

void free_student_list(Node** list){
    free(*list); 
    *list = NULL;
    return ;
}

/*
    Autor: Paulo Rodrigues
    Data: 23/03/2024
    Descrição: Exemplo básico de registro de alunos usando 
    listas encadeadas
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include <stdbool.h>

/*
    estrutura alunos        Done
    inicializa lista        Done
    adiciona estudante      Done
    busca estudante         Done
    remove estudante        Done
    atualiza estudante      Done
    printa estudante        Done
    libera lista            Done
    cadastra disciplina     Done
    remove disciplina       Done
    fazer o menu (chatooo)  Done
*/

/*
    TO-DOs futuros que vale pensar
    implementar uma hash table para melhorar eficiencia
    implementar com I/O de arquivos para salvar os dados
*/



int main(void){

    Node* list_student = initialize_student_list();
    char name[50];
    char temp;
    Student student;
    int numberSbj;
    int option;
    printf("\n******************************************** REGISTRO ALUNO ******************************************\n");
    while(true){
        printf("********************************\n");
        printf("* Escolha uma operacao abaixo  *\n");
        printf("********************************\n");
        printf("*  0 - Sair                    *\n");
        printf("*  1 - Adicionar Aluno         *\n");
        printf("*  2 - Buscar Aluno            *\n");
        printf("*  3 - Remover Aluno           *\n");
        printf("*  4 - Listar Alunos           *\n");
        printf("*  5 - Atualiza Aluno          *\n");
        printf("********************************\n");
        printf("-> ");
        scanf("%d", &option);

        switch (option){
            case 0:
                printf("Muito obrigado!\n");
                exit(1);
                break;

            case 1:{
                printf("\n ----- Adicionar Aluno ------\n");
                
                printf("Nome do aluno: ");
                scanf("%c",&temp); // limpar o buffer
	            scanf("%[^\n]",student.name);
                printf("Data Nascimento\n");
                printf("   -> Dia: ");
                scanf("%d", &student.date.day);
                printf("   -> Mes: ");
                scanf("%d", &student.date.month);
                printf("   -> Year: ");
                scanf("%d", &student.date.year);
                printf("Curso do aluno: ");
                scanf("%c",&temp); // limpar o buffer
	            scanf("%[^\n]",student.course);
                printf("Matricula do aluno: ");
                scanf("%c",&temp);
	            scanf("%[^\n]",student.id);
                
                printf("Numero de disciplinas: ");
                scanf("%d", &numberSbj);
                student.numDiscipline = numberSbj;
                student.discipline = (char**)malloc(sizeof(char*) * numberSbj);
                if (student.discipline == NULL) exit(1);
                for (int i = 0; i < numberSbj; i++){
                    char discipline[50];
                    printf("Digite o nome da disciplina %d: ", i + 1);
                    scanf("%c", &temp);
                    scanf("%[^\n]", discipline);
                    student.discipline[i] = (char*)malloc((strlen(discipline) + 1) * sizeof(char));
                    if (student.discipline[i] == NULL) exit(1);
                    strcpy(student.discipline[i], discipline);
                }
                insert_student(&list_student, student);
                printf("\nAluno cadastrado com sucesso!\n\n\n");
                break;
            }

            case 2:
                printf("\n ----- Buscar Aluno ------\n");
                
                printf("Nome do aluno: ");
                scanf("%c",&temp); // limpar o buffer
	            scanf("%[^\n]", name);
                Student* student = search_student(&list_student, name);
               
               if (student != NULL){
                    printf("\n--- Aluno encontrado! ---\n\n");
                    printf("Nome: %s\n", student->name);
                    printf("Data Nascimento: %d/%d/%d\n", student->date.day, student->date.month, student->date.year);
                    printf("Matricula: %s\n", student->id);
                    printf("Curso: %s\n", student->course);
                    printf("Disciplinas: %d\n", student->numDiscipline);
                    for (int i = 0; i < student->numDiscipline; i++){
                        printf("   -> %s\n", student->discipline[i]);
                    }
                    printf("\n");
               }else{
                    printf("\nAluno nao encontrado.\n\n");
               }
                
                break;

            case 3:{
                printf("\n ----- Remover Aluno ------\n");
                if (list_student != NULL){
                    Student student;
                    printf("Matricula do aluno: ");
                    scanf("%c",&temp);
                    scanf("%[^\n]",student.id);
                    remove_student(&list_student, student.id);
                    printf("\nAluno removido com sucesso!\n\n\n");
                }else{
                    printf("nenhum estudante cadastrado.\n\n");
                }
                break;
            }

            case 4:{
                printf("\n----------- ALUNOS ----------\n");
                if (list_student == NULL) 
                    printf("nenhum estudante cadastrado.\n");
                display_students(&list_student);
                break;
            }

            case 5:{   
                printf("\n----------- Atualiza Alunos ----------\n");
                printf("Nome do aluno: ");
                scanf("%c",&temp); // limpar o buffer
	            scanf("%[^\n]", name);
                Student* student = search_student(&list_student, name);
                if (student != NULL){
                    update_student(&list_student, student->id);

                    printf("\nAluno atualizado com sucesso!\n\n");
                }else{
                    printf("\nAluno nao encontrado.\n\n");
                }
                break;
            }

        }
    }
    
    return 0;
}
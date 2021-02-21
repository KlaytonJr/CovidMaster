#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Questionario.h"
#include <unistd.h>

//Prototipação
void questionario(void);
void menu();
void sobre();
void creditos();
int main()
{
    setlocale(LC_ALL, "Portuguese");
    menu();

    return 0;
}

void menu()
{ 
    while (1)
    {
        int digito;
        printf("\t\t-------------------------------\n");
        printf("\t\t|        COVID MASTER         |\n");
        printf("\t\t-------------------------------\n");
        printf("Pressione a tecla para executar a função correspondente:\n\n");
        printf("Digite (1) - INICIAR\n\n");
        printf("Digite (2) - SOBRE\n\n");
        printf("Digite (3) - CRÉDITOS\n\n");
        printf("Digite (0) - SAIR\n\n");
        scanf("%d", &digito);
        system("clear");

        if (digito == 1)
        {
            questionario();
        }
        else if (digito == 2)
        {
          sobre();

        }
        else if (digito == 3)
        {
          creditos();
        }
        else if (digito == 0)
        {
            system("clear");
            printf(" PROGRAMA ENCERRADO !\n");
            break;
        }
        else
        {
            printf("Valor incorreto, digite novamente!\n");
            sleep(1);
            system("clear");
        }
    }
}



void sobre(){
  printf("O programa COVID MASTER é uma ferramenta feita com o intuito de indicar a mais\n provável doença que o paciente pode possuir, o programa utiliza de um sistema\n especialista por meio de um questionario e define a mais provável doença,\npodendo ser:\n• COVID-19;\n• Gripe;\n• Resfriado.\n\n\n");
  printf("Aperte a tecla ENTER para continuar...\n");
  getchar();
  getchar();
  system("clear");
}

void creditos(){
  printf("Desenvolvedores :\n\n");
  printf("Gabriel Alves - gabriel.costa@uepb.aluno.edu.br\n\n");
  printf("José Carlos - jose.carlos@uepb.aluno.edu.br\n\n");
  printf("Klayton Marcos - klayton.junior@uepb.aluno.edu.br\n\n");
  printf("Lucas Henrique - lucas.pereira@uepb.aluno.edu.br\n\n\n");
  printf("Aperte a tecla ENTER para continuar...\n");
  getchar();
  getchar();
  system("clear");    
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX 2
#define ANSI_COLOR_RED   
float corona = 0;
float resfriado = 0;
float gripe = 0;
bool verificar;
char entradas[10];
int EntradaAlt[2];

//Prototipação
void DORES();
void CORIZA();
void DORGARGANTA();
void ESPIRRO();
int TOSSE();
void CANSACO();
void FEBRE();
void DIARREIA();
void DORCABECA();
void FALTAAR();
void alteracao();

void questionario(){
  char idade[MAX];
  corona = 0;
  resfriado = 0;
  gripe = 0;
  int idade_num = 0, i;

  printf("Digite sua idade: ");
  do
  {
    scanf("%s", idade);
    for (i = 0; i < strlen(idade); i++)
    {
      if (isdigit(idade[i]))
      {
        verificar = true;
        EntradaAlt[1] = atoi(idade);
      }
      else
      {
        verificar = false;
        printf("\nvalor digitado incorreto, digite novamente: ");
        break;
      }
    }
  } while (!verificar);

  printf("\nPara cada uma das perguntas digite :\n(1) se teve o sintoma\n(0) se não teve o sintoma\n\n");

  FEBRE();

  CANSACO();

  TOSSE();

  ESPIRRO();

  DORES();

  CORIZA();

  DORGARGANTA();

  DIARREIA();

  DORCABECA();

  FALTAAR();

  printf("\n");

  //Alteração
  alteracao();

  //Calculo da porcentagem
  corona = (corona / 16) * 100;
  gripe = (gripe / 21) * 100;
  resfriado = (resfriado / 17) * 100;

  printf("Resultado Coronavirus  = %.2f %% \n", corona);
  printf("Resultado Gripe        = %.2f %% \n", gripe);
  printf("Resultado Resfriado    = %.2f %% \n", resfriado);

  printf("\n");

  if (corona > gripe && corona > resfriado)
    printf("Você tem mais chances de estar com Corona Vírus\n\n");

  else if (gripe > corona && gripe > resfriado)
    printf("Você tem mais chances de estar com gripe\n\n");

  else if (resfriado > gripe && resfriado > corona)
    printf("Você tem mais chances de estar com resfriado\n\n");

  else if (resfriado == 0 && gripe == 0 && corona == 0 )
    printf("Você não possui nenhum sintoma de corona vírus, gripe ou resfriado.\n\n");

  printf("Aperte a tecla ENTER para continuar...\n");
  getchar();
  getchar();
 
  system("clear");
}

//Febre
void FEBRE(){
  char febre;
  printf("Febre: ");
  do
  {
    scanf("%s", &febre);

    if (isdigit(febre) && (febre == '1' || febre == '0'))
    {
      entradas[0] = febre;
      verificar = true;
      if (febre == '1')
      {
        corona += 3;
        gripe += 3;
      }
    }
    else
    {
      verificar = false;
      printf("\nvalor digitado incorreto, digite novamente: ");
    }
  } while (!verificar);
}

//Cansaço
void CANSACO(){
  char cansaco;
  printf("Cansaço: ");
  do
  {
    scanf("%s", &cansaco);

    if (isdigit(cansaco) && (cansaco == '1' || cansaco == '0'))
    {
      entradas[1] = cansaco;
      verificar = true;
      if (cansaco == '1')
      {
        corona += 2;
        resfriado += 2;
        gripe += 3;
      }
    }
    else
    {
      verificar = false;
      printf("\nvalor digitado incorreto, digite novamente: ");
    }
  } while (!verificar);
}

//Tosse
int TOSSE(){
  char tosse, tosse_nivel;
  printf("Tosse: ");
  do
  {
    scanf("%s", &tosse);

    if (isdigit(tosse) && (tosse == '1' || tosse == '0'))
    {
      entradas[2] = tosse;
      verificar = true;
      if (tosse == '1')
      {
        printf("Tosse leve (1) Tosse seca (2): ");
        do
        {
          scanf("%s", &tosse_nivel);
          if (isdigit(tosse_nivel) && (tosse_nivel == '1' || tosse_nivel == '2'))
          {
            EntradaAlt[0] = atoi(&tosse_nivel);
            verificar = true;
            if (tosse_nivel == '1')
            {
              resfriado += 3;
            }

            if (tosse_nivel == '2')
            {
              corona += 3;
              gripe += 3;
            }
          }
          else
          {
            verificar = false;
            printf("\nvalor digitado incorreto, digite novamente: ");
          }
        } while (!verificar);
      }
    }
    else
    {
      verificar = false;
      printf("\nvalor digitado incorreto, digite novamente: ");
    }
  } while (!verificar);
  return 0;
}

//Espirros
void ESPIRRO(){
  char espirro;
  printf("Espirros: ");
  do
  {
    scanf("%s", &espirro);

    if (isdigit(espirro) && (espirro == '1' || espirro == '0'))
    {
      entradas[3] = espirro;
      verificar = true;
      if (espirro == '1')
      {
        resfriado += 3;
      }
    }
    else
    {
      verificar = false;
      printf("\nvalor digitado incorreto, digite novamente: ");
    }
  } while (!verificar);
}

//Dores no corpo e mal-estar
void DORES(){
  char dores;
  printf("Dores no corpo e mal-estar: ");
  do
  {
    scanf("%s", &dores);

    if (isdigit(dores) && (dores == '1' || dores == '0'))
    {
      entradas[4] = dores;
      verificar = true;
      if (dores == '1')
      {
        corona += 2;
        resfriado += 3;
        gripe += 3;
      }
    }
    else
    {
      verificar = false;
      printf("\nvalor digitado incorreto, digite novamente: ");
    }
  } while (!verificar);
}

//Coriza ou nariz entupido
void CORIZA(){
  char coriza;
  printf("Coriza ou nariz entupido: ");
  do
  {
    scanf("%s", &coriza);

    if (isdigit(coriza) && (coriza == '1' || coriza == '0'))
    {
      entradas[5] = coriza;
      verificar = true;
      if (coriza == '1')
      {
        resfriado += 3;
        gripe += 2;
      }
    }
    else
    {
      verificar = false;
      printf("\nvalor digitado incorreto, digite novamente: ");
    }
  } while (!verificar);
}

//Dor de garganta
void DORGARGANTA(){
  char dorDeGarganta;
  printf("Dor de garganta: ");
  do
  {
    scanf("%s", &dorDeGarganta);

    if (isdigit(dorDeGarganta) && (dorDeGarganta == '1' || dorDeGarganta == '0'))
    {
      entradas[6] = dorDeGarganta;
      verificar = true;
      if (dorDeGarganta == '1')
      {
        corona += 2;
        resfriado += 3;
        gripe += 2;
      }
    }
    else
    {
      verificar = false;
      printf("\nvalor digitado incorreto, digite novamente: ");
    }
  } while (!verificar);
}

//Diarreia
void DIARREIA(){
  char diarreia;
  printf("Diarreia: ");
  do
  {
    scanf("%s", &diarreia);

    if (isdigit(diarreia) && (diarreia == '1' || diarreia == '0'))
    {
      entradas[7] = diarreia;
      verificar = true;
      if (diarreia == '1' && (EntradaAlt[1] <= 12))
      {
        gripe += 2;
      }
    }
    else
    {
      verificar = false;
      printf("\nvalor digitado incorreto, digite novamente: ");
    }
  } while (!verificar);
}

//Dor de Cabeça
void DORCABECA(){
  char dorDeCabeca;
  printf("Dor de cabeça: ");
  do
  {
    scanf("%s", &dorDeCabeca);

    if (isdigit(dorDeCabeca) && (dorDeCabeca == '1' || dorDeCabeca == '0'))
    {
      entradas[8] = dorDeCabeca;
      verificar = true;
      if (dorDeCabeca == '1')
      {
        corona += 2;
        gripe += 3;
      }
    }
    else
    {
      verificar = false;
      printf("\nvalor digitado incorreto, digite novamente: ");
    }
  } while (!verificar);
}

//Falta de Ar
void FALTAAR(){
  char faltaDeAr;
  printf("Falta de Ar: ");
  do
  {
    scanf("%s", &faltaDeAr);

    if (isdigit(faltaDeAr) && (faltaDeAr == '1' || faltaDeAr == '0'))
    {
      entradas[9] = faltaDeAr;
      verificar = true;
      if (faltaDeAr == '1')
      {
        corona += 2;
      }
    }
    else
    {
      verificar = false;
      printf("\nvalor digitado incorreto, digite novamente: ");
    }
  } while(!verificar);
 
}

void alteracao(){
  int escolha;
  int escolhaAlt;
    system("clear");
  
  printf("Deseja fazer alguma alteração nas respostas do questionário?\n");
  printf("1 - Sim\n0 - Não\n\n");
  while(scanf("%d",&escolha) == 1){
    system("clear");
    if(escolha==0){
      break;
    }
    if(escolha==1){
      
      printf("Digite qual escolha você quer alterar:\n");
      printf("1 - Febre: %d\n2 - Cansaço: %d\n3 - tosse: %d\n4 - Espirros: %d\n5 - Dores no corpo e mal-estar: %d\n6 - Coriza ou nariz entupido: %d\n7 - Dor de garganta: %d\n8 - Diarreia: %d\n9 - Dor de cabeça: %d\n10 - Falta de ar: %d\n11 - Sair\n", entradas[0] - 48, entradas[1] - 48, entradas[2] - 48, entradas[3] - 48, entradas[4] - 48, entradas[5] - 48, entradas[6] - 48, entradas[7] - 48, entradas[8] - 48, entradas[9] - 48);
      scanf("%d",&escolhaAlt);
    }
    switch(escolhaAlt){
      case 1: 
        if(entradas[0] == '1'){
          corona -= 3;
          gripe -= 3;
        }
        FEBRE();
      break;
      
      case 2:
       if(entradas[1] == '1'){
          corona -= 2;
          resfriado -= 2;
          gripe -= 3;
        }
        CANSACO();
      break;

      case 3:
        if(entradas[2] == '1'){
          if(EntradaAlt[0] == 1){
            resfriado -= 3;
          } else {
            corona -= 3;
            gripe -= 3;
          }
        }
        TOSSE();
      break;
        
      case 4:
        if(entradas[3] == '1'){
          resfriado -=3;
        }
        ESPIRRO();
      break;

      case 5:
        if(entradas[4] == '1'){
          corona -= 2;
          resfriado -= 3;
          gripe -= 3;
          }
        DORES();
      break;
      
      case 6:
        if(entradas[5] == '1'){
          resfriado -= 3;
          gripe -= 2;
          }
        CORIZA();
      break;

      case 7:
        if(entradas[6] == '1'){
          corona -= 2;
          resfriado -= 3;
          gripe -= 2;
        }
        DORGARGANTA();
      break;

      case 8:
        if (entradas[7] == '1' && EntradaAlt[1] <= 12){
          gripe -= 2;
        }
        DIARREIA();
      break;

      case 9:
        if(entradas[8] == '1'){
          corona -= 2;
          gripe -= 3;
        }
        DORCABECA();
      break;

      case 10:
        if(entradas[9] == '1'){
          corona -= 2;
        }
        FALTAAR();
      break;

      case 11:
      break;
    }
    system("clear");
    printf("Deseja fazer alguma alteração nas respostas do questionário?\n");
    printf("1 - Sim\n0 - Não\n\n");
  }
}
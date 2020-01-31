#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

FILE *testepantheon;
FILE *ordempantheon;

void Menu();
void MenuBubbleSort();
void MenuShellSort();
void BubbleSort();
void ShellSort();

clock_t tempoInicial, tempoFinal;
double tempoGasto;

struct Dados{

    long int en_curid;
    char name[100], countryName[100];
};

int qtd;
int w, z, L, L2;

void gotoxy(int x, int y){

    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main (){

    system("color 09");

    setlocale(LC_ALL, "Portuguese");

    Menu();

    return 0;
}

void Menu(){

    int opcao;

    qtd = 0;

    do{
        opcao = 0;
        L = 4;
        L2 = 2;
        z = 2;

        printf("\n\n\tMENU PRINCIPAL\n\n");
        printf("\tOrdenção Alfabética (Bubble Sort)\n");
        printf("\tOrdenção Alfabética (Shell Sort)\n");
        printf("\tSair do Sistema");

        do{
            gotoxy(4, L);
            printf("-->");
            gotoxy(0, 0);

            if (kbhit){
                w = getch();
            }if (w == 80 && z < 4){
                L2 = L;
                L++;
                z++;
            }if (w == 72 && z > 2){
                L2 = L;
                L--;
                z--;
            }if (L != L2){
                gotoxy(4, L2);
                printf("   ");
                L2 = L;
            }if (w == 13){
                opcao = z - 1;
            }
        }while (opcao == 0);

        if (opcao == 1){
            system("cls");
            MenuBubbleSort();
        }else if (opcao == 2){
            system("cls");
            MenuShellSort();
        }else if (opcao == 3){
            system("cls");
            printf("Saindo do Sistema. Aguarde...");
            Sleep(3000);
            printf("\n");
            exit (0);
        }else;
    }while (opcao != 3);

    getchar();
}

void MenuBubbleSort(){

    int opcao;

    do{
        opcao = 0;
        L = 4;
        L2 = 2;
        z = 2;

        printf("\n\n\tMENU PRINCIPAL\n\n");
        printf("\t20 Ordenações\n");
        printf("\t50 Ordenações\n");
        printf("\t100 Ordenações\n");
        printf("\t500 Ordenações\n");
        printf("\t1000 Ordenações\n");
        printf("\t10000 Ordenações\n");
        printf("\tVoltar para o Menu Principal");

        do{
            gotoxy(4, L);
            printf("-->");
            gotoxy(0, 0);

            if (kbhit){
                w = getch();
            }if (w == 80 && z < 8){
                L2 = L;
                L++;
                z++;
            }if (w == 72 && z > 2){
                L2 = L;
                L--;
                z--;
            }if (L != L2){
                gotoxy(4, L2);
                printf("   ");
                L2 = L;
            }if (w == 13){
                opcao = z - 1;
            }
        }while (opcao == 0);

        if (opcao == 1){
            system("cls");
            qtd = 20;
            BubbleSort();
        }else if (opcao == 2){
            system("cls");
            qtd = 50;
            BubbleSort();
        }else if (opcao == 3){
            system("cls");
            qtd = 100;
            BubbleSort();
        }else if (opcao == 4){
            system("cls");
            qtd = 500;
            BubbleSort();
        }else if (opcao == 5){
            system("cls");
            qtd = 1000;
            BubbleSort();
        }else if (opcao == 6){
            system("cls");
            qtd = 10000;
            BubbleSort();
        }else if (opcao == 7){
            system("cls");
            Menu();
        }else;
    }while (opcao != 7);

    getchar();
}

void MenuShellSort(){

    int opcao;

    do{
        opcao = 0;
        L = 4;
        L2 = 2;
        z = 2;

        printf("\n\n\tMENU PRINCIPAL\n\n");
        printf("\t20 Ordenações\n");
        printf("\t50 Ordenações\n");
        printf("\t100 Ordenações\n");
        printf("\t500 Ordenações\n");
        printf("\t1000 Ordenações\n");
        printf("\t10000 Ordenações\n");
        printf("\tVoltar para o Menu Principal");

        do{
            gotoxy(4, L);
            printf("-->");
            gotoxy(0, 0);

            if (kbhit){
                w = getch();
            }if (w == 80 && z < 8){
                L2 = L;
                L++;
                z++;
            }if (w == 72 && z > 2){
                L2 = L;
                L--;
                z--;
            }if (L != L2){
                gotoxy(4, L2);
                printf("   ");
                L2 = L;
            }if (w == 13){
                opcao = z - 1;
            }
        }while (opcao == 0);

        if (opcao == 1){
            system("cls");
            qtd = 20;
            ShellSort();
        }else if (opcao == 2){
            system("cls");
            qtd = 50;
            ShellSort();
        }else if (opcao == 3){
            system("cls");
            qtd = 100;
            ShellSort();
        }else if (opcao == 4){
            system("cls");
            qtd = 500;
            ShellSort();
        }else if (opcao == 5){
            system("cls");
            qtd = 1000;
            ShellSort();
        }else if (opcao == 6){
            system("cls");
            qtd = 10000;
            ShellSort();
        }else if (opcao == 7){
            system("cls");
            Menu();
        }else;
    }while (opcao != 7);

    getchar();
}

void BubbleSort(){

    int i, j, fim;
    long int auxnum, trocas = 0;
    char auxnome[100], auxpais[100];
    struct Dados d[qtd];

    testepantheon = fopen("testePantheon.tsv", "r");

    rewind(testepantheon);

    for(i = 0; i < qtd; i++){
        fscanf(testepantheon, "%d\t", &d[i].en_curid);
        fscanf(testepantheon, "%[^\n]s\t", &d[i].name);
        fscanf(testepantheon, "%[^\n]s\n", &d[i].countryName);
    }

    fclose(testepantheon);

    tempoInicial = clock();    ///Começa contar o tempo de compilação

    for (fim = qtd - 1; fim > 0; --fim){
        for (i = 0; i < fim; ++i){
            if (strcmp(d[i].name, d[i + 1].name) > 0){
                trocas++;

                auxnum = d[i].en_curid;
                d[i].en_curid = d[i + 1].en_curid;
                d[i + 1].en_curid = auxnum;

                strcpy(auxnome, d[i].name);
                strcpy(d[i].name, d[i + 1].name);
                strcpy(d[i + 1].name, auxnome);

                strcpy(auxpais, d[i].countryName);
                strcpy(d[i].countryName, d[i + 1].countryName);
                strcpy(d[i + 1].countryName, auxpais);
            }else;
        }
    }

    tempoFinal = clock();      ///Termina de contar o tempo de compilação

    tempoGasto = (((double)(tempoFinal-tempoInicial))/CLOCKS_PER_SEC);  ///Calcula o tempo gasto

    for (i = 0; i < qtd; i++){
        printf("%d\t", d[i].en_curid);
        printf("%s\t", d[i].name);
        printf("%s\n", d[i].countryName);
    }

    ordempantheon = fopen("ordemalfabeticaPantheonBubbleSort.txt", "w");

    for (i = 0; i < qtd; i++){
        fprintf(ordempantheon, "%d\t", d[i].en_curid);
        fprintf(ordempantheon, "%s\t", d[i].name);
        fprintf(ordempantheon, "%s\n", d[i].countryName);
    }

    fclose(ordempantheon);

    printf("\nTEMPO DE EXECUÇÃO DO BUBBLE SORT\n\n");
    printf("Tempo em Segundos: %f", tempoGasto);

    printf("\n\nQUANTIDADE DE TROCAS DO BUBBLE SORT\n\n");
    printf("Quantidade de Trocas: %d", trocas);

    puts("\n");
    system("pause");
    system("cls");
    Menu();
}

void ShellSort(){

    int i, j, h = 1;
    long int auxnum, trocas = 0;
    char value[100], auxnome[100], auxpais[100];
    struct Dados d[qtd];

    testepantheon = fopen("testePantheon.tsv", "r");

    rewind(testepantheon);

    for(i = 0; i < qtd; i++){
        fscanf(testepantheon, "%d\t", &d[i].en_curid);
        fscanf(testepantheon, "%[^\n]s\t", &d[i].name);
        fscanf(testepantheon, "%[^\n]s\n", &d[i].countryName);
    }

    fclose(testepantheon);

    tempoInicial = clock();    ///Começa contar o tempo de compilação

    while (h < qtd){
        h = 3 * h + 1;
    }

    while (h > 0) {
        for (i = h; i < qtd; i++){
            j = i;
            while (j > h - 1){
                if (strcmp(d[j - h].name, d[j].name) > 0){
                    trocas++;

                    auxnum = d[j].en_curid;
                    d[j].en_curid = d[j - h].en_curid;
                    d[j - h].en_curid = auxnum;

                    strcpy(auxnome, d[j].name);
                    strcpy(d[j].name, d[j - h].name);
                    strcpy(d[j - h].name, auxnome);

                    strcpy(auxpais, d[j].countryName);
                    strcpy(d[j].countryName, d[j - h].countryName);
                    strcpy(d[j - h].countryName, auxpais);
                }else;
                j = j - h;
            }
        }
        h = h/3;
    }

    tempoFinal = clock();      ///Termina de contar o tempo de compilação

    tempoGasto = (((double)(tempoFinal-tempoInicial))/CLOCKS_PER_SEC);  ///Calcula o tempo gasto

    for (i = 0; i < qtd; i++){
        printf("%d\t", d[i].en_curid);
        printf("%s\t", d[i].name);
        printf("%s\n", d[i].countryName);
    }

    ordempantheon = fopen("ordemalfabeticaPantheonShellSort.txt", "w");

    for (i = 0; i < qtd; i++){
        fprintf(ordempantheon, "%d\t", d[i].en_curid);
        fprintf(ordempantheon, "%s\t", d[i].name);
        fprintf(ordempantheon, "%s\n", d[i].countryName);
    }

    fclose(ordempantheon);

    printf("\nTEMPO DE EXECUÇÃO DO SHELL SORT\n\n");
    printf("Tempo em Segundos: %f", tempoGasto);

    printf("\n\nQUANTIDADE DE TROCAS DO SHELL SORT\n\n");
    printf("Quantidade de Trocas: %d", trocas);

    puts("\n");
    system("pause");
    system("cls");
    Menu();
}

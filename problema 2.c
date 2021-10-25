//Jesús Huerta Aguilar, Javier de La Luz Ruiz, Ernesto Flores Cesareo
//Programación I - "Programa: Multiplicación de matrices"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//VARIABLES GLOBALES
int FFA=100;
int CCA=100;
int FFB=100;
int CCB=100;
//PROTOTIPOS
void super(int);
void tammtrz(int *,int *,int *,int *);
void entrada(int [][CCA],int [][CCB],int *);
void spaces(int ,int ,int ,int ,int [][CCA],int [][CCB]);
void printab(int ,int [][CCA],int [][CCB]);
void mult(int *,int [][CCA],int [][CCB],int [][CCB]);
void printc(int ,int [][CCA],int [][CCB]);
void cont(char *);
//PRINCIPAL
int main(){
    int FA,FB,CA,CB,reclongval=0;
    char op;
    do{
        tammtrz(&FA,&FB,&CA,&CB);
        int ma[FA][CA],mb[FB][CB],mc[FA][CB];
        FFA = FA; 
        CCA = CA;
        FFB = FB;
        CCB = CB;
        entrada(ma,mb,&reclongval);
        printab(reclongval,ma,mb);
        mult(&reclongval,ma,mb,mc);
        printc(reclongval,ma,mc);
        cont(&op);
    } while (op == 'S' || op == 's');
    getch();
    return 0;
}
//ENCABEZADO
void super(int situa){
    printf("\t\tPROGRAMACION I      -      EQUIPO 8\n");
    printf("\n\t       - - - MULTIPLICACI%cN DE MATRICES - - -",224);
    switch (situa){
    case 1:
        printf(" ");
        break;
    case 2:
        printf("\n\nDIMENCIONES  A[%d x %d]\tB[%d x %d]    %c    C[%d x %d]",FFA,CCA,FFB,CCB,26,FFA,CCB);
        break;
    }
}
//TAMAÑO MATRIZ M N
void tammtrz(int *FA,int *FB,int *CA,int *CB){
    int i=0; 
    do{ 
        system("cls");
        super(1);
        printf("\n\nIngresa el tama%co de la ",164);
        if (i == 0){
            printf("matriz A: \n");
            printf("\n///// FILAS: ");
            scanf("%d",FA);
            printf("///// COLUMNAS: ");
            scanf("%d",CA); 
        }
        else{
            printf("matriz B: \n");
            *FB = *CA;
            printf("\n///// FILAS: %d",*FB);
            printf("\n///// COLUMNAS: ");
            scanf("%d",CB);
        }
        i++;
        if (*FA <= 1 || *FB <= 1 || *CA <= 1 || *CB <= 1){
            printf("\n[!] ERROR: verifica tu informaci%cn [!]",162);
            i--;
            getch();
        }
    } while (i < 2);
}
//INGRESO DE VALORES
void entrada(int ma[][CCA],int mb[][CCB],int *reclongval){
    int n,m,i,j,k,longval;
    char aux[50];
    *reclongval = 0;
    system("cls");
    super(2);
    printf("\n\n\t\t  ||| VALORES DE LA MATRIZ A |||\n");
    n = FFA;
    m = CCA;
    for (i = 0; i <= 1; i++){
        if (i == 1){
            system("cls");
            super(2);
            printf("\n\n\t\t  ||| VALORES DE LA MATRIZ B |||\n");
            n = FFB;
            m = CCB; 
        }
        for (j = 0; j < n; j++){
            printf("\n%c %c %c %c FILA %d\n\n",219,219,219,219,j);
            for (k = 0;k < m; k++){
                printf("\t[%d][%d] %c ",j,k,17);
                if (i == 0){
                    scanf("%d",&ma[j][k]);
                    sprintf(aux,"%d",ma[j][k]);
                }
                else{
                    scanf("%d",&mb[j][k]);
                    sprintf(aux,"%d",mb[j][k]);
                }
                longval = strlen(aux);
                if (longval > *reclongval){
                    *reclongval = longval;
                }
            }
        }
    }
}
// CREACION DE MATRICES
void printab(int reclongval,int ma[][CCA],int mb[][CCB]){
    int i,j=0,k,n,m;
    char l;
    system("cls");
    super(2);
    printf("\n");
    for (i = 0; i < 2; i++){
        printf("\n");
        switch (i){
        case 0:
            l = 'A';
            n = FFA;
            m = CCA;
            break;
        case 1:
            l = 'B';
            n = FFB;
            m = CCB; 
            break;
        }
        for (j = 0; j < n; j++){
            if (j == ceil(n/2)-1){
                printf("    %c = ",l);
            }
            else{
                printf("        ");
            }
            for (k = 0;k < m; k++){
                spaces(i,j,k,reclongval,ma,mb);
            }
            printf("|\n");
        }
    }
}
//AJUSTADOR DE ESPACIOS
void spaces(int i,int j,int k,int reclongval,int ma[][CCA],int mb[][CCB]){
    int swch,izc,e,q;
    char textval[50],textvalf[50],x[50],iz[50],dr[50];
    x[0] = 32;
    x[1] = '\0';
    strcpy(iz,x);
    strcpy(dr,x);
    swch = 0;
    izc = 0;
    do{
        switch (i){
        case 0:
            sprintf(textval,"%d",ma[j][k]);
            break;
        case 1:
            sprintf(textval,"%d",mb[j][k]);
            break;
        }
        strcpy(textvalf,strcat(iz,textval));
        strcat(textvalf,dr);
        e = strlen(textvalf);
        strcpy(iz,x);
        if (e < reclongval + 1 && swch == 0){
            strcat(dr,x);
            swch = 0;
        }
        else{
            izc++;
            for (q = 0; q < izc; q++){
                strcat(iz,x);
            }
            swch = 1;
        }
    } while (e < reclongval + 2);
    printf("|%s",textvalf);
}
//MULTIPLICAR MATRICES A Y B
void mult(int *reclongval,int ma[][CCA],int mb[][CCB],int mc[][CCB]){
    int i,j,k,longval,gmult=0,aux=0;
    char cont[50];
    for (i = 0; i < FFA; i++){
        for (j = 0; j < CCB; j++){
            aux = 0;
            for (k = 0; k < CCA; k++){
                gmult = ma[i][k]*mb[k][j];
                aux = aux + gmult;
                sprintf(cont,"%d",aux);
                longval = strlen(cont);
            }
            mc[i][j] = aux;
            if (longval > *reclongval){
                *reclongval = longval;
            }
        }
    }
}
//IMPRIMIR MATRIZ C
void printc(int reclongval,int ma[][CCA],int mc[][CCB]){
    int i,j=0,k,n,m;
    char l;
    printf("\n");
    for (j = 0; j < FFA; j++){
        if (j == ceil(FFA/2)-1){
            printf("    C = ");
        }
        else{
            printf("        ");
        }
        for (k = 0;k < CCB; k++){
            spaces(1,j,k,reclongval,ma,mc);
        }
        printf("|\n");
    }
}
//CONTINUAR
void cont(char *op){
    int error;
    do{
        error = 0;
        printf("\n%cDesea continuar? [S/N] >> ",168);
        scanf("%s",op);
        if (*op == 's' || *op == 'S'){
            system("cls");
        }
        else{
            if (*op == 'n' || *op == 'N'){
                system("cls");
                printf("\n\n\tGRACIAS POR USAR NUESTROS SERVICIOS");
                printf("\n\n\t   Equipo 8\t-\tBUAP");
            }
            else{
                printf("\n[!] ERROR: Ingresa una opci%cn valida [!]\n",162);
                error = 1;
            }
        }
    } while (error == 1);
}
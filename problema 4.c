//Jesús Huerta Aguilar, Javier de La Luz Ruiz, Ernesto Flores Cesareo.
/* 4. Implemente un programa en C que lea una matriz de dimensión m x n y
almacene la suma de cada fila de la matriz en un arreglo. */
#include <stdio.h>
#include <stdlib.h>
void dimension (int *m,int *n);
void lectura (int m, int n, float matriz[][n]);
void impresion (int m ,int n, float matriz[][n]);
void sumatriz(int m, int n, float matriz[][n]);
int main(){
     int i, j, m, n;
     dimension (&m,&n);
     float matriz[m][n];
     lectura (m, n,matriz);
     impresion (m, n, matriz);
     sumatriz(m, n, matriz);
     system("pause");
     return 0;
}

void impresion( int m, int n, float matriz[][n]){
     int i, j;
     float suma=0, fila[n];
     printf("La Matriz generada es:\n\n");
     for (i=0;i<m;i++){
          for (j=0;j<n;j++){
               printf("[%.2f]", matriz[i][j]);
          }
          printf("\n");
     }
     printf("\n\n");
}
void sumatriz(int m, int n, float matriz[][n]){
     int i, j;
     float suma=0, fila[n];
     for (i=0;i<m;i++){
          suma=0;
          for (j=0;j<n;j++){
               suma+=matriz[i][j];
          }
          fila[i]=suma;
     }
     printf("\n\n La suma de filas es:\n\n");
     for(i=0;i<m;i++){
          printf("[%.2f]",fila[i]);
     }
     printf("\n\n");
}
void dimension (int *m,int *n){
     int error;
     do{
          error=0;
          printf("\nIngrese el numero de columnas en su matriz: ");
          scanf("%d",m);
          printf("\nIngrese el numero de filas en su matriz: ");
          scanf("%d",n);
          if (*m<2 || *n<2){
               printf ("\n Error: alguna dimension ingresada es menor menor a 2\n");
               error=1;
               system("pause");
               system("cls");
          }
     }while(error!=0);
     printf ("\n");
}
void lectura (int m, int n, float matriz[][n]){
     int i, j;
     for (i=0;i<m;i++){
          for (j=0;j<n;j++){
               printf("Ingrese el valor de - fila(%d), columna(%d): ", i+1,j+1);
               scanf("%f", &matriz[i][j]);
          }
          printf("\n");
     }
     system("cls");
}
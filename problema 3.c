//3. Traspuesta

//Librerias
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

//Prototipos
void titulo ();
void dimension(int *m,int *n);
void lectura (int m, int n, int M[][n]);
void impresionOG (int m, int n, int M[][n]);
void trasponer (int m, int n, int M[][n], int W[][m]);
void impresionNW (int m, int n, int W[][m]);
void salida (char *op);

//Principal
int main(){

	int m,n;
	char op;
	do{
		titulo ();
		dimension(&m,&n);
		int M[m][n];
		lectura(m,n,M);
		impresionOG(m,n,M);
		int W[m][n];
		trasponer(m,n,M,W);
		impresionNW(m,n,W);
		fflush(stdin);
		salida (&op);
	}while(op == 's' || op == 'S');

	printf ("\n");
	getch();
	return 0;
}

void titulo(){
	printf("\tOBTENGA LA TRASPUESTA DE UNA MATRIZ\n");
}

void dimension (int *m,int *n){
	int error;
	do{
		error=0;
		printf("\n%c Ingrese el n%cmero de filas en su matriz: ",219,163);	
		scanf("%d",m);
		printf("\n%c Ingrese el n%cmero de columnas en su matriz: ",219,163);	
		scanf("%d",n);		
		if (*m<2 || *n<2){
			printf ("\n ERROR: Alguna dimensi%cn ingresada es menor a 2",162);
			error=1;
			getch();
			system("cls");
		}
	}while(error!=0);
	printf ("\n");
}

void lectura (int m, int n, int M[][n]){
    int i, j;
    system ("cls");
    titulo ();
    printf ("\n%c Ingrese los valores de su matriz en las siguientes posiciones:\n\n",219);
    printf (">>>>Recuerde que acaba de ingresar una matriz de %d x %d<<<<\n\n",m,n);
    for(i = 0; i < m; i++){
        printf("\n///// FILA %d\n\n",i);
        for(j = 0; j < n; j++){
            printf("[%d][%d] >>> ",i, j);
            scanf("%d",&M[i][j]);
        }    
    }
}
void impresionOG (int m, int n, int M[][n]){
    int i, j;
    printf ("\n%c Esta es su matriz ingresada:\n\n",219);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("[%d]\t",M[i][j]);
        } 
        printf("\n");   
    }	
    getch();
}

void trasponer (int m, int n, int M[][n], int W[][m]){
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            W[j][i] = M[i][j];
        }    
    }
}	

void impresionNW (int m, int n, int W[][m]){
    int i, j;
    printf ("\n%c Esta es su matriz traspuesta:\n\n",219);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("[%d]\t",W[i][j]);
        } 
        printf("\n");   
    }	
}

void salida (char *op){
    int error;
    do{
    	error=0;
    	printf("\n%cIngresar otra matriz? (s/n) %c ",168,175);
        scanf("%s",op);
        fflush(stdin);
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
                printf("\n[!] ERROR: Ingresa una opci%cn valida [!]",162);
                error = 1;
            }
        }
    }while(error!=0); 
}

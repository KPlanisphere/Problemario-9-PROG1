//1. Triangular superior

//Librerias
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

//Prototipos
void titulo ();
void dimension(int *N);
void lectura (int N, int M[][N]);
void impresionOG (int N, int M[][N]);
void comprobar (int N, int M[][N]);
void salida (char *op);

//Principal
int main(){

	int N;
	char op;
	do{
		titulo();
		dimension(&N);
		int M[N][N];
		lectura(N,M);
		impresionOG(N,M);
		comprobar(N,M);
		fflush(stdin);
		salida (&op);
	}while(op == 's' || op == 'S');

	printf ("\n");
	getch();
	return 0;
}

void titulo(){
	printf("\tVERIFICA SI SU MATRIZ ES TRIANGULAR SUPERIOR\n");
}

void dimension (int *N){
	int error;
	do{
		error=0;
		printf("\n%c Ingrese la dimensi%cn de su matriz cuadrada: ",219,162);	
		scanf("%d",N);		
		if (*N<2){
			printf ("\n[!] ERROR: Dimensi%cn ingresada es menor a 2 [!]",162);
			error=1;
			getch();
			system("cls");
		}
	}while(error!=0);
	printf ("\n");
}

void lectura (int N, int M[][N]){
    int i, j;
    system ("cls");
    titulo();
    printf ("\n%c Ingrese los valores de su matriz en las siguientes posiciones:\n\n",219);
    printf (">>>>Recuerde que acaba de ingresar una matriz cuadrada de %d x %d<<<<\n\n",N,N);
    for(i = 0; i < N; i++){
		printf("\n///// FILA %d\n\n",i);
        for(j = 0; j < N; j++){
            printf("[%d][%d] >>> ",i, j);
            scanf("%d",&M[i][j]);
        }    
    }
}
void impresionOG (int N, int M[][N]){
    int i, j;
    printf ("\n%c Esta es su matriz ingresada:\n\n",219);
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("[%d]\t",M[i][j]);
        } 
        printf("\n");   
    }	
    getch();
}

void comprobar (int N, int M[][N]){
	int sup=0;
	int diag=0,i=1,j;
	while(i<N){
		j=0;
		do{
			if(M[i][j]==0){
				j++;
			}
			else{
				sup=1;
				break;
			}
		}while((j<i)&&(sup==0));
		i++;
	}
	for ( i = 0; i < N; i++){
		for ( j = 0; j < N; j++){
			if (i != j ){
				diag += M[i][j];
			}
		}
	}
	if(sup==0 && diag != 0){
		printf ("\n%c Es una matriz triangular superior\n",219);
	}
	else{
		printf ("\n%c No es una matriz triangular superior\n",219);
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

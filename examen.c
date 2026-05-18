#include<stdio.h>
void lecturaYAlmacenamiento( );
void conteoDeVotos ( );
void personaGanadora ( );

int primera;
int segunda;
int tercera; 
int matriz[100][10]; 
int i; 
int j;
int número;
int matrizCanción[10];
int matrizOyente[100];
int cont;
int canciónMásVotada1;
int canciónMásVotada2;
int votosmáximos;
int puntosmáximos;
int oyenteganador;
    
int main()
{
   
    lecturaYAlmacenamiento ( );
    while(número!=0)
    {
        conteoDeVotos ( );
        personaGanadora ( );
        número=0;
    }
    return 0;
}


void lecturaYAlmacenamiento ( )
{
    número=0;
    i=0;
    j=0;
    while(i<100)
    {
        while(j<10)
        {
            matriz[i][j]=0;
            j++;
        }
        i++;
    }
    printf ("Escribe las 3 canciones de mayor a menor, con comas, -1 para fin\n");
    cont=0;
    
    while(cont<100 && primera!=-1)
    {
        primera=segunda=tercera=-10;
        printf("oyente %d\n", número);
        scanf("%d,%d,%d", &primera, &segunda, &tercera);
        
        while(segunda == -10 || tercera==-10 || primera<-1 ||primera>9 || segunda<0 ||segunda>9 ||tercera<0 ||tercera>9 || primera==segunda || primera==tercera || segunda==tercera)
        {
            if (segunda == -10 || tercera == -10 )
            {
                printf("Debes ingresar tres números\n");
                printf("oyente %d\n", número);
                primera=segunda=tercera=-10;
                scanf("%d,%d,%d", &primera, &segunda, &tercera);
            }
            
            if ( (primera<-1 ||primera>9 || segunda<0 ||segunda>9 ||tercera<0 ||tercera>9) && (segunda != -10 || tercera!=-10))
            {
                printf("Deben ser números entre 0 y 9\n");
                printf("oyente %d\n", número);
                primera=segunda=tercera=-10;
                scanf("%d,%d,%d", &primera, &segunda, &tercera);
            }
            
            if ((primera==segunda || primera==tercera || segunda==tercera)&& (segunda!=-10 &&tercera!=-10))
            {
                printf("Debes ingresar números diferentes entre sí\n");
                printf("oyente %d\n", número);
                primera=segunda=tercera=-10;
                scanf("%d,%d,%d", &primera, &segunda, &tercera);
            }
        }
        
        if (primera!=-1)
        {
            matriz[cont][primera]=3;
            matriz[cont][segunda]=2;
            matriz[cont][tercera]=1;
            número ++;
        }
        cont++;
    }
    
}


void conteoDeVotos( )
{
   i=0;
   cont=0;
   while (cont<10)
   {
       matrizCanción[cont]=0;
       cont++;
   }
  
   while(i<10)
   {
       cont=0;
       while(cont<10)
       {
           matrizCanción[i]=matrizCanción[i] + matriz[cont][i];
           cont++;
       }
       i++;
   }
    i=0;
    while(i<10)
    {
        printf("La canción %d tuvo ",i);
        printf("%d puntos\n", matrizCanción[i]);
        i++;
    }
    
    i=0;
    votosmáximos=matrizCanción[0];
    canciónMásVotada1=0;
    canciónMásVotada2=0;
    while(i<9)
    {
        if(votosmáximos<matrizCanción[i+1])
        {
            canciónMásVotada1=i+1;
            votosmáximos=matrizCanción[i+1];
        }
        i++;
    }
    printf("La canción más votada es la número %d\n", canciónMásVotada1);
    
    matrizCanción[canciónMásVotada1]=0;
    
    votosmáximos=matrizCanción[0];
    i=0;
    while(i<9)
    {
        if(votosmáximos<matrizCanción[i+1])
        {
            canciónMásVotada2=i+1;
            votosmáximos=matrizCanción[i+1];
        }
        i++;
    }
    printf("La segunda canción más votada es la número %d\n", canciónMásVotada2);
}

void personaGanadora ( )
{
    
    i=0;
    cont=0;
    while(cont<número)
    {
        if(matriz[cont][canciónMásVotada1]!=0)
        {
            matrizOyente[cont]=30;
        }
        if(matriz[cont][canciónMásVotada2]!=0)
        {
            matrizOyente[cont]=matrizOyente[cont]+20;
        }
        if(matriz[cont][canciónMásVotada1]!=0 && matriz[cont][canciónMásVotada2]!=0 )
        {
            matrizOyente[cont]=60;
        }
        printf("Oyente número %d: %d puntos\n",cont, matrizOyente[cont]);
        cont++;
    }
    
    oyenteganador=0;
    puntosmáximos=matrizOyente[0];
    
    cont=0;
    while(cont<número)
    {
        if(matrizOyente[cont+1]>puntosmáximos)
        {
            puntosmáximos=matrizOyente[cont+1];
            oyenteganador=cont+1;
        }
        
        cont++;
    }
    cont=0;
    while(cont<número)
    {
        if(matrizOyente[cont]==puntosmáximos)
        {
            oyenteganador=cont;
            printf("Ha ganado el oyente número %d\n", oyenteganador);
        }
        
        cont++;
    }
}

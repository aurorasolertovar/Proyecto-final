#include<stdio.h>
//aquí van las funciones
void lecturaYAlmacenamiento( );
void conteoDeVotos ( );
void personaGanadora ( );

int primera;
int segunda;
int tercera; 
int matriz[10][10]; 
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
    conteoDeVotos ( );
    personaGanadora ( );
    return 0;
}


void lecturaYAlmacenamiento ( )
{
    i=0;
    j=0;
    while(i<10)
    {
        while(j<10)
        {
            matriz[i][j]=0.0;
            j++;
        }
        i++;
    }
    printf ("Escribe las 3 canciones de mayor a menor, con comas, -1 para fin\n");
    cont=0;
    número=0;
    while(cont<10 && primera!=-1)
    {
        printf("oyente %d\n", número);
        
        scanf("%d,%d,%d", &primera, &segunda, &tercera);
        if (primera!=-1)
        {
            for(i=0; i<10; i++)
            {
                matriz[cont][primera]=3;
                matriz[cont][segunda]=2;
                matriz[cont][tercera]=1;
            }
        }
        
        número ++;
        cont++;
    }

    
    
}


void conteoDeVotos( )
{
   i=0;
   matrizCanción[10]={(0,0,0,0,0,0,0,0,0,0)};
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
       //
    
    

    for(i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            printf("%d ", matriz[i][j]);
        
        }
        
        printf("\n");
      
    }
    
    ////
    i=0;
    cont=0;
    while(cont<número-1)
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
    printf("Ha ganado el oyente número %d", oyenteganador);
    
}

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
int cont;
int canciónMásVotada1;
int canciónMásVotada2;
int votosmáximos;
    
int main()
{
   
    lecturaYAlmacenamiento ( );
    conteoDeVotos ( );
    personaGanadora ( );
    return 0;
}


void lecturaYAlmacenamiento ( )
{
    
    for(i=0; i<10 ; i++)
    {
        for(j=0; j<10 ; j++)
        {
            matriz[i][j]=0;
        }
    }
    printf ("Escribe las 3 canciones de mayor a menor, con comas, -1 para fin\n");
    cont=0;
    número=0;
    while(cont<10 && primera!=-1)
    {
        printf("oyente %d\n", número+1);
        
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
    printf("La segunda canción más votada es la número %d", canciónMásVotada2);
}

void personaGanadora ( )
{
    cont=0;
    while (cont<número)
    {
        if(matriz[cont][canciónMásVotada1]=3)
        {
            
        }
    }
}

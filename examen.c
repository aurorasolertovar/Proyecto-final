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
int matrizCanciónMásVotada[10];
int matrizSegundaCanciónMásVotada[10];

    
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
    printf ("Existen diez canciones numeradas del 0 al 9 por las cuales se puede votar. \nPídele a tus oyentes que elijan tres canciones y las ordenen empezando por la que más les guste.\nDespués, escribe separados por comas los tres números que te digan\nPara dejar de agregar canciones, debes escribir: -1, cualquier número, cualquier número.\n");
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
    
    
    votosmáximos=matrizCanción[0];
    cont=0;
    while (cont<10)
    {
        matrizCanciónMásVotada[cont]=0;
        cont++;
    }
    cont=0;
    while (cont<10)
    {
        matrizSegundaCanciónMásVotada[cont]=0;
        cont++;
    }
    canciónMásVotada1=0;
    canciónMásVotada2=0;
    i=0;
    while(i<9)
    {
        if(votosmáximos<matrizCanción[i+1])
        {
            canciónMásVotada1=i+1;
            votosmáximos=matrizCanción[i+1];
        }
        i++;
    }
    
    i=0;
    while(i<10)
    {
        if(votosmáximos==matrizCanción[i])
        {
            matrizCanciónMásVotada[i]=1;
        }
        i++;
    }
    
    i=0;
    while(i<10)
    {
        if (matrizCanciónMásVotada[i]==1)
        {
         printf("La canción más votada es la número %d\n", i);
        }
        i++;
    }
    
    i=0;
    while(i<10)
    {
        if (matrizCanciónMásVotada[i]==1)
        {
            matrizCanción[i]=0;
        }
        i++;
    }
    
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
    
    i=0;
    while(i<10)
    {
        if(votosmáximos==matrizCanción[i])
        {
            matrizSegundaCanciónMásVotada[i]=1;
        }
        i++;
    }
    
    i=0;
    while(i<10)
    {
        if (matrizSegundaCanciónMásVotada[i]==1)
        {
         printf("La segunda canción más votada es la número %d\n", i);
         
        }
        i++;
    }
}

void personaGanadora ( )
{
    
    i=0;
    cont=0;
    while(cont<número)
    {
        i=0;
        while(i<10)
        {
            if(matrizCanciónMásVotada[i]==1)
            {
                if(matriz[cont][i]!=0)
                {
                    matrizOyente[cont]=30;
                }
            }
            i++;
        }
        
        
        i=0;
        while(i<10)
        {
            if(matrizSegundaCanciónMásVotada[i]==1 && i<10)
            {
                if(matriz[cont][i]!=0)
                {
                    if(matrizOyente[cont]==30)
                    {
                        matrizOyente[cont]=60;
                    }
                    else
                    {
                        matrizOyente[cont]=20;
                        i=10; 
                    }
                    
                }
            }
            i++;
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

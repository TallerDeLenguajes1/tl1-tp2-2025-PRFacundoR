#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 6
#define M 10
#define C 5

struct {
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
   }typedef compu;



   void listarPCs(compu *pcs){

    for (int i = 0; i < C; i++)
    {
        printf("La velocidad de procesamiento es %d\n", pcs[i].velocidad);
        printf("El anio de fabricacion es %d\n", pcs[i].anio);
        printf("La cantidad de nucleos es %d\n", pcs[i].cantidad_nucleos);
        printf("El tipo de cpu es " );
        
        puts(pcs[i].tipo_cpu);
        printf("\n");

    }
    

   }


   void mostrarMasVieja(compu *pcs){

    int aux=3000;
    int j=0;
    for ( int i=0; i < C; i++)
    {
       
        
        if (pcs[i].anio<aux)
        {
            aux=pcs[i].anio;
            j=i;
        }
    
    }
    
        printf("La velocidad de procesamiento es %d\n", pcs[j].velocidad);
        printf("El anio de fabricacion es %d\n", aux);
        printf("La cantidad de nucleos es %d\n", pcs[j].cantidad_nucleos);
        printf("El tipo de cpu es ");
        puts(pcs[j].tipo_cpu);
        printf("\n");


   }


int main()
{
    compu *compus=(compu* )malloc(C*sizeof(compu));
    char tipos[N][M] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
        "Pentium"};

    int pos;
        
    srand(time(NULL));

    for (int i = 0; i < C; i++)
    {
        compus[i].velocidad= rand()%(3+1-1)+1;
        compus[i].anio=rand()%(2024+1-2015)+2015;
        compus[i].cantidad_nucleos=rand()%(8+1-1)+1;
        
        compus[i].tipo_cpu=(char*)malloc(M*sizeof(char));

        pos=rand()%(N);
        
          strcpy(compus[i].tipo_cpu,tipos[pos]);  
        
        /*for (int j = 0; j < N; j++)
        {
            for (int z = 0; z < M; z++)
            {
                
                compus[i].tipo_cpu[z]=tipos[][];
            }
            
        }*/
        

    }
    printf("Lista de PCs\n");
    listarPCs(compus);

    printf("La PC mas vieja\n");
    mostrarMasVieja(compus);
    
    for (int i = 0; i < C; i++)
    {
        free(compus[i].tipo_cpu);
    }
    free(compus);

    
    
    return 0;
}

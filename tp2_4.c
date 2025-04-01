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

        pos=rand()%(5+1);
        int z=0;
        while (tipos[pos][z]!='\0')
        {
            int j=0;
          strcpy(compus[i].tipo_cpu[j],tipos);
            j++;
            z++;
        }
        
           
        
        
        
        
        /*for (int j = 0; j < N; j++)
        {
            for (int z = 0; z < M; z++)
            {
                
                compus[i].tipo_cpu[z]=tipos[][];
            }
            
        }*/
        

    }
    


    
    
    return 0;
}

//La técnica empleada para resolver el problema fué programación dinámica para que no fuese necesario volver a comparar los caracteres que ya habían sido pasados por el proceso
//Complejidad: O(n^2) ya que en el peor de los casos las secuencias a comparar tienen la misma longitud que multiplica el número de veces que se ejecutan los ciclos
//Alberto Pascal A01023607

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

    int longSubsecuencia(int n, int m, char *arr1, char *arr2)
    {
        int comparativa[n+1][m+1]; // arreglo bidimensional que contiene la matriz de comparación (longitud más larga)

        for(int i=0; i<=n; i++) // recorre filas
        {
            for(int j=0; j<=m; j++) // recorre columnas
            {
                if(i==0 || j==0) // la primera fila y columna tienen asignado cero coincidencia
                {
                    comparativa[i][j] = 0;
                }else{
                    if(arr1[i-1] == arr2[j-1]) // en caso de que los caracteres en esa posición sean iguales
                    {
                        comparativa[i][j] = comparativa[i-1][j-1]+1; // se le añade uno a la cuenta de caracteres repetidos
                    }else{
                        comparativa[i][j] = max(comparativa[i-1][j], comparativa[i][j-1]); // en caso de que no coincidan los caracteres se asigna la cuenta más alta claculada en la fila actual
                    }
                }
            }
        }
        
        //imprime la subsecuencia encontrada recorriendo inversamente la matriz
        
        int k = comparativa[n][m];// arreglo que almacena la subsecuencia
        char subsecuencia[k+1];
        
        int i = n;
        int j = m;
        
        while(i>0 && j>0) // mientras que el ciclo no llegue a la esquina superior izquierda se seguirá corriendo
        {
            if(arr1[i-1] == arr2[j-1]) // cuando el último caracter de las subsecuencias coinciden se almacena automáticamente en el arreglo de caracteres de salida
            {
                subsecuencia[k-1] = arr1[i-1];
                i--;
                j--;
                k--;
            }else{ // en el caso de que no coincidan se aplica la lógica para discernir si se va a en diagonal izquierda o diagonal derecha basandose en el número mayor
                if(comparativa[i-1][j] > comparativa[i][j-1])
                {
                    i--;
                }else{
                    j--;
                }
            }
        }
        
        cout << "Subsecuencia: " << subsecuencia << endl;
        
        return comparativa[n][m];
    }

int main()
{
    char arr1[] = "AJIKLN";
    char arr2[] = "AILMJN";

    int n = strlen(arr1);
    int m = strlen(arr2);

    cout << "longitud " << longSubsecuencia(n, m, arr1, arr2);
}

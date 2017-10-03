//Alberto Pascal A01023607

#include <iostream>
#include <fstream>

using namespace std;
 /*complejidad O(n) porque en el peor de los casos tendría que recorrer todas las gasolineras pero no tenemos ciclos anidados. 
 Por lo tanto, jamás multiplicaré N*N y se queda lineal.Usa Algoritmos ávidos*/
class camionero
{
public:
    float *distancias;
    int n;
    float kmpt;

    camionero(){}

    camionero(string archivo, float kmpt)
    {
        this->kmpt = kmpt;
        leeDistancias(archivo);
    }

    void leeDistancias(string archivo)
    {
        ifstream entrada(archivo);
        entrada >> n;

        distancias = new float[n];

        for(int i=0; i<n; i++)
        {
            entrada >> distancias[i];
        }
    }

    void calcular()
    {
        float tmp = kmpt;
        for(int i=0; i<n; i++)
        {
            if(tmp-distancias[i]<distancias[i+1])
            {
                cout << "Se requiere de carga en la gasolinera " << i+1 << endl;
                cout << "Faltarian " << distancias[i+1]-(tmp-distancias[i]) << "km para llegar" << endl << endl;
                tmp = kmpt;
            }else{
                cout << "No se carga gasolina en la gasolinera " << i+1 << endl;
                tmp = tmp-distancias[i];
                cout << "distancia en tanque restante: " << tmp << "km" << endl << endl;
            }
        }
    }
};

int main()
{
    camionero ejemplo("datos.txt", 300);
    ejemplo.calcular();
    return 0;
}

//Alberto Pascal A01023607
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// https://biblioteca.unirioja.es/tfe_e/TFE001024.pdf
/*http://www.geeksforgeeks.org/stable-marriage-problem/

 Complejidad: O(n^2) porque se recorre la matriz que tiene que recorrer n elementos de un vector n veces. En el peor de los casos voy a tener
 que checar toda mi matríz y no sólo parte de ella.
 Técnica: Backtracking
*/

bool checaMejorHombre(vector<vector<int>> pref, int hombre, int mujer, int hombre1, int n);

void Relaciona(vector<vector<int>> pref, int columnas);

int main() {

  //tam de columnas y columnas de las matrices de hombres y mujeres
  int columnas = 4;

  //matriz de preferencias de hombres y mujeres
  vector<vector<int>> pref(2 * columnas, vector<int>(columnas));

  
  pref =
  {
    //hombres
    { 4, 5, 6, 7 },
    { 7, 6, 7, 4 }, 
    { 5, 7, 4, 5 }, 
    { 6, 4, 5, 6 }, 

    //mujeres
    { 0, 1, 2, 3 }, 
    { 1, 2, 3, 0 }, 
    { 2, 3, 0, 1 }, 
    { 3, 0, 1, 2 }, 

  };

  Relaciona(pref, columnas);

}//cierre del main


void Relaciona(vector<vector<int>> pref, int columnas) {

  vector<int> parejaMujeres;
  vector<bool> asignadosH;

  //se ponen a todas las mujeres y hombres disponibles
  for (int i = 0; i < columnas; i++) {

    parejaMujeres.push_back(-1);
    asignadosH.push_back(false);

  }

  int H_disponibles = columnas;

  while (H_disponibles > 0) {

    int hombre;

    for (int i = 0; i < columnas; i++) {

      if (asignadosH[i] == false) {
        hombre = i;
        i = columnas;
      }

    }

    for (int i = 0; (i < columnas) && (asignadosH[hombre] == false); i++) {

      int mujer = pref[hombre][i];

      if (parejaMujeres[mujer - columnas] == -1) {
        parejaMujeres[mujer - columnas] = hombre;
        asignadosH[hombre] = true;
        H_disponibles--;
      }

      else {

        int otroHombre = parejaMujeres[mujer - columnas];

        if (checaMejorHombre(pref, hombre, mujer, otroHombre, columnas) == false) {
          parejaMujeres[mujer - columnas] = hombre;
          asignadosH[hombre] = true;
          asignadosH[otroHombre] = false;
        }

      }

    }

  }

  for (int i = 0; i < columnas; i++) {
    cout << "La mujer no." << i + columnas << " fue asignada al hombre no." << parejaMujeres[i] << endl;
  }

}


bool checaMejorHombre(vector<vector<int>> pref, int hombre, int mujer, int otroHombre, int columnas) {

  for (int i = 0; i < columnas; i++) {

    if (pref[mujer][i] == otroHombre) {
      return true;
    }
    if (pref[mujer][i] == hombre) {
      return false;
    }

  }

  return false;

}

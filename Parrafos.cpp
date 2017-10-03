//Alberto Pascal A01023607

#include <iostream>
#include <vector>
#include <math.h>
#include<string>
using namespace std;
/* Es de complejidad O(n) porque solamente se utiliza un for para revisar el espacio que se está ocupando. Utiliza Algoritmo ávido

*/
float Reduccion(float red, float amplitudIdeal, int j, int i);
float PenalizarAmpliar(float amp, float amplitudIdeal, int j, int i);

int main(int argc, const char * argv[]) {
  
 
  vector<string> texto_a_justificar = {"Esta", "es", "una", "prueba", "para", "ver","si", "divide", "correctamente", "los", "parrafos"};
  vector<int> Word_size;
  vector<string> linea;
  
  //longitud 'L' de las líneas
  float Line = 25;
  float tamano_completa = 0;
  float tamano_Espacio = 0;
  float amplitudIdeal = 1;
  float sobrante;
  
  int i = 0;
  int j;
  
  float red;
  float amp;
  
  bool mostrado = true;
  
  for (int i = 0; i < texto_a_justificar.size(); i++) {
    Word_size.push_back( int(texto_a_justificar[i].length()) );
  }
  
  for (j = 0; j < texto_a_justificar.size(); j++) {
    
    if (mostrado) {
      i = j;
      mostrado = false;
      linea.clear();
      tamano_completa = 0;
    }
    
    tamano_completa += Word_size[j];
    tamano_Espacio = tamano_completa + ((j - i) * amplitudIdeal);
    
    if (tamano_Espacio > Line) {
      sobrante = tamano_Espacio - Line;
      red = amplitudIdeal - (sobrante / (j - i));
      amp = amplitudIdeal + (Line - ( (tamano_completa - Word_size[j]) + (amplitudIdeal * (j - i - 1) ) ) ) / (j - i - 1);
      
      if ( PenalizarAmpliar(amp,amplitudIdeal,j,i) > Reduccion(red, amplitudIdeal,j,i) && red > 0 ) {
        linea.push_back(texto_a_justificar[j]);
        
        for (int i = 0; i < linea.size(); i++) {
          cout << linea[i] << " ";
        }
        
        cout << " " <<  "-> reducción en la línea de: " << red << " mm.";
        cout << endl;
        mostrado = true;
      }//cierre del segundo if
      else {
        for (int i = 0; i < linea.size(); i++) {
          cout << linea[i] << " ";
        }
        
        cout << " " << "-> ampliación en la línea de: " << amp << " mm.";
        cout << endl;
        j--;
        mostrado = true;
      }//cierre del else
      
    }//cierre del primer if
    
    linea.push_back(texto_a_justificar[j]);
    
  }//cierre del for
  
  
  for (int i = 0; i < linea.size(); i++) {
    cout << linea[i] << " ";
  }
  
  cout << endl;
  
}//cierre del main



float Reduccion(float red, float amplitudIdeal, int j, int i) {
  //valor absoluto
  return ( fabs(red - amplitudIdeal) * (j - i) );
}

float PenalizarAmpliar(float amp, float amplitudIdeal, int j, int i) {
  //valor absoluto
  return ( fabs(amp - amplitudIdeal) * (j - i - 1) );
}
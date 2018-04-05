#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int mayor(int a, int b);

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  Album(int n);
  bool esta_lleno();
  void compra();
  int * Alb();
  int * rep();
  int n_r();
  void da_repetida(int i);
  void recibe_repetida(int i);

private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int n_sobres_comprados;

  int *album;
  int *repetidas;
};

void cambia(Album A, Album B);

int * Album::Alb(){
  return album;
}

int * Album::rep(){
  return repetidas;
}
void Album::da_repetida(int i){
  repetidas[i] = repetidas[i] - 1;
  n_repetidas -= 1;
}

void Album::recibe_repetida(int i){
  album[i] += 1;
  n_en_album += 1;
}

int Album::n_r(){
  return n_repetidas;
}

void Album::compra(){
  cout << "Numero de sobres comprados" << " " << n_sobres_comprados << endl;
}

void Album::Status(void){
  cout << n_en_album << " "<<n_repetidas << " " << n_sobres_comprados << endl;
}

void Album::CompraSobre(int n_en_sobre){
  int lamina;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
  n_sobres_comprados++;
}

bool Album::esta_lleno(){
  if(n_total == n_en_album){
    return true;
  }
  else{
    return false;
  }
}

Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_sobres_comprados = 0;
  n_repetidas = 0;
  n_en_album = 0 ;
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}

int menor(int a, int b){
  if(a>b){
    return b;
      }
  
  else{
    return a;
  }
  
}

void cambia(Album A, Album B){
  int * Album_a = A.Alb();
  int * Album_b = B.Alb();
  int * rep_a = A.rep();
  int * rep_b = B.rep();
  for(int i = 0; i<661; i++){
    if(rep_a[i] != 0 and Album_b[i] == 0){
      A.da_repetida(i);
      B.recibe_repetida(i);
    }
    if(rep_b[i] != 0 and Album_a[i] == 0){
      B.da_repetida(i);
      A.recibe_repetida(i);
    }
  }
}


int main(){
  srand(time(0));
  Album A(660);
  Album B(660);
  int n_compradas = 0;
  while(!A.esta_lleno() and !B.esta_lleno()){
    A.CompraSobre(5);
    B.CompraSobre(5);
    cambia(A,B);
    n_compradas ++;
  }
  cout << n_compradas << endl;
}

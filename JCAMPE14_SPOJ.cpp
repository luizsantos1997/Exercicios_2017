#include<iostream>

using namespace std;



int main(){

  int Cvi=0,Cem=0,Cgol=0,Cponto=0;
  int Fvi=0,Fem=0,Fgol=0,Fponto=0;

  cin >>Cvi>>Cem>>Cgol>>Fvi>>Fem>>Fgol;
  Cponto = (3*Cvi)+Cem;
  Fponto = (3*Fvi)+Fem;


    bool retorno = true;

    if((Cvi < 0 || Cvi > 100)|| Cem < 0 || Cem > 100 ){
      retorno = false;
    }
    if((Fvi < 0 || Fvi > 100)|| Fem < 0 || Fem > 100 ){
        retorno = false;
    }
    if(Cponto < -1000 || Cponto > 1000){
        retorno = false;
    }
    if(Fponto < - 1000 || Fponto > 1000){
      retorno = false;
    }


  if(retorno){ // CONDIÇÃO PARA FUNCIONAMENTO
  if(Cponto > Fponto){
    cout << "C" << endl;  // TESTA PONTUAÇÂO
  }else if(Fponto > Cponto){
    cout << "F" << endl;  // TESTA PONTUAÇÂO
  }else if(Fponto == Cponto){
    if(Cgol > Fgol){    // TESTA SALDO DE GOLS
      cout << "C" << endl;
    }else if(Fgol > Cgol){  // TESTA SALDO DE GOLS
      cout << "F" << endl;
    }else{    // TESTA SALDO DE GOLS IGUAIS
      cout << "=" << endl;
    }

  } // END SALDO DE GOLS
}

}

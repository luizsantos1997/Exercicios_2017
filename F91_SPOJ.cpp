
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int f91(int n){ // FUNÇÃO RECURSIVA
    	if (n <= 100) {
			return f91(f91(n + 11));
		}
		else {
			return n - 10;
		}
	}
bool condicaoIN(int n) { // CONDIÇÃO DO TESTE
	bool retorno = false;
	if (n <= 1000000 && n > 0) {
		retorno = true;
	}
	return retorno;
}
int main(){
		
	
	
	int data ;
	
	string saida = ""; // APRESENTAÇÃO FORMATADA EM	COMPILAÇÃO
	int resultado = 0;
	int count = 1;
	cin >> data;
	while (data > 0 && count < 250000) {
		
		if (condicaoIN(data)) {
			resultado = f91(data);
			saida += "f91("+to_string(data)+") = "+to_string(resultado)+ '\n'; // realizar inserção no vector para print
			
			count++;
			cin >> data;
		} // END IF INTERNO
		
	} 
	cout << saida;
	return 0;
}

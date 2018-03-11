#include <iostream>
// author: Luiz Eduardo

using namespace std;

bool Validar(int inicio, int fim) { // FUN��O PARA VALIDAR CONDI��O
	
	if ((1 <= inicio) && (inicio <= fim) && (fim <= 1000000000) && (fim - inicio <= 100000)) {
		return true;
	}
	return false;
}
bool isPrime(int n) {
	bool retorno = true; // declara��o do bool true
	for (int i = (n-1); i > 1; i--) { // REALIZAR LOOP DE PRIMO COME�ANDO DE N-1 at� 2
		if ( n % i  == 0) {       // CONDI��O PARA ACHAR DIVISOR COM RESTO 0 == numero n � primo
			return false;
		}
		
	} 
	return retorno;
}
void print_prime(int inicio, int fim) {
	while (inicio <= fim) {
		if (inicio == 1) { inicio++; continue; }
		else {
			if ( isPrime( inicio ) ) { //CHAMANDO FUN��O isPrime com invers�o de resposta
				cout << inicio << endl;
			} //END IF INTERNO
		} // END ELSE
		inicio++;
	} // END WHILE LOOP
}

void main() {
	int array_index;
	cin >> array_index;
	int begin, end;

	for (int i = 0; i < array_index; i++) { // quantidades de testes loop
		
		cin >> begin >> end;
		if (Validar(begin, end)) {
			print_prime(begin, end);
		}
		cout << endl;
		begin = 0; end = 0;
	}
}
#include<iostream>

using namespace std;

class no_simples{
public:
	int valor;
	no_simples * prox;

};
class Lista_Circula{
public:
	no_simples * cabeca;
	no_simples * cauda;

	bool isEmpty(){
		return cabeca == NULL;
	}
	void push_front(int valu){
		no_simples * novo = new no_simples;
		novo->valor = valu;

		if(isEmpty()){
			cabeca = cauda = novo;
			cauda->prox = cabeca;
		}else{
			novo->prox = cabeca;
			cabeca = novo;
			cauda->prox = cabeca;
		}
	} // END PUSH FRONT
	void push_back(int value){
		if(isEmpty()){
			push_front(value);
		}else{
			no_simples * novo = new no_simples;
			cauda->prox = novo;
			cauda = novo;
			cauda->prox = cabeca; // LINHA RESPONSAVEL PELO FATOR CIRCULAR DA LISTA
		}
	}
	void verificar_lista(){
		no_simples * auxiliar = cabeca;
		while(auxiliar != cauda){
			if(auxiliar->prox == cauda){
				break;
			}
			cout << "Lista Completa - " << auxiliar->valor << endl;
			auxiliar = auxiliar->prox;

		}
	}
	};

int main(){
	Lista_Circula l;
	l.push_front(1);
	//l.push_front(2);
	l.push_front(3);
	//l.push_front(4);
	l.push_front(5);
	//l.push_front(6);
	l.push_front(7);
	//l.push_front(8);
	l.push_front(9);
	//l.push_front(10);
	//l.mostrar_par();

	l.verificar_lista();
	cout << "cheguei aqui " << endl;
	return 0;
};

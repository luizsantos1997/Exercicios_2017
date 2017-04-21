#include <iostream>

using namespace std;

// classe no
class no{
	public:
	int v;
	no* prox;
	no* revi;

	no(int v=0) // construtor
	{
		this->v = v;
		this->prox = NULL;
	}


	int obterValor() // obtém o valor
	{
		return v;
	}

	no* obterProx() // obtém o próximo no
	{
		return prox;
	}
	no* obterRevi() // obtém o próximo no
	{
		return revi;
	}


	void setProx(no* p) // seta o próximo no
	{
		prox = p;
	}
	void setRevi(no* p) // seta o próximo no
	{
		revi = p;
	}
};

// classe Lista
class Lista{
public:
	no* cabeca; // primeiro elemento
	no* cauda; // último elemento


	Lista()
	{
		// se não passar elemento, então cabeca e cauda são NULL

		cabeca = NULL;
		cauda = NULL;
	}

	Lista(int v)
	{
		// se passar elemento, então cria novo no
		cabeca = new no(v);
		cauda = cabeca;
	}

  void mostrar(){
    no* aux = cabeca;

		cout << " ---- MOSTRAR TODOS ----"<< endl;
    if(vazio()){
			cout << " Lista VAZIA" << endl;

  	}else{
			while(aux){
        cout << aux->obterValor() <<" FUCK " <<endl;

				aux = aux->obterProx();

			}
		}
	}
  void push_front(int v=0){
    no * aux = new no(v);
		aux->setRevi(NULL);

		cout << " ---- PUSH FRONT ----"<< endl;
		if(vazio()){
			cabeca = aux;
			cauda = aux;
		}else{
    aux->setProx(cabeca);
		cabeca->setRevi(aux);
    cabeca = aux;
	}
  }
	void push_back(int v=0){

		cout << " ---- PUSH BACK ----"<< endl;
		no * aux = new no(v);

		aux->setProx(NULL);

		if(vazio()){
			cabeca = aux;
			cauda = aux;
		}else{
		aux->setRevi(cauda);
    cauda->setProx(aux);
    cauda = aux;
		}
  }


	bool vazio(){
		if (cabeca == NULL && cauda == NULL){
			return true;
		}
		return false;
	}

	int existe(int comparar){
		no * aux = cabeca;
		int contador = 0;
		while(aux){
			if(aux->obterValor() == comparar){
				contador++;
			}else{}
			aux = aux->obterProx();
		}
			return contador;
	}// FIM existe

	void pop_front(){

			cout << "------ POP_FRONT -----"<<endl;
			if(vazio()){
				cout << " NÃO EXISTE ELEMENTO PARA SER EXCLUIDO !" << endl;
			}else{
				cabeca->prox->revi = NULL;
				cabeca = cabeca->obterProx();

			}
	}

	void pop_back(){

			cout << "----- POP_BACK -----"<<endl;
			if(vazio()){
				cout << " NÃO EXISTE ELEMENTO PARA SER EXCLUIDO !" << endl;

			}else{
				cauda->revi->prox = NULL;
				cauda = cauda->obterRevi();

			}

	}

	void delete_x(no * deleter){
		std::cout << "DELETER ON" << '\n';

		if(cabeca != deleter && deleter != cauda){

				std::cout << "ENTREI PRIMEIRO IF" << '\n';
				deleter->prox->revi = deleter->revi->revi;
				deleter->revi->prox = deleter->prox->prox;

		}else if(deleter == cabeca){
			pop_front();
		}else if(deleter == cauda){
			pop_back();
		}else{
			std::cout << "NAO TEM OQ DELETER PARÇA" << '\n';
		}

	}
	void qtd_Dois(int x, int y){
		int xis = existe(x);
		int ipsilon = existe(y);
		if(xis > 0 < ipsilon){
			cout << "TEM - "<< xis << " - " << x << endl;

				cout << "TEM - "<< ipsilon << " - " << y << endl;
		}else{
			cout << "NAO TEM ESSES ELEMENTOS NA LISTA" << endl;
		}
	}

}; // FIM CLASSE LISTA

int main(){
  Lista l;
	l.push_front(5);
	l.push_front(15);
	l.push_front(25);
	l.push_front(35);
	l.push_front(35);
	l.push_front(35);
	l.push_front(35);
	l.push_front(35);
	l.push_front(45);
	l.push_front(45);
	l.push_front(45);
	l.push_front(45);
	l.push_front(55);
	l.push_back(81);
	l.mostrar();
	l.qtd_Dois(35,45);
	
  l.mostrar();

  return 0;

}

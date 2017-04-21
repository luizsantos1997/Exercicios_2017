  #include<iostream>

  using namespace std;

  class pilha{
  	public:
  	int v;
    int qtd;
  	pilha* prox;
  	pilha* Top;

    pilha(){ // construtor
      prox = NULL;
      Top = prox;
      qtd = 0;
    }

    bool isEmpty(){
      if(Top == NULL){
        cout << " PILHA VAZIA " << endl;
        return true;
      }
      return false;

    }

    void makeEmpty(){
      Top = NULL;
    }

    void push(int t){
      cout << "PUSH "<< endl;
      pilha* novo = new pilha;
      novo->v = t;

      if(isEmpty()){
      Top = novo;
      Top->prox = NULL;

      }else{

      novo->prox = Top;
      Top = novo;

      }
      qtd++;
      mostrar();
    }
    void pop(){
      cout << "POP" << endl;
      Top = Top->prox;
      qtd--;
      mostrar();
    }

    void mostrar(){
      cout << "MOSTRAR " << endl;
      pilha* novo = new pilha;
      novo = Top;
      while(novo){
        if(isEmpty()){
          return;

        }else{
        cout << novo->v<< endl;
        novo = novo->prox;
        }

      }

    }

  };

  int main(){
    pilha pi ;


    pi.push(10);
    pi.push(10);
    pi.push(1);
    pi.pop();
    pi.pop();
    pi.pop();
    return 0;
  };

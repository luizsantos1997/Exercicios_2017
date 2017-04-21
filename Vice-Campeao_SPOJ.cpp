#include<iostream>

using namespace std;



int main(){
 int P1,C1,P2,C2;
 int T1, T2;
 cin >> P1 >> C1 >> P2 >> C2;
 T1 = P1 * C1;
 T2 = P2 * C2;

 if(T1 == T2){
   cout << "0"<<endl;
 }else if(T1 > T2){
   cout << "-1" <<endl;
 }else{
   cout << "1" <<endl;
 }

}

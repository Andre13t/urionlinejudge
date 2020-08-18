#include <iostream>
#include <vector>
using namespace std;
 
int main() {
 
   int altura{}, espessura{}, galhos{}, iteracoes{},vezes{};
   cin >> vezes;
   vector <bool> validacao;
   while(iteracoes != vezes){
	   cin>> altura >> espessura >> galhos;

	   if((altura >=200 && altura <= 300) && (espessura >= 50) && (galhos >= 150))
		{
			validacao.push_back(1);
		}else
		{
			validacao.push_back(0);
		}
		iteracoes++;
   }
   for(int i = 0; i< vezes;i++)
   {
	   if(validacao[i])
	   {
		cout<< "Sim" << endl;
		}else
		{
			cout<< "Nao" << endl;
		}
   }
    return 0;
}

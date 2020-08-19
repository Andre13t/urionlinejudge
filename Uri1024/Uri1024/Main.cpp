#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <cstring>
using namespace std;


int main()
{
	/*
	São feitas três passadas em todo o texto.

	Na primeira passada, somente caracteres que sejam
	letras minúsculas e maiúsculas devem ser deslocadas 3 posições para a direita

	Ex:segundo a tabela ASCII: letra 'a' deve virar letra 'd', letra 'y' deve
	virar caractere '|' e assim sucessivamente

	Na segunda passada, a linha deverá ser invertida. Na terceira e última passada,
	todo e qualquer caractere a partir da metade em diante
	truncada) devem ser deslocados uma posição para a esquerda na tabela ASCII.
	Neste caso, 'b' vira 'a' e 'a' vira '`'.

	Por exemplo, se a entrada for “Texto #3”, o primeiro processamento sobre esta entrada
	deverá produzir “Wh{wr #3”. O resultado do segundo processamento inverte os caracteres
	e produz “3# rw{hW”. Por último, com o deslocamento dos caracteres da metade em diante,
	o resultado final deve ser “3# rvzgV”.

	entrada							saida
	4								3# rvzgV
	Texto #3						1FECedc
	abcABC1							ks. \n{frzx
	vxpdylY .ph						gi.r{hyz-xx
	vv.xwfxo.fd

	*/
	string criptografia(const string & entrada);
	string entrada{};
	vector<string> saidas{};
	int vezes;


	cin >> vezes;
	for (int i = 0; i < vezes; i++)
	{
		if(i== 0)
			cin.ignore();
		
		getline(cin, entrada); 
		
		saidas.push_back(criptografia(entrada));

	}
	for (string saidas : saidas)
	{
		cout << saidas << endl;;
	}
}

string criptografia(const string& entrada)
{
	unsigned  int d{ entrada.length() };

	string aqui{ entrada }, aux{ entrada }, aux2{ entrada };

	for (size_t i = 0; i < aqui.length(); i++)
	{
		if ((aqui.at(i) >= 97 && aqui.at(i) <= 122) || (aqui.at(i) >= 65 && aqui.at(i) <= 99))
			aux.at(i) = aqui.at(i) + 3;
	}


	aux2 = aux;
	for (size_t j = 0; j < entrada.length(); j++)
	{
		//aux2.at(j) = aux.at(j);
		aux.at(j) = aux2.at((d - 1) - j);


	}

	for (size_t i = 0; i < entrada.length(); i++)
	{
		if (i >= d / 2) {
			aux.at(i) = aux.at(i) - 1;
		}
	}

	return aux;
}


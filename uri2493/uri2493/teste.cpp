#include <cstdio>
#include<stdio.h> 
#include<stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {

	vector<vector<bool>> testeRespsotas(int vezes, vector<string> todosNomes, vector<int> possConta, vector<string> todosOpera, vector<vector<bool>> quaisOperadore, vector<vector<bool>> acertaraolista, vector<bool> operacaoCorretas, vector<vector<int>> todasContas);
	void reorganizarNomes(vector<string> todosNomes);

	/*
	entrada
	quantidad de e contas
	entrada = "X Y=Z" depois de todas as ccontas
	nomes qual o numero da conta em sequecia e operaçao

	saida
	se todos acertarem imprimi "You Shall All Pass!"

	se nehuem passar "None Shall Pass!"

	se nap imprima, em ordem e entre espaços, o nome dos jogadores que erraram a resposta

	*/

	int vezes{}, iValorUm{}, iValorDois{ 0 }, iResposta{ 0 }, s{}, g{}, o_meu_inteiro{}, possContaNum;
	string segParte{}, valorDois{}, resposta{}, a_minha_string{}, operadorConta{};
	vector<int> contas{}, possConta{};
	vector<bool> acertarao{}, seila2{ 0 };
	vector<string> nomes;
	vector<vector<int>> todasContas;
	vector<vector<bool>> quaisOperadore{}, acertaraolista{}, seila{};
	vector <vector <char>> lista;
	vector<bool> operacaoCorretas;

	string nome{}, opera{};
	vector<string>todosNomes{}, todosOpera{}, todosErraram{};



	while (scanf_s("%ld", &vezes) == 1) //while (scanf_s("%d", &vezes) == 1)
	{
		//cin >> vezes;

		//tratamento das contas
		for (int i = 0; i < vezes; i++)
		{
			cin >> iValorUm >> segParte;

			contas.push_back(iValorUm);


			for (size_t j = 0; j < segParte.length(); j++)
			{
				s++;
				if (segParte[j] == 61)
					break;
			}

			std::cout << "index: " << s << endl;

			int total = segParte.length();

			valorDois = segParte;
			valorDois.erase(s - 1, total);
			resposta = segParte;
			resposta.erase(0, s);

			stringstream sValorDois(valorDois);
			sValorDois >> iValorDois;
			contas.push_back(iValorDois);

			stringstream sResposta(resposta);
			sResposta >> iResposta;
			contas.push_back(iResposta);

			cout << "contas " << i << ": " << contas.at(0) << contas.at(1) << contas.at(2) << endl;

			todasContas.push_back(contas);
			contas.clear();
			s = 0;

		}
		// nomes e respostas
		for (int i = 0; i < vezes; i++)
		{

			cin >> nome >> possContaNum >> opera;
			todosNomes.push_back(nome);
			possConta.push_back(possContaNum);
			todosOpera.push_back(opera);

		}
		acertaraolista = testeRespsotas(vezes, todosNomes, possConta, todosOpera, quaisOperadore, acertaraolista, operacaoCorretas, todasContas);
		// ver se  alguem erro
		// mostrar se todos ou nem um errou
		// mostrar quem erro



	}
	int acertos{};
	for (size_t i = 0; i < acertaraolista.size(); i++)
	{
		if (acertaraolista.at(i).at(0) == 1)
			acertos++;

		if (acertos == acertaraolista.size())
		{
			cout << "todos acertaram";
		}
		else if (acertos == 0)
		{
			cout << "todos erraram";
		}


	}
	if (acertos != 0 && acertos != acertaraolista.size())
	{
		cout << "alguem errou" << endl;
		for (size_t j = 0; j < acertaraolista.size(); j++)
			if (acertaraolista.at(j).at(0) == 0) {
				todosErraram.push_back(todosNomes.at(j));
				cout << todosNomes.at(j) << endl;
			}
	}

	return 0;
}



vector<vector<bool>> testeRespsotas(int vezes, vector<string> todosNomes, vector<int> possConta, vector<string> todosOpera, vector<vector<bool>> quaisOperadore, vector<vector<bool>> acertaraolista, vector<bool> operacaoCorretas, vector<vector<int>> todasContas)
{
	int X{}, Y{}, Z{}, iteracoes{};
	vector<vector<bool>> acertaraolistaInterno= acertaraolista;
	vector < bool> a2{0};
	// se todos acertaram
	// se todos erraram 
	// se alguem erro

	for (int i = 0; i < vezes; i++)
	{
		X = todasContas.at(possConta[i] - 1).at(0);
		Y = todasContas.at(possConta[i] - 1).at(1);
		Z = todasContas.at(possConta[i] - 1).at(2);
		cout << X << " " << todosOpera.at(i) << " " << Y << " = " << Z << endl;
		if (todosOpera.at(i) == "+") {
			if ((X + Y) == Z)
			{
				a2.at(0) = true;
				acertaraolistaInterno.push_back(a2);
			}
			else {
				a2.at(0) = false;
				acertaraolistaInterno.push_back(a2);
			}

		}
		else if (todosOpera.at(i) == "-") {

			if ((X - Y) == Z) {
				a2.at(0) = true;
				acertaraolistaInterno.push_back(a2);
			}
			else {
				a2.at(0) = false;
				acertaraolistaInterno.push_back(a2);
			}
		}
		else if (todosOpera.at(i) == "*") {

			if ((X * Y) == Z) {
				a2.at(0) = true;
				acertaraolistaInterno.push_back(a2);
			}
			else {
				a2.at(0) = false;
				acertaraolistaInterno.push_back(a2);
			}
		}
		else if (todosOpera.at(i) == "I") {
			a2.at(0) = true;
			acertaraolistaInterno.push_back(a2);

		}
		else {
			a2.at(0) = false;
			acertaraolistaInterno.push_back(a2);
		}
	}
	return acertaraolistaInterno;
}

	void reorganizarNomes(vector<string> todosNomes)
	{
		string aux{};
		for (size_t i = 0; i < todosNomes.size(); i++)
		{
			for (size_t j = 0; j < todosNomes.size() - 1 - i; j++)
			{
				if (todosNomes.at(j) > todosNomes.at(j + 1))
				{
					aux.append(todosNomes.at(j));
					todosNomes.at(j) = todosNomes.at(j + 1);
					todosNomes.at(j + 1) = aux;

					aux.clear();
				}

			}
		}
	}
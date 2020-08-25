#include <cstdio>
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector <string> reorganizarNomes(vector<string> todosNomes);



int main()
{
	int intVezes{}, intPrimeiraParte{}, intNumeroIteracao{}, intValorDois{},
		intResposta{}, intPossConta{}, erraramItera{};
	string strSegundaParte{}, strValorDois{}, strResposta{}, strNomes{};
	char strOperadores{};
	vector <string> vec2dStrTodosNomes{}, resultado{}, osQueErraram{};
	vector<char> vecStrTodosOperadores{};
	vector <int> vecIntContas{}, vecIntPossConta{};
	vector<vector<int>> todasContas{};


	while (scanf_s("%d", &intVezes) == 1)//(cin >> intVezes) 
	{
		for (int i = 0; i < intVezes; i++)
		{
			cin >> intPrimeiraParte >> strSegundaParte;
			vecIntContas.push_back(intPrimeiraParte);

			for (size_t j = 0; j < strSegundaParte.length(); j++)
			{
				intNumeroIteracao++;
				if (strSegundaParte[j] == 61)
					break;
			}

			int intTotal = strSegundaParte.length();

			strValorDois = strSegundaParte;
			strValorDois.erase(intNumeroIteracao - 1, intTotal);
			strResposta = strSegundaParte;
			strResposta.erase(0, intNumeroIteracao);

			stringstream strintValorDois(strSegundaParte);
			strintValorDois >> intValorDois;
			vecIntContas.push_back(intValorDois);

			stringstream strintResposta(strResposta);
			strintResposta >> intResposta;
			vecIntContas.push_back(intResposta);

			todasContas.push_back(vecIntContas);
			vecIntContas.clear();
			intNumeroIteracao = 0;

		}

		for (int i = 0; i < intVezes; i++)
		{
			cin >> strNomes >> intPossConta >> strOperadores;
			vec2dStrTodosNomes.push_back(strNomes);
			vecIntPossConta.push_back(intPossConta - 1);
			vecStrTodosOperadores.push_back(strOperadores);

		}
		for (int i = 0; i < intVezes; i++)
		{

			switch (vecStrTodosOperadores.at(i))
			{
			case'+':

				if ((todasContas.at((vecIntPossConta.at(i))).at(0) + todasContas.at((vecIntPossConta.at(i))).at(1)
					== todasContas.at((vecIntPossConta.at(i))).at(2))) {
				}
				else {
					osQueErraram.push_back(vec2dStrTodosNomes.at(i));
					erraramItera++;
				}
				break;
			case'-':

				if ((todasContas.at((vecIntPossConta.at(i))).at(0) - todasContas.at((vecIntPossConta.at(i))).at(1)
					== todasContas.at((vecIntPossConta.at(i))).at(2))) {
				}
				else {
					osQueErraram.push_back(vec2dStrTodosNomes.at(i));
					erraramItera++;
				}
				break;
			case'*':

				if ((todasContas.at((vecIntPossConta.at(i))).at(0) * todasContas.at((vecIntPossConta.at(i))).at(1)
					== todasContas.at((vecIntPossConta.at(i))).at(2))) {
				}
				else {
					osQueErraram.push_back(vec2dStrTodosNomes.at(i));
					erraramItera++;
				}
				break;
			case'I':

				if (!((todasContas.at((vecIntPossConta.at(i))).at(0) + todasContas.at((vecIntPossConta.at(i))).at(1)
					== todasContas.at((vecIntPossConta.at(i))).at(2))
					|| (todasContas.at((vecIntPossConta.at(i))).at(0) - todasContas.at((vecIntPossConta.at(i))).at(1)
						== todasContas.at((vecIntPossConta.at(i))).at(2))
					|| (todasContas.at((vecIntPossConta.at(i))).at(0) * todasContas.at((vecIntPossConta.at(i))).at(1)
						== todasContas.at((vecIntPossConta.at(i))).at(2)))) {

				}
				else {
					osQueErraram.push_back(vec2dStrTodosNomes.at(i));
					erraramItera++;
				}
				break;
			default:
				break;
			}

		}
		vecStrTodosOperadores.clear();
		todasContas.clear();
		vecIntPossConta.clear();

		int erraram = { erraramItera };
		erraramItera = 0;
		string nova{};
		if (erraram < intVezes && erraram > 0)
		{
			osQueErraram = reorganizarNomes(osQueErraram);
			for (string a : osQueErraram)
			{
				nova += (" " + a);
			}
			nova.erase(0, 1);
			resultado.push_back(nova);

		}
		else if (erraram == intVezes)
		{
			resultado.push_back("None Shall Pass!");
		}
		else {
			resultado.push_back("You Shall All Pass!");
		}
	}

	for (string a : resultado)
		cout << a << endl;

	return 0;
}

vector <string> reorganizarNomes(vector<string> todosNomes)
{
	string aux{};
	vector<string> retorna{ todosNomes };
	for (size_t i = 0; i < retorna.size(); i++)
	{
		for (size_t j = 0; j < retorna.size() - 1 - i; j++)
		{
			if (retorna.at(j) > retorna.at(j + 1))
			{
				aux.append(retorna.at(j));
				retorna.at(j) = retorna.at(j + 1);
				retorna.at(j + 1) = aux;

				aux.clear();
			}

		}
	}
	return retorna;
}


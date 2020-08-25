#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int vezes{ };
    cin >> vezes;
    int * saida = new int[vezes];
    for (int i = 0; i < vezes; i++)
    {
        int pessoas; int pula;
        cin >> pessoas >> pula;
        vector<int> vivos{};
        for (int i = 1; i <= pessoas; i++)
        {
            vivos.push_back(i);
        }
        
        int pivo {0};
        while (vivos.size() != 1)
        {
            pivo += pula -1;
            pivo = pivo % vivos.size();
            vivos.erase(vivos.begin() + pivo);
        

        } 
        saida[i] = vivos.at(0);
    }
    
    for (int i = 0; i < vezes; i++)
    {
        cout << "Case " << i + 1 << ": " << saida[i] << endl;
    }
}
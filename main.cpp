#include <iostream>

using namespace std;

void generate_kartu(string cards[])
{
    string lambang[] = {"Waru", "Hati", "Wajik", "Keriting"};
    string angka[] = {"As", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Jack", "Queen", "King"};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            cards[i * 13 + j] = (angka[j] + " " + lambang[i]);
        }
    }
}

int main()
{

    return 0;
}
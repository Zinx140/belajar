#include <iostream>
#include <cstdlib>
#include <time.h>

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
    const int total_kartu = 52;
    string cards[total_kartu];
    generate_kartu(cards);

    // Mengacak kartu
    srand(time(0));
    int kartu_terpilih = rand() % total_kartu;

    string tebakan;
    cout << "Selamat datang di permainan Tebak Kartu!" << endl;
    cout << "Tebak nama kartu (contoh: As Waru, Tiga Hati, Queen Wajik): " << endl;

    // Looping sampai tebakan benar

    if (tebakan == cards[kartu_terpilih])
    {
        cout << "Selamat! Tebakan Anda benar, kartu tersebut adalah " << cards[kartu_terpilih] << "." << endl;
    }
    else
    {
        cout << "Tebakan Anda salah. Coba lagi!" << endl;
    }

    return 0;
}

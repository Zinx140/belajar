#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

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


// Fungsi untuk menghitung nilai kartu
int hitung_nilai(const vector<string>& hand) {
    int total = 0, ace_count = 0;
    for (const string& card : hand) {
        if (card.find("As") != string::npos) {
            total += 11;
            ace_count++;
        } else if (card.find("Jack") != string::npos ||
                   card.find("Queen") != string::npos ||
                   card.find("King") != string::npos) {
            total += 10;
        } else {
            size_t pos = card.find(' ');
            if (pos != string::npos) {
                total += stoi(card.substr(0, pos)); // Ambil angka jika valid
            }
        }
    }
    // Atur nilai As jika total > 21
    while (total > 21 && ace_count > 0) {
        total -= 10;
        ace_count--;
    }
    return total;
}


// Fungsi untuk menampilkan kartu
void tampilkan_kartu(const vector<string>& hand) {
    for (const string& card : hand) {
        cout << card << " | ";
    }
    cout << endl;
}

// Fungsi untuk menarik kartu secara acak
string tarik_kartu(string cards[], vector<string>& deck, int& size) {
    int index = rand() % size;
    string card = cards[index];
    swap(cards[index], cards[size - 1]); // Hapus kartu dari dek
    size--;
    return card;
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

    string cards[52];
    vector<string> player_hand, dealer_hand;
    int deck_size = 52;

    generate_kartu(cards);

    // Tarik 2 kartu awal untuk pemain dan dealer
    player_hand.push_back(tarik_kartu(cards, player_hand, deck_size));
    player_hand.push_back(tarik_kartu(cards, player_hand, deck_size));
    dealer_hand.push_back(tarik_kartu(cards, dealer_hand, deck_size));
    dealer_hand.push_back(tarik_kartu(cards, dealer_hand, deck_size));

    cout << "=== Selamat datang di Blackjack! ===\n";
    cout << "Kartu Dealer: " << dealer_hand[0] << " | ??\n";
    cout << "Kartu Anda: ";
    tampilkan_kartu(player_hand);

    // Giliran Pemain
    string pilihan;
    while (true) {
        cout << "Nilai Anda: " << hitung_nilai(player_hand) << endl;
        if (hitung_nilai(player_hand) > 21) {
            cout << "Anda Bust! Dealer Menang.\n";
            return 0;
        }
        cout << "Hit (tambah kartu) atau Stand (berhenti)? (h/s): ";
        cin >> pilihan;
        if (pilihan == "h") {
            player_hand.push_back(tarik_kartu(cards, player_hand, deck_size));
            cout << "Kartu Anda: ";
            tampilkan_kartu(player_hand);
        } else {
            break;
        }
    }

    // Giliran Dealer
    cout << "Kartu Dealer: ";
    tampilkan_kartu(dealer_hand);
    while (hitung_nilai(dealer_hand) < 17) {
        dealer_hand.push_back(tarik_kartu(cards, dealer_hand, deck_size));
        cout << "Kartu Dealer: ";
        tampilkan_kartu(dealer_hand);
    }

    // Menentukan Pemenang
    int player_score = hitung_nilai(player_hand);
    int dealer_score = hitung_nilai(dealer_hand);
    cout << "Nilai Anda: " << player_score << ", Nilai Dealer: " << dealer_score << endl;

    if (dealer_score > 21 || player_score > dealer_score) {
        cout << "Selamat! Anda Menang!\n";
    } else if (player_score < dealer_score) {
        cout << "Dealer Menang! Coba lagi.\n";
    } else {
        cout << "Seri!\n";
    }

    return 0;
}

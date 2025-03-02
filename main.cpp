#include <iostream>

using namespace std;

class Railways {
private:
    static int total;
    int id;
public:
    gamma() //конструктор без аргументов
    {
        total++; //увеличить счетчик объектов
        id = total; //id равен текущему значению total
        cout << "Создание ID " << id << endl;
    }

    ~gamma() //деструктор
    {
        total--;
        cout << "Удаление ID " << id << endl;
    }

    static void showtotal() // статическая функция
    {
        cout << "\nBcero: " << total << endl;
    }

    void showID() // нестатическая функция
    {
        cout << "\nID: " << id << endl;
    }
};

//---------------------------------
int gamma::total = 0;

int main() {
    gamma::showtotal();
    gamma g1;
    g1.showtotal();
    gamma g2;
    gamma g3;
    g3.showtotal();
    g1.showID();
    g2.showID();
    g3.showID();
    cout << "Конец программы" << endl;
    return 0;
}

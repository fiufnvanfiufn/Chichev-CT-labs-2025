#include <iostream>
#include <cstring>

namespace roadClass {

class road {
private:
    char* roadName;
    int roadLength;
    int roadWidth;
    int permittedSpeed;

public:
    // Конструктор по умолчанию
    road();

    // Конструктор с параметрами
    road(const char* name, int length, int width, int speed);

    // Конструктор копирования
    road(const road& other);

    // Оператор присваивания
    road& operator=(const road& other);

    // Деструктор
    ~road();

    // Сеттеры
    void SetRoadName(const char* name);
    void SetRoadLength(int length);
    void SetRoadWidth(int width);
    void SetPermittedSpeed(int speed);

    // Геттеры
    const char* GetRoadName() const;
    int GetRoadLength() const;
    int GetRoadWidth() const;
    int GetPermittedSpeed() const;

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& in, road& Corusant);

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const road& Corusant);
};
}

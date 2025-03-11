#include "road.hpp"

namespace roadClass {
    road::road() : roadName(nullptr), roadLength(0), roadWidth(0), permittedSpeed(0) {}

    // Конструктор с параметрами
    road::road(const char* name, int length, int width, int speed) {
        roadName = new char[std::strlen(name) + 1];
        std::strcpy(roadName, name);
        roadLength = length;
        roadWidth = width;
        permittedSpeed = speed;
    }

    // Конструктор копирования
    road::road(const road& other) {
        roadName = new char[std::strlen(other.roadName) + 1];
        std::strcpy(roadName, other.roadName);
        roadLength = other.roadLength;
        roadWidth = other.roadWidth;
        permittedSpeed = other.permittedSpeed;
    }

    // Оператор присваивания
    road& road::operator=(const road& other) {
        if (this == &other) return *this;  // Проверка на самоприсваивание

        delete[] roadName;  // Очистка старой памяти

        roadName = new char[std::strlen(other.roadName) + 1];
        std::strcpy(roadName, other.roadName);
        roadLength = other.roadLength;
        roadWidth = other.roadWidth;
        permittedSpeed = other.permittedSpeed;

        return *this;
    }

    // Деструктор
    road::~road() {
        delete[] roadName;
    }

    // Сеттеры
    void road::SetRoadName(const char* name) {
        delete[] roadName;
        roadName = new char[std::strlen(name) + 1];
        std::strcpy(roadName, name);
    }

    void road::SetRoadLength(int length) { roadLength = length; }
    void road::SetRoadWidth(int width) { roadWidth = width; }
    void road::SetPermittedSpeed(int speed) { permittedSpeed = speed; }

    // Геттеры
    const char* road::GetRoadName() const { return roadName; }
    int road::GetRoadLength() const { return roadLength; }
    int road::GetRoadWidth() const { return roadWidth; }
    int road::GetPermittedSpeed() const { return permittedSpeed; }

    // Перегрузка оператора ввода
    std::istream& operator>>(std::istream& in, road& Corusant) {
        char tempName[30];  // Временный буфер для имени
        int length, width, speed;

        in >> tempName >> length >> width >> speed;

        Corusant.SetRoadName(tempName);
        Corusant.SetRoadLength(length);
        Corusant.SetRoadWidth(width);
        Corusant.SetPermittedSpeed(speed);

        return in;
    }

    // Перегрузка оператора вывода
    std::ostream& operator<<(std::ostream& out, const road& Corusant) {
        out << Corusant.GetRoadName() << '\t'
            << Corusant.GetRoadLength() << '\t'
            << Corusant.GetRoadWidth() << '\t'
            << Corusant.GetPermittedSpeed() << std::endl;
        return out;
    }
}

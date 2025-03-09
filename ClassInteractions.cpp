#include "ClassInteractions.hpp"
#include "road/road.hpp"

namespace {
void PrintMenu() {
    std::cout << "Методы:" << '\n'
              << "1. Считать БД из файла" << '\n'
              << "2. Запись БД в файл" << '\n'
              << "3. Сортировка БД" << '\n'
              << "4. Добавление нового объекта в БД" << '\n'
              << "5. Удаление элемента из БД" << '\n'
              << "6. Вывод БД на экран" << "\n"
              << "7. Выход" << "\n"
              << std::endl;
}
void ReadContinueExecution(char& ReadContinueExecution) {
    std::cout << "Введите [y/n] для продожения выполнения программы" << std::endl;
    std::cin >> ReadContinueExecution;
}

void ReadMethodFromStdin(int& method) {
    std::cout << "Введите цифрами номер метода, который хотите выполнить" << std::endl;
    std::cin >> method;
}

void CopyMassive(roadClass::road* a, roadClass::road* b, int elements) {
    for (int i{}; i < elements; ++i) {
        b[i] = a[i];
    }
}

void Resize(roadClass::road*& Data, int& elements) {
    roadClass::road* NewData = new roadClass::road[elements * 2];
    CopyMassive(Data, NewData, elements);
    elements *= 2;
    delete[] Data;
    Data = NewData;
}

void FreeData(roadClass::road* Data) {
    delete[] Data;
}
}  // namespace

namespace roadClass {

void StartApp() {
    SelectMethod();
}

void SelectMethod() {
    int elements = 0;
    int massiveLength = 10;
    road* Data = new road[10];

    char continueExecution = 'y';

    while (continueExecution == 'y') {
        PrintMenu();

        int method{};
        ReadMethodFromStdin(method);

        switch (static_cast<Methods>(method)) {
            case Methods::ReadDataFromFile:
                ReadDataFromFile(Data, elements, massiveLength);
                break;
            case Methods::WriteDataToFile:
                WriteDataToFile(Data, elements);
                break;
            case Methods::SortData:
                SortData(Data, elements);
                break;
            case Methods::AddNewElementToData:
                AddNewElementToData(Data, elements, massiveLength);
                break;
            case Methods::DeleteElementFromData:
                DeleteElementFromData(Data, elements);
                break;
            case Methods::PrintDataConsole:
                PrintDataConsole(Data, elements);
                break;
            default:
                std::cout << "Такого действия нет" << std::endl;
                break;
        }
        ReadContinueExecution(continueExecution);
    }
    delete[] Data;
}

void SortData(road* Data, int elements) {
    if (Data == nullptr) {
        std::cout << "Произошла ошибка при передаче массива" << std::endl;
        return;
    }

    if (elements == 0) {
        return;
    }

    bool isElementsSwap = false;

    for (size_t i = 0; i < elements - 1; ++i) {
        for (size_t j = 0; j < elements - 1 - i; ++j) {
            char* a = Data[j].GetRoadName();
            char* b = Data[j + 1].GetRoadName();
            if (strcmp(Data[j].GetRoadName(), Data[j + 1].GetRoadName()) > 0) {
                road a = Data[j];
                Data[j] = Data[j + 1];
                Data[j + 1] = a;
                isElementsSwap = true;
            }
        }

        if (!isElementsSwap) {
            break;
        }
    }
}

void ReadDataFromFile(road* Data, int& elements, int& massiveLength) {
    std::ifstream inputFile("input.txt");

    if (!inputFile) {
        std::cout << "Произошла ошибка при открытии файла" << std::endl;
        return;
    }

    int i = 0;
    while (inputFile >> Data[i]) {
        if (i == massiveLength) {
            Resize(Data, massiveLength);
        }
        ++i;
    }
    elements = i;
}

void WriteDataToFile(road* Data, int elements) {
    if (Data == nullptr) {
        std::cout << "Произошла ошибка при передаче массива" << std::endl;
        return;
    }

    std::ofstream fout("input.txt");

    if (!fout) {
        std::cout << "Ошибка при открытии файла" << std::endl;
        return;
    }

    for (int i = 0; i < elements; ++i) {
        fout << Data[i];
    }
}

void AddNewElementToData(road* Data, int& elements, int& massiveLength) {
    if (Data == nullptr) {
        std::cout << "Произошла ошибка при передаче массива" << std::endl;
        return;
    }

    if (elements + 1 >= massiveLength) {
        Resize(Data, massiveLength);
    }

    std::cin >> Data[elements];
    elements++;
}

void DeleteElementFromData(road* Data, int& elements) {
    if (Data == nullptr) {
        std::cout << "Произошла ошибка при передаче массива" << std::endl;
        return;
    }

    char* deletedElement = new char[30];
    std::cout << "Введите имя дороги вы хотите удалить" << std::endl;
    std::cin >> deletedElement;

    road* NewData = new road[elements - 1];
    bool isElementInData = false;

    int k = 0;
    for (int i{}; i < elements; ++i) {
        if (std::strcmp(Data[i].GetRoadName(), deletedElement) != 0) {
            NewData[k] = Data[i];
            k += 1;
            std::cout << Data[i];
            isElementInData = true;
        }
    }

    delete[] Data;
    Data = NewData;
    elements -= 1;
}

void PrintDataConsole(road* Data, int& elements) {
    std::cout << elements << std::endl;
    for (int i{}; i < elements; ++i) {
        std::cout << Data[i];
    }
}
}  // namespace roadClass

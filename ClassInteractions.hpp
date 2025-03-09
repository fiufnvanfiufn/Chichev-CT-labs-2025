#pragma once
#include "road/road.hpp"

namespace roadClass {

enum class Methods{
    ReadDataFromFile = 1,
    WriteDataToFile,
    SortData,
    AddNewElementToData,
    DeleteElementFromData,
    PrintDataConsole,
};

void StartApp();

void SelectMethod();

void ReadDataFromFile(road* Data, int& elements, int& massiveLength);

void WriteDataToFile(road* Data, int elements);

void SortData(road* Data, int elements);

void AddNewElementToData(road* Data, int& elements, int& massiveLength);

void DeleteElementFromData(road* Data, int& elements);

void PrintDataConsole(road* Data, int& elements);

}  // namespace roadClass

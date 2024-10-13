#include <windows.h>
#include <iostream>

using namespace std;

// Объявляем типы функций для использования из DLL
typedef void (*SetSides)(double, double, double);
typedef double (*CalculateArea)();
typedef double (*CalculatePerimeter)();
typedef const char* (*GetTriangleDescription)();

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Загружаем динамически подключаемую библиотеку
    HMODULE hDll = LoadLibrary("TriangleDll13.09.dll");
    if (!hDll) {
        cerr << "Не удалось загрузить библиотеку." << endl;
        return GetLastError();
    }

    // Получаем адреса функций
    SetSides setSides = (SetSides)GetProcAddress(hDll, "SetSides");
    CalculateArea calculateArea = (CalculateArea)GetProcAddress(hDll, "CalculateArea");
    CalculatePerimeter calculatePerimeter = (CalculatePerimeter)GetProcAddress(hDll, "CalculatePerimeter");
    GetTriangleDescription getTriangleDescription = (GetTriangleDescription)GetProcAddress(hDll, "GetTriangleDescription");

    if (!setSides || !calculateArea || !calculatePerimeter || !getTriangleDescription) {
        cerr << "Не удалось получить адреса функций." << endl;
        FreeLibrary(hDll);
        return GetLastError();
    }

    // Устанавливаем стороны треугольника
    setSides(3.0, 4.0, 5.0); // Пример сторон треугольника

    // Выводим результаты
    cout << "Описание треугольника: " << getTriangleDescription() << endl;
    cout << "Площадь треугольника: " << calculateArea() << endl;
    cout << "Периметр треугольника: " << calculatePerimeter() << endl;

    // Отключаем библиотеку
    FreeLibrary(hDll);
    return 0;
}

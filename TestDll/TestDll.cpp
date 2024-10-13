#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    HMODULE hD11; // дескриптор DLL
    int (*Add)(int); // указатель на функцию Add из DLL
    int (*Sub)(int); // указатель на функцию Sub из DLL
    int* pCount; // указатель на переменную count из DLL

    // Загружаем динамически подключаемую библиотеку
    hD11 = LoadLibrary(L"Dll06.09.dll"); // Имя вашей библиотеки с префиксом L
    if (!hD11) {
        cerr << "Load library failed." << endl;
        return GetLastError();
    }

    // Настраиваем адрес переменной count из DLL
    pCount = (int*)GetProcAddress(hD11, "count");
    if (!pCount) {
        cerr << "Get variable address failed." << endl;
        return GetLastError();
    }

    // Выводим начальное значение переменной count
    cout << "Initial count = " << (*pCount) << endl;

    // Настраиваем адреса функций
    Add = (int (*)(int))GetProcAddress(hD11, "Add");
    Sub = (int (*)(int))GetProcAddress(hD11, "Sub");
    if (!Add || !Sub) {
        cerr << "Get procedure address failed." << endl;
        return GetLastError();
    }

    // Изменяем значение счетчика
    cout << "count after Add(20) = " << Add(20) << endl;
    cout << "count after Sub(15) = " << Sub(15) << endl;

    // Отключаем библиотеку
    if (!FreeLibrary(hD11)) {
        cerr << "Free library failed." << endl;
        return GetLastError();
    }

    // Выходим из программы
    cout << "Press any key to exit";
    cin.get();
    return 0;
}

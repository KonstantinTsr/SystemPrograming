// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <windows.h>

extern "C" int count = -5; // Инициализация переменной count

// Точка входа для DLL
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH: // Загрузка DLL
        break;
    case DLL_THREAD_ATTACH: // Создание потока
        break;
    case DLL_THREAD_DETACH: // Завершение потока
        break;
    case DLL_PROCESS_DETACH: // Отключение DLL
        break;
    }
    return TRUE;
}

// Функция для сложения
extern "C" int Add(int n) {
    count += n;
    return count;
}

// Функция для вычитания
extern "C" int Sub(int n) {
    count -= n; // Исправлено с "==" на "-"
    return count;
}

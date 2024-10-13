#include "pch.h"
#include <windows.h>
#include <cmath>
#include <stdio.h>

// Глобальные переменные для сторон треугольника
extern "C" double side1 = 0.0;  // Определение переменных
extern "C" double side2 = 0.0;
extern "C" double side3 = 0.0;

// Точка входа для DLL
BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved) {
    switch (dwReason) {
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

// Функция для установки сторон треугольника
extern "C" void SetSides(double s1, double s2, double s3) {
    side1 = s1;
    side2 = s2;
    side3 = s3;
}

// Функция для вычисления полупериметра
extern "C" double CalculateSemiPerimeter() {
    return (side1 + side2 + side3) / 2;
}

// Функция для вычисления площади треугольника
extern "C" double CalculateArea() {
    double s = CalculateSemiPerimeter();
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

// Функция для вычисления периметра треугольника
extern "C" double CalculatePerimeter() {
    return side1 + side2 + side3;
}

// Функция для получения описания треугольника
extern "C" const char* GetTriangleDescription() {
    static char description[100];
    sprintf_s(description, sizeof(description), "Треугольник со сторонами: %.2f, %.2f, %.2f", side1, side2, side3);
    return description;
}

#include "labwork2.h"
#include <iostream>
#include <math.h>
#define NO_EXCEPTION 0;
#define INVALID_INPUT_EXCEPTION -1;

using namespace std;

int lw2::RunTasks() {
    TaskSelection();

    return NO_EXCEPTION;
}

#pragma region Task selection

int lw2::TaskSelection() {
    int taskNumber;
    TaskSelectionInputHandling(taskNumber);

    switch (taskNumber) {
    case 1:
        Task1();
        break;
    case 2:
        Task2();
        break;
    case 3:
        Task3();
        break;
    case 4:
        Task4();
        break;
    case 0:
        Task4c();
        break;
    case 5:
        Task5();
        break;
    }

    return 0;
}

int lw2::TaskSelectionInputHandling(int& n) {
    int invalidInputCount = 0;

    while (TaskSelectionInputN(n)) {
        cout << "Invalid input" << endl;
        invalidInputCount++;
    }

    return invalidInputCount;
}

int lw2::TaskSelectionInputN(int& n) {
    cout << "Choose task number (1-5): ";
    cin >> n;

    if (n < 0 || n > 5)
        return INVALID_INPUT_EXCEPTION;
    return NO_EXCEPTION;
}

#pragma endregion

#pragma region Task 1

int lw2::Task1() {
    double x, a;
    Task1inputHandling(x, a);

    cout << endl << Task1main(x, a) << endl;

    return NO_EXCEPTION;
}

double lw2::Task1main(double x, double a) {
    if (x > 0)
        return Task1l(x, a);

    return Task1e(x, a);
}

double lw2::Task1l(double x, double a) {
    if (x == 1) // to avoid -0 edge case
        return 0; // Gotta document this is a lwd

    return log(x) / log(a);
}

double lw2::Task1e(double x, double a) {
    return exp(a * x * x);
}

int lw2::Task1inputHandling(double& x, double& a) {
    int invalidInputCount = 0;

    cout << "Input x: ";
    cin >> x;

    while (Task1inputA(a)) {
        cout << "Invalid input" << endl;
        invalidInputCount++;
    }

    return invalidInputCount;
}

int lw2::Task1inputA(double& a)
{
    cout << "Input a: ";
    cin >> a;

    if (a <= 0)
        return INVALID_INPUT_EXCEPTION;

    return NO_EXCEPTION;
}

#pragma endregion

#pragma region Task 2

int lw2::Task2() {
    double x, y;
    Task2inputHandling(x, y);

    cout << endl << Task2main(x, y) << endl;

    return NO_EXCEPTION;
}

int lw2::Task2inputHandling(double& x, double& y)
{
    cout << "Input x: ";
    cin >> x;
    cout << "Input y: ";
    cin >> y;

    return NO_EXCEPTION;
}

bool lw2::Task2main(double x, double y) {
    double lenSquared = x * x + y * y;
    return lenSquared >= 4 && lenSquared <= 25;
}

#pragma endregion

#pragma region Task 3

int lw2::Task3() {
    double a, b, c;
    Task3inputHandling(a, b, c);
    Task3main(a, b, c);

    cout << endl << "a: " << a << " b: " << b << " c: " << c << endl;

    return NO_EXCEPTION;
}

int lw2::Task3inputHandling(double& a, double& b, double& c)
{
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    cout << "Input c: ";
    cin >> c;

    return NO_EXCEPTION;
}

int lw2::Task3main(double& a, double& b, double& c) {
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    return NO_EXCEPTION;
}

#pragma endregion

#pragma region Task 4

int lw2::Task4() {
    int n;
    double l;
    Task4inputHandling(n, l);
    TriangleParams triangleP = Task4main(n, l);

    cout << endl << "Separate function\nLeg - " << triangleP.leg << "\nHypothenus - " << triangleP.hypothenus << "\nHeight - " << triangleP.height << "\nArea - " << triangleP.area << endl;

    return NO_EXCEPTION;
}

int lw2::Task4c() {
    int n;
    double l;
    Task4inputHandling(n, l);
    Triangle triangle(n, l);

    cout << endl << "Constructor\nLeg - " << triangle.leg << "\nHypothenus - " << triangle.hypothenus << "\nHeight - " << triangle.height << "\nArea - " << triangle.area << endl;

    return NO_EXCEPTION;
}
int lw2::Task4inputHandling(int& n, double& l) {
    int invalidInputCount = 0;

    while (Task4inputN(n)) {
        cout << "Invalid input\n";
        invalidInputCount++;
    }
    while (Task4inputL(l)) {
        cout << "Invalid input\n";
        invalidInputCount++;
    }

    return invalidInputCount;
}
int lw2::Task4inputN(int& n) {
    cout << "Input the measured part number\n1) Leg\n2) Hypothenus\n3) Height to hypothenus\n4) Area\nInput: ";
    cin >> n;

    if (n < 1 || n > 4)
        return INVALID_INPUT_EXCEPTION;

    return NO_EXCEPTION;
}
int lw2::Task4inputL(double& l) {
    cout << "Input length of selected part: ";
    cin >> l;

    if (l < 0)
        return INVALID_INPUT_EXCEPTION;

    return NO_EXCEPTION;
}
TriangleParams lw2::Task4main(int n, double l) {
    TriangleParams triangle;

    if (l == 0)
        return triangle;

    switch (n) {
    case 1:
        triangle.area = l * l;
        break;
    case 2:
        triangle.area = l * l * 0.5;
        break;
    case 3:
        triangle.area = l * l * 2;
        break;
    case 4:
        triangle.area = l;
        break;
    }

    triangle.leg = sqrt(triangle.area);
    triangle.hypothenus = sqrt(triangle.area * 2);
    triangle.height = sqrt(triangle.area * 0.5);

    return triangle;
}

#pragma endregion

#pragma region Task 5

int lw2::Task5() {
    int n;
    Task5inputHandling(n);
    Task5Parse(Task5main(n));

    return NO_EXCEPTION;
}
int lw2::Task5inputHandling(int& n) {
    int invalidInputCount = 0;

    while (Task5inputN(n)) {
        cout << "Invalid input" << endl;
        invalidInputCount++;
    }

    return invalidInputCount;
}
int lw2::Task5inputN(int& n) {
    cout << "Input grade: ";
    cin >> n;

    if (n > 12 || n < 1)
        return INVALID_INPUT_EXCEPTION;

    return NO_EXCEPTION;
}

int lw2::Task5main(int n) {
    if (n == 4) // Не певний, математично 4 - задовільно, але наче незадовільно...
        return 1; // Тому так
    return (n + 2) / 3;
}

int lw2::Task5Parse(int n) {
    switch (n) {
    case 4:
        cout << "Відмінно";
        break;
    case 3:
        cout << "Добре";
        break;
    case 2:
        cout << "Задовільно";
        break;
    case 1:
        cout << "Незадовільно";
        break;
    default:
        return INVALID_INPUT_EXCEPTION;
    }

    return NO_EXCEPTION;
}

#pragma endregion
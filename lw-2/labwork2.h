#pragma once
#include <math.h>

struct TriangleParams {
    double leg;
    double hypotenus;
    double height;
    double area;

    TriangleParams() {
        leg = 0;
        hypotenus = 0;
        height = 0;
        area = 0;
    }
};

struct Triangle : TriangleParams {
    Triangle() : TriangleParams() { }

    Triangle(int n, double l) : TriangleParams() {
        TriangleParams triangle;

        if (l == 0)
            return;

        switch (n) {
        case 1:
            triangle.area = l * l * 0.5;
            break;
        case 2:
            triangle.area = l * l * 0.25;
            break;
        case 3:
            triangle.area = l * l;
            break;
        case 4:
            triangle.area = l;
            break;
        }

        triangle.leg = sqrt(triangle.area * 2);
        triangle.hypotenus = sqrt(triangle.area) * 2;
        triangle.height = triangle.hypotenus * 0.5;
    }

    Triangle(TriangleParams modelTriangle) : TriangleParams() {
        leg = modelTriangle.leg;
        hypotenus = modelTriangle.hypotenus;
        height = modelTriangle.height;
        area = modelTriangle.area;
    }
};

class lw2 {
public: 
    static int RunTasks();
    static double Task1main(double x, double a);
    static bool Task2main(double x, double y);
    static int Task3main(double& a, double& b, double& c);
    static TriangleParams Task4main(int n, double l);
    static int Task5main(int n);

private:
    static int TaskSelection();
    static int TaskSelectionInputHandling(int& n);
    static int TaskSelectionInputN(int& n);

    static int Task1();
    static int Task1inputHandling(double& x, double& a);
    static int Task1inputA(double& a);
    static double Task1e(double x, double a);
    static double Task1l(double x, double a);

    static int Task2();
    static int Task2inputHandling(double& x, double& y);

    static int Task3();
    static int Task3inputHandling(double& a, double& b, double& c);

    static int Task4();
    static int Task4c();
    static int Task4inputHandling(int& n, double& l);
    static int Task4inputN(int& n);
    static int Task4inputL(double& l);

    static int Task5();
    static int Task5inputHandling(int& n);
    static int Task5inputN(int& n);
    static int Task5Parse(int n);
};
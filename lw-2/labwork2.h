#pragma once
#include <math.h>

struct TriangleParams {
    double leg;
    double hypothenus;
    double height;
    double area;

    TriangleParams() {
        leg = 0;
        hypothenus = 0;
        height = 0;
        area = 0;
    }
};

struct Triangle : TriangleParams {
    Triangle() : TriangleParams() { }

    Triangle(int n, double l) : TriangleParams() {
        if (l == 0)
            return;

        switch (n) {
        case 1:
            area = l * l;
            break;
        case 2:
            area = l * l * 0.5;
            break;
        case 3:
            area = l * l * 2;
            break;
        case 4:
            area = l;
            break;
        }

        leg = sqrt(area);
        hypothenus = sqrt(area * 2);
        height = sqrt(area * 0.5);
    }

    Triangle(TriangleParams modelTriangle) : TriangleParams() {
        leg = modelTriangle.leg;
        hypothenus = modelTriangle.hypothenus;
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
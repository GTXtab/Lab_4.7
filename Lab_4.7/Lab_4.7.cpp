// Lab_04_7.cpp
// ������������ �����
// ����������� ������ � 4.7
// ���������� ���� ���� ������� �� ��������� ����������� ����� �� �����������
// ������ 20

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
    int n = 0;
    const double PI = 3.14159265358979323846;

    // �������� ���������� �����
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << " |"
        << setw(12) << "arccos(x)" << " |"
        << setw(10) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk) {
        n = 0;
        a = x; // ������ ���� ����
        S = a;

        double numerator = 1;  // ��������� � ���������� 1 * 3 * 5 * ...
        double denominator = 2; // ���������� � ���������� 2 * 4 * 6 * ...
        double power_x = x * x * x; // ������ x^(2n+1) ��������� � x^3

        do {
            n++;
            numerator *= (2 * n - 1); // 1 * 3 * 5 * ...
            denominator *= (2 * n * (2 * n + 1)); // 2 * 4 * 6 * ... * (2n+1)
            a = numerator * power_x / denominator; // ����������� ����
            S += a;
            power_x *= x * x; // �������� ������ x^(2n+1)
        } while (abs(a) >= eps);

        // ��������� ��������
        double arccos_value = PI / 2 - S;

        // ��������� ����������
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(12) << setprecision(5) << acos(x) << " |"
            << setw(10) << setprecision(5) << arccos_value << " |"
            << setw(5) << n << " |"
            << endl;

        x += dx;
    }

    cout << "-------------------------------------------------------------" << endl;
    return 0;
}

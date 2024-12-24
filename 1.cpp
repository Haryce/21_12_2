#include <iostream>
using namespace std;
double NewtonInterpol(double x[], double y[], int n, double x_value) {
    double table[10][10]; // Таблица разделенных разностей (максимум 10 узлов)
    for (int i = 0; i < n; i++) {
        table[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
    //вычисление интерполяционного значения
    double res = table[0][0];
    double G = 1.0;

    for (int i = 1; i < n; i++) {
        G *= (x_value - x[i - 1]);
        res += table[0][i] * G;
    }
    return res;
}

int main() {
    const int MAX_NODES = 10; //максимальное количество узлов
    int n;
    double x[MAX_NODES], y[MAX_NODES]; //массивы для узлов и значений функции
    double x_value; // Значение для интерполяции
    cout << "Введите количество узлов (максимум " << MAX_NODES << "): ";
    cin >> n;
    if (n < 1 || n > MAX_NODES) {
        cout << "Ошибка: количество узлов должно быть от 1 до " << MAX_NODES << "." << endl;
        return 1;
    }
    cout << "Введите узлы (x):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }
    cout << "Введите значения функции (y):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }
    cout << "Введите значение x для интерполяции: ";
    cin >> x_value;

    // Вычисление интерполяционного значения
    double interpolV = NewtonInterpol(x, y, n, x_value);
    cout << "Интерполированное значение в x = " << x_value << " : " << interpolV << endl;
    return 0;
}
#include <iostream>
using namespace std;
double LagrangeInterpol(double x[], double y[], int n, double x_value) {
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        double tm = y[i]; 
        for (int j = 0; j < n; j++) {
            if (j != i) {
                tm *= (x_value - x[j]) / (x[i] - x[j]);
            }
        }
        res += tm; 
    }
    return res;
}
int main() {
    setlocale(LC_ALL, "Russian");
    const int maxN = 10; // Максимальное количество узлов
    int n; 
    double x[maxN], y[maxN];
    double x_value;
    cout << "Введите количество узлов (максимум " << maxN << "): ";
    cin >> n;
    if (n < 1 || n > maxN) {
        cout << "Ошибка: количество узлов должно быть от 1 до " << maxN << "." << endl;
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
    double interpolV = LagrangeInterpol(x, y, n, x_value);
    cout << "Интерполированное значение в x = " << x_value << " : " << interpolV << endl;
    return 0;
}
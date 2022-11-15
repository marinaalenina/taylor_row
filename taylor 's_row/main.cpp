#include <iostream>

using namespace std;


double my_abs(double val) {
    double ret = val;
    if (val < 0)
        ret *= -1;
    return ret;
}

double Taylor(double x, double e, long& n) {
    double sum = 0;
    double an = 1;
    n = 1;
    do {
        sum += an;
        n += 1;
        an *= (-1) * (x * x / (2.0 * n * 2 * (n - 1)));
    } while (e <= my_abs(an));
    return sum;
}


int main() {
    long n;
    float x_start, x_end, dx, e;
    //cout << "xn = ";
    //cin >> x_start;
    //cout << "xk = ";
    //cin >> x_end;
    //cout << "dx = ";
    //cin >> dx;
    //cout << "e = ";
    //cin >> e;
    x_start = 0;
    x_end = 1;
    dx = 0.01;
    e = 0.00001;
    cout << "|  x  |  Sum  |   N   |\n";
    while (x_start <= x_end) {
        cout << x_start << " | " << Taylor(x_start, e, n) << " |  ";
        cout << n << endl;
        x_start = x_start + dx;
    }

    return 0;
}
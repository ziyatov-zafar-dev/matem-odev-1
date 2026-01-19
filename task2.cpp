#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// Verilen fonksiyon degeri
double f(double x) {
    return pow(x + 1, 2) / (1 + x * x);
}

// Birinci türev (sayisal yaklasik)
double f_prime(double x) {
    double h = 0.0001;
    return (f(x + h) - f(x - h)) / (2 * h);
}

// Ikinci türev (sayisal yaklasik)
double f_double_prime(double x) {
    double h = 0.0001;
    return (f_prime(x + h) - f_prime(x - h)) / (2 * h);
}

// Kritik noktalari bulmak için basit bir tarama
vector<double> find_critical_points() {
    vector<double> points;
    double step = 0.01;
    for (double x = -10; x <= 10; x += step) {
        if (abs(f_prime(x)) < 0.01) { // yaklasik sifir kontrolü
            points.push_back(x);
        }
    }
    // Benzer noktalari birlestir
    vector<double> unique_points;
    double tolerance = 0.1;
    for (int i = 0; i < points.size(); ++i) {
        if (i == 0 || points[i] - points[i - 1] > tolerance) {
            unique_points.push_back(points[i]);
        }
    }
    return unique_points;
}

// Ikinci türevin sifir oldugu noktalari bulma (bükülme noktalari için yaklasik)
vector<double> find_inflection_candidates() {
    vector<double> points;
    double step = 0.01;
    for (double x = -10; x <= 10; x += step) {
        if (abs(f_double_prime(x)) < 0.01) {
            points.push_back(x);
        }
    }
    // Benzer noktalari birlestir
    vector<double> unique_points;
    double tolerance = 0.1;
    for (int i = 0; i < points.size(); ++i) {
        if (i == 0 || points[i] - points[i - 1] > tolerance) {
            unique_points.push_back(points[i]);
        }
    }
    return unique_points;
}

int main() {
    cout << "f(x) = (x+1)^2 / (1+x^2) fonksiyonu analizi" << endl;
    cout << "===========================================" << endl;

    cout << "\na) Tanim kumesi: Tum reel sayilar (payda her zaman pozitif)." << endl;
    cout << "   f(-x) = " << f(-1) << ", f(x) = " << f(1) << endl;
    cout << "   f(-x) != f(x) ve f(-x) != -f(x) oldugu icin cift veya tek degil." << endl;

    double x_sample = 1.0;
    cout << "\nb) Ornek bir noktada turevler:" << endl;
    cout << "   f'(" << x_sample << ") ˜ " << f_prime(x_sample) << endl;
    cout << "   f''(" << x_sample << ") ˜ " << f_double_prime(x_sample) << endl;

    vector<double> crit_points = find_critical_points();
    cout << "\nc) Kritik noktalar (yaklasik): ";
    for (int i = 0; i < crit_points.size(); i++) {
        cout << crit_points[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < crit_points.size(); i++) {
        double pt = crit_points[i];
        double second = f_double_prime(pt);
        if (second > 0)
            cout << "   x = " << pt << " yerel minimum (f'' > 0)" << endl;
        else if (second < 0)
            cout << "   x = " << pt << " yerel maksimum (f'' < 0)" << endl;
        else
            cout << "   x = " << pt << " belirsiz (f'' ˜ 0)" << endl;
    }

    cout << "\nd) Ornek aralik incelemesi:" << endl;
    double test_points[] = { -2.0, 0.0, 2.0 };
    int test_size = 3;
    for (int i = 0; i < test_size; i++) {
        double tp = test_points[i];
        double deriv = f_prime(tp);
        if (deriv > 0)
            cout << "   x = " << tp << " civarinda artan (f' > 0)" << endl;
        else if (deriv < 0)
            cout << "   x = " << tp << " civarinda azalan (f' < 0)" << endl;
        else
            cout << "   x = " << tp << " civarinda sabit (f' ˜ 0)" << endl;
    }

    vector<double> infl_points = find_inflection_candidates();
    cout << "\ne) Bukumleme noktalari (yaklasik): ";
    for (int i = 0; i < infl_points.size(); i++) {
        cout << infl_points[i] << " ";
    }
    cout << endl;

    cout << "\nf) Dikey asimptot yok (payda hic sifir olmaz)." << endl;
    cout << "   Yatay asimptot: x ? ±8 icin f(x) ? 1 (y = 1)." << endl;
    cout << "   Egik asimptot yok (derece ayni)." << endl;

    cout << "\ng) Onemli noktalar:" << endl;
    cout << "   Eksen kesisimleri:" << endl;
    cout << "   x = -1 icin f(-1) = 0 -> (-1, 0)" << endl;
    cout << "   x = 0 icin f(0) = 1 -> (0, 1)" << endl;
    cout << "   Kritik noktalar ve bükülme noktalari yukarida listelenmistir." << endl;
    cout << "\nGrafik cizimi icin bu noktalari isaretleyip, fonksiyonun" << endl;
    cout << "arttigi/azaldigi ve y = 1 yatay asimptotu goz onune alinmalidir." << endl;

    return 0;
}
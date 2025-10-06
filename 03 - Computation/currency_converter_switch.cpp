#include <iostream>
using namespace std;

int main(){
    constexpr double dollar_per_yen = 0.0069;
    constexpr double dollar_per_kroner = 0.1;
    constexpr double dollar_per_pound = 1.35;
    constexpr double dollar_per_franc = 1.22;
    double money = -1;
    char currency;
    cout << "Please enter an amount of money followed by a currency ( yen (y) / "
         << "  kroner (k) / pounds (p) / francs (f) ):\n";
    cin >> money >> currency;

    switch (currency)
    {
    case 'y':
        cout << money << " yen == " << money*dollar_per_yen << " dollars\n";
        break;
    case 'k':
        cout << money << " krones == " << money*dollar_per_kroner << " dollars\n";
        break;
    case 'p':
        cout << money << " pounds == " << money*dollar_per_pound << " dollars\n";
        break;
    case 'f':
        cout << money << " francs == " << money*dollar_per_franc << " dollars\n";
        break;
    default:
        cout << "Sorry, I am unaware of the " << currency << " currency\n";
        break;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    constexpr double dollar_per_yen = 0.0069;
    constexpr double dollar_per_kroner = 0.1;
    constexpr double dollar_per_pound = 1.35;
    double money = -1;
    char currency;
    cout << "Please enter an amount of money followed by a currency ( yen (y) / kroner (k) / "
         << "pounds (p) ):\n";
    cin >> money >> currency;
    if (currency == 'y')
        cout << money << " yen == " << money*dollar_per_yen << " dollars\n";
    else if (currency == 'k')
        cout << money << " krones == " << money*dollar_per_kroner << " dollars\n";
    else if (currency == 'p')
        cout << money << " pounds == " << money*dollar_per_pound << " dollars\n";
    else
        cout << "Sorry, I am unaware of the " << currency << " currency\n";
    return 0;
}
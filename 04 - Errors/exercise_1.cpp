#include <iostream>
#include <exception>
#include <stdexcept>

using std::cin;
using std::cout;
using std::exception;
using std::string;

void error(string s) {
    throw std::runtime_error{s};
}

double ctok(double c)
{
    if (c <= -273.15) {
        error("Temperature cannot be below absolute zero\n");
    }
    double k = c + 273.25;
    return k;
}

double ktoc(double k)
{
    if (k < 0) {
        error("Temperature cannot be below absolute zero\n");
    }
    double c = k - 273.25;
    return c;
}

int main()
{
    try {
    double temp = 0;
    char unit;
    cout << "Celsius-Kelvin Temperature Converter.\nEnter temp followed by unit:\n";
    cin >> temp >> unit;

    if (cin.fail()) {
        error("Invalid Input!\n");
    }

    if (unit == 'C' || unit == 'c') {
        double k = ctok(temp);
        cout << "Temp in Kelvin: " << k << "K" << '\n';
    }

    if (unit == 'K' || unit == 'k') {
        double c = ktoc(temp);
        cout << "Temp in Celsius: " << c << "C" << '\n';
    }
    return 0;
    } 
    
    catch (exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }

    catch(...) {
        std::cerr << "Oops! Unknown exception!\n";
        return 2;
    }

    return 0;
}
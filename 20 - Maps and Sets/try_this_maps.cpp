#include <map>
#include <string>
#include <iostream>

using std::cout;
using std::map;
using std::string;

int main() {

    map<string, double> dow_price = {
    {"MMM", 104.48}, 
    {"AAPL", 165.02}, 
    {"MSFT", 285.76},
    {"CAT", 412.58},
    {"BA", 231.71},
    {"INTC", 23.90}
};

    map<string, double> dow_weight = {
    {"MMM", 2.41}, {"APPL", 2.84}, {"MSFT", 4.88}};

    map<string, string> dow_name = {
        {"MMM", "3M"},
        {"AAPL", "Apple"},
        {"MSFT", "Microsoft"},
        {"CAT", "Caterpillar"},
        {"BA", "Boeing"},
        {"INTC", "Intel"}
    };

    // double caterpillar = dow_price["CAT"];
    // double boeing_price = dow_price["BA"];

    if (dow_price.find("INTC") != dow_price.end()) {
        cout << "Intel is in the Dow\n";
    }

    for (const auto& [symbol, price] : dow_price) {
        cout << symbol << '\t' << price << '\t' << dow_name[symbol] << '\n';
    }

}




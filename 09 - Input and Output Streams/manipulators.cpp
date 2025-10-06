#include <iostream>

int main () {

    int age = 24, birth = 2001;

    std::cout << "My birth year:" << '\n';
    std::cout << "Decimal: " << std::dec << birth << "\tHexadecimal: " << std::hex << birth 
              << "\tOctal: " << std::oct << birth << '\n';

    std::cout << "My age:" << '\n';
    std::cout << "Decimal: " << std::dec << age << "\tHexadecimal: " << std::hex << age 
              << "\tOctal: " << std::oct << age << '\n';


}

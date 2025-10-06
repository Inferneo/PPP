#include <iostream>

int main(){
    std::string name;
    double age;
    std::cout << "Enter your name and age:\n";
    std::cin >> name >> age;
    std::cout << "Hi, "<< name << ". " <<"You are " << age*12 << " months old.\n";
    return 0;
}
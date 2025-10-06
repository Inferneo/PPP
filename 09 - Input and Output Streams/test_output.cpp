#include <fmt/core.h>
#include <iostream>
#include <string>

int main() {
    
    // constexpr int birth_year = 2001;
    // constexpr int age = 24;

    // fmt::print("\t\tDecimal\tHexadecimal\tOctal\n");
    // fmt::print("Birth Year:\t{:d}\t{:x}\t\t{:o}\n", birth_year, birth_year, birth_year);
    // fmt::print("Age:\t\t{:d}\t{:x}\t\t{:o}\n", age, age, age);


    // int a=0, b=0, c=0, d=0;
    // std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
    // std::cout << a << '\t' << b << '\t' << c << '\t' << d <<'\n';


    // constexpr double dr = 1234567.89;
    // // a-> hexfloat  e-> scientific   f-> fixed    g-> general, with precision 6
    // fmt::print("{}\t{:f}\t{:e}\n", dr, dr, dr);
    

    std::string last_name_0 = "Tarkovsky", last_name_1 = "Godard", 
                last_name_2 = "Snyder", last_name_3 = "Tarantino", last_name_4 = "Rogen";

    std::string first_name_0 = "Andrei", first_name_1 = "Jean-Luc", 
                first_name_2 = "Zack", first_name_3 = "Quentin", first_name_4 = "Seth";

    std::string phone_0 = "1966", phone_1 = "1980", phone_2 = "2021", phone_3 = "1990", phone_4 = "2025";

    std::string email_0 = "christ@rublev.com", email_1 = "cinema@doc.com", 
                email_2 = "cut@justice.com", email_3 = "pulp@fiction.com", email_4 = "holly@wood.com";

    fmt::print("Last Name\tFirst Name\tPhone\tEmail\n");


    std::cout << last_name_0 << '\t' << first_name_0 << "\t\t" << phone_0 << '\t' << email_0 << '\n';
    std::cout << last_name_1 << "\t\t" << first_name_1 << "\t" << phone_1 << '\t' << email_1 << '\n';
    std::cout << last_name_2 << "\t\t" << first_name_2 << "\t\t" << phone_2 << '\t' << email_2 << '\n';
    std::cout << last_name_3 << '\t' << first_name_3 << "\t\t" << phone_3 << '\t' << email_3 << '\n';
    std::cout << last_name_4 << "\t\t" << first_name_4 << "\t\t" << phone_4 << '\t' << email_4 << '\n';

    // fmt::print("{}\t{}\t{}\t{}\t{}\n", last_name_0, first_name_0, phone_0, email_0);
    // fmt::print("{}\t{}\t{}\t{}\t{}\n", last_name_1, first_name_1, phone_1, email_1);
    // fmt::print("{}\t{}\t{}\t{}\t{}\n", last_name_2, first_name_2, phone_2, email_2);
    // fmt::print("{}\t{}\t{}\t{}\t{}\n", last_name_3, first_name_3, phone_3, email_3);
    // fmt::print("{}\t{}\t{}\t{}\t{}\n", last_name_4, first_name_4, phone_4, email_4);
}
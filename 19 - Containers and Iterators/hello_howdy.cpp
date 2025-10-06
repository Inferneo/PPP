#include <iostream>
#include <list>
#include <string>
#include <vector>

template<typename T>
void hello_howdy(T& char_comp) {
    if (char_comp == "Hello!") {
        std::cout << "Hello!" << '\n';
    }
}

int main() {
    char c_char[] {'H', 'e', 'l', 'l', 'o', '!'};
    std::vector<char> v_char {'H', 'e', 'l', 'l', 'o', '!'};
    std::list<char> l_char {'H', 'e', 'l', 'l', 'o', '!'};
    std::string s_char = "Hello!";

    hello_howdy(s_char);
}
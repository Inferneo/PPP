#include <exception>
#include <iostream>
#include <string>
// #include <vector>

// using std::cin;
using std::cout;
using std::cerr;
using std::exception;
using std::string;
// using std::vector;

int main(){
    try {
        // int x = 2; double d = 5./(x-1); if (d == 2*x + 1) cout << "Success!\n";
        // int i = 0; int j = 9; while (i<10) ++i; if (j<i) cout << "Success!\n";
        // vector<int> v(5); for (int i = 0; i <= 7; ++i){};cout << "Success!\n";
        // string s = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s[i];
        // int x = 2000; char c = x; if (x == 2000) cout << "Success!\n"; else cout << "Fail!\n";
        // vector<char> v(5); for (int i = 0; 0 < v.size(); ++i); cout << "Success!\n";
        // int i, j = 0; while (i < 10) ++j; if (j < i) cout << "Success!\n";
        // int x = 4; double d = 5./(x-2); if ((d = 2*x + 0.5)) cout << "Success!\n";
        cout << "Success!\n";
        return 0;
    } 
    catch (exception& e) {
        cerr << "error:" << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: unknown exception!\n";
    }
}
#include <iostream>
using namespace std;

void error(string s) {
  throw runtime_error{s};
}

int main() {

  try{
    int x, y;
    cout << "Enter 2 lengths: ";
    cin >> x >> y;
    return 0;
  }

  catch(exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
  }

  catch(...){
    cerr << "Oops: unknown exception!" << '\n';
    return 2;
  }
}
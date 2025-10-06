#include <exception>
#include <iostream>
#include <stdexcept>
using namespace std;

void error(string s) {
  throw runtime_error{s};
}

int area(int length, int width) {
  if (length <= 0 || width <= 0) {
    error("non-positive argument!");
  }
  return length * width;
}

int framed_area(int x, int y) {
  constexpr int frame_width = 2;
  if (x - frame_width <= 0 || y - frame_width <= 0) {
    error("non-positive argument in framed_area!");
  }
  return area(x - frame_width, y - frame_width);
}

int f(int x, int y, int z) {
  int area1 = area(x, y);
  if (area1 <= 0) {
    error("non-positive area1!");
  }
  int area2 = framed_area(10, z);
  int area3 = framed_area(y, z);
  double ratio = double(area1) / area3;

  cout << area1 << " = area1 (x*y)" << '\n';
  cout << area2 << " = area2 (10-2)*(z-2))"<< '\n';
  cout << area3 << " = area3 (y-2)*(z-2)" << '\n';
  cout << ratio << " = ratio (area1/area3)" << '\n';
  return 0;
}


int main() {

  try{
    int x, y, z;
    cout << "Enter 3 lengths: ";
    cin >> x >> y >> z;
    f(x, y, z);
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

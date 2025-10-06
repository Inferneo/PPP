#include <vector>
#include <list>
#include <array>
#include <iostream>

using std::vector;
using std::list;
using std::array;

template <typename T>
T copy(const T& ints){
    return ints;
} 

int main(){

    int a_int[] = {1,2,3,4,5};
    vector<int> v_int {1,2,3,4,5};
    list<int> l_int {1,2,3,4,5};
    array<int, 5> arr_int {1,2,3,4,5};

    auto a2 = copy(arr_int);
    vector<int> v2 = copy(v_int);
    list<int> l2 = copy(l_int);

    int five = copy(5);
    // std::cout << five;

    for (int x:a2){
        std::cout << x << '\t';
    }
    
    std::cout << '\n';
}


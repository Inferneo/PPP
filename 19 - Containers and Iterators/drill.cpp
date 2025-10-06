#include <algorithm>
#include <vector>
#include <list>
#include <array>
#include <iostream>
#include <iterator>

using std::vector;
using std::list;
using std::array;
using std::cout;

template <std::input_iterator Iter1, std::output_iterator<std::iter_value_t<Iter1>> Iter2>
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2) {
    for (; f1 != e1; ++f1, ++f2) {
        *f2 = *f1;
    }
    return f2;
}

// void copy(int* f1, int* e1, int* f2) {
//     for (; f1 != e1; ++f1, ++f2) {
//         *f2 = *f1;
//     }
// }

int main() {

    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec_int = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst_int = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> array_int = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int arr_2[10];
    for (int i = 0; i < 10; ++i) {
        arr_2[i] = arr[i];
    }
    
    vector<int> vec_2 = vec_int;
    list<int> lst_2 = lst_int;
    array<int, 10> array_2 = array_int;

    for (auto& x : arr_2) {
        x += 2;
    }
    for (auto& x : vec_2) {
        x += 3;
    }
    for (auto& x : lst_2) {
        x += 5;
    }

    copy(std::begin(lst_2), std::end(lst_2), std::begin(arr_2));

    for (auto& x: vec_2) {
        cout << x << '\t';
    }
    cout << '\n';

    auto it = std::find(std::begin(vec_2), std::end(vec_2), 40);
    if (it != vec_2.end()) {
        auto pos = std::distance(vec_2.begin(), it);
        cout << pos << '\n';
    }
    else if (it == vec_2.end()) {
        cout << "Value not found!" << '\n';
    }
}
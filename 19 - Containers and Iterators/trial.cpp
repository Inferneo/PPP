#include <iostream>
#include <iterator>

using std::cout;

template <std::input_iterator Iter1, std::output_iterator<std::iter_value_t<Iter1>> Iter2>
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2) {
    for (; f1 != e1; ++f1, ++f2) {
        *f2 = *f1;
    }
    return f2;
}

int main() {

    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr_2[10];

    copy(std::begin(arr), std::end(arr), std::begin(arr_2));
    
    for (auto& x: arr_2) {
        cout << x << '\t';
    }
    cout << '\n';
}
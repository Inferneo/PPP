#include <fmt/core.h>

int main() {
    
    constexpr double d = 1234.56789;
    // a-> hexfloat  e-> scientific   f-> fixed    g-> general, with precision 6
    fmt::print("{} - {:a} - {:e} - {:f} - {:g}\n\n", d, d, d, d, d);
    
    fmt::print("{:12} - {:12.2f} - {:30.20e}\n", d, d, d);

}
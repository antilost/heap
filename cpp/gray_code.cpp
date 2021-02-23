#include <iostream>
#include <bitset> // https://en.cppreference.com/w/cpp/utility/bitset

int main()
{
    char a = -58;
    std::bitset<8> x(a);
    std::cout << x << '\n';

    short c = -315;
    std::bitset<16> y(c);

    return 0;
}
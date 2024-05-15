#include <iostream>
#include <string>
#include <vector>
#include "random_access_iterator.hpp"

// #if MY_STL
//     #include <vector.hpp>
// #else
//     #include <vector>
//     namespace ft = std;

// #endif

int main()
{
    std::vector<int> v;
    for (int i = 1; i <= 10; i++)
        v.push_back(i);
    
    ft::random_access_iterator<std::vector<int>::iterator> it(v.begin()); 
    // explicit으로 인해 암시적 변환 불가능
    std::cout << *it << '\n';
    return 0;
}

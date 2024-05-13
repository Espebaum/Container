#include <iostream>
#include <string>

#if MY_STL
    #include <vector.hpp>
#else
    #include <vector>
    namespace ft = std;

#endif

int main()
{
    ft::vector<int>v;
    v.push_back(1);
    std::cout << v.front();
}
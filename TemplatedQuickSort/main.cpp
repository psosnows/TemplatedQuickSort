// TemplatedQuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IsCombinable.h"
#include "MyQuickSort.h"

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> v)
{
    std::size_t i{ 0 };
    for (T el : v) {
        os << el;
        if (i < v.size() - 1) {
            os << " ";
            ++i;
        }
        else {
            os << std::endl;
        }
    }
    return os;
};

int main()
{
    {
        double k = 5;
        std::vector<double> varr = { 777, 4.2 ,-1,2,3,-4,5,6,-7,1 };

        std::cout << "input vector: " << varr << std::endl;
        my_quick_sort::sort(varr);
        std::cout << "sorted vector: " << varr << std::endl;

        std::string output = "false";
        if (is_combinable::check(k, varr))
            output = "true";

        std::cout << "Can " << k << " be created as a sum of two elements from the vector above?: " << output << std::endl << std::endl;
    }
    {
        int i = 6444;
        std::vector<int> ivarr = { 3,67,23,-23,67,43,-4,6,7,-124,76,75968,0,-43,6 };
        std::cout << "input vector: " << ivarr << std::endl;
        my_quick_sort::sort(ivarr);
        std::cout << "sorted vector: " << ivarr << std::endl;

        std::string output = "false";
        if (is_combinable::check(i, ivarr))
            output = "true";

        std::cout << "Can " << i << " be created as a sum of two elements from the vector above?: " << output << std::endl << std::endl;
    }
}

#include <iostream>
#include <vector>

long long sum(std::vector<int> &a) {
    long long sum = 0;
    for(auto i : a) {
        sum += i;
    }
    return sum;
}
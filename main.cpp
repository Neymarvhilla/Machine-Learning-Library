#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
int main() {


    std::vector<std::pair<double, int>> my_vec {{3.14,1},
                                                {2.71, 2},
                                                {1.41, 3}};


    std::sort(my_vec.begin(), my_vec.end(), [] (const std::pair<double, int> &a, const std::pair<double, int> &b) {
        return a.first < b.first;
    });
    for (const auto& pair : my_vec) {
        std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
    }
    return 0;
}

//
// Created by Neso Aniagboso on 2024-05-31.
//

#include "Manhattan_Distance.h"
#include <vector>
#include <cmath>

Manhattan_Distance::Manhattan_Distance() {}
Manhattan_Distance::~Manhattan_Distance() {}
double Manhattan_Distance::calculate(const std::vector<double> &a, const std::vector<double> &b) {
    double sum {0};
    for(size_t i {0}; i < a.size(); ++i) {
        sum += std::fabs((a[i] - b[i]));
    }
    return sum;
}

//DistanceMetric * Manhattan_Distance::clone() const {
//    return new Manhattan_Distance();
//}
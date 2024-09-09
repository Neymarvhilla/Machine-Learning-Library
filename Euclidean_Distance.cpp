//
// Created by Neso Aniagboso on 2024-05-31.
//

#include "Euclidean_Distance.h"
#include <cmath>

double Euclidean_Distance::calculate(const std::vector<double> &a, const std::vector<double> &b) {
    double sum{0};
    for(size_t i {0}; i < a.size(); ++i) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

//DistanceMetric * Euclidean_Distance::clone() const {
//    return new Euclidean_Distance;
//}


Euclidean_Distance::Euclidean_Distance() {}
Euclidean_Distance::~Euclidean_Distance() {}


//
// Created by Neso Aniagboso on 2024-05-31.
//

#ifndef PORTFOLIO_PROJECT_1_DISTANCEMETRIC_H
#define PORTFOLIO_PROJECT_1_DISTANCEMETRIC_H
#include <vector>

class DistanceMetric {
public:
    virtual double calculate(const std::vector<double> &a, const std::vector<double> &b)  = 0;
    virtual ~DistanceMetric();
    //virtual DistanceMetric *clone() const = 0;
};


#endif //PORTFOLIO_PROJECT_1_DISTANCEMETRIC_H

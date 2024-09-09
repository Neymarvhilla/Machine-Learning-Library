//
// Created by Neso Aniagboso on 2024-05-31.
//

#ifndef PORTFOLIO_PROJECT_1_EUCLIDEAN_DISTANCE_H
#define PORTFOLIO_PROJECT_1_EUCLIDEAN_DISTANCE_H
#include "DistanceMetric.h"

class Euclidean_Distance : public DistanceMetric {
public:
    virtual double calculate(const std::vector<double> &a, const std::vector<double> &b) override;
    Euclidean_Distance();
    ~Euclidean_Distance();
    //virtual DistanceMetric *clone() const override;

};


#endif //PORTFOLIO_PROJECT_1_EUCLIDEAN_DISTANCE_H

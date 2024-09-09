//
// Created by Neso Aniagboso on 2024-05-31.
//

#ifndef PORTFOLIO_PROJECT_1_MANHATTAN_DISTANCE_H
#define PORTFOLIO_PROJECT_1_MANHATTAN_DISTANCE_H
#include "DistanceMetric.h"

class Manhattan_Distance : public DistanceMetric {
public:
    Manhattan_Distance();
    ~Manhattan_Distance();
    virtual double calculate(const std::vector<double> &a, const std::vector<double> &b) override;
    //virtual DistanceMetric *clone() const override;

};


#endif //PORTFOLIO_PROJECT_1_MANHATTAN_DISTANCE_H

//
// Created by Neso Aniagboso on 2024-05-29.
//

#ifndef PORTFOLIO_PROJECT_1_MODEL_H
#define PORTFOLIO_PROJECT_1_MODEL_H
#include <vector>
#include <iostream>

class Model {
    virtual void fit(const std::vector<double> &train, const int &label) = 0;
    virtual double accuracy_score() = 0;
    virtual int predict_label(std::vector<double> &test, std::vector<std::vector<double>> &train_data, const int &true_label) = 0;
    virtual double compute_distance(const std::vector<double> &a, const std::vector<double> &b) = 0;


};


#endif //PORTFOLIO_PROJECT_1_MODEL_H

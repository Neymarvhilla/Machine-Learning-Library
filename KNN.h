//
// Created by Neso Aniagboso on 2024-05-29.
//

#ifndef PORTFOLIO_PROJECT_1_KNN_H
#define PORTFOLIO_PROJECT_1_KNN_H
#include <vector>
#include "DistanceMetric.h"
#include <memory>
#include "Model.h"
#include <map>

class KNN : public Model {
public:
    int K;
    std::unique_ptr<DistanceMetric> metric_utilized;
    std::vector<std::vector<double>> train_data;
    std::vector<int> train_labels;
   //DistanceMetric *distance_metric_utilized;
    int correct_predictions{0};
    int total_predictions{0};
    std::vector<int> predicted_labels;
    std::vector<int> actual_labels;
    //KNN(int k_value, const DistanceMetric &distance_metric_val);
    KNN (int k_value, std::unique_ptr<DistanceMetric> &metric_value);
    ~KNN();
    virtual double compute_distance(const std::vector<double> &a, const std::vector<double> &b) override;
    virtual void fit(const std::vector<double> &train, const int &label) override;
    std::vector<std::pair<double, int>> get_neighbours(const std::vector<double> &test, const std::vector<std::vector<double>> &train_data);
    std::map<int, int> vote(std::vector<std::pair<double, int>> &nearest_neighbours);
    std::map<int, int> vote_process(std::vector<std::pair<double, int>> &nearest_neighbours);
    virtual int predict_label(std::vector<double> &test, std::vector<std::vector<double>> &train_data, const int &true_label) override;
    virtual double accuracy_score() override;




};


#endif //PORTFOLIO_PROJECT_1_KNN_H

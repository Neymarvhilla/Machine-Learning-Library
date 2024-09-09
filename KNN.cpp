//
// Created by Neso Aniagboso on 2024-05-29.
//

#include "KNN.h"
#include "DistanceMetric.h"
#include "Euclidean_Distance.h"
#include <utility>
#include <algorithm>
#include <set>
#include <limits>
#include <memory>
#include <map>
//KNN::KNN(int k_value, const DistanceMetric &distance_metric_val)
//    : K{k_value}, distance_metric_utilized{distance_metric_val.clone()} {}

KNN::KNN(int k_value, std::unique_ptr<DistanceMetric> &metric_value)
    : K{k_value}, metric_utilized{std::move(metric_value)} {}

double KNN::compute_distance(const std::vector<double> &a, const std::vector<double> &b) {
    return metric_utilized->calculate(a,b);
}

void KNN::fit(const std::vector<double> &train, const int &label) {
    train_data.push_back(train);
    train_labels.push_back(label);
}

std::vector<std::pair<double, int>> KNN::get_neighbours(const std::vector<double> &test, const std::vector<std::vector<double>> &train_data) {
    std::vector<std::pair<double, int>> neighbours{};
    for(size_t i {0}; i < train_data.size(); ++i) { // this method get the nearest neighbours to the test data point, and stores them in the nearest_neighbours vector as well as their labels.
        // we call the compute_distance member function and pass in the test data point and every data point in our train_data vector.
        // we then make them into a pair of values to be stored in the nearest_neighbour vector. the pairs are the distances from the test point and their respective indices
        neighbours.push_back(std::make_pair(compute_distance(test, train_data[i]), i));
    }
    // we loop through the nearest_neighbours vector and replace the indices with their labels
    for(size_t i {0}; i < neighbours.size(); ++i) {
        neighbours[i].second = train_labels[i];
    }
    // we then sort the by distances in ascending order, hence, the first K distances are the nearest neighbours
    std::sort(neighbours.begin(), neighbours.end(), [](const std::pair<double, int> &a, const std::pair<double, int> &b) {
        return a.first < b.first;
    });
    neighbours.assign(neighbours.begin(), neighbours.begin() + K);
    return neighbours;
}


std::map<int, int> KNN::vote(std::vector<std::pair<double, int>> &nearest_neighbours) {
    std::map<int, int> vote_results;
    for (auto &value : nearest_neighbours) {
        ++vote_results[value.second];
    }
    return vote_results;
}
int KNN::predict_label(std::vector<double> &test, std::vector<std::vector<double>> &train_data, const int &true_label) {
    std::vector<std::pair<double, int>> neighbours {get_neighbours(test,train_data)};
    std::map<int, int> votes{vote(neighbours)};
    int max_votes {std::numeric_limits<int>::min()};
    int predicted_label = -1; // to store the predicted label
    for (const auto &vote : votes) {
        if (vote.second > max_votes) {
            max_votes = vote.second;
            predicted_label = vote.first;
        }
    }
    total_predictions+=1;
    predicted_labels.push_back(predicted_label);
    actual_labels.push_back(true_label);
    return predicted_label;
}

double KNN::accuracy_score() {
    if(!actual_labels.empty() && !predicted_labels.empty()) {
        for(size_t i {0}; i < actual_labels.size(); ++i) {
            if(actual_labels[i] == predicted_labels[i]) {
                correct_predictions +=1;
            }
        }
    }
    return static_cast<double>(correct_predictions) / total_predictions;
}

KNN::~KNN(){
    //delete distance_metric_utilized;
}
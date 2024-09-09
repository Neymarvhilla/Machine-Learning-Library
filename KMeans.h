//
// Created by Neso Aniagboso on 2024-05-29.
//

#ifndef PORTFOLIO_PROJECT_1_KMEANS_H
#define PORTFOLIO_PROJECT_1_KMEANS_H
#include <memory>
#include "DistanceMetric.h"
#include "Model.h"
#include <vector>
class KMeans : public Model {
public:
    // Attributes
    std::vector<std::vector<double>> data_points;
    std::unique_ptr<DistanceMetric> distance_metric_utilized;
    int K; // number of clusters
    std::vector<int> number_of_centroids;
    int maximum_iterations; // maximum number of iterations for the algorithm to run
    double tolerance; // a threshhold to determine convergence
    std::vector<int> cluster_labels; // stores the cluster label for each data point
    // Overloaded constructor
    KMeans(int k_value, std::unique_ptr<DistanceMetric> distance_metric_value, int max_iterations, double tolerance);
    // Destructor
    ~KMeans();
    // Methods
    std::vector<std::vector<double>> initial_centroids();
    std::vector<std::vector<std::vector<double>>> assign_clusters();
    virtual double compute_distance(const std::vector<double> &a, const std::vector<double> &b) override;




};


#endif //PORTFOLIO_PROJECT_1_KMEANS_H

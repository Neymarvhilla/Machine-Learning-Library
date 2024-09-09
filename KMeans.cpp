#include "KMeans.h"
#include <random>
#include <set>
#include <map>

KMeans::KMeans(int k_value, std::unique_ptr<DistanceMetric> distance_metric_value, int max_iterations, double tolerance)
    : K {k_value}, distance_metric_utilized {std::move(distance_metric_value)}, maximum_iterations {max_iterations}, tolerance {tolerance} {}


KMeans::~KMeans(){}

std::vector<std::vector<double>> KMeans::initial_centroids() {
    // create a random number engine with a seed
    std::random_device seed_generator;
    std::mt19937 gen(seed_generator()); // Mersenne Twister engine seeded with rd()

    // define the distribution (e.g. uniform distribution for integers)
    std::uniform_int_distribution<> distribution(0, data_points.size() - 1);

    std::vector<std::vector<double>> centroids{};
    std::set<int> random_numbers;
    // generate K random number
    if (K <= data_points.size()) {
        while (random_numbers.size() != K) {
            random_numbers.insert(distribution(gen));
        }
        for (auto value: random_numbers) {
            centroids.push_back(data_points[value]);
        }
    }
    return centroids;
}

std::vector<std::vector<std::vector<double>>> KMeans::assign_clusters() {
    //std::map<std::vector<double>, std::vector<double>> centroid_and_corresponding_distances {};
    std::vector<std::vector<double>> distances_for_each_centroid {};
    std::vector<std::vector<double>> centroids = initial_centroids();
    for (int i {0}; i < centroids.size(); ++i) {
        std::vector<double> distances{};
        for (int j {0}; j < data_points.size(); ++j) {
            double distance = compute_distance(centroids[i], data_points[j]);
            distances.push_back(distance);
        }
        distances_for_each_centroid.push_back(distances);
    }
    std::vector<std::vector<std::vector<double>>> clusters (centroids.size());
    for (int i {0}; i < data_points.size(); ++i) {
        double minimum_distance = distances_for_each_centroid[0][i];
        int nearest_centroid = 0;
        for (int j {1}; j < centroids.size(); ++j) {
            if (distances_for_each_centroid[j][i] < minimum_distance) {
                minimum_distance = distances_for_each_centroid[j][i];
                nearest_centroid = j;
            }
        }
        clusters[nearest_centroid].push_back(data_points[i]);
    }
    return clusters;
}

double KMeans::compute_distance(const std::vector<double> &a, const std::vector<double> &b) {
    return distance_metric_utilized->calculate(a,b);
}
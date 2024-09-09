//
// Created by Neso Aniagboso on 2024-05-29.
//

#ifndef PORTFOLIO_PROJECT_1_DATASET_H
#define PORTFOLIO_PROJECT_1_DATASET_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class DataSet {

public:
    // Data storage
    std::vector<std::vector<double>> data; // 2D vector to store the dataset's features
    std::vector<int> labels; // A vector to store the labels corresponding to the dataset

    // Metadata
    int num_sample; // number of rows in the data set
    int num_features; // number of columns in the data set
    std::vector<double> feature_max; // to store the maximum value of each feature for normalization purposes
    std::vector<double> feature_min; // to store the minimum value of each feature for normalization purposes

    // Accessing File Paths
    std::string file_path; // A string to store the path of the dataset file for loading data.

    // Splits
    std::vector<std::vector<double>> train_data; // A 2D vector to store the training data after splitting
    std::vector<int> train_label; // A vector to store the labels of the training data
    std::vector<std::vector<double>> test_data; // A 2D vector to store the testing data after splitting
    std::vector<int> test_labels; // A vector to store the labels of the testing data

    // Normalization Flags
    bool is_normalized; // A boolean flag to indicate whether the data has been normalized

    // Methods
    void load_data();
    void initialize_feature_stats();
    void normalize_data();
    void split_data(double training_ratio);
    void print_data();

    DataSet(const std::string &file_path, int num_samples = 0, int num_features = 0, bool is_normalized=false);
    ~DataSet();


};


#endif //PORTFOLIO_PROJECT_1_DATASET_H

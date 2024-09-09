//
// Created by Neso Aniagboso on 2024-05-29.
//

/*
 *
 * .assign()
 * example
 *          std::vector<int> vec1 = {1, 2, 3, 4, 5};
            std::vector<int> vec2;
            vec2.assign(vec1.begin(), vec1.begin() + 3);  // vec2 now contains {1, 2, 3}

            example 2
            std::vector<int> vec;
            vec.assign({1, 2, 3, 4, 5});  // vec now contains {1, 2, 3, 4, 5}

            example 3
            std::vector<int> vec;
            vec.assign(5, 10);  // vec now contains {10, 10, 10, 10, 10}

The assign method is a powerful tool in the C++ Standard Library for copying and filling containers.
It can take a range of iterators, an initializer list, or a specific value repeated multiple times.
This method not only simplifies code but also ensures that the container's size is correctly adjusted to accommodate the new elements.





*/


#include "DataSet.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

// Constructor
DataSet::DataSet(const std::string &file_path, int num_samples, int num_features, bool is_normalized)
    : file_path {file_path}, num_sample{num_samples}, num_features{num_features}, is_normalized{is_normalized} {}


// Destructor
DataSet::~DataSet() {}

// Implementing the load file method

void DataSet::load_data() {
    try {
        if (file_path.empty()) {
            throw std::runtime_error{"Can't find the file path"};
        }
        std::ifstream dataset_file{file_path};
        if (!dataset_file) {
            throw std::runtime_error{"Failed to open file"};
        }
        std::string line{};

        while(std::getline(dataset_file, line)) {
            std::vector<std::string> token{split(line, ',')};
            if (token.empty()) {
                continue;
            }
            std::vector<double> features;
            for (size_t i {0}; i < token.size()- 1; ++i) {
                features.push_back(std::stod(token[i]));
            }
            data.push_back(features);
            labels.push_back(std::stoi(token.back()));
        }
        if(data.empty()) {
            throw std::runtime_error{"data vector is empty"};
        }
        num_sample = data.size();
        num_features = data[0].size();
    }
    catch (const std::runtime_error &e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument &e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }


//    std::ifstream dataset_file{file_path}; // We are utilizing the input file stream to read from files.
//    std::string line;
//    // utilize a while loop to read every line from the dataset file and store it in our variable line
//    // the loop will run until it has retrieved all the lines from the dataset file and stored them in our string, 'line'
//    while(std::getline(dataset_file, line)) {
//        std::vector<std::string> token{split(line, ',')};
//        if(token.empty()) {
//            continue;
//        }
//        std::vector<double> features;
//        for(size_t i{0}; i < token.size() - 1; ++i) {
//            features.push_back(std::stod(token[i])); // std::stoi() is standard library function that converts a string to an integer
//        }
//        data.push_back(features);
//        labels.push_back(std::stoi(token.back())); // converts the last token of the line (which is the label) from a string to an integer and adds it to the labels vector
//    }
//    // overall, the loop reads each line and converts them to the appropriate type before storing in a vector. This vector is then stored in our data attribute.
//    if(!data.empty()) {
//        num_sample = data.size(); // the number of rows (it is a 2-dimensional vector)
//        num_features = data[0].size(); // the number of columns.
//    }
//    else{
//        std::cout << "No data loaded from file: " << file_path << std::endl;
//    }

}

// Implement
void DataSet::initialize_feature_stats() {
    // we begin by resizing our feature feature_max vector to make sure it matches the number of feature(columns) we have
    // we also set the values to the lowest possible that C++ would allow
    // we do the same with our feature min vector but we set the values to the highest possible that C++ would allow
    feature_max.resize(num_features, std::numeric_limits<double>::min());
    feature_min.resize(num_features, std::numeric_limits<double>::max());
    for(size_t i {0}; i < data.size(); ++i) {
        for(size_t j {0}; j < data[i].size(); ++j) {
            if(data[i][j] > feature_max[j]) {
                feature_max[j] = data[i][j];
            }
            if(data[i][j] < feature_min[j]) {
                feature_min[j] = data[i][j];
            }
        }

    }
}

void DataSet::normalize_data() {
    if(is_normalized) {
        return;
    }
    for (size_t i {0}; i < data.size(); ++i) {
        for (size_t j {0}; j < num_features; ++j) {
            data[i][j] = (data[i][j] - feature_min[j]) / (feature_max[j] - feature_min[j]);
        }
    }
    is_normalized = true;
}


void DataSet::split_data(double training_ratio) {
    // description of the assign method above
    int training_size {static_cast<int>(training_ratio * num_sample)};
    train_data.assign(data.begin(), data.begin() + training_size);
    train_label.assign(labels.begin(), labels.begin() + training_size);
    test_data.assign(data.begin() + training_size, data.end());
    test_labels.assign(labels.begin() + training_size, labels.end());
}

void DataSet::print_data() {
    for(size_t i {0}; i < data.size(); ++i) {
        for (size_t j {0}; j < data[i].size(); ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}




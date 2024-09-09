cmake_minimum_required(VERSION 3.27)
project(Portfolio_Project_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Portfolio_Project_1 main.cpp
        DataSet.cpp
        DataSet.h
        Model.cpp
        Model.h
        KNN.cpp
        KNN.h
        KMeans.cpp
        KMeans.h
        DistanceMetric.cpp
        DistanceMetric.h
        Euclidean_Distance.cpp
        Euclidean_Distance.h
        Manhattan_Distance.cpp
        Manhattan_Distance.h
)

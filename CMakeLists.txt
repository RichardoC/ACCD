cmake_minimum_required(VERSION 3.6)
project(ACCD)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    data_export_cobercat/data_export_01-2015.csv
    data_export_cobercat/data_export_01-2016.csv
    data_export_cobercat/data_export_02-2015.csv
    data_export_cobercat/data_export_02-2016.csv
    data_export_cobercat/data_export_03-2015.csv
    data_export_cobercat/data_export_03-2016.csv
    data_export_cobercat/data_export_04-2015.csv
    data_export_cobercat/data_export_04-2016.csv
    data_export_cobercat/data_export_05-2015.csv
    data_export_cobercat/data_export_05-2016.csv
    data_export_cobercat/data_export_06-2015.csv
    data_export_cobercat/data_export_06-2016.csv
    data_export_cobercat/data_export_07-2015.csv
    data_export_cobercat/data_export_07-2016.csv
    data_export_cobercat/data_export_08-2015.csv
    data_export_cobercat/data_export_08-2016.csv
    data_export_cobercat/data_export_09-2015.csv
    data_export_cobercat/data_export_09-2016.csv
    data_export_cobercat/data_export_1-2015.csv
    data_export_cobercat/data_export_10-2015.csv
    data_export_cobercat/data_export_11-2015.csv
    data_export_cobercat/data_export_12-2015.csv
    README
    "Richard's analysis code.ipynb" CellUser.cpp CellUser.h Analysis.cpp Analysis.h)

add_executable(ACCD ${SOURCE_FILES})
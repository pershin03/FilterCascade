//
// Created by Admin on 22.04.2025.
//

#include "signal_processing.h"



#include <fstream>
#include <iostream>



void SignalProcessing::readIQFromTxt(const std::string &path, std::vector<std::complex<int64_t> > &vector_iq_complexes) {
    vector_iq_complexes.clear();
    vector_iq_complexes.reserve(1048576);
    std::ifstream fin;
    fin.open(path);
    if (!fin.is_open()) {
        std::cout << "Error opening file " <<  std::endl;
    }
    else {
        std::cout << "File opened" << std::endl;

        int64_t re, im;
        while (fin >> re && fin >> im) {
            vector_iq_complexes.emplace_back(re, im);
            // std::cout << vector_iq_complexes.size() << std::endl;
        }
    }
    fin.close();
}
void SignalProcessing::readFilterCoefficients(const std::string &path, std::vector<int32_t> &filterCoefficients) {
    filterCoefficients.clear();
    std::ifstream fin;
    fin.open(path);
    if (!fin.is_open()) {
        std::cout << "Error opening file " <<  std::endl;
    }
    else {
        std::cout << "File opened" << std::endl;
        int32_t value;

        while (fin >> value) {
            filterCoefficients.push_back(value);
        }
    }
    fin.close();
}

void SignalProcessing::writeComplexSignalToTxt(const std::string& path, const std::vector<std::complex<int64_t>>& signal) {
    std::ofstream fout(path);

    if (!fout.is_open()) {
        std::cerr << "Error: cannot open file for writing: " << path << std::endl;
        return;
    }

    for (const auto& sample : signal) {
        fout << sample.real() << "\n" << sample.imag() << "\n";
    }

    fout.close();
}

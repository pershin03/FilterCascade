//
// Created by user on 21.04.2025.
//

#ifndef SIGNAL_PROCESSING_H
#define SIGNAL_PROCESSING_H
#include <complex>
#include <cstdint>
#include <vector>

class SignalProcessing {
public:
    void readIQFromTxt(std::vector<std::complex<int32_t>>& vector_iq_complexes);
    void readFilterCoefficients(std::vector<int32_t>& filterCoefficients);
private:
    std::vector<std::complex<int32_t>> vector_iq_complexes_;
    std::vector<int32_t> filterCoefficients_;
};

#endif //SIGNAL_PROCESSING_H

//
// Created by Admin on 22.04.2025.
//

#ifndef SIGNAL_PROCESSING_H
#define SIGNAL_PROCESSING_H
#include <string>
#include <complex>
#include <vector>
#include <cstdint>

class SignalProcessing {
public:
    void readIQFromTxt(const std::string& path, std::vector<std::complex<int64_t>>& vector_iq_complexes);
    void readFilterCoefficients(const std::string& path, std::vector<int32_t>& filterCoefficients);
    void writeComplexSignalToTxt(const std::string& path, const std::vector<std::complex<int64_t>>& signal);
// private:
//     std::vector<std::complex<int32_t>> vector_iq_complexes_{};
//     std::vector<int32_t> filterCoefficients_{};
};

#endif //SIGNAL_PROCESSING_H

//
// Created by Admin on 22.04.2025.
//

#ifndef FILTERFIR_H
#define FILTERFIR_H
#include <cstdint>
#include <vector>
#include <complex>

class FIRFilter {
public:
    FIRFilter(const std::vector<int32_t>& coefficients, int decimation);
    std::vector<std::complex<int64_t>> apply(std::vector<std::complex<int64_t>>& signal);
private:
    std::vector<int32_t> coefficients_;
    int decimation_;

};
#endif //FILTERFIR_H

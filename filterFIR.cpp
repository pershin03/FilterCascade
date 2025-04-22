#include "filterFIR.h"
//
// Created by Admin on 22.04.2025.
//
FIRFilter::FIRFilter(const std::vector<int32_t> &coefficients, int decimation) : coefficients_(coefficients), decimation_(decimation) {}

//std::vector<std::complex<int64_t>> FIRFilter::apply(std::vector<std::complex<int64_t>> &signal) {
    // std::vector<std::complex<int64_t>> result;
    // size_t filter_size = coefficients_.size();
    //
    // for (size_t i = 0; i + filter_size <= signal.size(); i += decimation_) {
    //     int64_t acc_re = 0;
    //     int64_t acc_im = 0;
    //
    //     for (size_t j = 0; j < filter_size; ++j) {
    //         acc_re += signal[i + j].real() * coefficients_[j];
    //         acc_im += signal[i + j].imag() * coefficients_[j];
    //     }
    //
    //     result.emplace_back(acc_re, acc_im);
    // }
    //
    // return result;

//}

std::vector<std::complex<int64_t>> FIRFilter::apply(std::vector<std::complex<int64_t>> &signal) {
    std::vector<std::complex<int64_t>> result;
    size_t filter_size = coefficients_.size();

    // Вычисляем, сколько выходных отсчётов должно быть
    size_t expected_output_size = signal.size() / decimation_;

    // Вычисляем, сколько входных отсчётов нужно, чтобы выдать expected_output_size
    size_t required_input_size = (expected_output_size - 1) * decimation_ + filter_size;

    // Если сигнал коротковат — дополняем нулями
    if (signal.size() < required_input_size) {
        signal.resize(required_input_size, std::complex<int64_t>(0, 0));
    }

    // Основной цикл фильтрации
    for (size_t i = 0; i + filter_size <= signal.size(); i += decimation_) {
        int64_t acc_re = 0;
        int64_t acc_im = 0;

        for (size_t j = 0; j < filter_size; ++j) {
            acc_re += signal[i + j].real() * coefficients_[j];
            acc_im += signal[i + j].imag() * coefficients_[j];
        }

        result.emplace_back(acc_re, acc_im);
    }

    return result;
}

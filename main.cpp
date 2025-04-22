#include "signal_processing.h"
#include "filterFIR.h"
#include <iostream>

int main() {
    std::vector<std::complex<int64_t>> signal;
    std::vector<int32_t> fir_coeffs;

    SignalProcessing sp;

    // Reading IQ from txt file
    sp.readIQFromTxt("C:/CLionProjects/FilterCascade/txt/Sig_1_Rx.txt", signal);
    std::cout << "signal size: " << signal.size() << std::endl;
    // FIR_32
    // sp.readFilterCoefficients("C:/CLionProjects/myProjectNIR/txt/FIR_32/LPF.txt", fir_coeffs);
    // FIRFilter filter(fir_coeffs, 32);
    // auto filtered_signal = filter.apply(signal);
    // sp.writeComplexSignalToTxt("C:/CLionProjects/FilterCascade/txt/FIR_32/filtered_output.txt", filtered_signal);


    //cascade-FIR 4_4_2
    sp.readFilterCoefficients("C:/CLionProjects/FilterCascade/txt/FIR_4_4_2/LPF_1.txt", fir_coeffs);
    FIRFilter filter1(fir_coeffs, 4);
    auto filtered_signal1 = filter1.apply(signal);
    std::cout << "filtered_signal1_size " << filtered_signal1.size() << std::endl;

    sp.readFilterCoefficients("C:/CLionProjects/FilterCascade/txt/FIR_4_4_2/LPF_2.txt", fir_coeffs);
    FIRFilter filter2(fir_coeffs, 4);
    auto filtered_signal2 = filter2.apply(filtered_signal1);
    std::cout << "filtered_signal1_size " << filtered_signal2.size() << std::endl;

    sp.readFilterCoefficients("C:/CLionProjects/FilterCascade/txt/FIR_4_4_2/LPF_3.txt", fir_coeffs);
    FIRFilter filter3(fir_coeffs, 4);
    auto filtered_signal3 = filter3.apply(filtered_signal2);
    std::cout << "filtered_signal1_size " << filtered_signal3.size() << std::endl;

    sp.writeComplexSignalToTxt("C:/CLionProjects/FilterCascade/txt/FIR_4_4_2/filtered_output.txt", filtered_signal3);




    return 0;
}
//
// Created by Admin on 22.04.2025.
//

#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <cstdint>


class Filter {
public:
    // void filter_fir(std::vector<int64_t>& signal_vector,
    //                 std::vector<int32_t>& filter_vector,
    //                 int decimation_coefficient);
    void filter_cic(std::vector<int64_t>& signal_vector,
                    std::vector<int32_t>& filter_vector,
                    int decimation_coefficient,
                    int delay_time_i);
// private:
//     int decimation_coefficient_{};
//     int delay_time_{};
//     int sec_number_{};

};

#endif //FILTER_H

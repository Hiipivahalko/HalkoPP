#ifndef _UTILS_UTILS_HPP_
#define _UTILS_UTILS_HPP_

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

namespace utils {
    void print_uInt_vector(const std::vector<u_int32_t> &v, const std::string s);
    void copy_n_blocks(const char *input_file, const std::string &output_file, const u_int64_t &n);
    template <typename T>
    void read_input_file(const char *input_file, std::vector<T> &vec_ref);
    std::string current_time2str();

    template <typename T>
    void read_input_file(const char *input_file, std::vector<T> &vec_ref) {
        FILE *fp = fopen(input_file, "r");
        uint64_t u, n;

        fseek(fp, 0, SEEK_END);
        n = ftell(fp) / sizeof(T);
        fseek(fp, 0, SEEK_SET);

        //std::cerr << ">> Number of integers: " << n << std::endl;
        vec_ref.resize(n);
        //uint64_t biggest_val = 0;
        //std::cerr << ">> Reading input...";
        for (uint64_t i = 0; i < n; i++) {
            fread(&u, sizeof(T), 1, fp);
            vec_ref[i] = u;
            //if (u > biggest_val) biggest_val = u;
        }

        //cout << "r biggest val: " << biggest_val << endl;

        fclose(fp);  // closing inputfile
        //std::cerr << " DONE" << std::endl;

    }
}

#endif

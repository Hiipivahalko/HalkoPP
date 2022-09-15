#ifndef _ZOMBIT_VECTOR_HPP_
#define _ZOMBIT_VECTOR_HPP_

#include <iostream>
#include <algorithm>
#include <sdsl/bit_vectors.hpp>
#include <vector>


template <
    typename T_u_vec, typename T_u_vec_rank,
    typename T_o_vec, typename T_o_vec_rank, typename T_o_vec_slc,
    typename T_m_vec, typename T_m_vec_rank, typename T_m_vec_slc
    >
class Zombit {
    public:

        Zombit();
        void build_zombit(sdsl::bit_vector &X, uint32_t b);
        void build_zombit(sdsl::bit_vector &X);
        uint32_t access(uint64_t i); // return value of i-th bit
        uint64_t nextGEQ(uint64_t x); // return next greater or equal than x
        uint64_t size(); // return lenght of the original bitvector
        uint64_t size_in_bits();
        float u_vector_size_in_bits();
        float o_vector_size_in_bits();
        float m_vector_size_in_bits();

        uint32_t block_size;
        uint64_t orig_bv_size = 0;
        uint64_t runs_n = 0;
        uint64_t m_blocks = 0;
        uint64_t block_n = 0;

        T_u_vec u_vector;
        T_o_vec o_vector;
        T_m_vec m_vector;

        T_u_vec_rank u_rank;
        T_o_vec_rank o_rank;
        T_o_vec_slc o_select;
        T_m_vec_rank m_rank;
        T_m_vec_slc m_select;
};


template <
    typename T_u_vec, typename T_u_vec_rank,
    typename T_o_vec, typename T_o_vec_rank, typename T_o_vec_slc,
    typename T_m_vec, typename T_m_vec_rank, typename T_m_vec_slc
    >
Zombit<T_u_vec,T_u_vec_rank,T_o_vec,T_o_vec_rank,T_o_vec_slc,T_m_vec,T_m_vec_rank,T_m_vec_slc>::Zombit() {};

/*
 * Note if |X| mod block_size != 0, bitvector X is modified to zero's are added end of X, such that
 * |X| mod block_size = 0 is valid.
 */
template <
    typename T_u_vec, typename T_u_vec_rank,
    typename T_o_vec, typename T_o_vec_rank, typename T_o_vec_slc,
    typename T_m_vec, typename T_m_vec_rank, typename T_m_vec_slc
    >
void Zombit<T_u_vec,T_u_vec_rank,T_o_vec,T_o_vec_rank,T_o_vec_slc,T_m_vec,T_m_vec_rank,T_m_vec_slc>::build_zombit(sdsl::bit_vector &X, uint32_t b) {
    block_size = b;
    orig_bv_size = X.size();
    if (runs_n == 0) {
        uint32_t prev = 0;
        for (uint64_t i = 0; i < X.size(); i++) {
            if (X[i] && !prev) {
                runs_n++;
                prev = 1;
            } else if (!X[i] && prev) {
                prev = 0;
            }
        }
    }
    // adding 0s end of X, so that all blocks have same length.
    if (X.size() % block_size != 0) {
        //std::cerr << ">> resizing X..";
        X.resize(X.size() + (block_size - (X.size() % block_size)));
        //std::cerr << "Done\n";
    }
    block_n = X.size() / block_size;
    sdsl::bit_vector U_bv = sdsl::bit_vector(block_n);
    sdsl::bit_vector O_bv = sdsl::bit_vector(block_n);
    char label = 'O';
    m_blocks = 0;
    std::vector<uint64_t> m_block_idx;

    // building U and O-vector
    for (uint64_t i = 0; i < block_n; i++) {
        //block first val
        if (X[i*block_size] == 0) label = 'Z';
        else label = 'O';
        for (uint64_t j = 1; j < block_size; j++) {

            if (X[i * block_size + j] == 0 && label == 'Z') continue;
            if (X[i * block_size + j] == 1 && label == 'O') continue;
            if (X[i * block_size + j] == 0 && label == 'O') {
                label = 'M';
                continue;
            }
            if (X[ (i * block_size) + j] == 1 && label == 'Z') {
                label = 'M';
                continue;
            }
        }
        // setting value for U-vector at index b_idx
        if (label == 'Z' || label == 'O') U_bv[i] = 1; // all values 0s or 1s
        else U_bv[i] = 0; // mix of 0s and 1s
        // setting value for O-vector at indexx b_idx
        if (label == 'Z') O_bv[i] = 0; // all 0s
        else O_bv[i] = 1; // block contain atleast one 1 bit

        if (label == 'M') {
            m_blocks++;
            m_block_idx.push_back(i);
        }
    }

    // building M-vector
    sdsl::bit_vector M_bv = sdsl::bit_vector(block_size * m_blocks);
    uint64_t m_idx = 0;
    for (uint64_t x : m_block_idx) {
        for (uint64_t k = 0; k < block_size; k++) {
            M_bv[m_idx] = X[(x * block_size) + k];
            m_idx++;
        }
    }

    u_vector = T_u_vec(U_bv);
    o_vector = T_o_vec(O_bv);
    m_vector = T_m_vec(M_bv);

    u_rank = T_u_vec_rank(&u_vector);
    o_rank = T_o_vec_rank(&o_vector);
    m_rank = T_m_vec_rank(&m_vector);
    o_select = T_o_vec_slc(&o_vector);
    m_select = T_m_vec_slc(&m_vector);
}

// build zombit-vector with optimal block size sqrt(n/runs) according article
template <
    typename T_u_vec, typename T_u_vec_rank,
    typename T_o_vec, typename T_o_vec_rank, typename T_o_vec_slc,
    typename T_m_vec, typename T_m_vec_rank, typename T_m_vec_slc
    >
void Zombit<T_u_vec,T_u_vec_rank,T_o_vec,T_o_vec_rank,T_o_vec_slc,T_m_vec,T_m_vec_rank,T_m_vec_slc>::build_zombit(sdsl::bit_vector &X) {
    uint32_t prev = 0;
    runs_n = 0;
    for (uint64_t i = 0; i < X.size(); i++) {
        if (X[i] && !prev) {
            runs_n++;
            prev = 1;
        } else if (!X[i] && prev) {
            prev = 0;
        }
    }
    if (runs_n == 0) runs_n = 1; // all 0s or 1s
    uint32_t b = (uint32_t) sqrt(X.size()/runs_n);
    std::cerr << ">> block size: " << b << "\n";

    build_zombit(X, b);
}


template <
    typename T_u_vec, typename T_u_vec_rank,
    typename T_o_vec, typename T_o_vec_rank, typename T_o_vec_slc,
    typename T_m_vec, typename T_m_vec_rank, typename T_m_vec_slc
    >
uint32_t Zombit<T_u_vec,T_u_vec_rank,T_o_vec,T_o_vec_rank,T_o_vec_slc,T_m_vec,T_m_vec_rank,T_m_vec_slc>::access(uint64_t i) {
    uint64_t j = i / block_size;
    //std::cout << "i:" << i << " j: " << j;
    if (u_vector[j] == 1) {
        //std::cout << " here1, " << o_vector[j] << "\n";
        if (o_vector[j] == 1) return 1;
        else return 0;
    }
    uint64_t q = u_rank(j);
    uint64_t delta_i = i % block_size;
    uint64_t beg_q = q * block_size;
    //std::cout << "here2, q:" << q << " delta_i:" << delta_i << " beg_q:" << beg_q << "\n";
    return m_vector[beg_q + delta_i];

}

template <
    typename T_u_vec, typename T_u_vec_rank,
    typename T_o_vec, typename T_o_vec_rank, typename T_o_vec_slc,
    typename T_m_vec, typename T_m_vec_rank, typename T_m_vec_slc
    >
uint64_t Zombit<T_u_vec,T_u_vec_rank,T_o_vec,T_o_vec_rank,T_o_vec_slc,T_m_vec,T_m_vec_rank,T_m_vec_slc>::nextGEQ(uint64_t x) {
    uint64_t j = x / block_size;
    uint64_t q = u_rank(j);
    //std::cout << "x:" << x << " j:" << j << " q:" << q;
    // x is in uniform block of 1s
    if (u_vector[j] == 1) {
        if (o_vector[j] == 1) {
            //std::cout << " res:" << x << " here1 x is in uniforms of 1s\n";
            return x;
        }
    } else {
        uint64_t beg_q = q * block_size;
        uint64_t delta_x = x % block_size;
        uint64_t s = m_select( m_rank(beg_q + delta_x)+1 );
        //std::cout << " beg_q:" << beg_q << " delta_x:" << delta_x << " s:" << s;
        //std::cout << " m_rank:" << (m_rank(beg_q + delta_x));
        if (s <= beg_q + block_size - 1) {
            //std::cout << " res:" << ((j * block_size) + (s % block_size)) << "\n";
            return (j * block_size) + (s % block_size);
        }
    }
    // x is in fixed block or block of 0s

    // jump func in article
    // next 1 is in next block
    //std::cout << " JUMP";
    uint64_t j_p = o_select( o_rank(j+1) + 1 );
    // next block is uniform full of 1s, return first item of block
    //std::cout << " j':" << j_p;
    if (u_vector[j_p] == 1) {
        //std::cout << " res:" << (j_p * block_size)  << "\n";
        return j_p * block_size;
    }
    uint64_t beg_q1 = u_vector[j] ? q * block_size : (q+1) * block_size;
    uint64_t s_p = m_select( m_rank( beg_q1 ) + 1 );
    uint64_t beg_j_p = j_p * block_size;
    uint64_t delta_s_p = s_p % block_size;
    //std::cout << " s':" << s_p;
    //std::cout << " m_rank:" << (m_rank(beg_q1)) << " beg_q+1:" << beg_q1 << " beg_j':" << beg_j_p << " delta_sp:" << delta_s_p;
    //std::cout << " res:" << (beg_j_p + delta_s_p) << "\n";
    return beg_j_p + delta_s_p;
}

template <
    typename T_u_vec, typename T_u_vec_rank,
    typename T_o_vec, typename T_o_vec_rank, typename T_o_vec_slc,
    typename T_m_vec, typename T_m_vec_rank, typename T_m_vec_slc
    >
uint64_t Zombit<T_u_vec,T_u_vec_rank,T_o_vec,T_o_vec_rank,T_o_vec_slc,T_m_vec,T_m_vec_rank,T_m_vec_slc>::size() {
    return orig_bv_size;
}


template <
    typename T_u_vec, typename T_u_vec_rank,
    typename T_o_vec, typename T_o_vec_rank, typename T_o_vec_slc,
    typename T_m_vec, typename T_m_vec_rank, typename T_m_vec_slc
    >
uint64_t Zombit<T_u_vec,T_u_vec_rank,T_o_vec,T_o_vec_rank,T_o_vec_slc,T_m_vec,T_m_vec_rank,T_m_vec_slc>::size_in_bits() {
    return (sdsl::size_in_bytes(u_vector) * 8) + \
        (sdsl::size_in_bytes(u_rank) * 8) + \
        (sdsl::size_in_bytes(o_vector) * 8) + \
        (sdsl::size_in_bytes(m_vector) * 8) + \
        (sdsl::size_in_bytes(o_rank) * 8) + \
        (sdsl::size_in_bytes(o_select) * 8) + \
        (sdsl::size_in_bytes(m_rank) * 8) + \
        (sdsl::size_in_bytes(m_select) * 8);
}

template <
    typename T_u_vec, typename T_u_vec_rank,
    typename T_o_vec, typename T_o_vec_rank, typename T_o_vec_slc,
    typename T_m_vec, typename T_m_vec_rank, typename T_m_vec_slc
    >
float Zombit<T_u_vec,T_u_vec_rank,T_o_vec,T_o_vec_rank,T_o_vec_slc,T_m_vec,T_m_vec_rank,T_m_vec_slc>::u_vector_size_in_bits() {
    return (sdsl::size_in_bytes(u_vector) * 8) + \
        (sdsl::size_in_bytes(u_rank) * 8);
}

template <
    typename T_u_vec, typename T_u_vec_rank,
    typename T_o_vec, typename T_o_vec_rank, typename T_o_vec_slc,
    typename T_m_vec, typename T_m_vec_rank, typename T_m_vec_slc
    >
float Zombit<T_u_vec,T_u_vec_rank,T_o_vec,T_o_vec_rank,T_o_vec_slc,T_m_vec,T_m_vec_rank,T_m_vec_slc>::o_vector_size_in_bits() {
    return (sdsl::size_in_bytes(o_vector) * 8) + \
        (sdsl::size_in_bytes(o_rank) * 8) + \
        (sdsl::size_in_bytes(o_select));
}

template <
    typename T_u_vec, typename T_u_vec_rank,
    typename T_o_vec, typename T_o_vec_rank, typename T_o_vec_slc,
    typename T_m_vec, typename T_m_vec_rank, typename T_m_vec_slc
    >
float Zombit<T_u_vec,T_u_vec_rank,T_o_vec,T_o_vec_rank,T_o_vec_slc,T_m_vec,T_m_vec_rank,T_m_vec_slc>::m_vector_size_in_bits() {
    return (sdsl::size_in_bytes(m_vector) * 8) + \
        (sdsl::size_in_bytes(m_rank) * 8) + \
        (sdsl::size_in_bytes(m_select));
}
#endif

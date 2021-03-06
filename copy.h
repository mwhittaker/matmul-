#ifndef __COPY_H__
#define __COPY_H__

#include <stdlib.h>
#include "indexing.h"

inline double *cm_copy(const double *A,
                       const int lN, const int lM,
                       const int N,  const int M) {
    double *transposed = (double *)malloc(N * M * sizeof(double));
    for (int m = 0; m < M; ++m) {
        for (int n = 0; n < N; ++n) {
            transposed[cm(N, M, n, m)] = A[cm(lN, lM, n, m)];
        }
    }
    return transposed;
}

inline double *rm_copy(const double *A,
                       const int lN, const int lM,
                       const int N,  const int M) {
    double *transposed = (double *)malloc(N * M * sizeof(double));
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            transposed[rm(N, M, n, m)] = A[rm(lN, lM, n, m)];
        }
    }
    return transposed;
}

inline void cm_copy_into(const double *A,
                         const int lN, const int lM,
                         const int N,  const int M,
                         double *A_,
                         const int A_N, const int A_M) {
    for (int m = 0; m < M; ++m) {
        for (int n = 0; n < N; ++n) {
            A_[cm(A_N, A_M, n, m)] = A[cm(lN, lM, n, m)];
        }
    }
}

#endif // __COPY_H__

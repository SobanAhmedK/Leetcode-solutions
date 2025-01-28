#include <mpi.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

#define N 1.0  
#define M 100  
#define TIME_STEPS 1000 
#define ALPHA 0.01  
#define T0 0.0  

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size); 

    double dx = N / M;
    double dt = 0.0001;  
    int local_M = M / size; 
    int start = rank * local_M; 
    int end = (rank == size - 1) ? M : start + local_M; 

    std::vector<double> rod(local_M + 2, T0);  
    std::vector<double> rod_next(local_M + 2, T0);

    for (int i = 1; i <= local_M; ++i) {
        double x = (start + i - 1) * dx;
        rod[i] = 100.0 * sin(M_PI * x);
    }

    for (int t = 0; t < TIME_STEPS; ++t) {
        if (rank > 0) {
            MPI_Send(&rod[1], 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD);
            MPI_Recv(&rod[0], 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        if (rank < size - 1) {
            MPI_Send(&rod[local_M], 1, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD);
            MPI_Recv(&rod[local_M + 1], 1, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        for (int i = 1; i <= local_M; ++i) {
            rod_next[i] = rod[i] + (ALPHA * dt / (dx * dx)) * (rod[i - 1] - 2 * rod[i] + rod[i + 1]);
        }

        rod.swap(rod_next);
    }

    std::vector<double> global_rod;
    if (rank == 0) {
        global_rod.resize(M + 1);
    }

    MPI_Gather(&rod[1], local_M, MPI_DOUBLE, global_rod.data(), local_M, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        std::cout << "Final Temperature Distribution:\n";
        for (int i = 0; i <= M; ++i) {
            double x = i * dx;
            std::cout << "x = " << std::setw(5) << std::fixed << std::setprecision(3) << x
                      << ", T = " << std::setw(8) << std::fixed << std::setprecision(3) << global_rod[i] << '\n';
        }
    }

    MPI_Finalize();
    return 0;
}

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <chrono>
#define N 1.0
#define M 100
#define TIME_STEPS 1000
#define ALPHA 0.01
#define T0 0.0

int main() {
  
    auto start_time = std::chrono::high_resolution_clock::now();

    double dx = N / M;
    double dt = 0.0001;
    std::vector<double> rod(M + 1, T0);
    std::vector<double> rod_next(M + 1, T0);

   
    for (int i = 0; i <= M; ++i) {
        double x = i * dx;
        rod[i] = 100.0 * sin(M_PI * x);
    }

    
    for (int t = 0; t < TIME_STEPS; ++t) {
        for (int i = 1; i < M; ++i) {
            rod_next[i] = rod[i] + (ALPHA * dt / (dx * dx)) * (rod[i - 1] - 2 * rod[i] + rod[i + 1]);
        }
        rod = rod_next;
    }

    
    std::cout << "Final Temperature Distribution:\n";
    for (int i = 0; i <= M; ++i) {
        double x = i * dx;
        std::cout << "x = " << std::setw(5) << std::fixed << std::setprecision(3) << x
                  << ", T = " << std::setw(8) << std::fixed << std::setprecision(3) << rod[i] << '\n';
    }

   
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    std::cout << "\nTotal time taken: " << duration << " milliseconds\n";

    return 0;
}

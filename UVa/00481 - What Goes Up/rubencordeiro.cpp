/*
 ID: Ruben Fernando Pinto Cordeiro
 PROG: What Goes Up?
 LANG: C++11
 */

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <cmath>

int main() {

    std::vector<int> X;
    int inputElem;
    while (!std::cin.eof()) {
        std::cin >> inputElem;
        X.push_back(inputElem);
    }

    std::vector<int> P(X.size());
    std::vector<int> M(X.size() + 1);

    int L = 0;
    for (size_t i = 0; i < X.size() - 1; ++i) {
        auto lo = 1;
        auto hi = L;

        while (lo <= hi) {
            auto mid = ceil((lo + hi) / 2);

            if (X[M[mid]] < X[i])
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        auto newL = lo;

        P[i] = M[newL - 1];
        M[newL] = i;

        if (newL > L)
            L = newL;
    }

    std::vector<int> solution(L);
    auto k = M[L];
    for (int i = L - 1; i >= 0; --i) {
        solution[i] = X[k];
        k = P[k];
    }

    std::cout << solution.size() << std::endl << '-' << std::endl;

    for (const int& item : solution) {
        std::cout << item << std::endl;
    }

    return 0;
}

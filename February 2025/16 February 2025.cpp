/*
You are given a square matrix N×N of integers. Your task is to calculate the sum of elements from three distinct regions:
Main diagonal and its adjacent diagonals: Elements from the main diagonal and one diagonal on each side (above and below).
Border elements: Elements on the outer border of the matrix.
Central sub-matrix: Elements in a smaller K × K sub-matrix (central region of the matrix). If N is even, the central sub-matrix is the smallest possible square that is completely enclosed within the matrix.
Note: Each element in the matrix can contribute to only one region.
*/
#include <iostream>
#include <vector>

void calculate_sum(const std::vector<std::vector<int>>& matrix, int n, int k) {
   if (n == 1) { // Special case for 1x1 matrix
        std::cout << matrix[0][0] << std::endl;
        return;
    }
    int main_diagonal_sum = 0;
    int border_sum = 0;
    int central_sum = 0;

    // Calculate sum for main diagonal and adjacent diagonals
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == j + 1 || i == j - 1) { // Main diagonal and adjacent
                main_diagonal_sum += matrix[i][j];
            }
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) { // Border elements
                border_sum += matrix[i][j];
            }

        }
    }

    // Find the start index for the central sub-matrix
    int start = (n - k) / 2;

    // Calculate sum for the central sub-matrix
    for (int i = start; i < start + k; i++) {
        for (int j = start; j < start + k; j++) {
            central_sum += matrix[i][j];
        }
    }

        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Remove overlap between border and main diagonal
            if ((i == j || i == j + 1 || i == j - 1) && (i == 0 || i == n - 1 || j == 0 || j == n - 1)) {
                main_diagonal_sum -= matrix[i][j];
            }
            // Remove overlap between border and central sub-matrix
            if ((i >= start && i < start + k && j >= start && j < start + k) && (i == 0 || i == n - 1 || j == 0 || j == n - 1)) {
                border_sum -= matrix[i][j];
            }
            // Remove overlap between main diagonal and central sub-matrix
            if ((i >= start && i < start + k && j >= start && j < start + k) && (i == j || i == j + 1 || i == j - 1)) {
                central_sum -= matrix[i][j];
            }
        }
    }
    // Print the final sum
    std::cout << (main_diagonal_sum + border_sum + central_sum) << std::endl;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    calculate_sum(matrix, n, k);
    return 0;
}
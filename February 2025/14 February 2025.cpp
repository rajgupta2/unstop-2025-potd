/*
The alpha bitwise operation applied on an array returns a single integer whose any bit is set if the count of set bits of all elements is greater than half the size of the array.
For example, if array A = [3, 4, 6, 7, 2],
The 0th bit (rightmost bit): 2 elements (3 = 011, 7 = 111) have this bit set, which is less than half of the array size (2.5, since 5/2 = 2.5). Therefore, the 0th bit in the final result is 0.
The 1st bit: 4 elements (3 = 011, 7 = 111, 2 = 010, 6 = 110) have this bit set, which is greater than half the array size (2.5). So, the 1st bit in the result is 1.
The 2nd bit: 3 elements (4 = 100, 7 = 111, 6 = 110) have this bit set, which is also greater than half the array size. Therefore, the 2nd bit is 1.
Thus, the final result is 110 in binary, which equals 6 in decimal.
Find the alpha bitwise of the given array A of size N.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int alpha_bitwise_operation(int n, std::vector<int>& arr)
{
    int result = 0;

    for (int bit = 0; bit < 32; ++bit) { // Assuming 32-bit integers
        int count = 0;
        for (int num : arr) {
            if (num & (1 << bit)) {
                count++;
            }
        }
        float size=n/2.0;
        if (count > size) {
            result |= (1 << bit);
        }
    }

    return result;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // Ensure the length of the array matches N
    assert(arr.size() == n);

    // Call user logic function and print the output
    int result = alpha_bitwise_operation(n, arr);
    std::cout << result << std::endl;

    return 0;
}
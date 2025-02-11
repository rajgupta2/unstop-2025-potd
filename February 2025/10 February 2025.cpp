/*
There is a garden in Scotland where all the mango trees are arranged in a row in an array A of size N, where Ai is the number of mangoes on the i’th tree, gardener Shifu received an order to divide the garden into three continuous Segment s1, s2 and s3.
The segment s1 and s3 belong to prince Ridge whereas s2 belongs to prince warren, gardener Shifu is biased and he wants to make more profit for prince Ridge, so he wants to divide the garden in such a way that sum of the total mango on s1 and s3 is greater than mango on s2 more formally (sum of mangoes on segment 1) s1+(sum of mangoes on segment 3) s3>s2 (sum of mangoes on segment 2).
For each test case print the total number of ways in which shifu can divide the garden in such a way that s1+s3>s2.where s’i is the sum of the mangoes of the i’th segment.
*/
//This code does not pass all the testcases in unstop platform
//I don't know why there is no testcase passing.
#include <iostream>
#include <vector>
using namespace std;

int shifu_divide_garden(int n, std::vector<int> &arr) {
    vector<int> prefixSum(n,0);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        prefixSum[i]=sum;
    }
    int totalWays=0;
    for (int i = 0; i < n-1; i++) {
        //I'm choosing the segment s1 upto index i;
        int s1=prefixSum[i];
        for(int j=i+1;j<n-1;j++){
            int s2=prefixSum[j]-s1;
            int s3=prefixSum[n-1]-prefixSum[j];
            if(s1+s3>s2) totalWays++;
            else break;
        }
    }
    return totalWays;
}

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        std::cin >> n;
        std::vector<int> A(n);
        for (int j = 0; j < n; j++) {
            std::cin >> A[j];
        }

        // Call user logic function and store the result
        int result = shifu_divide_garden(n, A);
        std::cout << result << std::endl;
    }

    return 0;
}
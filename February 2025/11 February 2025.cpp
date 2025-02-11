/*
Zyan has an array Arr of size N. He needs to divide the array at any index from 0 to N-1 into two parts. The goal is to maximize the product of the sums of the elements in these two parts.
Specifically, if the array is divided at index Idx, then:
The first part of the array will contain elements from 0 to Idx.
The second part will contain elements from Idx+1 to N-1.
Zyan needs to calculate the sum of the elements in both parts and find the index Idx that maximizes the product of these two sums.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <vector>

long long maximum_product_of_sums(const std::vector<int>& arr) {
    int n=arr.size();
    long long sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];

    long long newSum=0;
    int ind=-1;
    long long maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        newSum+=arr[i];
        long long product=newSum*(sum-newSum);
        if(maxi<product)
        {
            maxi=product;
            ind=i;
        }
    }
    return maxi;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    long long result = maximum_product_of_sums(arr);
    std::cout << result << std::endl;
    return 0;
}ECHO is on.

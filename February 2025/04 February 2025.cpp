/*
You are given an array of integers arr[] of size N. Your task is to find the two smallest distinct two-digit numbers from the array, rearrange them in such a way that the largest possible number is formed, and then return that number. If there are no two-digit numbers or if there are fewer than two distinct two-digit numbers, return 0.
Note: After identifying the required two-digit numbers, you need to rearrange the digit in such a way that the largest number is formed.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int fun(int n, std::vector<int> &arr){
    int smallest=INT_MAX;
    int ssmallest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest && arr[i]/10>0 && arr[i]/100==0){
            ssmallest=smallest;
            smallest=arr[i];
        }else if(arr[i]<ssmallest && arr[i]!=smallest  && arr[i]/10>0 && arr[i]/100==0){
            ssmallest=arr[i];
        }
    }
    if(smallest==INT_MAX || ssmallest==INT_MAX || ssmallest==-1) return 0;
    vector<int> vec(4,0);
    vec[0]=smallest%10;
    vec[1]=(smallest/10)%10;
    vec[2]=ssmallest%10;
    vec[3]=(ssmallest/10)%10;
    sort(vec.begin(),vec.end());
    int num=vec[3]*1000+vec[2]*100+vec[1]*10+vec[0];
    return num;
}

void user_logic(int n, std::vector<int> &arr) {
     cout<<fun(n,arr);
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    user_logic(N, arr);
    return 0;
}
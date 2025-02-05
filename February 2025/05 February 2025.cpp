/*
You need to find the minimum cost to reach the last element of a given vector V of positive integers of size N.
The cost of moving from one element to another is the absolute difference between the elements.
You can only take a jump of max size equal to 3, i.e. if you are at index i, you can go to i+1,i+2 or i+3.
Note : the cost of reaching to the first element is 0.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int min(int a, int b){
    if(a<b) return a;
    return b;
}
int minimumCost(vector<int> &arr,int n,vector<int> &dp){
  if(n==0) return 0;
  if (dp[n] != -1) return dp[n];
  int oneJump=1e9;
  int secJump=1e9;
  int thirdJump=1e9;
  if(n>=1){
    oneJump=abs(arr[n]-arr[n-1])+minimumCost(arr,n-1,dp);
  }
  if(n>=2){
    secJump=abs(arr[n]-arr[n-2])+minimumCost(arr,n-2,dp);
  }
  if(n>=3){
    thirdJump=abs(arr[n]-arr[n-3])+minimumCost(arr,n-3,dp);
  }
  return dp[n]=min(oneJump,min(secJump,thirdJump));
}


int min_cost(vector<int>& v) {
    int n=v.size();
    vector<int> dp(n, -1);
    return minimumCost(v,n-1,dp);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int result = min_cost(v);
    std::cout << result << std::endl;
    return 0;
}
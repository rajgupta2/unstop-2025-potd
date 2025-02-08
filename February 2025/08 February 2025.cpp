/*
Given a vector V of positive integers of size N.
The task is to find the maximum difference of the number of even numbers and the number of odd numbers (number of even – number of odd) in all the possible subarray of the vector.
Note: In the case of all odds, the answer will be -1.
*/
#include <iostream>
#include <vector>
int max(int a,int b){
    return a>b ? a : b;
}
int max_difference(const std::vector<int>& arr) {
    /* Write your logic here. */
    int n=arr.size();
    int even=0;
    int odd=0;
    int ans=-1;
    bool isEven=false;
    for(int i=0;i<n;i++){
        int even=0;
        int odd=0;
        for(int j=i;j<n;j++){
            if(arr[j]%2==0) even++;
            else odd++;
            ans=max(ans,even-odd);
        }
        if(arr[i]%2==0) isEven=true;
    }
    if(!isEven)
     return -1;
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> V(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }
    int result = max_difference(V);
    std::cout << result << std::endl;
    return 0;
}

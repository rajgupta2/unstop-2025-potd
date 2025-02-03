/*
Bob has an array Arr of N integers representing the heights of poles arranged in a straight line. He wants to use exactly three poles to make a tent. The conditions for selecting these three poles are:
The middle pole must be the tallest among the three.
The first pole must be the shortest among the three.
The last pole must be taller than the first pole but shorter than the middle pole.
However, Alice, who is jealous of Bob, has secretly reduced the height of all the tallest poles by X units. If the tallest pole was originally of height h, its new height will be max(0, h - X).
Your task is to determine if it is still possible for Bob to select three poles that meet the conditions to make a tent after Alice's tampering.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void change_longest(std::vector<int>& arr, int x) {
    // User should implement this function
    int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=(maxi>arr[i])?maxi:arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]==maxi)
        arr[i]=((arr[i]-x)>0)?(arr[i]-x):0;
    }
}

bool pole_arrangement(vector<int>& arr) {
    // User should implement this function
    int n=arr.size();

    for(int i=0;i<n-2;i++){

        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if((arr[j]>arr[i] && arr[j]>arr[k]) && arr[i]<arr[k] ){
                    return true;
                }
            }
        }
    }
    return false; // Placeholder return value
}

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Modify the array by reducing the tallest poles by x units
    change_longest(arr, x);

    // Determine if it is possible to choose three poles to make the tent
    bool result = pole_arrangement(arr);

    // Print the result as 1 for True and 0 for False
    std::cout << (result ? 1 : 0) << std::endl;

    return 0;
}
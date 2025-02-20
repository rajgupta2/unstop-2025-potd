/*
Lily’s teacher gave her a number N and asked her to calculate X using the following rules:
If ( N = 0 ), then ( X = 2 ).
If ( N = 1 ), then ( X = 1 ).
If ( N > 1 ), then ( X ) is calculated as ( L(N-1) + L(N-2) ), where L is the function defined by these rules.
Given a number ( N ), help Lily find ( X ).

Note: Since the output can be very large, calculate the answer modulo ( 10^9 + 7 ).
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int user_logic(int n) {
    if(n==0) return 2;
    if(n==1) return 1;
    vector<int> L(n + 1);
    L[0] = 2;
    L[1] = 1;

    for (int i = 2; i <= n; ++i) {
        L[i] = (L[i - 1] + L[i - 2]) % MOD;
    }

    return L[n];
}

int main() {
    int n;
    std::cin >> n; // The input integer N

    // Call user logic function and print the output
    int result = user_logic(n);
    std::cout << result << std::endl;

    return 0;
}
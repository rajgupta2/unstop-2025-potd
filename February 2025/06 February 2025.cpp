/*
James has a new robot that moves along a straight line. Initially, the robot starts at a position X on this line. The robot is given a sequence of N commands, represented by the string S. Each character in S tells the robot to move either one step left (L) or one step right (R). Your task is to determine how many distinct points the robot visits after executing all the commands.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int user_logic(int n, int x, const std::string& s) {
    // Write your logic here.
    unordered_map<int,int> mp;
    int Initial=x;
    mp[Initial]=1;
    for(int i=0;i<n;i++){
        if(s[i]=='L') Initial--;
        else Initial++;
        mp[Initial]=1;
    }
    return mp.size();
}

int main() {
    int T;
    std::cin >> T;

    std::vector<int> results;
    for (int t = 0; t < T; ++t) {
        int n, x;
        std::string s;
        std::cin >> n >> x >> s;
        int result = user_logic(n, x, s);
        results.push_back(result);
    }

    for (int result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}
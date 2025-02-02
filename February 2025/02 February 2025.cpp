/*
You are given a string consisting of lowercase English letters. Your task is to determine if there are at least three characters in the string that appear an odd number of times. If there are, print 1,otherwise, print 0.
*/
#include <iostream>
#include <string>
using namespace std;
int check_odd_frequency(string& s) {
    // Write your logic here.
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    int cnt=0;
    for(int i=0;i<26;i++){
      if(hash[i]%2!=0) cnt++;
      if(cnt>=3) return 1;
    }
    return 0;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    int result = check_odd_frequency(s);
    std::cout << result << std::endl;
    return 0;
}
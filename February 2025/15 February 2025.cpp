/*
Alice loves palindromes. She has been given a string S of length N, and she can perform up to K operations on the string. Each operation can either be an insertion or a deletion of a character at any position in the string. The goal is to determine how many distinct palindromic strings can be formed after exactly K operations and also return the lexicographically smallest palindrome that can be created.
A palindrome is a string that reads the same forwards and backwards.
Operations:
Insertion: You can insert any character at any position in the string.
Deletion: You can delete any character from the string.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(const string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}
void generatePalindromes(string s, int k, set<string> &palindromes) {
    if (k == 0) {
        if (isPalindrome(s)) {
            palindromes.insert(s);
        }
        return;
    }

    // Try inserting characters at all positions
    for (char ch = 'a'; ch <= 'z'; ch++) {
        for (int i = 0; i <= s.size(); i++) {
            string newS = s.substr(0, i) + ch + s.substr(i);
            generatePalindromes(newS, k - 1, palindromes);
        }
    }

    // Try deleting each character
    if (!s.empty()) {
        for (int i = 0; i < s.size(); i++) {
            string newS = s.substr(0, i) + s.substr(i + 1);
            generatePalindromes(newS, k - 1, palindromes);
        }
    }
}
void user_logic(int n, int k, std::string s, int& result_count, std::string& result_string) {
    set<string> palindromes;
    generatePalindromes(s, k, palindromes);

    if(palindromes.size()>0){
    result_count=palindromes.size() ;
    result_string= *palindromes.begin();
    }
    else
    result_count=-1;
}

int main() {
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    int result_count;
    std::string result_string;

    user_logic(n, k, s, result_count, result_string);

    if (result_count == -1) {
        std::cout << result_count << std::endl;
    } else {
        std::cout << result_count << std::endl;
        std::cout << result_string << std::endl;
    }

    return 0;
}
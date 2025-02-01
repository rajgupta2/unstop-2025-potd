/*
In a distant village, there is a magical garden where flowers grow in perfect harmony. Each flowerbed is arranged in a straight row, and the villagers believe that the garden’s magic depends on maintaining balance. The garden can only thrive if every consecutive group of the flowerbed contains an equal number of blue and white flowers.
However, over time, some flowers in the bed have lost their colors, turning gray. To restore the garden’s magic, the caretaker, Mira, must relace the gray flowers either blue or white. Mira’s challenge is to ensure that for every consecutive group of flowers of the given size h (always an even number), the number of blue and white flowers is equal.
Can Mira replace the gray flowers to restore the balance in the garden? Or is it impossible to bring harmony back to the magical garden?
Input Format
The first line contains two space-separated integers N and h denoting the length of the flowerbed and the length for a magical sequence respectively.
The next line contains the sequence S of length N. It is given that S consists of only 'b (blue)', 'w (white)', and 'x (gray)'.
*/
#include <iostream>
#include <string>
using namespace std;

bool can_balance(string& S, int h) {
     int b = 0, w = 0, x = 0;
     int N=S.size();

    // Count initial window of size h
    for (int i = 0; i < h; ++i) {
        if (S[i] == 'b') b++;
        else if (S[i] == 'w') w++;
        else x++;
    }

    //we need b==h/2 and W==h/2;
    // Check if the current window can be balanced
    if(b>h/2 || w>h/2) return false;
    int howMuchB=h/2-b;
    if ((h / 2 - w) != x-howMuchB) return false;

    // Sliding window over the rest of S
    for (int i = h; i < N; ++i) {
        // Remove leftmost character of previous window
        if (S[i - h] == 'b') b--;
        else if (S[i - h] == 'w') w--;
        else x--;

        // Add new rightmost character
        if (S[i] == 'b') b++;
        else if (S[i] == 'w') w++;
        else x++;
         if(b>h/2 || w>h/2) return false;
         int howMuchB=h/2-b;
         if ((h / 2 - w) != x-howMuchB) return false;
    }

    return true;
}

int main() {
    int N, h;
    std::string S;
    std::cin >> N >> h >> S;

    bool result = can_balance(S, h);

    if (result) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }

    return 0;
}
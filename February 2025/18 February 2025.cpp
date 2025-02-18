/*
In a classroom with N students and N available seats, each student has a preferred seat number, given in an array A. Students enter the classroom one by one in order from student 1 to N.
Each student follows these rules when choosing a seat:
If their preferred seat is vacant, they sit there.
If their preferred seat is occupied, they continue searching circularly (wrapping around if needed) until they find an empty seat.
Your task is to determine the final seating arrangement of all students.
*/
#include <iostream>
#include <vector>
using namespace std;

void user_logic(int n, const std::vector<int>& seat_preferences, std::vector<int>& final_seating);

int main() {
    int n;
    std::cin >> n;
    std::vector<int> seat_preferences(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> seat_preferences[i];
    }
    std::vector<int> final_seating(n,-1);
    user_logic(n, seat_preferences, final_seating);
    for (int i = 0; i < n; ++i) {
        std::cout << final_seating[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

void user_logic(int n, const std::vector<int>& seat_preferences, std::vector<int>& final_seating) {
    vector<bool> isEmpty(n,true);
    for(int i=0;i<n;i++){
        int whereSit=seat_preferences[i]-1;
        while(!isEmpty[whereSit]){
            whereSit=(whereSit+1)%n;
        }
        isEmpty[whereSit]=false;
        final_seating[i]=whereSit+1;
    }
}
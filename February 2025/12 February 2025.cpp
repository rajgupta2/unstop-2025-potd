/*
A chef wants to prepare a meal for a group of guests based on their favorite dish. The guests are divided into two categories: vegetarians and non-vegetarians.
Vegetarians: These are guests whose favorite dish contains only vegetables.
Non-Vegetarians: These are guests whose favorite dish contains non-veg.
The chef wants to organize the guests in the dining hall in the following manner:
Vegetarians First: First, group the vegetarians based on their favorite dish. Arrange the groups in descending order of the number of guests in each group. If two groups have the same number of guests, arrange them alphabetically by the name of the dish.
Non-Vegetarians Next: After organizing the vegetarians, group the non-vegetarians based on their favorite dish, again in descending order of the number of guests in each group. If two groups have the same number of guests, arrange them alphabetically by the name of the dish.
Print the resultant string in the format: each group is represented by the dish name followed by the number of guests who prefer that dish.
If there are no guests, return "NULL". If there are no vegetarians or no non-vegetarians, their corresponding section of the result should be omitted.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void arrange_guests(const std::string& dishes) {
    // Write your logic here.
    //fav,cnt
    map<int,set<char>> food;
    vector<int> dish(26,0);

    for(int i=0;i<dishes.size();i++){
         dish[dishes[i]-'a']++;
    }
    for(int i=0;i<dish.size();i++){
         if(dish[i]>0)
         food[dish[i]].insert((char)i+'a');
    }
    string resVeg="",nVeg="";
    for(auto it:food){
        int cnt=it.first;
        set<char> st=it.second;
        if(st.size()==1)
        {
             char d=*st.begin();
             if(d=='a' || d=='e' ||d=='i' ||d=='o' ||d=='u'){
                resVeg=d+to_string(cnt)+resVeg;
             }else{
                nVeg=d+to_string(cnt)+nVeg;
             }

        }else{
          string veg="";
          string nonVeg="";
          for(char d:st){
             if(d=='a' || d=='e' ||d=='i' ||d=='o' ||d=='u'){
                veg+=d+to_string(cnt);
             }else{
                nonVeg+=d+to_string(cnt);
             }
           }
           resVeg=veg+resVeg;
           nVeg=nonVeg+nVeg;
        }
    }
    cout<<resVeg+nVeg;
}

int main() {
    std::string dishes;
    std::getline(std::cin, dishes);

    arrange_guests(dishes);
    return 0;
}
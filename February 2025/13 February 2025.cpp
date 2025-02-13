/*
Steve has N movie tickets with different prices. M customers are arriving one by one, and each customer specifies the maximum price they are willing to pay for a ticket. You need to assign each customer to the nearest available ticket price that does not exceed their maximum budget.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int lowerBound(int budget,vector<int> prices,vector<int> &isAvailable){
    int left=0;
    int right=prices.size()-1;
    int ans=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(prices[mid]<=budget){
            ans=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    if(ans!=-1 && isAvailable[ans]==1)
    {
        isAvailable[ans]=-1;
        return prices[ans];
    }
    for(int i=ans-1;i>=0;i--){
        if(isAvailable[i]==1){
            isAvailable[i]=-1;
            return prices[i];
        }
    }
    return -1;
}
std::vector<int> user_logic(int n, int m, std::vector<int> prices, std::vector<int> budgets) {
    // Write your logic here.
    sort(prices.begin(),prices.end());
    vector<int> ans(m,-1);
    vector<int> isAvailable(n,1);

    for(int i=0;i<=m-1;i++){
        int budget=budgets[i];
        int priceInd=lowerBound(budget,prices,isAvailable);
        ans[i]=priceInd;
    }
    return ans;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }

    std::vector<int> budgets(m);
    for (int i = 0; i < m; i++) {
        std::cin >> budgets[i];
    }

    std::vector<int> results = user_logic(n, m, prices, budgets);
    for (int result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}
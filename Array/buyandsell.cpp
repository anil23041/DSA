#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int profit = maxProfit(prices);
    cout << "Maximum Profit: " << profit << endl;
    return 0;
}

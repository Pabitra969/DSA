#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &prices, int i, int buy) {
    //base case 
    if(i >= prices.size()) {
        return 0;
    }

    //for buying the stocks
    int profit = 0;
    if(buy) {
        int buyProfit = maxProfit(prices, i+1, 0) - prices[i];
        int skipBuyProfit = maxProfit(prices, i+1, 1);
        profit = max(buyProfit, skipBuyProfit);
    }
    else {
        int sellProfit = prices[i] + maxProfit(prices, i+1, 1);
        int skipSellProfit = maxProfit(prices, i+1, 0);
        profit = max(sellProfit, skipSellProfit);
    }

    return profit;
    
}

int main()
{
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
    
    // function call 
    int ans = maxProfit(prices, 0, 1);
    cout << "Max profit -> " << ans << endl;
    return 0;
}



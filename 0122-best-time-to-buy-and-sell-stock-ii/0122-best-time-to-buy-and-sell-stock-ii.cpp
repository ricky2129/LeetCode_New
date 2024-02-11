// class Solution {
// public:
//     void maxProfitFinder(vector<int>&prices,int i,int&minPrice,int&maxPrice,int&maxProfit,int&ans){
//         //BaseCase
//         if(i==prices.size()){
//             //  ans+=maxprofit;
//              return;
//         }
//         //new case
//         if(prices[i]<maxPrice){
//             ans+=maxProfit;
//             maxProfit=0;
//             minPrice=INT_MAX;
//             maxPrice=INT_MIN;
//         }
        
//         //one case solve
//         if(prices[i]<minPrice) minPrice=prices[i];
//         int todaysProfit=prices[i]-minPrice;
//         if(todaysProfit>maxProfit) {
//             maxProfit=todaysProfit;
//             maxPrice=prices[i];
//         }

//     //RE
//     maxProfitFinder(prices,i+1,minPrice,maxPrice,maxProfit,ans);
//     }
//     int maxProfit(vector<int>& prices) {
//         int minPrice=INT_MAX;
//         int maxProfit=0;
//         int i=0;
//         int maxPrice=INT_MIN;
//         int ans=0;

//         maxProfitFinder(prices,i,minPrice,maxPrice,maxProfit,ans);
//         if(maxProfit>ans) return maxProfit;
//         return ans;
//     }
// };
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int totalProfit = 0;
//         for (int i = 0; i < prices.size() - 1; ++i) {
//             if (prices[i + 1] > prices[i]) { // If next day's price is higher, buy today and sell tomorrow
//                 totalProfit += prices[i + 1] - prices[i];
//             }
//         }
//         return totalProfit;
//     }
// };
class Solution {
public:
    void maxProfitFinder(vector<int>&prices, int i, int& ans) {
        // Base case: if we've reached the end of the array, return
        if (i >= prices.size() - 1) return;

        // If next day's price is higher, consider it a transaction and add to ans
        if (prices[i + 1] > prices[i]) {
            ans += prices[i + 1] - prices[i];
        }

        // Recurse to the next day
        maxProfitFinder(prices, i + 1, ans);
    }

    int maxProfit(vector<int>& prices) {
        int ans = 0; // Initialize the total profit to 0

        // Start the recursion from the first day
        maxProfitFinder(prices, 0, ans);

        return ans; // Return the accumulated profit
    }
};

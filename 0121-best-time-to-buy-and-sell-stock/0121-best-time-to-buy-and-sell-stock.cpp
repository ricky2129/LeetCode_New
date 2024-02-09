class Solution {
public:

    void maxProfitFinder(vector<int>&prices,int i,int&minPrice,int&maxProfit){
        //BaseCase
        if(i==prices.size()) return;
        //one case solve
        if(prices[i]<minPrice) minPrice=prices[i];
        int todaysProfit=prices[i]-minPrice;
        if(todaysProfit>maxProfit) maxProfit=todaysProfit;

    //RE
    maxProfitFinder(prices,i+1,minPrice,maxProfit);
    }
    int maxProfit(vector<int>& prices) {
        // int max_prof=0;
        // int min_price=prices[0];

        // for(int i=0;i<prices.size();i++){
        //     max_prof=max(max_prof,prices[i]-min_price);
        //     min_price=min(min_price,prices[i]);
        // }

        // return max_prof;

        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;
        int i=0;

        maxProfitFinder(prices,i,minPrice,maxProfit);
        return maxProfit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof=0;
        int min_price=prices[0];

        for(int i=0;i<prices.size();i++){
            max_prof=max(max_prof,prices[i]-min_price);
            min_price=min(min_price,prices[i]);
        }

        return max_prof;
    }
};
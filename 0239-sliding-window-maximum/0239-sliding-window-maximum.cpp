class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        deque<int>dq;


        for(int i=0;i<nums.size();i++){
            //remove elements out of the window

            if(!dq.empty() && dq.front()==i-k){

                dq.pop_front();

            }

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add the current element at the back of the deque
            dq.push_back(i);

            // The front of the deque is the maximum element in the current window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
        
    }
};
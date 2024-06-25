class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int trappedWater = 0;

        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int curr = st.top();
                st.pop();
                
                if (st.empty()) {
                    break;
                }

                int ngl = st.top();
                int width = i - ngl - 1;
                int waterHeight = min(height[i], height[ngl]) - height[curr];
                trappedWater += waterHeight * width;
            }
            st.push(i);
        }

        return trappedWater;
    }
};
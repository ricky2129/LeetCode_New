#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> prevSmallerElement(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());

        for (int i = 0; i < heights.size(); i++) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());

        for (int i = heights.size() - 1; i >= 0; i--) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prevSmallerElement(heights);
        vector<int> next = nextSmallerElement(heights);

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int length = heights[i];
            if (next[i] == -1) {
                next[i] = heights.size();
            }
            int width = next[i] - prev[i] - 1;
            int area = length * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = (i == 0) ? 1 : heights[i-1][j] + 1;
                } else {
                    heights[i][j] = 0;
                }
            }
        }

        int maxRectangle = 0;
        for (int i = 0; i < n; i++) {
            maxRectangle = max(maxRectangle, largestRectangleArea(heights[i]));
        }

        return maxRectangle;
    }
};

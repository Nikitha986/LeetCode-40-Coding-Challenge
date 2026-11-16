
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> s;

        for (int i = 0; i < n; i++) {

            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int h = heights[s.top()];
                s.pop();

                int left = s.empty() ? -1 : s.top();
                int width = i - left - 1;

                maxArea = max(maxArea, h * width);
            }

            s.push(i);
        }

        while (!s.empty()) {
            int h = heights[s.top()];
            s.pop();

            int left = s.empty() ? -1 : s.top();
            int width = n - left - 1;

            maxArea = max(maxArea, h * width);
        }

        return maxArea;
    }
};

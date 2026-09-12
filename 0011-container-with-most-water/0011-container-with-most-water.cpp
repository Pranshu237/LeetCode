#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        while (left < right) {
            int current_height = min(height[left], height[right]);
            int current_width = right - left;
            long long current_area = (long long)current_height * current_width;

            if (current_area > max_water) {
                max_water = current_area;
            }

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};
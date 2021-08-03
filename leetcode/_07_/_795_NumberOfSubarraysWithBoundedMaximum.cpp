#include "../../base/base.h"

class Solution {
public:
    /**
     * 给定一个元素都是正整数的数组A ，正整数 L 以及 R (L <= R)。
     * 求连续、非空且其中最大元素满足大于等于L 小于等于R的子数组个数。
     */
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
        int ans = 0;
        int l = int(nums.size());
        for (int i = 0, j = 0, count = 0; i < l; ++i) {
            if (nums[i] >= left && nums[i] <= right) {
                count = i - j + 1;
            } else if (nums[i] > right) {
                count = 0;
                j = i + 1;
            }
            ans += count;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> x = {1, 2, 3, 4, 2, 6, 4, 5, 3, 7, 4, 5, 6, 9, 8, 6, 3, 2, 4, 6, 3, 4, 6, 3, 7, 2, 6, 3, 7, 4, 7};
    auto c = s.numSubarrayBoundedMax(x, 3, 7);
    cout << c << endl;
}
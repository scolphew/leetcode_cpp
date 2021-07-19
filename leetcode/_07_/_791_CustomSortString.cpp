//
// Created by scolphew on 2021/7/19.
//

#include "../../base/base.h"


class Solution {
public:
    /**
     * 字符串S和 T 只包含小写字符。在S中，所有字符只会出现一次。
     * S 已经根据某种规则进行了排序。我们要根据S中的字符顺序对T进行排序。
     * 更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。
     * 返回任意一种符合条件的字符串T。
     * @param order
     * @param s
     * @return
     */
    string customSortString(string order, string s) {
        int count[26] = {};
        for (const auto &c : s) {
            count[c - 'a']++;
        }

        string ans(s.length(), 0);
        int index = 0;
        for (const auto &item : order) {
            while (count[item - 'a']-- > 0) {
                ans[index++] = item;
            }
            count[item - 'a'] = 0;
        }
        for (int i = 0; i < 26; ++i) {
            while (count[i]-- > 0){
                ans[index++] = 'a' + i;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    auto str = s.customSortString("cba", "cdab");
    cout << str;
    return 0;
}
//
// Created by scolphew on 2021/6/11.
//

#include "iostream"
#include "string"
#include "../../base/kmp.h"

using std::string;

class Solution {
public:
    /**
     * 求将a字符串首字母移到最后若干次能否变为b
     * @param s
     * @param goal
     * @return
     */
    bool rotateString(string s, string goal) {
        auto N = s.length();
        if (N != goal.length()) {
            return false;
        }
        if (N == 0) {
            return true;
        }
        s = s + s;
        return kmp(s, goal) > 0;
    }
};

int main() {
    auto s = Solution();
    bool b = s.rotateString("qwert", "ertqw");
    std::cout << std::boolalpha << b << std::noboolalpha << std::endl;
    return 0;
}


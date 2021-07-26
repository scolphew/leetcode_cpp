//
// Created by scolphew on 2021/7/19.
//

#include "../../base/base.h"

class Solution {
public:
    /**
     * 有两种形状的瓷砖：一种是2x1 的多米诺形，另一种是形如"L" 的托米诺形。两种形状都可以旋转。
     * XX  <- 多米诺
     * XX  <- "L" 托米诺
     * X
     * 给定N 的值，有多少种方法可以平铺2 x N 的面板？返回值 mod 10^9 + 7。
     *（平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，
     * 使得恰好有一个平铺有一个瓷砖占据两个正方形。）
     * @param n
     * @return
     */
    int numTilings(int n) {
        int M = 1e9 + 7;
        if (n <= 2) return n;
        int dp[1001];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1] % M + dp[i - 3]) % M;
        }
        return dp[n];
    }
};

int main() {
    Solution s = Solution();
    int x = s.numTilings(100);
    cout << x;
    return 0;
}


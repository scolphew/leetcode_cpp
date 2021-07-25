//
// Created by scolphew on 2021/7/25.
//

# include "../../base/base.h"

class Solution {
public:
    int trail_zeros(long n) {
        return n < 5 ? 0 : int(n / 5 + trail_zeros(n / 5));
    }

    /**
     * f(x)是x!末尾是 0 的数量。（回想一下x! = 1 * 2 * 3 * ... * x，且 0! = 1 ）
     * 例如，f(3) = 0，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2，因为 11!= 39916800 末端有 2 个 0 。给定K，找出多少个非负整数 x，能满足 f(x) = K 。
     * @param K 
     * @return 
     */
    int preimageSizeFZF(int K) {
        long lo = 0, hi = 10 * K + 1;
        while (lo < hi) {
            long mi = lo + ((hi - lo) >> 1);
            long mi_zero = trail_zeros(mi);
            if (mi_zero == K) {
                return 5;
            } else if (mi_zero < K) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    int x = s.preimageSizeFZF(10);
    cout << x;
    return 0;
}
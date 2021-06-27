//
// Created by scolphew on 2021/6/26.
//
#include<string>
#include<iostream>

using std::string;

class Solution {
public:
    /**
     * 我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
     * 如果一个数的每位数字被旋转以后仍然还是一个数字，则这个数是有效的。
     * 0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方（在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；
     * 6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
     * 现在我们有一个正整数N, 计算从 1 到 N 中有多少个数X 是好数？
     * @param n [1,10000]
     * @return
     */
    int rotatedDigits(int n) {
        // todo
        auto A = std::to_string(n);
        int K = A.length();

        // 其中 i 表示当前正在写第 i 位数字
        // equality_flag 表示已经写出的 j 位数字是否等于 N 的 j 位前缀
        // involution_flag 表示从最高位到比当前位高一位的这段前缀中是否含有 2569 中的任意一个数字
        // dp(i, equality_flag, involution_flag) 表示在特定 equality_flag，involution_flag 的状态下，有多少种从 i 到末尾的后缀能组成一个好数。
        // 最终的结果为 dp(0, True, False)。

        int memo[6][2][2];
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    memo[i][j][k] = 0;
                }
            }
        }
        memo[K][0][1] = 1;
        memo[K][1][1] = 1;

        for (int i = K - 1; i >= 0; --i) {
            for (int eqf = 0; eqf <= 1; ++eqf) {
                for (int invf = 0; invf <= 1; ++invf) {
                    // 计算第0位到第i-1位  包含2569和不包含2569的好数
                    int ans = 0;
                    for (char d = '0'; d <= (eqf == 1 ? A[i] : '9'); ++d) {
                        // eqf==1 ==> 取0到该位最大数字
                        // eqf==0 ==> 取0-9
                        if (d == '3' || d == '4' || d == '7') continue;
                        auto invo = (d == '2' || d == '5' || d == '6' || d == '9');
                        ans += memo[i + 1][d == A[i] ? eqf : 0][invo ? 1 : invf];
                    }
                    memo[i][eqf][invf] = ans;
                }
            }
        }

        return memo[0][1][0];
    }
};

int main() {
    auto s = Solution();
    auto x = s.rotatedDigits(123);
    std::cout << x << std::endl;
    return 0;
}
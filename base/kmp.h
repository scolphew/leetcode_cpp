//
// Created by scolphew on 2021/6/11.
//

#ifndef LEETCODE_CPP_KMP_H

#include "string"

int *kmp_next(std::string s) {
    int *next = new int[s.length()];
    next[0] = -1;
    int j = 0;
    int k = -1;

    while (j < (int) s.length() - 1) {
        if (k == -1 || s[j] == s[k]) {
            ++j;
            ++k;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
    return next;
}

int kmp(std::string a, std::string b) {
    int m = a.length();
    int n = b.length();
    int *next = kmp_next(a);

    int i = 0, j = 0;
    while (i < m && j < n) {
        if (j == -1 || a[i] == b[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    // delete next;
    if (j == n) {
        return i - j;
    }
    return -1;
}


#define LEETCODE_CPP_KMP_H

#endif //LEETCODE_CPP_KMP_H

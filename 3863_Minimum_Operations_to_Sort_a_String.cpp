// Author: Sabbir Hossain
// Problem Link:
// https://leetcode.com/problems/minimum-operations-to-sort-a-string

class Solution {
public:
  int minOperations(string s) {
    char minc = s[0];
    char maxc = s[0];
    bool is_sorted = true;

    for (int i = 1; i < s.size(); i++) {
      minc = min(minc, s[i]);
      maxc = max(maxc, s[i]);

      if (s[i] < s[i - 1])
        is_sorted = false;
    }

    if (is_sorted)
      return 0;
    if (s.size() == 2)
      return -1;

    if (minc == s[0] || maxc == s.back())
      return 1;

    for (int i = 1; i + 1 < s.size(); i++) {
      if (s[i] == minc || s[i] == maxc)
        return 2;
    }

    return 3;
  }
};
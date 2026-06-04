// Author: Sabbbir Hossain
// Problem Link:
// https://leetcode.com/problems/find-target-indices-after-sorting-array

class Solution {
public:
  vector<int> targetIndices(vector<int> &nums, int target) {
    vector<int> indexes;
    int prev = -1;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target)
        count++;

      if (nums[i] < target) {
        prev += 1;
      }
    }

    while (count--) {
      indexes.push_back(++prev);
    }
    return indexes;
  }
};
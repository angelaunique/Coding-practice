/**
 * 本代码来自 CSON 官方视频课程，由 @CSON 提供
 * 题目来源：http://leetcode.com
 * - CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
 * - 讲师：Edward Shi
 * - 官方网站：https://cspiration.com
 * - 版权归CSON所有，禁止转载
 */
class Solution {
 public:
  int majorityElement1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

class Solution {
 public:
  int majorityElement2(vector<int>& nums) {
    map<int, int> mymap;
    int res = 0;
    for (auto num : nums) {
      if (mymap.find(num) == mymap.end()) {
        mymap[num] = 1;
      } else {
        mymap.find(num)->second += 1;
      }
      if (mymap[num] > nums.size() / 2) {
        res = num;
        break;
      }
    }
    return res;
  }
};

class Solution {
 public:
  int majorityElement3(vector<int>& nums) {
    int count = 0;
    int res = 0;
    for (int num : nums) {
      if (count == 0) {
        res = num;
      }
      if (num != res) {
        count--;
      } else
        count++;
    }
    return res;
  }
};
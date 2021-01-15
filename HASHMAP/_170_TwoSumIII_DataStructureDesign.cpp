/**
 * 本代码来自 CSON 官方视频课程，由 @CSON 提供
 * 题目来源：http://leetcode.com
 * - CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
 * - 讲师：Edward Shi
 * - 官方网站：https://cspiration.com
 * - 版权归CSON所有，禁止转载
 */
// method1
class TwoSum {
 public:
  /** Initialize your data structure here. */
  map<int, int> mymap;
  /** Add the number to an internal data structure.. */
  void add(int number) {
    if (mymap.find(number) == mymap.end()) {
      mymap[number] = 1;
    } else {
      mymap.find(number)->second += 1;
    }
  }

  /** Find if there exists any pair of numbers which sum is equal to the value.
   */
  bool find(int value) {
    for (auto num : mymap) {
      int i = num.first;
      int j = value - i;
      if ((i == j && num.second > 1) ||
          (i != j && (mymap.find(j) != mymap.end()))) {
        return true;
      }
    }
    return false;
  }
};

// method2
class TwoSum {
 public:
  /** Initialize your data structure here. */
  map<int, int> mymap;
  vector<int> list;
  /** Add the number to an internal data structure.. */
  void add(int number) {
    if (mymap.find(number) == mymap.end()) {
      mymap[number] = 1;
      list.push_back(number);
    } else {
      mymap.find(number)->second += 1;
    }
  }

  /** Find if there exists any pair of numbers which sum is equal to the value.
   */
  bool find(int value) {
    for (int num1 : list) {
      int num2 = value - num1;
      if ((num1 == num2 && mymap[num1] > 1) ||
          (num1 != num2 && (mymap.find(num2) != mymap.end()))) {
        return true;
      }
    }
    return false;
  }
};

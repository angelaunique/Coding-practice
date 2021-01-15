/*127. Word Ladder
Medium

3646

1270

Add to List

Share
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(), wordList.end()); //快速吧vector 转换为unordered set      
        if (!dict.count(endWord)) return 0;// 用 set 来查找endword  用来快速查找
        /*Searches the container for elements with a value of k and returns the number of elements found. Because unordered_set containers do not allow for duplicate values, this means that the function actually returns 1 if an element with that value exists in the container, and zero otherwise.
*/
        
        queue<string> q;//用来放被modified 并checked的单词
        q.push(beginWord);//放入第一个
        
        int l = beginWord.length();
        int step = 0;//用来计数符合条件的单词
        
        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; size--) {                
                string w = q.front(); // 拿出q里的第一个单词q             
                q.pop();//拿出
                for (int i = 0; i < l; i++) {  //循环单词 ，循环3个，较短用for loop即可           
                    char ch = w[i];//用来后面复位用
                    /*****内循环用来改掉某一问单词*******/
                    for (int j = 'a'; j <= 'z'; j++) {//循环26个，较短，用for loop 即可
                        w[i] = j;//改掉单词的第i位
                        // Found the solution
                        if (w == endWord) return step + 1;//如果改掉某位的单词与 endWord相等，step+1
                        // Not in dict, skip it
                        if (!dict.count(w)) continue;//如果没有，继续，字典可以用来快速查看
                        // Remove new word from dict
                        dict.erase(w);//用过之后从字典中移除，此处字典可以用来快速移除
                        // Add new word into queue
                        q.push(w);  //push w 到q                  
                    }
                    w[i] = ch;// 第 i 位复位，因为把之前在q里的单词改掉了，之前的单词肯定是符合条件的，要变回来
                }
            }
        }
        return 0;//最后没找到直接return 0;
    }
};
/* Another tricks for chr<-> int
for(char c = 'a'; c <= 'z'; c++){
                        curr[j] = c;*/

//Solution 2: Bidirectional BFS begin and end 交换改变, until they are equal and meet with each other
// Running time: 32 ms (better than 96.6%)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());        
        if (!dict.count(endWord)) return 0;
        
        int l = beginWord.length();
        
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
                
        int step = 0;
        
        while (!q1.empty() && !q2.empty()) {
            ++step;
            
            // Always expend the smaller queue first
            if (q1.size() > q2.size())
                std::swap(q1, q2);
                        
            unordered_set<string> q;
            
            for (string w : q1) {
                for (int i = 0; i < l; i++) {
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if (q2.count(w)) return step + 1;
                        if (!dict.count(w)) continue;                        
                        dict.erase(w);
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }
            
            std::swap(q, q1);
        }
        
        return 0;
    }
};                        
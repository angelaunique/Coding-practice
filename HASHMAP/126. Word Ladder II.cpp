/*126. Word Ladder II
Hard

1963

261

Add to List

Share
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.*/
//https://www.youtube.com/watch?v=PblfQrdWXQ4
//用图来解，找到达终点的不同路径，因有可能有不同parents,所以有不同路径
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(), wordList.end());        
        if (!dict.count(endWord)) return {};//如果endword不存在，空集
        dict.erase(beginWord);//不需要从beginWord 变到 beginWord
        dict.erase(endWord);//不需要从endWord变到 endWord
        
        unordered_map<string, int> steps{{beginWord, 1}};//steps用来数从beginword 开始记录的不熟
        unordered_map<string, vector<string>> parents;//用来记录string的parents--list of string
        queue<string> q;//用来bfs
        q.push(beginWord);//push第一个单词
        
        vector<vector<string>> ans;
        
        const int l = beginWord.length();
        int step = 0;        
        bool found = false;
        
        while (!q.empty() && !found) {
            ++step;            
            for (int size = q.size(); size > 0; size--) {
                const string p = q.front();     
                      q.pop();
                string w = p;
                for (int i = 0; i < l; i++) {
                    const char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        if (j == ch) continue;
                        w[i] = j;
                        if (w == endWord) {//找到
                            parents[w].push_back(p);
                            found = true;
                        } else {
                            // Not a new word, but another transform
                            // with the same number of steps
                            if (steps.count(w) && step < steps.at(w))// map 用 at 访问，否则如果不在里面会创建一个新的vector,出现bug
                                parents[w].push_back(p);//把另外一个parent 存入
                        }
                        
                        if (!dict.count(w)) continue;//如果w不存在，这个单词 返回到for loop, 下面的code不会再执行
                        //如果存在此变形，加入parent，加入q，把w从dict中国拿出，增加steps
                        parents[w].push_back(p);
                        dict.erase(w);// remove w from dict
                        q.push(w);//
                        steps[w] = steps.at(p) + 1;
                        
                    }
                    w[i] = ch;//变回原来到单词
                }
            }
        }
        
        if (found) {
            vector<string> curr{endWord};
            getPaths(endWord, beginWord, parents, curr, ans);
        }
    
        return ans;
    }
private:
    void getPaths(const string& word, 
                  const string& beginWord, 
                  const unordered_map<string, vector<string>>& parents,
                  vector<string>& curr,
                  vector<vector<string>>& ans) {        
        
        if (word == beginWord) {
            ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
            return;
        }
        
        for (const string& p : parents.at(word)) {
            curr.push_back(p);
            getPaths(p, beginWord, parents, curr, ans);
            curr.pop_back();
        }        
    }
};
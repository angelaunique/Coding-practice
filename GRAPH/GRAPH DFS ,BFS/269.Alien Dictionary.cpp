/*There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
Accepted
151,528
Submissions
454,974 */


class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        unordered_map<char, unordered_set<char>>    suc, prev;
        string s;
        unordered_set<char> chars;
        
        for(auto t:words){
            chars.insert(t.begin(), t.end());// char has all the chars in words array
            if(s.size() > t.size() && s.substr(0, t.size()) == t)   return "";     //add this line to deal with {"wrtkj", "wrt"}
            
            for(int i =0;i<min(s.size(), t.size()); i++){
                if(s[i] != t[i]){//if found different letter compare t2: s1, s size is 1 smaller than t
                    suc[s[i]].insert(t[i]);// insert letter  into suc map {t:f}
                    prev[t[i]].insert(s[i]);// invert map of suc{f:t}
                    break;
                } 
            // cout <<"s:" << s << endl; //  s:wrt,s:wrt ,s:er, s:rftt
            }
            s = t; // s only starts here, s is the copied array without the last word
        }
        cout <<"s:" << s << endl;// s:rftt
        
        unordered_set<char> myq (chars);// copy unordered set chars
       
        for(auto p:prev)
        {   
            
            myq.erase(p.first); //only the first char"w" remains, delete all the parents in the  myq sets
         
        }
       
       
        string res;
        while(!myq.empty()){//q用来keep track of result
            auto c = *(myq.begin());
            myq.erase(c);
            res+=c;// c = w
            for(auto a:suc[c]){ //  a =e
                prev[a].erase(c);// delete [101 'e'] = {[0] = 'w'} pair
                if(prev[a].empty())    myq.insert(a); // myq = e //反向把连接的pair 都删除 w->e ->r->t->f 从suc里找到下一个需要加入res的值，pre用来keep track  e 是否还有其他parents,如果没有表面全部parent已经删除，插入到q；否则for loop 继续删除
            }
        }
        
        return res.size() == chars.size() ? res : "";//如果全部相连，最后graph 则会被全部删除干净， res.size() == chars.size() ；否则，graph 未被则删除干净，说明有 ab,abc 这样的不合法字符， 那么把"" 加入result
    }
};
/*
suc: {[101 'e'] = {[0] = 'r'}, [116 't'] = {[0] = 'f'}, [114 'r'] = {[0] = 't'}, [119 'w'] = {[0] = 'e'}}
prev: {[114 'r'] = {[0] = 'e'}, [102 'f'] = {[0] = 't'}, [116 't'] = {[0] = 'r'},[101 'e'] = {[0] = 'w'}
s: "rftt"
chars: {[0] = 'e', [1] = 'w', [2] = 'r', [3] = 't', [4] = 'f'}
myq: {[0] = 'e', [1] = 'w', [2] = 'r', [3] = 't', [4] = 'f'}
res: “"*/

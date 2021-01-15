
/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.


*/

    bool cmp(const pair<string, int>& a, const pair<string, int>& b) 
{ 
    
     if(a.second != b.second){
          return a.second > b.second;
                }
     else{
        return a.first < b.first;// IF count equals, return alphabeticaly
        }
} 
 /*
    void msort( map<string, int> & M) { // name of this function need to be distinguished from vector sort function
        
        for( auto & it : A) {
            
            cout << it.first << ' ' << it.second << endl;
        }
     }
    */
class Solution {
public:
   
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for( int i = 0; i < words.size(); i++){
            mp[words[i]] +=1;
        }
       
       // msort(mp); 
        
        // Delcare vector of pairs
        vector< pair <string, int>> A;
        // Copy key-vlaue pair from Map to vector of pairs
        for( auto & it: mp) {
            A.push_back(it);
        }
       // Sort using comparator function 
        sort(A.begin(), A.end(), cmp); 
        // print the sorted value
        
        vector<string> result;
        
        for(int i=0;i< A.size();i++){ // can't iterate through map, only can get result from vecotr
            
            if(k==0) return result;
            else{
                result.push_back(A[i].first);
            }
            k--;
        }
        return result;
    }
    
};
/* similar method 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& word, int k) {
        map<string,int> count;
        vector<pair<string,int>> ret;
        for(int i=0;i<word.size();i++){
            count[word[i]]++;
            }
        for(auto itr=count.begin();itr!=count.end();itr++){
            ret.push_back(make_pair(itr->first,itr->second));
            
        }
       
                sort(ret.begin(),ret.end(),[](const pair<string,int> &u,const pair<string,int> &v){
                    if(u.second != v.second){
                        return u.second > v.second;

                    }
                    else{
                        return u.first < v.first;
                    }
                });
       
        vector<string> ans;
        for(int i=0;i<ret.size();i++){
            if(k==0) break;
            else{
                ans.push_back(ret[i].first);
            }
            k--;
        }
        return ans;
    }
};
*/

#define P pair<int, string>

struct compare {
    bool operator()(const P& p, const P& q) {// p.second big count on the top,p.first  are strings
        return (p.first < q.first) || (p.first == q.first && p.second > q.second);
         // if string equal, compare count, other wise compare string alphabetically
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string, int> m;
        for (auto word : words) {
            m[word] += 1;
        }
        priority_queue <P, vector<P>, compare> pq;
        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push({it->second, it->first});//() operator is defined
            // second are count, first are string
        }
        vector <string> ans;
        
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
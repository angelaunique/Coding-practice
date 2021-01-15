/*1152. Analyze User Website Visit Pattern
Medium

102

870

Add to List

Share
We are given some website visits: the user with name username[i] visited the website website[i] at time timestamp[i].

A 3-sequence is a list of websites of length 3 sorted in ascending order by the time of their visits.  (The websites in a 3-sequence are not necessarily distinct.)

Find the 3-sequence visited by the largest number of users. If there is more than one solution, return the lexicographically smallest such 3-sequence.

 

Example 1:

Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
Explanation: 
The tuples in this example are:
["joe", 1, "home"]
["joe", 2, "about"]
["joe", 3, "career"]
["james", 4, "home"]
["james", 5, "cart"]
["james", 6, "maps"]
["james", 7, "home"]
["mary", 8, "home"]
["mary", 9, "about"]
["mary", 10, "career"]
The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.
 

Note:

3 <= N = username.length = timestamp.length = website.length <= 50
1 <= username[i].length <= 10
0 <= timestamp[i] <= 10^9
1 <= website[i].length <= 10
Both username[i] and website[i] contain only lowercase characters.
It is guaranteed that there is at least one user who visited at least 3 websites.
No user visits two websites at the same time.*/
// python
class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
       
        packed_tuple = zip(timestamp, username, website)   # ---> [(3, 'joe', 'career'),....]
        sorted_packed_tuple = sorted(packed_tuple)  # sort by timestamp (By default tuple always sorted by first item )
        
        mapping = defaultdict(list)
        for t, u, w in sorted_packed_tuple:     # joe: [home, about, career]  websites in list are in ascending timestamp order
            mapping[u].append(w) # user-key; website list
           
        counter_dict = defaultdict(int)         # use a dict for counting
        for website_list in mapping.values():# [home, about, career] 
            combs = set(combinations(website_list, 3))    # size of combination is set to 3 
            # ["james",  "home","cart", "maps","home"] different combo of web list 
            for comb in combs:
                counter_dict[comb] += 1       # Tuple as key, counter as value,  e.g. ('home', 'about', 'career') : 2
        
        sorted_counter_dict = sorted(counter_dict, key=lambda x: (-counter_dict[x], x)) # sort descending by value: -counter_dict[x], -2,-1, then lexicographically: x : ('home', 'about', 'career')
        
        return sorted_counter_dict[0]
        

//c++

class Solution {
public:
vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
  int const N = username.size();

  unordered_map<string, map<int, string>> visits; // user -> visits
  unordered_map<string, unordered_map<string, unordered_map<string, unordered_set<string>>>> store;

  // Reorganize the data; map username to a list of websites sorted by timestamp
  for (int i = 0; i < N; ++i)
    visits[username[i]].emplace(timestamp[i], website[i]);
  for (auto& userVisits : visits)
    for (auto i = userVisits.second.begin(); i != userVisits.second.end(); ++i)
      for (auto j = next(i); j != userVisits.second.end(); ++j)
        for (auto k = next(j); k != userVisits.second.end(); ++k)
          store[i->second][j->second][k->second].insert(userVisits.first);

  // Find the best triple
  int mostUsers = 0;
  vector<string> result;
  for (const auto& it1 : store) {
    for (const auto& it2 : it1.second) {
      for (const auto& it3 : it2.second) {
        if (it3.second.size() < mostUsers)
          continue;
        vector<string> triple = { it1.first, it2.first, it3.first };
        if (it3.second.size() > mostUsers) {
          mostUsers = it3.second.size();
          result = move(triple);
        } else if (lexicographical_compare(triple.begin(), triple.end(), result.begin(), result.end())) {
          result = move(triple);
        }
          }
        }
      }

      return result;
    }

};
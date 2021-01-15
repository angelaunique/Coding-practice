
/*
Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

Return true if and only if she can.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.

// only need one group that contain consecutive numbers of size w
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> m;
        // build map
        for( int i = 0; i < hand.size(); i++){
            m[hand[i]]++;
        }
        
        // print map
        for( auto & pair:m) {
            cout << pair.first <<":" << pair.second <<endl;
        }
      
         while (m.size() > 0) {
            int firstKey = m.begin()->first;
               // map automatically sorted according to keys, thus first is the min key
            for (int card =firstKey; card < firstKey + W; card++) {
                if(m.find(card)==m.end()) return false;// if can't find card, return false, no consecutive
                int v = m.find(card)->second;
                if(v == 1)
                    m.erase(card);// take card out 
                else
                    m[card] = v-1;
                }
            } 
        return true;
    }
   
};
/*
[1,2,3,4]
4
*/
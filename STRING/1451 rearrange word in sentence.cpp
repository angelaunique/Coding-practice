 
       /*
Given a sentence text (A sentence is a string of space-separated words) in the following format:

First letter is in upper case.
Each word in text are separated by a single space.
Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.

Return the new text following the format shown above.

 

Example 1:

Input: text = "Leetcode is cool"
Output: "Is cool leetcode"
Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
Output is ordered by length and the new first word starts with capital letter.
Example 2:

Input: text = "Keep calm and code on"
Output: "On and keep calm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.
Example 3:

Input: text = "To be or not to be"
Output: "To be or to be not"
       
       */ 
        
/*  vector<string> words;
  string str;
  
  while( cin >> str ) words.push_back(str);

  vector<string>::iterator iter;
  for( iter = words.begin(); iter != words.end(); iter++ ) {
    cout << *iter << endl;
  }*/

 eg: stable_sort(words.begin(), words.end(), [](const auto& a, const auto& b){ return a.size() < b.size(); }); 
 


/*pop_back() is a built-in function in C++ STL which is used to remove an 
element from the back of a list container. That is, this function deletes the last 
element of a list container.*/
//python
// c++ ostream solotion, you can't directly break the text ,must use the os tring to break it
class Solution:
    def arrangeWords(self, text: str) -> str:
        return " ".join(sorted(text.split(" "), key=len)).capitalize()

class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        stringstream ss(text);
        map<int, vector<string>> mWords;
        string word;
        while (getline(ss, word, ' ')) {//you can't directly break the text ,must use the os tring to break it
            mWords[word.size()].push_back(word);//after put into map, auto sort
        }
        /*
         while(ss >> str){
             str+=' ';
            mWords[str.size()].push_back(str);
        }
        */
        string sRet;
        for (const auto& wordLength : mWords) {// iterate through key, auto use &
            for (const auto& w : wordLength.second) {// iterate throw value(text)
                sRet += w;
                sRet += " ";
            }
        }
        sRet.pop_back();
        sRet[0] = toupper(sRet[0]);
        return sRet;
    }
};
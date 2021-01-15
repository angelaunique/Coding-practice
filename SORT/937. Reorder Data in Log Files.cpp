/*You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]*/


/*
Instead of sorting in the default order, we'll sort in a custom order we specify.

The rules are:

Letter-logs come before digit-logs;
Letter-logs are sorted alphanumerically, by content then identifier;
Digit-logs remain in the same order.
It is straightforward to translate these ideas into code.
*/
// algorithm library : https://www.youtube.com/watch?v=_dC6Pvk0awA
#include <iostream>
using namespace std;

// if both are letter-logs, compare a vs b
// 

    bool myCompare(string a, string b){
        int i = a.find(' '); // eg: a = vect[0]
        int j = b.find(' ');// eg:  b = vect[1]
         cout <<"a.substr(i + 1):" << a.substr(i + 1) << endl; // substring after first ' '
        /* a.substr(i + 1):art can
        a.substr(i + 1):3 6
        a.substr(i + 1):3 6
        a.substr(i + 1):art zero
        a.substr(i + 1):own kit dig
        a.substr(i + 1):own kit dig
        a.substr(i + 1):own kit dig
        a.substr(i + 1):art zero
*/
        cout <<"a[i + 1]:" << a[i + 1] << endl; // First char after ' '
         //cout <<"a.substr(j + 1):" << a.substr(j + 1) << endl;
        cout <<"a.substr(0, i + 1) " << a.substr(0, i + 1) << endl; // First char after ' '
            if(!isdigit(a[i + 1]) && !isdigit(b[j + 1])) //  a.substr(a.find(' ')  + 1)get words not including identifier== s.substr(pos + 1); find any word following ' '
            {
                // if both sub string list are equal , compare log identifier 
                if (a.substr(i + 1) == b.substr(j + 1)) { //  Letter-logs are sorted alphanumerically,by content 
                    return a.substr(0, i + 1) < b.substr(0, j + 1);  //如果两个都是letters 而且log string group 一模一样，那么按照log ID排序
                } 
                return a.substr(i + 1) < b.substr(j + 1); } //如果两个都是letters, 比较sub group  //Letter-logs are sorted by identifier;
         
                // if both a and b are not digit, then return T, means put a infront of b
            else if(!isdigit(a[i + 1]) ) {
                
          return true; //if a is letter a automatically comes before b:Letter-logs come before digit-logs;       
        }
        return false;// for all other cases order keeps the same order keeps the same:Digit-logs remain in the same order.
    }
  
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        //use stable_sort as order of equivalent elements is preserved
        // stable_sort will go from beging to end compare each pairs
        stable_sort(logs.begin(), logs.end(), myCompare);
        return logs;
    }
};  
         

              

/*
 e1: art can
 e2: 8 1 5 1
 e1: 3 6
 e2: art can
 e1: 3 6
 e2: 8 1 5 1
 e1: art zero
 e2: own kit dig
 e1: own kit dig
 e2: 3 6
 e1: own kit dig
 e2: 8 1 5 1
 e1: own kit dig
 e2: art can
 e1: art zero
 e2: art can
 */

/*
int main() 
{ 
    // Take any string 
    string s = "dog:cat"; 
  
    // Find position of ':' using find() 
    int pos = s.find(":"); 
  
    // Copy substring after pos 
    string sub = s.substr(pos + 1); 
  
    // prints the result 
    cout << "String is: " << sub; 
  
    return 0; 
} 
output:  String is: cat
*/

/* template <class RandomAccessIterator, class Compare>
  void stable_sort ( RandomAccessIterator first, RandomAccessIterator last,
                     Compare comp );
comp
Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. The value returned indicates whether the element passed as first argument is considered to go before the second in the specific strict weak ordering it defines.
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.*/
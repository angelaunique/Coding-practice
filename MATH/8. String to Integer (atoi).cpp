
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, 
takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it 
contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the 
numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.


//https://www.geeksforgeeks.org/removing-spaces-string-using-stringstream/

#include <iostream>
class Solution {
    /* Solution 3 cases: First, trim up empty spaces
    Second, decide sign of the string
    Third, */
   /* clear() — to clear the stream
str() — to get and set string object whose content is present in stream.
operator << — add a string to the stringstream object.
operator >> — read something from the stringstream object,*/
    // C++ program to remove spaces using stringstream 
#include <bits/stdc++.h> 
  
// Function to remove spaces 
string removeSpaces(string str) 
{ 
    stringstream ss; 
    string temp; 
  
    // Storing the whole string 
    // into string stream 
    ss << str; 
  
    // Making the string empty 
    str = ""; 
  
    // Running loop till end of stream 
    while (!ss.eof()) { 
  
        // Extracting word by word from stream 
        ss >> temp; 
  
        // Concatenating in the string to be 
        // returned 
        str = str + temp; 
    } 
    return str; 
} 
  
// Driver function 
int main() 
{ 
    // Sample Inputs 
    string s = "This is a test"; 
    cout << removeSpaces(s) << endl; 
  
    s = "geeks for geeks"; 
    cout << removeSpaces(s) << endl; 
  
    s = "geeks quiz is awsome!"; 
    cout << removeSpaces(s) << endl; 
  
    s = "I love     to     code"; 
    cout << removeSpaces(s) << endl; 
  
    return 0; 
} 
/*Thisisatest
geeksforgeeks
geeksquizisawsome!
Ilovetocode*/

public:
    int myAtoi(string str) {
        cout <<"size of str:" << str.size() <<endl;
        /*
        cout << "Enter price: "; 
        getline (cin,mystr); 
        stringstream(mystr) >> price; */
        stringstream ss(str); //copy str to ss
        str = "";
        /*
         // Extracting word by word from stream 
        ss >> temp; */
        ss >> str; 
         cout <<"size of str2:" << str.size() <<endl;
        int i = 0;
        int sign = 1;
        if(str[i] == '-' || str[i] == '+') {
            sign = (str[i] == '-')? -1 : 1;
            i++;
        }
        long long int res = 0;
        while('0'<= str[i] && str[i] <= '9') {
            res = res*10 + (str[i]-'0');//the character value of 0 is taken off the character value 
            //retrieved from the string. The value of '0' is 48 and '1' is 49 and they increase 
            //sequentially, so taking off 48 ('0') converts the ascii value of a number to its actual value.
            i++;
            if(res*sign >= INT_MAX) return INT_MAX;
            if(res*sign <= INT_MIN) return INT_MIN;
        }
        return res * sign;
    }
};

// remove algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::remove

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};      // 10 20 30 30 20 10 10 20

  // bounds of range:
  int* pbegin = myints;                          // ^
  int* pend = myints+sizeof(myints)/sizeof(int); // ^                       ^

  pend = std::remove (pbegin, pend, 20);         // 10 30 30 10 10 ?  ?  ?
                                                 // ^              ^
  std::cout << "range contains:";
  for (int *p=pbegin; p!=pend; ++p)
    std::cout << ' ' << *p;
  std::cout << '\n';

  return 0;

#include <iostream> 
#include <algorithm> 
using namespace std; 
  
// Function to remove all spaces from a given string 
string removeSpaces(string str)  
{ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
} 
/*
template <class ForwardIterator, class T>
  ForwardIterator remove (ForwardIterator first, ForwardIterator last, const T& val);
Remove value from range
[Note: This is the reference for algorithm remove. See remove for <cstdio>'s remove.]

Transforms the range [first,last) into a range with all the elements that compare equal 
to val removed, and returns an iterator to the new end of that range.
*/
//SINCE REMOVE ONLY RETURN AN ITERATOR AND STRING DOESNT HAVE STR.REMOVE FUNCTION,
//thus we need to use str.erase to change it itorator back to string
  
// Driver program to test above function 
int main()  
{ 
    string str = "g  eeks   for ge  eeks   "; 
    str = removeSpaces(str); 
    cout << str; 
    return 0; 
} 
 geeksforgeeeks 
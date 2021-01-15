/*6. ZigZag Conversion
规律找出来了，但公式的得出过程还是很懵逼！！！
Add to List

Share
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 



Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

class Solution {
public:
    string convert(string s, int numRows) {
    /*
      2*（row-1） ，//last row ,first row
       2*（row-1）  step= 2*（row-1）-row*2 =2*3-4    */// other rows
           if (numRows == 1) return s;
         int step = 0 ;
          string res ="";
          int cycle = 2*(numRows-1);
        
         for (int i = 0;i < numRows;i++){   //i=1
            for( int j = 0; j+i < s.length();j+=cycle) {//
                   res+= s[i+j];//j=1.i+1=2
                //j+=cycle; can't change j value     
                if(i!= 0 &&i!= numRows-1&& j + cycle - i< s.length()) {
                    step =  j + cycle- i;//j + cycleLen - i
                    res+=s[step];
                }
            }
        }
        return res;
    }          
};
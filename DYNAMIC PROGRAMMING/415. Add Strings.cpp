/*
415. Add Strings

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

//搞笑讲解视频 https://www.youtube.com/watch?v=b-9tinoH8S4
class Solution {
public:
    string addStrings(string num1, string num2) {  

        string s = "";
        
        int carry = 0;
        int sum = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        while(i >= 0 || j >= 0 )
        {
            sum = carry;
            if( i >=0 ) sum+= num1[i] -'0';
            if( j >=0 ) sum+= num2[j] -'0';
            s += to_string (sum % 10 );// use to_string!新语法
            carry = sum/10;
            i--;
            j--;    
        }
        if(carry != 0 ) s+= to_string(carry);
        
        reverse(s.begin(), s.end());// directly reverse begin ,end 新语法
        return s;
    }
};
/* method2 similar 
class Solution {
public:
string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while(i>=0 || j>=0 || carry){
        long sum = 0;
        if(i >= 0){sum += (num1[i] - '0');i--;}
        if(j >= 0){sum += (num2[j] - '0');j--;}
        sum += carry; 
        carry = sum / 10;
        sum = sum % 10;
        res =  res + to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
}
};*/
///A school method based C++ program to  
// check if a number is prime 
#include <bits/stdc++.h> 
using namespace std; 
  
// function check whether a number  
// is prime or not 
bool isPrime(int n) //检查n是否质数
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) //2，3，4，5 如果module 之后为0
        if (n % i == 0) //从2开始，小于n的所有数字中，如果有一个数字module完为0,那么此数字不是质数
            return false; 
  
    return true; 
} 
  
// Driver Program 
int main() 
{ 
    isPrime(11) ? cout << " true\n" :  
                  cout << " false\n"; 
    return 0; 
} 

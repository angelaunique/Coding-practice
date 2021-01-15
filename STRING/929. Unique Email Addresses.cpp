
/*Approach 1: Canonical Form
Intuition and Algorithm

For each email address, convert it to the canonical address that actually receives the mail. This involves a few steps:

Separate the email address into a local part and the rest of the address.

If the local part has a '+' character, remove it and everything beyond it from the local part.

Remove all the zeros from the local part.

The canonical address is local + rest.

After, we can count the number of unique canonical addresses with a Set structure.*/




class Solution {
public:
   
    int numUniqueEmails(vector<string>& emails) {
         unordered_set<string> m;// use set
         //for( int i = 0; i < emails.size();i++) {//Don't need *emails
         for(string email : emails) {    
            email = cleanleft(email)+ email.substr(email.find('@'));
            m.insert(email); 
         }
        return m.size();
    }
    
     string cleanleft( string str){
      
          //vector<string> v = '';// string vector will be ARRAY OF STRINGS, not single string anymore! use string //push_back should be called with () not []. Fixes the issue.
          string v="";//use string and str++
      for ( int i = 0; i < str.size();i++){   
        if ( str[i] =='@'|| str[i] =='+'){// must be single quote!
            break;
        }
          else  if ( str[i] !='.'){ 
              v+=str[i];
            }         
      }
        return v;     
    }
};
/* method1 
int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> st;
    for(string &email : emails) {
        string cleanEmail;
        for(char c : email) {
            if(c == '+' || c == '@') break;
            if(c == '.') continue;
            cleanEmail += c;
        }
        cleanEmail += email.substr(email.find('@'));
        st.insert(cleanEmail);
    }
    return st.size();
}*/

/*sestemail@lee.tcode.com" 
testemail@lee.tcode.com
destemail@lee.tcode.com
... unordered set is enough!
*/

/* method2
int numUniqueEmails(vector<string>& emails) {
        
        unordered_set<string> s;
        for(string email : emails)
        {
            string localName = email.substr(0,email.find_first_of('@'));
            string domain = email.substr(email.find_first_of('@'));
            
            if(localName.find('+') != string::npos)
                localName.erase(localName.find_first_of('+'));
            
            localName.erase(remove(localName.begin(), localName.end(), '.'), localName.end());
            s.insert(localName+domain);
        }
        
        return s.size();
    }
    
    */
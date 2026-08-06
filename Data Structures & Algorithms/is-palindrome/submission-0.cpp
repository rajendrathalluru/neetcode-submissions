class Solution {
public:
   bool valchar(char c){
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
     }
    bool isPalindrome(string s) {
        int b=0;
        int e=s.length()-1;
     while(b<=e){
        if(!valchar(s[b])){
            b++;
        }
        else if(!valchar(s[e])){
            e--;
        }
        else{
            char x= tolower(s[b]);
            char y= tolower(s[e]);
            if(x!=y) return false;
            b++;
            e--;
        }
     }
  
     return true;
    }
};
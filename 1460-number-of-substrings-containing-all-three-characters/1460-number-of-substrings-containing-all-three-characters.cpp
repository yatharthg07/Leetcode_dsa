#define ll long long
class Solution {
public:
    int numberOfSubstrings(string s) {
      ll n=s.size();
      ll total=n*(n+1)/2;
      
      //now write code to find for at most 2 distinct characters
      ll acnt=0,bcnt=0,ccnt=0,res=0,l=0,r=0;
      
      while(r<n){
          if(s[r]=='a')acnt++;
          if(s[r]=='b')bcnt++;
          if(s[r]=='c')ccnt++;
          
          while(acnt>0 && bcnt>0 && ccnt>0){
               if(s[l]=='a')acnt--;
               if(s[l]=='b')bcnt--;
               if(s[l]=='c')ccnt--;
              l++;
          }
          
          res+=(r-l+1);
          
        r++;  
      }
      
      
      return total-res;      //total no of subarrays-subarrys with at most two distinct
        
    }
};
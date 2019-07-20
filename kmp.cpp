#include<bits/stdc++.h>
using namespace std;

int *lps(string pattern){

     int *arr = new int[pattern.length()];
     int i = 1;
     int j = 0;

     arr[0] = 0;

     while(i < pattern.length()){

          if(pattern[i] == pattern[j]){
               arr[i] = j + 1;
               j++;
               i++;
          }else{

               if(j > 0)
                    j = arr[j-1];
               else{
                    arr[i] = 0;
                    i++;
               }
          }
     }
     return arr;
}

int kmp(string text, string pattern){

     int *arr = lps(pattern);
     int i = 0;
     int j = 0;

     while(i < text.length() && j < pattern.length()){

          if(text[i] == pattern[j]){
               i++;
               j++;
          }else{

               if(j > 0)
                    j = arr[j-1];
               else{
                    i++;
               }
          }
     }

     if(j == pattern.length())
          return i - j;
     return -1;
}

int main(){
     string s,p;
     s = "AAAABAAAAABBBAAAAB";
     p = "AAA";
     std::cout << kmp(s,p) << '\n';
}

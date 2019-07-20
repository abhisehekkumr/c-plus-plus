#include<iostream>
using namespace std;

bool uniqueSubstring(string str, int end, int start){

     int arr[26];
     for(int i = 0; i < 26; i++)
          arr[i] = 0;

     for(int i = start; i <= end; i++)
          arr[str[i]- 'a']++;

     for(int i = 0; i < 26; i++){

          if(arr[i] > 1)
               return false;
     }

     return true;
}

string uniqueString(string str){

     int start = 0, end = 0, max = -1;
     for(int i = 0; i < str.length(); i++){
          for(int j = i-1; j >= 0; j--){
               if(uniqueSubstring(str,i,j)){

                    if(max < i - j){
                         start = j;
                         end = i;
                         max = i - j;
                         //std::cout << start << " "  << end << " " << max << '\n';
                    }
               }
          }
     }

     string ans = "";
     for(int i = start; i <= end; i++)
          ans = ans + str[i];
     return ans;
}

int main(){
     string str;
     cin >> str;
     string s = uniqueString(str);
     std::cout << s << '\n';
}

#include<bits/stdc++.h>
#include<string>
using namespace std;


bool check(string s1, string s2){

  string s = s1 + s2;
  int arr[26] = {0};

  int i = 0;
  while(s[i] != '\0'){

      arr[s[i] - 'a']++;
      i++;
  }

  if(arr['a' - 'a'] && arr['e' - 'a'] && arr['i' - 'a'] && arr['o' - 'a'] && arr['u' - 'a'])
    return true;
  return false;
}


int main(){

    int t;
    cin >> t;

    while(t--){

          int n;
          cin >> n;

          string arr[n];

          for(int i = 0; i < n; i++)
              cin >> arr[i];

          int count = 0;
          for(int  i = 0; i < n; i++){

              for(int j = i; j < n; j++){

                  if(i != j && check(arr[i], arr[j]))
                      count++;
              }
          }

          std::cout << count << '\n';
    }
}

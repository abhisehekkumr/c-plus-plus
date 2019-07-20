#include<iostream>
#include<string>
using namespace std;

int main(){
  int t;
  std::cin >> t;

  while(t--){

    int max = 0, min = 0, i = 0;
    string s1,s2;
    std::cin >> s1;
    std::cin >> s2;

    while(s1[i] != '\0'){

      if(s1[i] == '?' && s2[i] == '?'){
        max++;
      }else if((s1[i] == '?' && s2[i] != '?') || (s1[i] != '?' && s2[i] == '?'))
        max++;
      else if(s1[i] != s2[i]){
        max++;
        min++;
      }

      i++;
    }

    std::cout << min<<" "<<max << '\n';
  }
}

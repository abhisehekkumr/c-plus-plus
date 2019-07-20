#include<bits/stdc++.h>
#include<set>
#include<string>
using namespace std;

int main(){

      int t;
      cin >> t;

      while(t--){

            int n;
            cin >> n;

            int arr[n][5] = {0};

            for(int i = 0; i < n; i++){

                  string str;
                  cin >> str;

                  set<char> myset;
                  int j = 0;
                  while (str[j] != '\0') {
                      myset.insert(str[j]);
                      j++;
                  }

                  set<char> :: iterator it;

                  for(it = myset.begin(); it != myset.end(); it++){

                        if(*it == 'a')
                          arr[i][0] = 1;
                        else if(*it == 'e')
                          arr[i][1] = 1;
                        else if( *it == 'i')
                          arr[i][2] = 1;
                        else if(*it == 'o')
                          arr[i][3] = 1;
                        else if(*it == 'u')
                          arr[i][4] = 1;
                  }
            }

            /*
            for(int i = 0; i < n; i++){
              for(int j = 0; j < 5; j++)
                std::cout << arr[i][j] << " ";
              std::cout  << '\n';
            }
            */

            int count = 0;

            for(int i = 0; i < n; i++){
              for(int j = i+1; j < n; j++){

                    if((arr[i][0] || arr[j][0]) && (arr[i][1] || arr[j][1]) && (arr[i][2] || arr[j][2]) && (arr[i][3] || arr[j][3]) && (arr[i][4] || arr[j][4]))
                        count++;
              }
            }

            std::cout << count << '\n';
      }
}

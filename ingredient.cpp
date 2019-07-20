#include<bits/stdc++.h>
using namespace std;

int main(){

      int t;
      cin>>t;

      while(t--){

            int n, j = 0;
            cin>>n;

            int mat[n][26] = {0};

            for(int i = 0; i<n; i++){

                  char str[200];
                  cin>>str;

                  int m = 0;

                  while(str[m] != '\0'){

                        mat[j][str[m] - 'a'] += 1;
                        m++;
                  }

                  j++;

            }

            int result = 0;
            for(int i = 0; i < 26; i++){

                  int count = 0;
                  for(int j = 0; j<n; j++){

                        if(mat[j][i])
                            count += 1;
                  }

                  if(count == n)
                      result += 1;
            }

            std::cout << result << '\n';

      }
}

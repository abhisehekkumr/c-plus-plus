#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

          int n;
          cin >> n;

          int a[n] = {0};
          int e[n] = {0};
          int i[n] = {0};
          int o[n] = {0};
          int u[n] = {0};

          int a_c = 0, e_c = 0, i_c = 0, o_c = 0, u_c = 0;

          string str;
          for(int k = 0; k < n; k++){

            cin >> str;
            int j = 0;
            a_c = 0;
            e_c = 0;
            i_c = 0;
            o_c = 0;
            u_c = 0;

            while(str[j] != '\0'){

              if(str[j] == 'a' && a_c == 0){
                a[k] = 1;
                a_c++;
              }

              else if(str[j] == 'e' && e_c == 0){
                e[k] = 1;
                e_c++;
              }

              else if(str[j] == 'i' && i_c == 0){
                i[k] = 1;
                i_c++;
              }

              else if(str[j] == 'o' && o_c == 0){
                o[k] = 1;
                o_c++;
              }

              else if(str[j] == 'u' && u_c == 0){
                u[k] = 1;
                u_c++;
              }
              j++;
            }
          }

          int count = 0;

          for(int k = 0; k < n; k++){

              for(int j = k + 1; j < n; j++){

                  if ((a[k] || a[j]) && (e[k] || e[j]) && (i[k] || i[j]) && (o[k] || o[j]) && (u[k] || u[j]))
                      count++;
              }
          }


          std::cout << count << '\n';
    }
}

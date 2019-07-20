#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin >> n;

     char arr[n];
     cin >> arr;

     int a = 0, e = 0, i = 0, u = 0, o = 0;

     for(int j = 0; j < n; j++){

          if(arr[j] == 'a')
               a++;
          else if(arr[j] == 'e')
               e++;
          else if(arr[j] == 'i')
               i++;
          else if(arr[j] == 'o')
               o++;
          else if(arr[j] == 'u')
               u++;
     }

     if(a && e && i && o)
          std::cout << "Yes" << '\n';
     else if(a && e && i && u)
          std::cout << "Yes" << '\n';
     else if(a && e && u && o)
          std::cout << "Yes" << '\n';
     else if(a && u && i && o)
          std::cout << "Yes" << '\n';
     else if(u && e && i && o)
          std::cout << "Yes" << '\n';
     else
          std::cout << "No" << '\n';
}

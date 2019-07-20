#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int power(int num, int y){

      int res = 1;
      num = num%100000;

      while(y > 0){

          if( y & 1)
              res = (res * num)%100000;
          y = y >> 1;
          num = (num * num)%100000;
      }

      return res%100000;
}

signed main(){

    int k,n;
    cin >>n;

    k = n;

    int ans = 0;

    for(int i=1; i<= min(k, (int64_t)(100000)); i++)
      ans = (ans + power(i,n))%100000;

    if(k <= 100000){

        if(ans < 10)
          std::cout << "0000" << ans << '\n';
        else if(ans < 100)
          std::cout << "000" << ans << '\n';
        else if(ans < 1000)
          std::cout << "00" << ans << '\n';
        else if(ans < 10000)
          std::cout << "0" << ans << '\n';
        else
          std::cout << ans << '\n';
          return 0;
    }

    if(k > 100000)
      ans = ((ans % 100000) * (k / 100000)%100000)%100000;

    k = k%100000;

    for(int i = 1; i<=k; i++)
      ans = (ans + power(i,n))%100000;

      if(ans < 10)
        std::cout << "0000" << ans << '\n';
      else if(ans < 100)
        std::cout << "000" << ans << '\n';
      else if(ans < 1000)
        std::cout << "00" << ans << '\n';
      else if(ans < 10000)
        std::cout << "0" << ans << '\n';
      else
        std::cout << ans << '\n';
        return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){

   long long n;
   cin >> n;
   long long startExcess = 8;
   long long Excess = startExcess;
   for (long  long i = 1; i < n - 2; i++)
       Excess += 4;

  long long resultExcess = Excess;
  int resultNeed = (n * 12) - resultExcess;
   cout << resultNeed <<endl;
}

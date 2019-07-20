#include<bits/stdc++.h>
using namespace std;


struct pair1{
     int start;
     int finish;
};


bool compare(struct pair1 s1, struct pair1 s2){

     if(s1.finish < s2.finish)
          return true;

     if(s1.finish == s2.finish && s1.start < s2.start)
          return true;

     return false;
}

int main(){

     int n;
     cin >> n;

     pair1 arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i].start >> arr[i].finish;

     sort(arr, arr + n, compare);

     int count = 1, max = arr[0].finish;

     for(int i = 0; i < n; i++){
          
          if(arr[i].start >= max){
               count += 1;
               max = arr[i].finish;
          }
     }

     std::cout << count << '\n';
}

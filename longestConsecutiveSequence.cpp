#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


// this code doesnt return the first max subsequence
vector<int> longestConsecutiveSequence(int arr[], int n){

     sort(arr,arr+n);
     int start = 0, end = 0, max = 0;
     int s1,e1;
     int count = 0;
     bool flag = true;

     for(int i = 0; i < n - 1; i++){
          if(arr[i] == arr[i+1]-1){
                    count++;
                    if(flag)
                         start = i;
                    end = i+1;
                    flag = false;
          }
          else{
               flag = true;
               if(count > max){
                    s1 = start;
                    e1 = end;
               }
               count = 0;
          }
     }

     std::vector<int> v;
     for(int i = start; i <= end; i++)
          v.push_back(arr[i]);
     return v;
}


// this code return the first subsequence
vector<int> subsequence(int arr[], int n){

     unordered_map<int,int> map;
     for(int i = 0; i < n; i++)
          map[arr[i]]++;

     int start = 0, end = 0, max = 0;
     for(int i = 0; i < n; i++){
          int number = arr[i];
          int j = number;
          int k = i;
          //std::cout << "/* message */" << '\n';
          while (map.count(j)) {
               //std::cout << j << " this is j" << '\n';
               j++;
               k++;
          }

          if(max < (k - i)) {
               max = k - i;
               start = i;
               end = k;
               //std::cout <<  max << " " << start << " " << end << " " << arr[start] << '\n';
          }
     }
     //std::cout << arr[start] << '\n';
     std::vector<int> v;
     for(int i = arr[start]; i < arr[start] + end - start; i++)
          v.push_back(i);
     return v;
}
int main(){
     int n;
     cin >> n;
     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     vector<int> v = subsequence(arr,n);

     for(int i = 0; i < v.size(); i++)
          std::cout << v[i] << ' ';
     std::cout << '\n';
}

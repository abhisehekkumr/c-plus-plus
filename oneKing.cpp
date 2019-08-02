#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> p;

bool compare(p a, p b){
     if(a.first < b.first)
          return true;
     if(a.first > b.first)
          return false;
     return a.second < b.second;
}

int result(vector<p> &v){
     sort(v.begin(), v.end(), compare);
     int count = 0;
     int l = INT_MIN;

     for(int i = 0; i < v.size(); i++){
          if(v[i].second > l){
               count += 1;
               l = v[i].first;
          }
     }
     return count;
}
int main(){
     int t = 1;
     cin >> t;

     while(t--){
          int n;
          vector<p> v;
          cin >> n;
          for(int i = 0; i < n; i++){
               int a,b;
               cin >> a >> b;
               v.push_back(p(b,a));
          }
          cout << result(v) << endl;
     }
}

/*
9
1 5
5 8
7 9
0 3
13 22
15 17
10 12
2 6
8 10
*/

#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

int main(){

      int t;
      cin >> t;

      while(t--){

            long long n;
            cin >> n;

            long long arr[n];

            for(int i = 0; i < n; i++)
                cin >> arr[i];

            priority_queue< int , vector<int> , greater<int>> queue(arr, arr + n);

            long long cost = 0;

            while(queue.size() > 1){

                  int i = queue.top();
                  queue.pop();
                  int j = queue.top();
                  queue.pop();

                  cost += i + j;
                  queue.push(i + j);
            }

            std::cout << cost << '\n';
      }
}

#include<bits/stdc++.h>
using namespace std;

struct item{
     int value;
     int weight;
};

bool compare(struct item a, struct item b){
     double v1 = ((double)a.value)/(a.weight);
     double v2 = ((double)b.value)/(b.weight);

     return v1 > v2;
}

double MaxValue(item arr[], int n, int w){

     sort(arr,arr + n, compare);

     int c = 0;

     double v = 0;

     for(int i = 0; i < n; i++){

          if(c  + arr[i].weight <= w){
               c += arr[i].weight;
               v += arr[i].value;
          }else{

               int r = w - c;
               v += arr[i].value* ((double)r/arr[i].weight)
               break;
          }
     }

     return v;
}

int main(){
     int w = 70;
     item arr[] = {{60,20}, {70,15}, {80,40}};
     std::cout << MaxValue(arr,3,w) << '\n';
}

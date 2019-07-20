#include<bits/stdc++.h>
using namespace std;

int main(){

     vector<int> v(4,12);
     v.push_back(15);
     int c = v.capacity();
     int m =  v.size();
     cout << m << ” “ << c;
}

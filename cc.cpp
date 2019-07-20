#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,arr[10],*p;
	
	for(i=0;i<3;i++){
		cin>>arr[i];
	}

	p=&arr[1];
cout<<++*p<<endl;
}
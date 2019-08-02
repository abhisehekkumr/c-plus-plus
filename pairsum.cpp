#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--){
	    unordered_map<int,int> map;
	    int n,k;
	    cin >> n >> k;

	    for(int i = 0; i < n; i++){
	        int a;
	        cin >> a;
	        map[a]++;
	    }

	    unordered_map<int,int> :: iterator it;

	    int count = 0;
	    for(it = map.begin(); it != map.end(); it++){
	        int number = it->first;
	        if(map.count(k - number)){
	            int m = k - number;
                 //cout << m << " " << number << endl;
	            if(m == number){
                      int l = map[m];
	                count += (l*(l-1))/2;
	            }
	            else{
	                count += map[number]*map[m];
	            }
	            map[number] = 0;
	            map[m] = 0;
	        }
        }
	    cout << count << endl;
	}
	return 0;
}

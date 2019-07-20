#include<iostream>
#include<set>
using namespace std;


char* uniqueChar(char *str){

  	set<char> letters;

  	int i = 0;
  	int countArr[26] = {0};

  	while(str[i] != '\0'){

      countArr[str[i] - 'a']++;
      i++;
    }

  	int count = 0;
  	for(int i = 0; i < 26; i++){

      	if(countArr[i])
          count++;
    }

  	char *c = new char[count];

  	i=0;
  	for(int j = 0; i < count; j++){

      if(i >= 0 && countArr[str[i]]){
        c[j] = str[i];
        countArr[i] = -1;
      }
      i++;
    }
  	return c;

}


int main(){

  char line[2000];
  cin>>line;

  set<int> s;
  pair <set<int> :: iterator, bool> ptr;
  for(int i = 0 ; i < 10; i++)
  {
    ptr = s.insert(10);
      if(ptr.second == false)
          std::cout << "yes" << '\n';
        else
        std::cout << "No" << '\n';
  }

}

#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main(){

      string line, word = "";
      getline(cin , line);

      int i = 0;
      vector<string> v;
      while(i < line.length()){

            if(line[i] == ' ' || line[i] == '\n' || line[i] == '\0'){
              v.push_back(word);
              word = "";
            }else
              word = word + line[i];

            if(i == line.length() - 1)
                v.push_back(word);
            i++;
      }

    map<string, int> m;

    vector<string> :: iterator it;
    for(it = v.begin(); it != v.end(); it++)
      m[*it]++;

    map<string, int> :: iterator k;

    bool flag  = true;
    for(k = m.begin(); k != m.end(); k++){

          if(k->second > 1){
              std::cout <<k->first << "\t" <<  k->second << '\n';
              flag = false;
            }
    }

    if(flag)
        std::cout << -1 << '\n';
}

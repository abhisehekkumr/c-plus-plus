#include<iostream>
#include<string>
using namespace std;


int ip_number(string str){
     int n = 0;

     for(int i = 0; i < str.length(); i++)
          n = n*10 + (str[i] - '0');
     return n;
}

bool leading_zeros(string str){
     if(str[0] == '0' && str[1] >= '0')
          return true;
     return false;
}
int main(){
     int t;
     cin >> t;

     while(t--){
          string ip;
          cin >> ip;


          int dots = 0;
          string temp = "";
          bool flag = false;
          int count = 0;
          //std::cout << "length : "<< ip.length() << '\n';
          for(int i = 0; ip[i] != '\0'; i++){

               if(ip[i] == '.' && ip[i+1] == '.'){
                    flag = false;
                    break;
               }
               if(ip[i] != '.')
                    temp += ip[i];
               else if(ip[i] == '.' || ip[i + 1] == '\0'){
                    dots++;

                    if(leading_zeros(temp)){
                         flag = false;
                         break;
                    }

                    int number = ip_number(temp);
                    if(number >= 0 && number < 256)
                         flag = true;
                    else{
                         flag = false;
                         break;
                    }

                    count++;
                    temp = "";
               }
          }

          if(flag && dots == 4 && count)
               std::cout << 1 << '\n';
          else
               std::cout << 0 << '\n';

     }
}

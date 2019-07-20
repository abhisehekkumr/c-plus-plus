#include<iostream>
#include<string>
using namespace std;

void breakWords(char arr[]){

     char c[2000];
     int i = 0, j = 0;
     while(arr[i] != '\0'){
          int k = i;
          while(arr[k] != ' ' && arr[k] != '\0')
               k++;

          int distance = k - i;

          if(distance%2 == 0 && distance >= 4){

               for(int b = i; b < k; b++){

                    if(b == i + distance/2)
                         c[j++] = ' ';
                    c[j++] = arr[b];
               }
               c[j++] = ' ';
          }else{


               for(int b = i; b < k; b++)
                    c[j++] = arr[b];
               c[j++] = ' ';
          }


          if(arr[k] == '\0'){
               break;
          }
          i = k + 1;
     }



     for(int i = 0; i < j; i++)
          arr[i] = c[i];
     arr[j] = '\0';
}

int main(){
     char arr[1000];
     cin.getline(arr,1000);
     breakWords(arr);
     std::cout << arr << '\n';
}

#include<iostream>
#include<cstring>
using namespace std;

void reverseWordWise(char arr[]){

     int i = 0;
     while(arr[i] != '\0'){
          int k = i;

          while(arr[k] != ' ' && arr[k] != '\0')
               k++;

          int distance = k - i;
          int m = k-1;
          for(int j = i; j < i + distance/2; j++){
               char temp = arr[j];
               arr[j] = arr[m];
               arr[m] = temp;
               m--;
          }

          if(arr[k] == '\0'){
               i = k;
               break;
          }
          i = k + 1;
     }

     int n = i;
     int j = n-1;
     i = 0;
     while(i <= j){
          char c = arr[i];
          arr[i] = arr[j];
          arr[j] = c;
          i++;
          j--;
     }
}

int main(){
     char arr[1000];
     cin.getline(arr,1000);
     reverseWordWise(arr);
     std::cout << arr << '\n';
}

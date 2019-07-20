#include<iostream>
using namespace std;

int power(int number, int n){
     int res = 1;
     while(n){
          if(n & 1)
               res = res*number;
          number = number*number;
          n = n >> 1;
     }
     return res;
}

/*
int subset(int input[],int size, int **output){

     if(size <= 0){
          output[0][0] = 0;
          return 1;
     }


     int smalloutput = subset(input + 1, size - 1, output);
     int k = smalloutput;

     for(int i = 0; i < smalloutput; i++){
          output[k + i][0] = output[i][0] + 1;
          output[k + i][1] = input[0];

          for(int j = 2; j <= output[k + i][0]; j++)
               output[k + i][j] = output[i][j-1];
     }
     std::cout << "hello" << '\n';
     return 2*smalloutput;
}
*/

/*
int subset1(int input[], int n, int **output) {
    // Write your code here
 if(n<=0) {
      output[0][0]=0;
      return 1;
  }

  int smallOutput = subset1(input+1,n-1,output);

  for(int i=0;i<smallOutput;i++) {
      int col = output[i][0] +1;
     output[i+smallOutput][0] = col;
       output[i+smallOutput][1] = input[0];
      for(int j=2; j<col+1;j++) {
        output[i+smallOutput][j] = output[i][j-1];
      }

  }
  std::cout << 2*smallOutput << '\n';
  return 2*smallOutput;
}
*/

void printArray(int input[], int size, int k, int output[], int m){

     if(size  <= 0){

          for(int i = 0; i < m; i++)
               std::cout << output[i] << ' ';

         std::cout << '\n';

        return;
     }


     int arr[k];

     for(int i = 0; i < m; i++)
          arr[i] = output[i];

     arr[m] = input[0];

     printArray(input + 1, size - 1, k, arr, m + 1);
     printArray(input + 1, size - 1, k, output, m);

}

void printSubsetsOfArray(int input[], int size) {

    int output[size];

    // second size is just for declaring array of size k in recursion
    printArray(input,size,size,output,0);
}


int main(){
     int n;
     cin >> n;

     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];
          /*
     int **output = new int*[100];

     for(int i = 0; i < n; i++)
          output[i] = new int[20];
          */
     int arr1[n];
     printSubsetsOfArray(arr,n);
     /*
     for(int i = 0; i < index; i++){
          int j = output[i][0];

          for(int k = 1; k <= j; k++)
               std::cout << output[i][k]  << ' ';
          std::cout << '\n';
     }
     */
}

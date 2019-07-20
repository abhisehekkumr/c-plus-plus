#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define N 10

void setHelper(bool helper[], int size){

     for(int i = 0; i < size; i++)
          helper[i] = false;
}

bool isVerticalPossible(char board[N][N], string  word, int row, int col){

     int count = 0;

     for(int i = 0; i + row < N && i < word.size(); i++){

          if(board[i + row][col] != '-'  && board[i + row][col] != word[i])
               break;

          if(board[i + row][col] == '-' || (board[i + row][col] == word[i]))
               count++;
     }

     if(row > 0 && board[row - 1][col] != '+')
          count--;
     //std::cout << "length : " << count << " : " << word << '\n';
     return count == word.length();
}


bool isHorizontalPossible(char board[N][N], string word, int row, int col){

     int count = 0;

     for(int i = 0; i + col < N && i < word.size(); i++){

          if(board[row][1 + col] != '-'  && board[row][1 + col] != word[i])
               break;

          if(board[row][1 + col] == '-' || board[row][1 + col] == word[i])
               count++;
     }

     if(col > 0 && board[row][col - 1] != '+')
          count--;
     //std::cout << "length : " << count << " : " << word << '\n';
     return count == word.length();
}

bool fillVertical(char board[N][N], string word, int row, int col, bool helper[]){

     for(int i = 0; i < word.length(); i++){

          if(board[i + row][col] == '-'){
               helper[i] = true;
               board[i + row][col] = word[i];
          }
     }

     return true;
}

void resetVerticalFill(char board[N][N],int row, int col, bool helper[], int size){

     for(int i = 0; i < size; i++){

          if(helper[i]){
               board[i + row][col] = '-';
          }
     }
}



bool fillHorizontal(char board[N][N], string word, int row, int col, bool helper[]){

     for(int i = 0; i < word.length(); i++){

          if(board[row][i + col] == '-'){
               helper[i] = true;
               board[row][i + col] = word[i];
          }
     }

     return true;
}

void resetHorizontalFill(char board[N][N], int row, int col, bool helper[], int size){

     for(int i = 0; i < size; i++){

          if(helper[i])
               board[row][i + col] = '-';
     }
}


bool crossword(char board[N][N], string words[], int index, int size){

     if(index == size){
          for(int i = 0; i < N; i++){
               for(int j = 0; j < N; j++)
                    std::cout << board[i][j] << ' ';
               std::cout << '\n';
          }
          return true;
     }

     /*
     std::cout  << '\n';
     for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++)
               std::cout << board[i][j] << ' ';
          std::cout << '\n';
     }
     std::cout  << '\n';
     */

     string s = words[index];
     for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++){

               if(board[i][j] == '-' || board[i][j] == s[0]){

                    if(isVerticalPossible(board, s, i, j)){
                         bool helper[s.length()];
                         setHelper(helper, s.length());
                         fillVertical(board, s, i, j, helper);

                         if(!crossword(board, words, index + 1, size))
                              resetVerticalFill(board, i, j, helper, s.length());


                    }

                    if(isHorizontalPossible(board, s, i, j)){
                         bool helper[s.length()];
                         setHelper(helper, s.length());
                         fillHorizontal(board, s, i , j , helper);

                         if(!crossword(board, words, index + 1, size))
                              resetHorizontalFill(board, i, j, helper, s.length());
                    }
               }
          }
     }

     return false;
}

int main(){

     char board[N][N];
     vector<string> arr;
     for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++)
               cin >> board[i][j];
     }

     string s,w;
     cin >> w;

     for(auto x : w){

          if(x == ';'){
               arr.push_back(s);
               s = "";
          }else
               s+=x;
     }

     arr.push_back(s);

     string words[arr.size()];

     for(int i = 0; i < arr.size(); i++)
          words[i] = arr[i];

     crossword(board, words, 0, 4);
}

/*

+-++++++++
+-++++++++
+-------++
+-++++++++
+-++++++++
+------+++
+-+++-++++
+++++-++++
+++++-++++
++++++++++

+E++++++++
+N++++++++
+GWALIOR++
+L++++++++
+A++++++++
+NORWAY+++
+D+++G++++
+++++R++++
+++++A++++
++++++++++


+-++++++++
+-++++++++
+-++++++++
+-----++++
+-+++-++++
+-+++-++++
+++++-++++
++------++
+++++-++++
+++++-++++

+L++++++++
+O++++++++
+N++++++++
+DELHI++++
+O+++C++++
+N+++E++++
+++++L++++
++ANKARA++
+++++N++++
+++++D++++

*/

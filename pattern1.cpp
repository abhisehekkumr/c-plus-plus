#include<iostream>
using namespace std;
void printPatt(int n)
{
    int spaces = 0;
    int s = n;
    n++;
    while(n){

        for(int i = 1; i <=s; i++)
            cout <<" ";
        for(int i = spaces; i > 0; i--)
           	cout << i;
        cout << 0;

        for(int i = 1; i <= spaces; i++)
        	cout << i;
        cout << endl;
        spaces++;
        s--;
        n--;
    }
}

int main(){

	int n;
    cin >> n;
    printPatt(n);
/*
    int spaces = n;
    int number = n;
    while(n){
        int j = 0;
        for(int i = n; i < number; i++){
            cout << i;
            j++;
        }

        for(int i = j; i < number; i++)
            cout << spaces;

        cout << endl;

        n--;
    }
    */
}

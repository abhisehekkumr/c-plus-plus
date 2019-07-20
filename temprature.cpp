#include<iostream>
using namespace std;


int temp(int f){

    float result = (f - 32)/1.8;
    return int(result);
}
int main(){

     int start, step, end;
    cin >> start;

    cin >> end;

    cin >> step;

    for(int i = start; i<=end; i += step)
        cout << i << '\t' << temp(i) << endl;
}

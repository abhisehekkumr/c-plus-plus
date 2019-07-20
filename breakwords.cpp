#include<bits/stdc++.h>
using namespace std;

void breakWords(char* );

int main()
{
	char str[100000];
	cin.getline(str,100000);
	breakWords(str);
	cout<<str;
}



void breakWords(char* S)
{
	/*
	 * Don't write main.
	 * Don't return or print anything.
	 * Changes should be done in the given string.
	*/
     std::cout << S << '\n';
    char arr[20000];
    int count = 1;
    int start = 0;
    int j=0,i,mid;
    int n = strlen(S);

    for(i=0;i<=n;i++)
    {

       // cout<<count;
     // std::cout << arr << '\n';
        if(S[i]==' ' || S[i]=='\0')
           {
                --count;
             //cout<<count << endl;

               if((count>4) && (count%2==0))
               {

                   mid = count/2;
                   while(j<mid);
                   {

                   arr[start] = S[j];
                   std::cout << arr[start] << "inside" << '\n';
                       start++;
                       j++;
                   }
                   arr[start] =' ';
                   start++;
                   while(j < i)
                   {
                        //std::cout << "this" << arr[start] << "inside" << '\n';
                       arr[start]= S[j];
                       start++;
                       j++;
                   }
                 //  cout<<arr;
               }
                else
                {
                    while(j< i-1)
                   arr[start]=S[j];
                    start++;
                    j++;
                }
            //cout<<arr;
             count = 1;

           }

            j = i+1;
            count++;
    }
    arr[start] = '\0';
    //std::cout << S << '\n';
    strcpy(S, arr);
    //cout<<S;
}

/*
Helloo world good morniing
*/

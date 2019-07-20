#include<stack>
int countBracketReversals(char input[]){

    stack<char> s;
    int count = 0;
    int i = 0;


    while(input[i] != '\0'){

        if(input[i] == '{')
            s.push(input[i]);
        else{

            if(!s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(input[i]);
        }
        i++;
    }

    if(s.empty())
        return 0;

    if(s.size() & 1)
        return -1;

    while(!s.empty()){
        char c1 = s.top();
        s.pop();
        char c2 = s.top();
        s.pop();

        if(c1 == c2)
            count += 1;
        else
            count += 2;
    }

    return count;
}

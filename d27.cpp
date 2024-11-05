#include <iostream>
#include <ctype.h>
using namespace std;

class stack
{
    int top;
    char data[20];

    public:
        stack()
        {
            top=-1;
        }

        void conversion(char in[20], char p[20]){
            int i, j=0;
            char e,t,x;

            for(i=0; in[i]!='\0';i++)
            {
                t=in[i];
                if(isalnum(t)){
                    p[j]=t;
                    j++;
                }
                else{
                    if(t=='(')
                    push(t);
                    else if(t==')'){
                        while((x=pop())!='('){
                            p[j]=x;
                            j++;
                        }
                    }
                    else{
                        e=topmost();
                        while(precedence(t)<=precedence(e)&& !empty()){
                            x=pop();
                            p[j]=x;
                            j++;
                        }
                        push(t);
                    }
                }
            }

            while(!empty()){
                x=pop();
                p[j]=x;
                j++;
            }
            p[j]='\0';
        }

        void push(int x)
        {
            top++;
            data[top]=x;
        }

        int pop()
        {
            char x;
            x=data[top];
            top--;
            return x;
        }

        char topmost()
        {
            char e;
            e=data[top];
            return e;
        }

        int precedence(char x)
        {
            if(x=='(')
                return 0;
            if(x=='+'||x=='-')
                return 1;

            if(x=='*'||x=='/'||x=='%')
                return 2;
            else
            return 3;
        }

        int empty()
        {
            if(top==-1)
                return 1;
            else
                return 0;
        }
};

int main()
{
    stack s;
    char in[20],p[20];
    cout<<"enter infix expression:"<<endl;
    cin>>in;
    s.conversion(in,p);
    cout<<"postfix expression is:"<<p;
    return 0;
}

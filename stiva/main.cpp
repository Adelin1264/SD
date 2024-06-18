#include <iostream>
#include <cstring>
using namespace std;

struct stiva
{
    char value;
    stiva* next;
};

void push(stiva* &s, char val)
{
    stiva* x=new stiva;
    x->value=val;
    if(s==NULL)
    {
        x->next=NULL;
        s=x;
    }
    else
    {
        x->next=s;
        s=x;
    }
}

char top(stiva* s)
{
    return s->value;
}

void pop(stiva* &s)
{
    stiva* t=s;
    s=s->next;
    delete t;
}

bool empty(stiva* s)
{
    return s==NULL;
}

int main()
{
    int ctinchise1=0,ctdeschise1=0,ctinchise2=0,ctdeschise2=0,i;
    char c;
    string t;
    stiva* s=NULL;
    cin>>t;
    for(i=0;i<t.size();i++)
        push(s,t[i]);
    while(!empty(s))
    {
        c=top(s);
        if(c=='(')
            ctdeschise1++;
        if(c==')')
            ctinchise1++;
        if(c=='[')
            ctdeschise2++;
        if(c==']')
            ctinchise2++;
        pop(s);
    }
    cout<<ctinchise1<<" "<<ctdeschise1<<" "<<ctinchise2<<" "<<ctdeschise2<<endl;
    if(ctdeschise1==ctinchise1 && ctdeschise2==ctinchise2)
        cout<<"DA";
    else cout<<"NU";
}

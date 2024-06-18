#include <iostream>

using namespace std;

struct nod
{
    int val;
    nod* next;
};

int sz=0;
nod *x,*p;

void addStart(nod* &start, nod* &end, int value)
{
    x=new nod;
    x->val=value;
    x->next=start;
    start=x;
    sz++;
}

void addEnd(nod* &start, nod* &end, int value)
{
    x=new nod;
    x->val=value;
    x->next=NULL;
    end->next=x;
    end=x;
    sz++;
}

void addPosition(nod* &start, nod* &end, int pos, int value)
{
    int i=1;
    if(pos<1||pos>sz+1)
        cout<<"Pozitie invalida";
    else
    {
        if(pos==1)
            addStart(start, end, value);
        else if(pos==sz+1)
            addEnd(start, end, value);
        else
        {
            x=new nod;
            x->val=value;
            p=start;
            while(i<pos-1)
            {
                p=p->next;
                i++;
            }
            x->next=p->next;
            p->next=x;
            sz++;
        }
    }
}

void afis(nod* p)
{
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
}


    int main()
{
    int i;
    nod* start=NULL;
    nod* end=NULL;
    for(i=1;i<=10;i++)
        if(start==NULL)
        {
            addStart(start, end, i);
            end=start;
        }
        else
            addEnd(start, end,i);
    addPosition(start, end, 1, 100);
    afis(start);
}

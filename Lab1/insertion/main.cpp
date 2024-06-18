#include <iostream>

using namespace std;

struct nod
{
    int val;
    nod* next;
};

int sz=0;
nod *x,*p;
nod *start0=NULL;
nod *end0=NULL;

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

int cautare(nod *start, nod *end,int value)
{
    int pozitie=1;
    p=start;
    while(p!=NULL)
    {
        if(p->val>=value)
            return pozitie;
        pozitie++;
        p=p->next;
    }
    return pozitie;
}

void insertion()
{
    int n,i,nr,poz;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>nr;
        if(start0==NULL)
        {
            x=new nod;
            x->val=nr;
            x->next=NULL;
            start0=x;
            end0=start0;
            sz++;
        }
        else
        {
            poz=cautare(start0,end0,nr);
            addPosition(start0,end0,poz,nr);
        }
    }
}

int main()
{
    insertion();
    afis(start0);
}

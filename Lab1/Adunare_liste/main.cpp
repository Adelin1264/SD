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

void adunare_liste(nod* start1, nod* end1, nod* start2, nod* end2, nod* &start3, nod* &end3)
{
    int sum;
    while(start1!=NULL && start2!=NULL)
    {
        sum=start1->val+start2->val;
        if(start3==NULL)
        {
            addStart(start3, end3, sum);
            end3=start3;
        }
        else
            addEnd(start3, end3, sum);
        start1=start1->next;
        start2=start2->next;
    }
    while(start1!=NULL)
    {
        sum=start1->val;
        addEnd(start3, end3, sum);
        start1=start1->next;
    }
    while(start2!=NULL)
    {
        sum=start2->val;
        addEnd(start3, end3, sum);
        start2=start2->next;
    }
}

int main()
{
    int i,a,b,nr;
    nod* start1=NULL;
    nod* end1=NULL;
    nod* start2=NULL;
    nod* end2=NULL;
    nod* start3=NULL;
    nod* end3=NULL;
    cin>>a;
    for(i=1;i<=a;i++)
    {
        cin>>nr;
        if(start1==NULL)
        {
            addStart(start1, end1, nr);
            end1=start1;
        }
        else
            addEnd(start1, end1, nr);
    }
    cin>>b;
    for(i=1;i<=b;i++)
    {
        cin>>nr;
        if(start2==NULL)
        {
            addStart(start2, end2, nr);
            end2=start2;
        }
        else
            addEnd(start2, end2, nr);
    }
    adunare_liste(start1, end1, start2, end2, start3, end3);
    afis(start3);
}


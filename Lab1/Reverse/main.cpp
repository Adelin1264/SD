#include <iostream>

using namespace std;

struct nod
{
    int val;
    nod* next;
};

int sz=0;
nod *x;

void Reverse(nod* &start, nod* &end)
{
    nod *st=start;
    nod *dr=start->next;
    start->next=NULL;
    while(dr!=NULL)
    {
        x=new nod;
        x=dr->next;
        dr->next=st;
        st=dr;
        dr=x;
    }
    end=start;
    start=st;
}

void afisare(nod* p)
{
    if(p == NULL)
        cout << "Lista vida";
    else
        while(p != NULL)
        {
            cout << p -> val << ' ';
            p = p -> next;
        }
    cout << '\n';
}

int main()
{
    int i;
    nod* start=NULL;
    nod* end=NULL;
    for(i=1;i<=10;i++)
    {
        x=new nod;
        x->val=i;
        x->next=NULL;
        sz++;
        if(start==NULL)
        {
            start=x;
            end=start;
        }
        else
        {
            end->next=x;
            end=x;
        }
    }
    Reverse(start,end);
    afisare(start);
}

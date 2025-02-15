#include<bits/stdc++.h>
using namespace std;

ifstream in("heap_sort.in");
ofstream out("heap_sort.out");

int v[1000000];

void heapify(int n,int i)
{
    int largest=i,l=2*i+1,r=2*i+2;
    if (l < n && v[l]>v[largest])
        largest=l;
    if (r<n && v[r]>v[largest])
        largest=r;
    if(largest!=i)
    {
        swap(v[i],v[largest]);
        heapify(n,largest);
    }
}

void heapSort(int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(n,i);
    for(int i=n-1;i>=0;i--)
    {
        swap(v[0],v[i]);
        heapify(i,0);
    }
}

int main()
{
    int n;
    in>>n;
    for(int i=0;i<n;i++)
        in>>v[i];
    heapSort(n);
    for(int i=0;i<n;i++)
        out<<v[i]<<" ";
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000;
int N, L, NR;
int A[maxn], Heap[maxn], Pos[maxn];

void push(int x)
{
    int aux;

    while (x/2 && A[Heap[x]]<A[Heap[x/2]])
    {
        aux = Heap[x];
        Heap[x] = Heap[x/2];
        Heap[x/2] = aux;

        Pos[Heap[x]] = x;
        Pos[Heap[x/2]] = x/2;
        x /= 2;
    }
}

void pop(int x)
{
    int aux, y = 0;

    while (x != y)
    {
        y = x;

        if (y*2<=L && A[Heap[x]]>A[Heap[y*2]]) x = y*2;
        if (y*2+1<=L && A[Heap[x]]>A[Heap[y*2+1]]) x = y*2+1;

        aux = Heap[x];
        Heap[x] = Heap[y];
        Heap[y] = aux;

        Pos[Heap[x]] = x;
        Pos[Heap[y]] = y;
    }
}

int main()
{
    ifstream f("heapuri.in");
    ofstream g("heapuri.out");

    int i, x, cod;

    f>>N;

    assert(1<=N && N<=200000);

    for (i=1; i<=N; i++)
    {
        f>>cod;
        assert(1<=cod && cod<=3);
        if (cod < 3)
        {
            f>>x;
            assert(1<=x && x<=1000000000);
        }

        if (cod == 1)
        {
            L++, NR++;
            A[NR] = x;
            Heap[L] = NR;
            Pos[NR] = L;

            push(L);
        }

        if (cod == 2)
        {
            A[x] = -1;
            assert(Pos[x] != 0);
            assert(1<=x && x<=NR);
            push(Pos[x]);

            Pos[Heap[1]] = 0;
            Heap[1] = Heap[L--];
            Pos[Heap[1]] = 1;
            if (L>1) pop(1);
        }

        if (cod == 3) g<<A[Heap[1]]<<endl;
    }

    return 0;
}
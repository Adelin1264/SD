#include <bits/stdc++.h>

using namespace std;

struct nod {
    int info;
    nod* st;
    nod* dr;
};

void inserare(nod* &r, int x) {
    if(r == NULL) {
        r = new nod;
        r -> info = x;
        r -> st = NULL;
        r -> dr = NULL;
    } else {
        if(r -> info > x) {
            inserare(r -> st, x);
        } else {
            inserare(r -> dr, x);
        }
    }
}

bool cautare(nod* r, int x) {
    if(r == NULL) {
        return false;
    } else {
        if(r -> info == x) {
            return true;
        } else {
            if(r -> info > x) {
                return cautare(r -> st, x);
            } else {
                return cautare(r -> dr, x);
            }
        }
    }
}

void stergereAux(nod* &p, nod* &r) {
    if(p -> dr) {
        stergereAux(p -> dr, r);
    } else {
        r -> info = p -> info;
        nod* aux = p;
        p = p -> st;
        delete aux;
    }
}

void stergere(nod* &r, int x) {
    if(r != NULL) {
        if(r -> info == x) {
            if(r -> st == NULL && r -> dr == NULL) {
                r = NULL;
                //cout << "DA\n";
                delete r;
            } else {
                if(r -> dr == NULL) {
                    nod* aux = r;
                    r = r -> st;
                    delete aux;
                } else {
                    if(r -> st == NULL) {
                        nod* aux = r;
                        r = r -> dr;
                        delete aux;
                    } else {
                        stergereAux(r -> st, r);
                    }
                }
            }
        } else {
            if(r -> info > x) {
                stergere(r -> st, x);
            } else {
                stergere(r -> dr, x);
            }
        }
    }
}

void inordine(nod *r) {
    if(r != NULL) {
        inordine(r -> st);
        cout << r -> info << ' ';
        inordine(r -> dr);
    }
}

int main() {
    nod* r = NULL;
    inserare(r, 3);
    inserare(r, 4);
    inserare(r, 2);
    inserare(r, 10);
    inserare(r, 8);
    //inserare(r, 4);
    //inordine(r);
    stergere(r, 2);
    inordine(r);
    return 0;
}

https://www.pbinfo.ro/probleme/3010/bst
https://leetcode.com/problems/binary-tree-preorder-traversal/
https://leetcode.com/problems/binary-tree-postorder-traversal/
https://leetcode.com/problems/range-sum-of-bst/description/
https://leetcode.com/problems/maximum-depth-of-binary-tree/
https://leetcode.com/problems/balanced-binary-tree/
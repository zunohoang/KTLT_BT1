#include <bits/stdc++.h>
#define int long long
#define FOD(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define QUERY while(q--)
#define MOD 1000000007
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
void setup(){
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    fastIO
}

struct LinkedList{
    int value;
    LinkedList* next;
    LinkedList(int v, LinkedList* n) : value(v), next(n) {}
};

LinkedList* createNode(vector<int> x, int id){
    if(id >= x.size()) return nullptr;
    LinkedList* root = new LinkedList(x[id], createNode(x, id + 1));
    return root;
}

void show(LinkedList* root){
    if(root == nullptr) return;
    cout << root-> value << " ";
    show(root->next);
}

void deleteBack(LinkedList*& root){
    if(root->next == nullptr) {
        root = nullptr;
        return;
    }
    deleteBack(root->next);
}

void insertBack(LinkedList*& root, int value){
    if(root == nullptr){
        root = new LinkedList(value, nullptr);
        return;
    }
    insertBack(root->next, value);
}

void insertMid(LinkedList*& root, int index, int value){
    index -= 1;
    if(index == 0){
        LinkedList* mid = new LinkedList(value, root->next);
        root->next = mid;
        return;
    }
    insertMid(root->next, index, value);
}

void deleteMid(LinkedList*& root, int index){
    index -= 1;
    if(index == 1){
        root->next = root->next->next;
        return;
    }
    deleteMid(root->next, index);
}

signed main(){
    //setup();
    vector<int> x = {1,2,3,4,5};

    LinkedList* root = (LinkedList*)malloc(sizeof(LinkedList));
    root = createNode(x, 0);
    show(root);

    insertBack(root, 44);
    cout << endl;
    show(root);

    deleteBack(root);
    cout << endl;
    show(root);

    insertMid(root, 2, 222);
    cout << endl;
    show(root);

    deleteMid(root, 3);
    cout << endl;
    show(root);
    return 0;
}

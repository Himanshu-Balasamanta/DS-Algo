#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>

struct Node{
    ll val;
    ll sum;
    Node* parent;
    Node* ancestor;
    vector<Node*> children;
    ll path;
    ll pathAnc;
    Node(int x) : val(x), parent(nullptr), ancestor(nullptr){
        path = 0;
        pathAnc = 0;
    }
};

ll n,q,r, h, sqrth;
Node* root;
map<int,Node*>mp;
vi level;

void build(){
    vector<vector<ll>>b,a;
    ll i, j, x, y, z;
    cin>>n>>q>>r;
    a = vector<vll>(n + 1);
    b = vector<vector<ll>>(n + 1);
    vi mrk = vi(n + 1, 0);
    level = vi(n + 1, 0);
    for(i = 1; i != n; i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        a[x].push_back(y);
        a[y].push_back(x);
        b[x].push_back(z);
        b[y].push_back(z);
    }
    root = new Node(r);
    mp[r] = root;
    stack<int>st;
    st.push(r);
    mrk[r] = 1;
    level[r] = 1;
    Node* curr;
    h = 1;
    while(!st.empty()){
        x = st.top();
        curr = mp[x];
        st.pop();
        h = level[x];
        z = a[x].size();
        for(i = 0; i != z; i++){
            y = a[x][i];
            if(mrk[y])continue;
            mrk[y] = 1;
            st.push(y);
            level[y] = h + 1;
            mp[y] = new Node(y);
            mp[y]->parent = curr;
            curr->children.push_back(mp[y]);
            mp[y]->path = b[x][i];
        }
    }
    h = *max_element(level.begin(),level.end());
    sqrth = (int)sqrt(h);
}

void majora(Node* strt, int till){
    stack<Node*>st;
    st.push(strt);
    Node* curr;
    while(!st.empty()){
        curr = st.top();
        st.pop();
        int x = curr->val;
        if(level[x] == till){
            majora(curr,till + sqrth);
            continue;
        }
        for(auto nde : curr->children){
            nde->pathAnc = curr->pathAnc + nde->path - strt->pathAnc;
            st.push(nde);
        }
    }
}

void updateAnc(){

    Node* nde = root;
    Node* curr = root;
    stack<Node*>st;
    st.push(nde);
    while(!st.empty()){
        curr = st.top();
        st.pop();
        int x = curr->val;
        if(level[x] % sqrth == 0){
            majora(curr,level[x] + sqrth);
            continue;
        }
        for(Node* n : curr->children){
            st.push(n);
        }
    }
}

ll findAnsc(Node* nde1, Node* nde2){
    if(nde1 == nde2)return 0;
    int x = nde1->val, y = nde2->val;
    int lx = level[x], ly = level[y];
    if(nde1->ancestor == nde2->ancestor){
        if(lx > ly){
            return nde1->path + findAnsc(nde1->parent,nde2);
        }
        else{
            return nde2->path + findAnsc(nde1,nde2->parent);
        }
    }
    if(lx > ly){
        return nde1->pathAnc + findAnsc(nde1->ancestor,nde2);
    }
    return nde2->pathAnc + findAnsc(nde2->ancestor,nde1);
}

void solve(){

    int x, y, i;
    mp.clear();
    build();
    updateAnc();
    for(i = 0; i != q; i++){
        scanf("%d%d",&x,&y);
        ll ansc = findAnsc(mp[x],mp[y]);
        cout<<ansc<<'\n';
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
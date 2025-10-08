#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main(){

int N,E;
cin>>N>>E;

vector<int>U(E),V(E);
vector<long long>W(E);

for(int i =0; i<E; i++){

    cin>> U[i]>>V[i]>>W[i];
}

int S;
cin>>S;
int T;
cin>>T;


vector<int>D(T);
for(int i = 0;i<T; i++)
cin>>D[i];

vector<long long>dist(N+1,INF);
dist[S]=0;

for(int i=1;i<=N-1;i++){

    bool updated = false;


    for(int j=0;j<E;j++){

        if(dist[U[j]] !=INF && dist[U[j]]+W[j]<dist[V[j]])
{
dist[V[j]]=dist[U[j]]+W[j];
updated = true;

}

    }



    if(!updated)
    break;
}


for(int j=0;j<E;j++){

    if(dist[U[j]] !=INF && dist[U[j]]+W[j]<dist[V[j]]){

        cout<<"Negative Cycle Detected"<<endl;
        return 0;
    }
}

for(int i =0;i<T;i++){

    if(dist[D[i]]==INF)
    cout<<"Not Possible"<<endl;

    else
    cout<<dist[D[i]]<<endl;
}

return 0;
}
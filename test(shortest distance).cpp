#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
int main(){


    int N,E;
    cin>>N>>E;

    vector<vector<long long>>dist(N+1,vector<long long>(N+1,INF));

    for(int i=1;i<=N;i++) 
    dist[i][i]=0;

    for(int i =0;i<E;i++){
        int A,B;
        long long W;
        cin>>A>>B>>W;
        dist[A][B]=min(dist[A][B],W);
    }


    for(int k=1;k<=N;k++){
        for(int i =1;i<=N;i++){

         for(int j =1;j<=N;j++){
            if(dist[i][k]+dist[k][j]<dist[i][j]){
                dist[i][j]=dist[i][k]+dist[k][j];
            }
         }    
        }
    }



int Q;
cin>>Q;
while(Q--){

    int X,Y;
    cin>>X>>Y;
    if(dist[X][Y]==INF)
    cout<<-1<<"\n";
    else
    cout<<dist[X][Y]<<"\n";
}

return 0;


}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
int minKey(int key[], bool mstSet[]){
    int min = INT_MAX, minIdx;
    for(int v = 0;v<5;v++){
        if(!mstSet[v] && key[v] < min){
            min = key[v];
            minIdx = v;
        }
    }
    return minIdx;
}
void primMST(int graph[5][5]){
    int parent[5];
    int key[5];
    bool mstSet[5];
    for(int i = 0;i<5;i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int c = 0;c < 4 ;c++){
        int u = minKey(key, mstSet);
        mstSet[u]= true;
        for(int v = 0 ;v<5;v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
}

int main(){
    
    return 0;
}
#include<stdio.h>
#define M 10

int adjM[M][M];
int visited[M] = {0};
int parent[M];
int rank[M];

int find(int i)
{
    if(parent[i] == i)
    {
        return i;
    }
    
    parent[i] = find(parent[i]);
    return parent[i];
}

void union_sets(int x, int y)
{
    int r1 = find(x);
    int r2 = find(y);
    
    if(r1 != r2)
    {
        if(rank[r1] > rank[r2])
        {
            parent[r2] = r1;
        }
        
        else if(rank[r1] < rank[r2])
        {
            parent[r1] = r2;
        }
        
        else{
            parent[r2] = r1;
            rank[r1]++;
        }
    }
}

int main()
{
    int v;
    scanf("%d", &v);
    
    int arr1[100][3];
    int e = 0;
    
    for(int i=0; i<v; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            scanf("%d", &adjM[i][j]);
        }
    }
    
    for(int i=0; i<v; i++)
    {
        for(int j=i+1; j<v; j++)
        {
            if(adjM[i][j] != 0)
            {
                arr1[e][0] = i;
                arr1[e][1] = j;
                arr1[e][2] = adjM[i][j];
                e++;
            }
        }
    }
    
    for(int i=0; i<e-1; i++)
    {
        for(int j=0; j<e-1-i; j++)
        {
            if(arr1[j][2] > arr1[j+1][2])
            {
                int temp[3];
                for(int z=0; z<3; z++)
                {
                    temp[z] = arr1[j][z];
                    arr1[j][z] = arr1[j+1][z];
                    arr1[j+1][z] = temp[z];
                }
            }
        }
    }
    
    for(int i=0; i<e; i++)
    {
        int u1 = arr1[i][0];
        int u2 = arr1[i][1];
        int u3 = arr1[i][2];
        if(find(u1) != find(u2))
        {
            visited[u1] = 1;
            visited[u2] = 1;
            printf("%d -> %d\n", u1+1, u2+1);
            union_sets(u1,u2);
        }
    }
    
    
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define M 10
#define inf 99999
int adj[M][M];
int vis[M] = {0};
struct Table{
    int vertex;
    int visited;
    int dv;
    int pv;
}table[M];
int main(){
    int v, e;
    scanf("%d %d",&v, &e);
    for(int i = 0;i<v;i++){
        for(int j = 0;j<e;j++){
            adj[i][j] = 0;
        }
    }
    for(int i = 0;i<e;i++){
        int src, dest, k;
        scanf("%d %d %d",&src, &dest, &k);
        adj[src][dest] = k;
        adj[dest][src] = k;
    }
    for(int i = 0;i<v;i++){
        table[i].vertex = i;
        table[i].visited = 0;
        table[i].dv = inf;
        table[i].pv = -1;
    }
    int s, d;
    scanf("%d %d",s,d);
    table[s].dv = 0;
    table[s].pv = s;
    for(int count = 0;count < v;count++){
        int min = inf, u = -1;
        for(int i = 0;i<v;i++){
            if(!table[i].visited && table[i].dv < min){
                min = table[i].dv;
                u = i;
            }
        }
        table[u].visited = 1;
        for(int j = 0;j<v;j++){
            int dist = table[u].dv + adj[u][j];
            if(adj[u][v] && !table[j].visited && table[j].dv){
                table[j].dv = dist;
                table[j].pv = u;
            }
        }

    }
    printf("Shortest Path");
    if(table[d].pv == -1) printf("Not found");
    else{
        int path[M];
        int c = 0;
        for(int i = d;i!=s ;i = table[i].pv){
            path[c++] = i;

        }
        path[c] = s;
        for(int i = c;i>= 0;i--){
            printf("%d", path[i]);
            if(i > 0) printf(" -> ");

        }
        printf("\n");
        printf("Shortest distance: %d", table[d].pv);
    }
    return 0;
}

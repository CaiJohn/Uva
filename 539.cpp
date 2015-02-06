#include<stdio.h>
#include<string.h>

int graph[1000][1000];
int visited[1000][1000];
int max=0;
int search(int node, int depth,int node_num){
  
  //printf("start: %d\n",node);
  if(depth>max)
    max = depth;

  for(int i=0;i<node_num;i++){
    if(visited[node][i]==0 && visited[i][node]==0 && graph[node][i]==1){
      //printf("%d %d\n",node,i);
      visited[node][i] = 1;
      visited[i][node] = 1;
      search(i,depth+1,node_num);
      
      visited[node][i] = 0;
      visited[i][node] = 0;
    }
  }
  return 0;
}

int main(){
  
  int node,edge;
  while(true){
    
    scanf("%d %d",&node,&edge);
    if(node==0 && edge ==0)
      break;
    
    max = 0;
    memset(graph,0,1000*1000*sizeof(int));
    memset(visited,0,1000*1000*sizeof(int));
    for(int i=0;i<edge;i++){
      int from,to;
      scanf("%d %d",&from,&to);

      graph[from][to] = 1;
      graph[to][from] = 1;
    }
    
    for(int i=0;i<node;i++){
      search(i,0,node);
    }
    printf("%d\n",max);
  }
  return 0;
}
    

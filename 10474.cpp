#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b){
  return (*((int *) a))-(*((int *) b));
}

int main(){
  int n_marble=0,n_query=0;
  int marbles[10001],queries[10001];
  int counter = 0;
  while(true){
    scanf("%d %d",&n_marble,&n_query);
    if(n_marble==0 && n_query==0)
      {
	return 0;
      }
    
    counter++;
    for(int i=0;i<n_marble;i++){
      scanf("%d",&marbles[i]);
    }

    for(int i=0;i<n_query;i++){
      scanf("%d",&queries[i]);
    }
    
    qsort(marbles,n_marble,sizeof(int),cmp);
    
    printf("CASE# %d:\n",counter);
    for(int i=0;i<n_query;i++){
      int j;
      for(j=0;j<n_marble;j++){
	if(marbles[j]==queries[i]){
	  printf("%d found at %d\n",queries[i],j+1);
	  break;
	}
      }
      if(j==n_marble){
	printf("%d not found\n",queries[i]);
      }
    }

  }
  return 0;
}

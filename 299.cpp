#include<stdio.h>
int main(){
  int n_case;
  scanf("%d",&n_case);
  int trains[100];
  while(n_case>0){
    n_case --;
    
    int n_train;
    scanf("%d",&n_train);
    
    for(int i=0;i<n_train;i++){
      scanf("%d",&trains[i]);
    }
    
    int counter=0;
    bool changed = true;
    
    for(int i=0;i<n_train&&changed == true;i++){
      changed = false;
      for(int j=n_train-1;j>i;j--){
	if(trains[j]<trains[j-1]){
	  //printf("swap %d and %d\n",j,j-1);
	  int tmp;
	  tmp = trains[j-1];
	  trains[j-1] = trains[j];
	  trains[j] = tmp;
	  counter ++;
	  changed = true;
	}
      }
    }
    printf("Optimal train swapping takes %d swaps.\n",counter);
  }
}

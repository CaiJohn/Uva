#include<stdio.h>
int main(){
  
  int c_num,d_num,n_num;

  scanf("%d",&c_num);
  
  while(c_num>0){
    c_num--;
    int digits[200][20]={0};

    scanf("%d",&d_num);
    scanf("%d",&n_num);

    for(int i=0;i<n_num;i++){
      for(int j=0;j<d_num;j++){
	scanf("%d",&digits[i][j]);
      }
    }
    
    int note[20] = {0};
    for(int i=0;i<(1<<d_num);i++){

      int cur = i;
      int answer[200]={0};
      int counter = 0;
      for(int j=d_num-1;j>=0;j--){
	if(cur>=(1<<j)){
	  cur = cur - (1<<j);
	  
	  for(int k=0;k<n_num;k++){
	    answer[k] = answer[k] | (digits[k][j]<<counter);
	  }
	  counter ++;
	}
      }
      
      bool ok = true;
      for(int j=0;j<n_num;j++){
	for(int k=j+1;k<n_num;k++){
	  if(answer[j]==answer[k]){
	    ok = false;
	  }
	}
      }
      if(ok == true){
	note[counter] = 1;
      }
      
    }
    
    for(int i=1;i<=d_num;i++){
      if(note[i]==1){
	printf("%d\n",i);
	break;
      }
    }
  }
  return 0;
}
	  

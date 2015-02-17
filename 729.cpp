#include<stdio.h>
int len,dist;
void search(int answer[],int depth,int end,int last){
  //printf("depth:%d\n",depth);
  if(depth>=end){
    for(int i=len-1;i>=0;i--){
      bool set = false;
      for(int j=0;j<depth;j++){
	if(answer[j]==i){
	  set = true;
	  break;
	}
      }
      if(set==true){
	printf("1");
      }
      else{
	printf("0");
      }
    }
    printf("\n");
  }
  else{
    for(int i=0;i<last;i++){
      //printf("choose %d\n",i);
      answer[depth] = i;
      search(answer,depth+1,end,i);
    }
  }
  return;
}

int main(){
  
  int num;
  scanf("%d",&num);
  while(num>0){
    num --;
    
  
    scanf("%d %d",&len,&dist);
    int answer[100];
    search(answer,0,dist,len);
    if(num>0)
      printf("\n");
  }
  
  return 0;
}
  

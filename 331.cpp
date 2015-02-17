#include<stdio.h>
int answer;


void swap(int input[], int a,int b){
  int tmp = input[a];
  input[a] = input[b];
  input[b] = tmp;
  return;
}

int bubble(int input[],int length){
  
  bool tag = true;
  int counter = 0;
  for(int i=0;i<length-1 && tag == true;i++){
    tag = false;
    for(int j=0;j<length-i-1;j++){
      if(input[j]>input[j+1]){
	tag = true;
	counter ++;
	swap(input,j,j+1);
      }
    }
  }
  return counter;
}

void search(int input[],int length,int depth,int max){

  if(depth==max){
    //printf("depth:%d\n",depth);
    
    int ok = true;
    for(int i=0;i<length-1;i++){
      //printf("input[%d]:%d ",i,input[i]);
      if(input[i]>input[i+1]){
	ok = false;
	break;
      }
    }
    //printf("\n");
    if(ok==true)
      answer ++;
    return;
  }
  else{
    for(int i=0;i<length-1;i++){
      swap(input,i,i+1);
      // for(int k=0;k<length;k++){
      // 	printf("input[%d]:%d ",k,input[k]);
      // }
      // printf("\n");
      search(input,length,depth+1,max);
      swap(input,i,i+1);
    }
  }
  return;
}
    
int main(){
  
  int counter = 0;
  while(true){
    counter ++;
    int num;
    int input[10];
    scanf("%d",&num);
    if(num == 0){
      break;
    }

    for(int i=0;i<num;i++){
      scanf("%d",&input[i]);
    }

    int tmp_input[10];
    for(int i=0;i<num;i++){
      tmp_input[i] = input[i];
    }

    int max_swap = bubble(tmp_input,num);
    //    printf("max_swap: %d\n",max_swap);
    answer = 0;
    if(max_swap>0)
      search(input,num,0,max_swap);
    
    printf("There are %d swap maps for input data set %d.\n",answer,counter);
  }
  return 0;
}

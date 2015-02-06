#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
using namespace std;
int answer[1000]={0};
int search(int pos){
  
  //printf("pos: %d, cur %d, depth %d tree %d\n",pos,cur,depth,tree[cur]);
  int tmp;
  scanf("%d",&tmp);
  if(tmp==-1){
    return -1;
  }
  else{
    answer[pos] = answer[pos] + tmp;
    search(pos-1);
    search(pos+1);
    return 1;
  }
}
  
int main(){
  
  //string input;
  //istringstream iss;
  int c_num = 0;
  while(true){
    c_num++;
    memset(answer,0,1000*sizeof(int));
    //iss.clear();
    //getline(cin,input);
    
    
    //iss.str(input);
    int tmp;
    int counter = 0;
    //int tree[1000];
    // while(iss>>tmp){
    //   tree[counter] = tmp;
    //   counter ++;
    // }
    
    if(counter==1 && tmp == -1){
      break;     
    }

    if(search(500)==-1)
      break;
    
    printf("Case %d:\n",c_num);
    bool tag = true;
    for(int i=0;i<1000;i++){
      if(answer[i]>0){
	if(tag==false){
	  printf(" ");
	}
	tag = false;
	printf("%d",answer[i]);
      }
    }
    printf("\n\n");
  }
  return 0;
}
    

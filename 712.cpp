#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
  
  int counter = 0;
  while(true){
    int level;
    scanf("%d",&level);
    //printf("level\n");

    if(level == 0)
      break;

    counter ++;

    char input[5];
    int order[100];
    for(int i=0;i<level;i++){
      scanf("%s",input);
      order[i] = input[1]-'1';
    }    

    // for(int k = 0;k<level;k++)
    //   printf("%d",order[k]);
    // printf("\n");
    scanf("\n");

    string leaves;
    getline(cin,leaves);

    int num;
    scanf("%d\n",&num);
    int answer[100];
    
    for(int i=0;i<num;i++){
      
      string seq_input;
      int seq[5000];
      getline(cin,seq_input);
      
      for(int j=0;j<level;j++){
	seq[j] = seq_input[order[j]]=='0'? 0 : 1;
      }

      // for(int k = 0;k<level;k++)
      // 	printf("%d",seq[k]);
      // printf("\n");

      
      
      int start = 0, end = (1<<level)-1;
      for(int j=0;j<level;j++){
	
	if(seq[j]==0){
	  end = (start+end)/2;
	}
	else{
	  start = (start+end)/2+1;
	}
      }
      answer[i] = leaves[start]=='0'? 0 : 1;
    }
    printf("S-Tree #%d:\n",counter);
    for(int i=0;i<num;i++){
      printf("%d",answer[i]);
    }
    printf("\n\n");
  }
  return 0;
}
      
      

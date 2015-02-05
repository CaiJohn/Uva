#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int cmp(const void* a, const void* b){
  return (* ((char *) a)) - (* ((char *) b));
}

void search(char* answer, char* base, int cur, int end){
  if(cur == end){
    for(int i=0;i<end;i++){
      printf("%c",answer[i]);
    }
    printf("\n");
    return;
  }
  else{
    for(int i=0;i<end;i++){
      bool ok = true;
      for(int j=0;j<cur;j++){
	if(answer[j]==base[i]){
	  ok = false;
	  break;
	}
      }
      if(ok == true){
	answer[cur] = base[i];
	search(answer,base,cur+1,end);
      }
    }
  }
  return;
}

int main(){
  
  int c_num;
  scanf("%d\n",&c_num);

  while(c_num>0){
    c_num --;
    string input;
    char base[100];
    getline(cin,input);
    
    strcpy(base,input.c_str());

    
    qsort(base,strlen(base),sizeof(char),cmp);
    char answer[100];
    //search(answer,base,0,strlen(base));
    do{
      for(int i=0;i<strlen(base);i++){
	printf("%c",base[i]);
      }
      printf("\n");
    }while(next_permutation(base,base+strlen(base)));
    printf("\n");
  }
  return 0;
}
    

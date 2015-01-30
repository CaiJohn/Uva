#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int cmp(const void* a,const void* b){
  return (*((char *) a))-(*((char *) b));
}

int main(){
  
  string tmp_input;
  char input[55];
  while(true){
    getline(cin,tmp_input);
    
    strcpy(input,tmp_input.c_str());//!!!!!

    if(input[0]=='#')
      break;
    

    int len = strlen(input);
    
    int tag = false;
    for(int i=len-1;i>=0;i--){
      //printf("i=%d, c=%c\n",i,input[i]);
      char max_c = 'z'+1;
      int pos = -1;
      for(int j=i+1;j<len;j++){
	if(input[j]>input[i] && input[j]<max_c){
	  max_c = input[j];
	  pos = j;
	}
      }
      if(pos!=-1){
	char tmp = input[i];
	input[i] = max_c;
	input[pos] = tmp;
	//printf("i==%d\n",i);
	//printf("len: %d %s\n",len-i-1,input+i+1);
	qsort(input+i+1,len-i-1,sizeof(char),cmp);
	//printf("len: %d %s\n",len-i-1,input+i+1);
	tag = true;
	break;
      }
    }
    if(tag == true){
      printf("%s\n",input);
    }
    else{
      printf("No Successor\n");
    }
  }
  return 0;
}
      
      
	

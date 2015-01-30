#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
int main(){
  
  string input;
  istringstream iss;
  while(getline(std::cin,input)){
    iss.clear();
    iss.str(input);
    
    int stack[99999];
    int sp = 0;
    int stack_v[99999];
    int sp_v = 0;
    int tmp=0;
    int volume = 0;
    int success = true;
    while(iss>>tmp){
      //printf("%d\n",tmp);
      if(tmp<0){
	if(sp>0){
	  if(stack_v[sp_v-1]-tmp<0){
	    stack[sp] = tmp;
	    sp++;
	    
	    
	    stack_v[sp_v] = tmp;
	    sp_v ++;
	    
	  }
	  else{
	    success = false;
	    break;
	  }
	}
	else{
	  stack_v[sp_v] = tmp;
	  sp_v ++;

	  stack[sp] = tmp;
	  sp++;
	}
      }
      else{
	if(sp>0){
	  int head = stack[sp-1];
	  sp = sp - 1;
	  if(head+tmp==0){
	    sp_v --;
	    stack_v[sp_v-1] = stack_v[sp_v-1]+tmp;
	    
	  }
	  else{
	    success = false;
	    break;
	  }
	}
	else{
	  success = false;
	  break;
	}
      }
    }
    if(success==true && sp == 0){
      printf(":-) Matrioshka!\n");
    }
    else{
      printf(":-( Try again.\n");
    }
  }
  return 0;
}
    
    
	
      
      
  

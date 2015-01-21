#include<iostream>
#include<sstream>
#include<string>
#include<stdio.h>
using namespace std;
int get_max(int a[],int head,int tail){
  int m = 0;
  int pos = -1;
  for(int i=head;i<tail+1;i++){
    if(a[i]>m){
      m = a[i];
      pos = i;
    }
  }
  return pos;
}

int swap(int a[],int head,int tail){
  int length = tail-head+1;
  int swap_end = (length-1)/2;
  int tmp;
  for(int i=0;i<=swap_end;i++){
    tmp = a[i+head];
    a[i+head] = a[length-1-i+head];
    a[length-1-i+head] = tmp;
  }
  return 0;
}
    
  
int main(){
  string input;
  istringstream iss;
  int pancakes[1000];
  while(getline(cin,input)){
    iss.clear();
    iss.str(input);
    
    int answer[1000];
    int tmp;
    int counter=0;
    while(iss>>tmp){
      pancakes[counter] = tmp;
      counter++;
    }

    for(int i=0;i<=counter-1;i++){
      printf("%d",pancakes[i]);
      if(i<counter-1)
	printf(" ");
      else
	printf("\n");
    }
    
    swap(pancakes,0,counter-1);

    
	
    int a_counter = 0;
    for(int i=0;i<counter;i++){
      int pos = get_max(pancakes,i,counter-1);


      if(pos==i)
	continue;
      if(pos!=counter-1){
	answer[a_counter] = pos+1;
	a_counter++;
	swap(pancakes,pos,counter-1);
      }
      answer[a_counter] = i+1;
      a_counter++;
      swap(pancakes,i,counter-1);
      
    }
    for(int i=0;i<a_counter;i++){
      printf("%d ",answer[i]);
    }
    printf("0\n");
    
  }
  return 0;
}
    
    

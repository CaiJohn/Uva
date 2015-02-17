#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int max_path = 200000000;
int answer = -1;

void search(int inorder[],int from_in,int to_in,int postorder[],int from_post,int to_post,int value){
  
  //printf("from %d to %d, from %d to %d\n",from_in,to_in,from_post,to_post);
  if(from_in==to_in && from_post == to_post){
    value = value + inorder[from_in];
    if(value<max_path){
      max_path = value;
      answer = inorder[from_in];
    }
    return;
  }
  else{
    int root_pos = -1;
    for(int i = from_in;i<=to_in;i++){
      if(inorder[i] == postorder[to_post]){
	root_pos = i;
	break;
      }
    }
    
    //right
    if(root_pos<to_in)
      search(inorder,root_pos+1,to_in,postorder,to_post-(to_in-root_pos),to_post-1,value+inorder[root_pos]);
    //left
    if(root_pos>from_in)
      search(inorder,from_in,root_pos-1,postorder,from_post,(to_post-(to_in-root_pos))-1,value+inorder[root_pos]);
    return;
  }
}

int main(){
  istringstream iss;
  string input1,input2;
  
  while(getline(cin,input1)){
    max_path = 200000000;
    answer = -1;
    getline(cin,input2);

    iss.clear();
    iss.str(input1);
    int inorder[20000],postorder[20000];
    int counter = 0;
    int tmp;

    while(iss>>tmp){
      inorder[counter] = tmp;
      counter++;
    }

    iss.clear();
    iss.str(input2);
    counter = 0;
    while(iss>>tmp){
      postorder[counter] = tmp;
      counter++;
    }
    search(inorder,0,counter-1,postorder,0,counter-1,0);
    
    printf("%d\n",answer);
  }
  return 0;
}
    

#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int min_b = 99999;
int graph[30][30];
int nodes[30];
int result[30];

bool a_less_b(int a[],int b[],int length){
  int i;
  for(i=0;i<length;i++){
    if(a[i]!=b[i]){
      break;
    }
  }
  return a[i]<b[i];
}

void search(int depth, int answer[],int end,int bandwidth){
  //printf("depth: %d\n",depth);
  if(depth>=end){
    // printf("hit\n");
    if(bandwidth < min_b){
      min_b = bandwidth;
      for(int i=0;i<end;i++){
	//printf("result: %c, answer: %c ||",result[i]+'A',answer[i]+'A');
	result[i] = answer[i];
      }
    }
    else{
      if(bandwidth == min_b){
	if(a_less_b(answer,result,end)==true){
	  for(int i=0;i<end;i++){
	    //printf("result: %c, answer: %c ||",result[i]+'A',answer[i]+'A');
	    result[i] = answer[i];
	  }
	  //printf("\n");
	}
      }
    }
    return;
  }
  else{
    for(int i=0;i<end;i++){
      bool ok = true;
      for(int j=0;j<depth;j++){
	if(answer[j]==nodes[i]){
	  ok = false;
	  break;
	}
      }
      if(ok == true){
	int tmp_bandwidth = 0;
	for(int j=0;j<depth;j++){
	  if(graph[nodes[i]][answer[j]] == 1){
	    if(tmp_bandwidth<depth-j){
	      tmp_bandwidth = depth-j;
	    }
	  }
	}
	if(tmp_bandwidth>min_b){
	  continue;
	}
	else{
	  answer[depth] = nodes[i];
	  bandwidth = bandwidth>tmp_bandwidth?bandwidth:tmp_bandwidth;
	  search(depth+1,answer,end,bandwidth);
	}
      }
    }
  }
  return;
}

int main(){
  
  string input;
  while(true){
    
    getline(cin,input);

    if(input.length()==1 && input[0]=='#'){
      break;
    }

    min_b = 99999;
    for(int i=0;i<30;i++){
      result[i] = 99999;
      for(int j=0;j<30;j++){
	graph[i][j] = 0;
      }
    }
    
      int counter=0;
      int node_num = 0;
      while(counter<input.length()){
	int from = input[counter] - 'A';
	bool new_node = true;
	for(int i=0;i<node_num;i++){
	  if(nodes[i]==input[counter]-'A'){
	    new_node = false;
	    break;
	  }
	}
	if(new_node==true){
	  nodes[node_num] = input[counter]-'A';
	  node_num++;
	}
	//printf("input:%c,counter:%d\n",input[counter],counter);
      
	// skip semicolon
	counter = counter + 2;
      
	while(counter<input.length() && input[counter]!=';'){
	  //printf("input:%c,counter:%d\n",input[counter],counter);
	  graph[from][input[counter]-'A'] = 1;
	  graph[input[counter]-'A'][from] = 1;
	  
	  bool new_node = true;
	  for(int i=0;i<node_num;i++){
	    if(nodes[i]==input[counter]-'A'){
	      new_node = false;
	      break;
	    }
	  }
	  if(new_node==true){
	    nodes[node_num] = input[counter]-'A';
	    node_num++;
	  }
	  counter ++;
	}
	counter ++;
      }

      // for(int i=0;i<node_num;i++){
      // 	printf("%c ",nodes[i]+'A');
      // }
   
      int answer[30]={0};
      search(0,answer,node_num,0);
      for(int i=0;i<node_num;i++){
	printf("%c ",result[i]+'A');
      }
      printf("-> %d\n",min_b);
    
    }
    return 0;
  }
      

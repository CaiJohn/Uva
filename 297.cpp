#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

typedef struct TNode{
  char node_type;
  TNode* child[4];
} Node;

Node* new_node(char node_type){
  Node* node = new Node();
  
  node->node_type = node_type;
  for(int i=0;i<4;i++){
    node->child[i] = NULL;
  }
  return node;
}

Node* build_tree(string input,int& pos){
  
  //printf("pos: %d input[pos]:%c\n",pos,input[pos]);
  Node* tmp_node = new_node(input[pos]);

  for(int i=0;i<4;i++){
    pos ++;
    
    //printf("pos: %d input[pos]:%c\n",pos,input[pos]);
    if(input[pos]=='p'){
      tmp_node->child[i] = build_tree(input,pos);
    }
    else{
      tmp_node->child[i] = new_node(input[pos]);
    }
  }
  return tmp_node;
}
      
Node* merge_tree(Node* root1, Node* root2){
  //printf("merge\n");
  //printf("root1 :%c root2:%c\n",root1->node_type,root2->node_type);
  if(root1->node_type == 'f' || root2 ->node_type == 'e'){
    return root1;
  }
  else{
    if(root2->node_type == 'f' || root1 ->node_type == 'e'){
      return root2;
    }
    else{
      Node* new_root = new_node('p');
      for(int i=0;i<4;i++){
	new_root->child[i] = merge_tree(root1->child[i],root2->child[i]);
      }
      return new_root;
    }
  }
}

int search_tree(Node* root,int depth){
  if(root->node_type=='e'){
    return 0;
  }
  else{
    if(root->node_type == 'f'){
      int answer = 1024;
      for(int i=0;i<depth;i++){
	answer = answer/4;
      }
      return answer;
    }
    else{
      return search_tree(root->child[0],depth+1) + search_tree(root->child[1],depth+1) + search_tree(root->child[2],depth+1) + search_tree(root->child[3],depth+1);
    }
  }
  
}

void print(Node* root){
  if(root->node_type=='p'){
    printf("p");
    for(int i=0;i<4;i++){
      print(root->child[i]);
    }
  }
  else{
    printf("%c",root->node_type);
  }
}
			       

int main(){
  
  int c_num;
  scanf("%d\n",&c_num);

  while(c_num>0){
    c_num --;

    string input1, input2;
    getline(cin,input1);
    getline(cin,input2);
    int pos = 0;
    Node* root1 = build_tree(input1,pos);
    pos = 0;
    Node* root2 = build_tree(input2,pos);
    
    // printf("finish building\n");
    // print(root1);
    // printf("\n");
    // print(root2);
    // printf("\n");
    
    int answer = search_tree(merge_tree(root1,root2),0);
    printf("There are %d black pixels.\n",answer);
  }
  return 0;
}
    
    
    


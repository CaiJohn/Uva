#include<stdio.h>
#include<iostream>
#include<string>
#include<cctype>
struct Node{
  char value;
  Node* left;
  Node* right;
  Node(){
    left = NULL;
    right = NULL;
  }
  Node(char v, Node* l, Node* r){
    value = v;
    left = l;
    right = r;
  }
  Node(Node* a){
    value = a->value;
    left = a->left;
    right = a->right;
  }
};

int main(){
  
  int num;
  scanf("%d\n",&num);
  
  while(num>0){
    num--;
    
    std::string input;
    
    getline(std::cin,input);
    
    int length = input.length();

    Node stack[20000];
    int sp = 0;
    for(int i=0;i<length;i++){
      
      if(islower(input[i])){
	Node tmp_node = Node(input[i],NULL,NULL);
	stack[sp] = tmp_node;
	sp++;
	//printf("sp = %d, input[i] = %c\n",sp,input[i]);
      }
      else{
	//printf("sp = %d, input[i] = %c\n",sp,input[i]);
	Node* tmp_node = new Node(input[i],NULL,NULL);
	Node* tmp_right = new Node(&stack[sp-1]);
	Node* tmp_left = new Node(&stack[sp-2]);

	sp = sp - 2;
	tmp_node->right = tmp_right;
	tmp_node->left = tmp_left;
	stack[sp] = *tmp_node;
	sp++;

	// // Wrong way
	// Node tmp_node = Node(input[i],NULL,NULL);
	// Node tmp_right = stack[sp-1];
	// Node tmp_left = stack[sp-2];
	// sp = sp - 2;
	// tmp_node.right = &tmp_right;
	// //printf("tmp_right:%c\n",(*(tmp_node.right)).value);
	// tmp_node.left = &tmp_left;
	// //printf("tmp_left:%c\n",(*(tmp_node.left)).value);
	// stack[sp] = tmp_node;
	// sp++;
	
      }
    }
    
    char r_answer[10001];
    int len_answer = 0;
    int head=0, tail=1;
    while(head!=tail){
      Node tmp_head = stack[head];
      r_answer[len_answer] = tmp_head.value;
      //printf("queue head: %c\n",tmp_head.value);
      len_answer ++;
      head = (head + 1)%20000;
      if(!islower(tmp_head.value)){
	stack[tail] = *(tmp_head.left);
	//printf("put right: %c\n",(*(tmp_head.right)).value);
	tail = (tail + 1)%20000;
	stack[tail] = *(tmp_head.right);
	//printf("put left: %c\n",(*(tmp_head.left)).value);
	tail = (tail + 1)%20000;
      }
    }
    
    //printf("length: %d\n",len_answer);
    //printf("string: %s\n",r_answer);
    for(int i=len_answer-1;i>=0;i--){
      printf("%c",r_answer[i]);
    }
    printf("\n");
      
  }
  return 0;
}

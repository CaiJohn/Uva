#include<stdio.h>
#include<iostream>
struct matrix{
  int line;
  int col;
};

int main(){
  int num;
  matrix matrixs[30]; // 0->A, 1->B...

  scanf("%d\n",&num);
  
  char tmp_name;
  int tmp_line,tmp_col;
  for(int i=0;i<num;i++){
    scanf("%c %d %d\n",&tmp_name,&tmp_line,&tmp_col);
    matrixs[tmp_name-'A'].line = tmp_line;
    matrixs[tmp_name-'A'].col = tmp_col;
  }
  
  matrix stack[99999];
  int stack_head;
  
  std::string input;
  bool error = false;
  while(getline(std::cin,input)){
    error = false;
    int input_length = input.length();
    int answer = 0;
    stack_head = 0;
    for(int i=0;i<input_length;i++){
      //printf("input[i]: %c\n",input[i]);
      if(input[i]=='(')
	continue;
      if(input[i]==')'){
       
	stack_head--;
	matrix tmp_m1 = stack[stack_head];
	stack_head --;
	matrix tmp_m2 = stack[stack_head];
	if(tmp_m2.col != tmp_m1.line){
	  error = true;
	  break;
	}
	answer += tmp_m2.col  * tmp_m1.col * tmp_m2.line;
	
	matrix new_m;
	new_m.line = tmp_m2.line;
	new_m.col = tmp_m1.col;
	//printf("new line: %d, new col: %d\n",new_m.line,new_m.col);
	stack[stack_head] = new_m;
	stack_head++;
      }
      else{
     
	stack[stack_head] = matrixs[input[i]-'A'];
	stack_head ++;
      }
    }
    if(error==true)
      printf("error\n");
    else
      printf("%d\n",answer);
  }
  return 0;
}
      
      

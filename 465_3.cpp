#include<cstdlib>
#include<stdio.h>
#include<climits>
int main(){
  char num1[10000],num2[10000];
  char op;
  scanf("%s %c %s",num1,&op,num2);
  double n1,n2;
  n1 = atof(num1);
  n2 = atof(num2);
  int max_int = INT_MAX;
  printf("%s %c %s\n",num1,op,num2);
  if(n1>INT_MAX){
    printf("first number too big");
  }
  if(n2>INT_MAX){
    printf("second number too big");
  }
  double result;
  if(op=='+')
    result = n1 + n2;
  else
    result = n1 * n2;
  if(result>INT_MAX){
    printf("result too big");
  }
  
  
  return 0;
}

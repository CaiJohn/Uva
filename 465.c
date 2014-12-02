#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* big_add(char a[], char b[]){
  char *answer;
  int la = strlen(a);
  int lb = strlen(b);
  int ll = la>lb?la:lb;
  
  answer = (char*) malloc (ll+10);
  int tag = 0;
  int i;
  for(i=0;i<ll;i++){
    int tmpa;
    int tmpb;
    int tmpanswer;
    tag = 0;
    if(i<la)
      tmpa = a[la-i-1]-'0';
    else
      tmpa = 0;
    if(i<lb)
      tmpb = b[lb-i-1]-'0';
    else
      tmpb = 0;
    tmpanswer = (tmpa + tmpb + tag)%10;
    answer[i] = tmpanswer + '0';
    tag = (tmpa + tmpb + tag)/10;
  }
  int len=0;
  if(tag != 0){
    answer[ll] = '1';
    len = ll+1;
  }
  else{
    len = ll;
  }
  
  for(i=0;i<len/2;i++){
    char tmp;
    tmp = answer[len-i-1];
    answer[len-i-1] = answer[i];
    answer[i] = tmp;
  }
  answer[len] = '\0';
  return answer;
}
int main(){
  char num1[10000],num2[10000];
  char largest_int[1000];
  strcpy(largest_int,"2147483647");
  char operator=0;
  while(scanf("%s %c %s",num1,&operator,num2)){
    int tag = 0;
    if(strlen(num1)>strlen(largest_int)||((strlen(num1)==strlen(largest_int)&&strcmp(num1,largest_int)>0))){
      //printf("first number too big\n");
      tag = 1;
    }
    if(strlen(num2)>strlen(largest_int)||((strlen(num2)==strlen(largest_int)&&strcmp(num2,largest_int)>0))){
      //printf("%s\n",num2);
      printf("second number too big\n");
      tag = 1;
    }
    char* sum=big_add(num1,num2);
    if(tag || (strlen(sum)>strlen(largest_int)||((strlen(sum)==strlen(largest_int)&&strcmp(sum,largest_int)>0)))){
      //printf("%s\n",sum);
      printf("result too big\n");
    }
    if(sum){
      free(sum);
    }
  }
  return 0;
}

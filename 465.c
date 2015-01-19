#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
char* big_add(char *a, char *b){
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

char* big_times(char *input1,char *input2){
  int i;
  int j;
  int tag = 0;
  int l1 = strlen(input1);
  int l2 = strlen(input2);
  char answer[100000];
  char *tmp = (char*)(malloc(sizeof(char)*100000));
  strcpy(tmp,"0");
  int len=0;
  for(i=0;i<l1;i++){
    
    int m;
    for(m=0;m<i;m++){
      answer[m] = '0';
    }
    tag = 0;
    for(j=0;j<l2;j++){
      answer[i+j] = ((input1[i]-'0')*(input2[j]-'0')+tag)%10 + '0';
      tag = ((input1[i]-'0')*(input2[j]-'0')+tag)/10;
    }
    if(tag==0){
      len = l2+i;
    }
    else{
      len = l2+1+i;
      answer[len-1] = tag + '0';
    }
    answer[len] = '\0';
    int k;
    for(k=0;k<len/2;k++){
      char t;
      t = answer[k];
      answer[k] = answer[len-1-k];
      answer[len-1-k] = t;
    }
    char *for_free = NULL;
    for_free = tmp;

    tmp = big_add(tmp,answer);
    free(for_free);
  }

  return tmp;
}

int big_cmp(char *a,char *b){
  return (strlen(a)>strlen(b)||((strlen(a)==strlen(b)&&strcmp(a,b))));
}
int main(){
  
  char num1[30000],num2[30000];
  char largest_int[1000];
  sprintf(largest_int,"%d",INT_MAX);
  char operator=0;
  while(scanf("%s %c %s",num1,&operator,num2)){
    int tag = 0;
    printf("%s %c %s\n",num1,operator,num2);
    if(big_cmp(num1,largest_int)){
      printf("first number too big\n");
      tag = 1;
    }

    if(big_cmp(num2,largest_int)){
      printf("second number too big\n");
      tag = 1;
    }
    char* sum;

    if(tag == 1){
      printf("result too big\n");
    }
    else{
      sum=operator=='+'?big_add(num1,num2):big_times(num1,num2);
      if(big_cmp(sum,largest_int)){
	printf("result too big\n");
      }
    }
    if(sum){
      free(sum);
    }
  }
  return 0;
}

#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#define MAX_NUM 200
#define MAX_DIGIT 50
using namespace std;
int numbers[MAX_NUM][MAX_DIGIT];
int c_num,d_num,n_num;
  


int search(int result[], int n, int from, int cur){
  if(cur==n){
    //printf("hit\n");
    
    // for(int i=0;i<n;i++){
    //   printf("%d ",result[i]);
    // }
    //printf("\n");
    int part[50] = {0};
    for(int i=0;i<n_num;i++){
      for(int j=0;j<n;j++){
	//printf("%d",numbers[i][j]);
	if(numbers[i][result[j]]==1){
	  part[i] = part[i] | (1<<j);
	}
      }
      //printf("part: %d\n",part[i]);
    }
    bool tag = true;
    for(int i=0;i<n_num;i++){
      for(int j=i+1;j<n_num;j++){
	if(part[i]==part[j]){
	  tag = false;
	  break;
	}
      }
      if(tag == false){
	break;
      }
    }
    if(tag == true){
      //printf("Here! %d\n",n);
      return n;
    }
    else{
      if(cur==from){
	return -1;
      }
      else{
	return search(result,n+1,from,cur+1);
      }
    }
  }
  else{
    for(int i=0;i<from;i++){
      //printf("hit1\n");
      bool ok = true;
      for(int j=0;j<cur;j++){
	if(result[j]==i){
	  ok=false;
	}
      }
      if(ok==true){
	result[cur] = i;
	int tmp_result = search(result,n,from,cur+1);
	if(tmp_result!=-1){
	  return tmp_result;
	}
      }
    }
  }
  return -1;
}
      


int main(){
  //  int c_num;
  scanf("%d\n",&c_num);
  istringstream iss;
  string input;
  //int numbers[101][20];
  while(c_num>0){
    c_num --;
    //printf("here\n");
    //int d_num,n_num;
    scanf("%d\n",&d_num);
    scanf("%d\n",&n_num);
    
    for(int i=0;i<n_num;i++){
      iss.clear();
      
      getline(cin,input);
      iss.str(input);
      int tmp;
      int counter = 0;
      while(iss>>tmp){
	//printf("%d",tmp);
	numbers[i][counter] = tmp;
	counter++;
      }
    }
    // for(int i=0;i<n_num;i++){
    //   for(int j=0;j<d_num;j++){
    // 	printf("%d",numbers[i][j]);
    //   }
    //   printf("\n");
    // }
    int start = 0;
    int tmp = n_num;
    while(tmp>0){
      start ++;
      tmp = tmp>>1;
    }

    //printf("start:%d\n",start);
    int result[200] = {0};
    
    int tmp_result = search(result,start,d_num,0);
    
    printf("%d\n",tmp_result);	
  }
  return 0;
} 

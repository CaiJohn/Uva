// Some template for permutation production


#include<stdio.h>
#include<algorithm>
using namespace std;
int permutation(int* p,int cur,int n){
  if(cur==n){
    for(int i=0;i<n;i++){
      printf("%d ",p[i]);
      
    }
    printf("\n");
    return 1;
  }
  else{
    int answer = 0;
    for(int i=0;i<n;i++){
      bool ok = true;
      for(int j=0;j<cur;j++){
	if(p[j]==i){
	  ok = false;
	  break;
	}
      }
      if(ok==true){
	p[cur] = i;
	answer = answer + permutation(p,cur+1,n);
      }
    }
    return answer;
  }

}

int permutation_2(int* input,int* p,int cur,int n,int* note){
  if(cur==n){
    for(int i=0;i<n;i++){
      printf("%d ",p[i]);
    }
    printf("\n");
    return 1;
  }
  else{
    int answer = 0;
    for(int i=0;i<n;i++){
      //printf("i: %d\n",i);
      if(i==0 || input[i]!=input[i-1]){
	int c1=0,c2=0;
	for(int t=0;t<cur;t++){
	  if(p[t]==input[i])
	    c1++;
	}
	for(int t=0;t<n;t++){
	  if(input[t]==input[i])
	    c2++;
	}
	if(c1<c2){
	
	  p[cur] = input[i];
	  note[i] = 1;
	  //printf("pick %d\n",i);
	  answer += permutation_2(input,p,cur+1,n,note);
	  note[i] = 0;
	}
      }
    }
    return answer;
  }
}



int main(){
  
  // produce all the permutation between 1 and 10
  int p[100];
  // printf("answer: %d\n",permutation(p,0,5));
  char input[100] = {'a','b','a','c','a'};
  int note[100] = {0};
  //  sort(input,input+3);
  //printf("answer: %d\n",permutation_2(input,p,0,3,note));

  next_permutation(input,input+5);
  for(int i=0;i<5;i++){
    printf("%c ",input[i]);
  }
  printf("\n");
  return 0;
}

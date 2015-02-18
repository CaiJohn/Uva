#include<stdio.h>
bool possible = false;
int a[5] = {0};

void search(int cur, int answer[],int sum){

  if(cur>=5){
    if(sum == 23){
      possible = true;
    }
  }
  else{
    for(int i=0;i<5 && possible == false;i++){
      int c1=0;
      for(int j=0;j<cur;j++){
	if(answer[j] == a[i]){
	  c1 ++;
	}
      }
      int c2=0;
      for(int j=0;j<5;j++){
	if(a[j] == a[i]){
	  c2++;
	}
      }
      if(c1<c2){
	answer[cur] = a[i];
	int tmp_sum = 0;
	if(cur>0){
	  for(int j=0;j<3;j++){
	 
	    switch(j){
	    case 0:
	      tmp_sum = sum + a[i];
	      break;
	    case 1:
	      tmp_sum = sum - a[i];
	      break;
	    case 2:
	      tmp_sum = sum * a[i];
	      break;
	    }
	    if(tmp_sum>23)
	      continue;
	    else{
	      search(cur+1,answer,tmp_sum);
	    }
	  }
	}
	else{
	  tmp_sum = a[i];
	  if(tmp_sum>23){
	    continue;
	  }
	  else{
	    search(cur+1,answer,tmp_sum);
	  }
	}
      }   
    }
  }
  return;
}
      

int main(){
  
  while(true){
    possible = false;
    bool end = true;
    for(int i=0;i<5;i++){
      scanf("%d",&a[i]);
      if(a[i]!=0){
	end = false;
      }
    }
    if(end == true){
      break;
    }
    int answer[10] = {0};
    search(0,answer,0);
    
    if(possible==true){
      printf("possible\n");
    }
    else{
      printf("impossible\n");
    }
  }
  return 0;
}

    

    

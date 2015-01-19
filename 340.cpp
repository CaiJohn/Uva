#include<stdio.h>
int main(){
  int length=0;
  int guess[2000];
  int tmp_code[2000];
  int code[2000];
  int counter = 0;
  while(true){
    scanf("%d",&length);
    if(length == 0){
      return 0;
    }

    for(int i=0;i<length;i++){
      scanf("%d",&(code[i]));
    }
    bool first = true;
    counter ++;
    
    while(true){
      bool stop = true;
      int strong=0,weak=0;
      for(int i=0;i<length;i++){
	scanf("%d",&(guess[i]));
	if(guess[i]!=0)
	  stop = false;
      }
      if(stop == true){
	break;
      }
      else{
	for(int i=0;i<length;i++){
	  tmp_code[i] = code[i];
	}					
	//printf("length: %d\n",length);

	for(int i=0;i<length;i++){
	  if(guess[i]==tmp_code[i]){
	    strong++;
	    tmp_code[i] = -1;
	    guess[i]=-1;
	  }
	}
	for(int i=0;i<length;i++){
	    for(int j=0;j<length;j++){
	      if(guess[i]!=-1 && guess[i]==tmp_code[j]){
		//	printf("i:%d,j:%d\n",i,j);
		weak++;
		tmp_code[j] = -1;
		break;
	      }
	    }
	  }
	}
      if(first == true){
	printf("Game %d:\n",counter);
	first = false;
      }
      printf("    (%d,%d)\n",strong,weak);
    }
  }
  return 0;
  }
    

#include<stdio.h>
int main(){
  int n_case;
  int info[101];
  scanf("%d",&n_case);

  while(n_case>0){
    n_case --;
    
    int days,n_party;
    int answer = 0;
    int day_counter = 0;
    scanf("%d",&days);
    scanf("%d",&n_party);
    for(int i=0;i<n_party;i++){
      scanf("%d",&info[i]);
      //printf("info[%d]:%d\n",i,info[i]);
    }

    for(int i=1;i<=days;i++){
      
      bool hartal = false;
      for(int j=0;j<n_party;j++){
	if(i%info[j]==0){
	  hartal = true;
	  break;
	}
      }
      //printf("i:%d\n",i);
      if(hartal==true && day_counter!=5 && day_counter!=6){
	answer ++;
	//printf("hit!\n");
      }
      day_counter = (day_counter+1)%7;
    }
    printf("%d\n",answer);
  }
  return 0;
}
      

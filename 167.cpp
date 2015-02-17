#include<stdio.h>

int max = 0;
int value[10][10];
int visited[10][10]={0};
//int tmp_counter = 0;
void search(int depth, int sum,int answer[]){
  //printf("depth: %d\n",depth);
  if(depth>=8){
    if(sum>max){
      max = sum;
      // for(int i=0;i<8;i++){
      // 	printf("%d ",answer[i]);
      // }
      // printf("\n");
    }
    //tmp_counter ++;
    //printf("%d\n",tmp_counter);
    return ;
  }
  else{
    for(int i=0;i<8;i++){
      //printf("i:%d\n",i);
      bool ok = true;
      for(int line=0;line<depth&&ok==true;line++){
	if(visited[line][i] == 1){
	  ok = false;
	}
	//printf("hit\n");
      }
      for(int line=depth-1,col=i-1;ok==true&&line>=0&&col>=0;line--,col--){
	if(visited[line][col] == 1){
	  ok = false;
	}
	//printf("hit\n");
      }
      // for(int line=depth+1,col=i-1;line<8&&col>=0;line++,col--){
      // 	if(visited[line][col] == 1){
      // 	  continue;
      // 	}
      // 	printf("hit\n");
      // }
      for(int line=depth-1,col=i+1;ok==true&&line>=0&&col<8;line--,col++){
	if(visited[line][col] == 1){
	  ok = false;
	}
	//printf("hit\n");
      }
      // for(int line=depth+1,col=i+1;line<8&&col<8;line++,col++){
      // 	if(visited[line][col] == 1){
      // 	  continue;
      // 	}
      // 	printf("hit\n");
      // }
      if(ok == false)
	continue;
      visited[depth][i] = 1;
      answer[depth] = i;
      search(depth+1,sum+value[depth][i],answer);
      visited[depth][i] = 0;
    }
  }
  return;
}
      
      
int main(){
  
  int num;
  scanf("%d",&num);
  while(num>0){
    num --;
    max = 0;
    
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
	scanf("%d",&value[i][j]);
	visited[i][j] = 0;
      }
    }
    int answer[10];
    search(0,0,answer);

    printf("%5d\n",max);
  }
  return 0;
}


/*
2
 1  2  3  4  5  6  7  8
 9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
 1  2  3  4  5  6  7  8
 9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
*/

    

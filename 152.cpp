#include<stdio.h>
#include<string.h>
#include<math.h>

struct tree{
  int x;
  int y;
  int z;
};

int dist(tree t1,tree t2){
  return pow(t1.x-t2.x,2) + pow(t1.y-t2.y,2) + pow(t1.z-t2.z,2);
}

int main(){
  tree trees[5001];
  int counter = 0;
  int result[12];
  memset(result,0,sizeof(int)*10);
  
  while(true){
    int tx,ty,tz;
    scanf("%d %d %d",&tx,&ty,&tz);
    if(tx==0 && ty==0 && tz==0){
      break;
    }
    trees[counter].x = tx;
    trees[counter].y = ty;
    trees[counter].z = tz;
    counter++;
  }
  
  for(int i=0;i<counter;i++){
    int max_dist = 999999;
    for(int j=0;j<counter;j++){
      if(i==j)
	continue;
      
      int tmp_dist = dist(trees[i],trees[j]);
      if(tmp_dist<max_dist){
	max_dist = tmp_dist;
      }
    }
    //printf("max_dist: %d\n",max_dist);
    if(max_dist>=0 && max_dist<1){
      result[0] ++;
    }
    else
      {
	if(max_dist>=1 && max_dist<4){
	  result[1] ++;
	}
	else
	  {
	    if(max_dist>=4 && max_dist<9){
	      result[2] ++;
	    }
	    else{
	      if(max_dist>=9 && max_dist<16){
		result[3] ++;
	      }
	      else{
		if(max_dist>=16 && max_dist<25){
		  result[4] ++;
		}
		else{
		  if(max_dist>=25 && max_dist<36){
		    result[5] ++;
		  }
		  else
		    {
		      if(max_dist>=36 && max_dist<49){
			result[6] ++;
		      }
		      else{
			if(max_dist>=49 && max_dist<64){
			  result[7] ++;
			}
			else{
			  if(max_dist>=64 && max_dist<81){
			    result[8] ++;
			  }
			  else{
			    if(max_dist>=81 && max_dist<100){
			      result[9] ++;
			    }
			  }
			}
		      }
		    }
		}
	      }
	    }
	  }
      }
  }
  for(int i=0;i<10;i++){
    printf("%4d",result[i]);
  }
  printf("\n");
  return 0;
}
		      
		  
	 
  
    

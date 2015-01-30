#include<stdio.h>
#include<string.h>
struct Node{
  int value;
  Node* last;
  Node* next;
};

int main(){
  int N,k,m;
  
  while(true){
    scanf("%d %d %d",&N,&k,&m);
    //printf("%d %d %d\n",N,k,m);
    if(N==0 && k==0 && m==0)
      break;
    
    Node* first = new Node();
    first->value = 1;
    Node* pre = first;
    for(int i=1;i<N;i++){
      Node* tmp = new Node();
      tmp->value = i+1;
      pre->next = tmp;
      tmp->last = pre;
      pre = tmp;
    }
    pre->next = first;
    first->last = pre;

    int counter = N;
    Node* curl = first;
    Node* curr = first->last;
    while(counter>0){
      if(counter<N){
	printf(",");
      }
      //printf("counter\n");
      int left = k;      
      while(left>1){
	left--;
	curl = curl->next;
      }

      int right = m;
      while(right>1){
	right--;
	curr = curr->last;
      }

      if(curl->value==curr->value){
	printf("%3d",curr->value);
	// printf("curr->next: %d\n",curr->next->value);
	// printf("curr->last: %d\n",curr->last->value);
	curr->next->last = curr->last;
	// printf("curr->next: %d\n",curr->next->value);
	// printf("curr->last: %d\n",curr->last->value);
	curr->last->next = curr->next;
	
	curr->value = -1;
	counter = counter - 1;
	//delete(curr);
      }
      else{
	printf("%3d%3d",curl->value,curr->value);
	curl->next->last = curl->last;
	curl->last->next = curl->next;
	curl->value = -1;

	curr->next->last = curr->last;
	curr->last->next = curr->next;
	curr->value = -1;
	counter = counter - 2;
	//delete
      }
      // printf("counter: %d\n",counter);
      while(curl->value==-1 && counter>0){
	curl = curl->next;
      }
      while(curr->value==-1 && counter>0){
	curr = curr->last;
      }
      // Dropped in such a way is problematic
      // curl = curl->next;
      // curr = curr->last;
      
      //printf("left: %d, right: %d\n",curl->value,curr->value);
    }
    printf("\n");
   
  }
  return 0;
}
      
	






// int main(){
  
//   int N,k,m;
//   int queue[25];
//   while(true){
//     scanf("%d %d %d",&N,&k,&m);
    
//     if(N==0 && k==0 && m==0)
//       break;
    
//     memset(queue,sizeof(int)*N,0);
    
//     int counter = N;
//     int left=0,right=N-1;
//     while(counter>0){
      

//       if(counter<N-1)
// 	printf(",");

//       int counterl = k;
//       while(counterl > 1){	
// 	while(true){
// 	  left = (left + 1) % 10;
// 	  if(queue[left]!=1)
// 	    break;
// 	}
// 	printf("choose left %d\n",left);
// 	counterl--;
//       }
//       queue[left] = 1;
//       printf("Set %d to 1\n",left);

//       int counterr = m;
//       while(counterr > 1){
// 	while(true){
// 	  if(right>0){
// 	    right --;
// 	  }
// 	  else{
// 	    right = N-1;
// 	  }
// 	  if(queue[right]!=1)
// 	    break;
// 	}
// 	printf("choose right %d\n",right);
// 	counterr--;
//       }
//       queue[right] = 1;
//       printf("Set %d to 1\n",right);

//       if(left == right){
// 	counter --;
// 	printf("  %d",left+1);
//       }
//       else{
// 	counter = counter -2;
// 	printf("  %d  %d",left+1,right+1);
//       }
//     }
//   }
//   return 0;
// }
      
      
    
    

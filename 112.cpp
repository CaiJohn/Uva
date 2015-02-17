#include<cstdio>
bool answer = false;
int sum;
bool tag = false;
void search(int result,int a[],int depth){
  
  scanf(" (");
  
  int node;
  if(scanf("%d",&node)==0){
    //printf("leave:%d\n",result);
    scanf(" )");
    if(result == sum && tag == true){
      for(int i=0;i<depth;i++)
	printf("%d ",a[i]);
      printf("\n");
      //printf("reach:%d\n",result);
      answer = true;
    }
  }
  else{
    //printf("node:%d\n",node);
    if(tag == false)
      tag = true;
    a[depth] = node;
    search(result+node,a,depth+1);
    search(result+node,a,depth+1);
    scanf(" )");
  }
  return;
}

int main(){
  
  while(true){
    answer = false;
    tag = false;
    if(scanf("%d",&sum)==EOF){
      break;
    }
    int a[100];
    search(0,a,0);
    if(answer == true){
      printf("yes\n");
    }
    else{
      printf("no\n");
    }
  }
  return 0;
}
    
//22 (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
// 18(4(9()())(1()(4()(9(3(9()(7()(8(6()())(5()(5()())))))(8(4()(1()()))()))()))))

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dict{
  char country[1000];
  int number;
};

int record_cmp(const void* a,const void* b){
  return strcmp(((dict*) a)->country,((dict*) b)->country);
}

int main(){
  int line_num;
  dict records[2005];
  int records_counter = 0;
  scanf("%d\n",&line_num);
  char s[1000];
  for(int i=0;i<line_num;i++){
    fgets(s,100,stdin);
    
    int strl = strlen(s);
    char country_name[1000];
    for(int c=0;c<strl;c++){
      if(s[c]!=' '){
	country_name[c] = s[c];
      }
      else{
	country_name[c] = '\0';
	break;
      }
    }
    
    int j;
    for(j=0;j<records_counter;j++){
      if(strcmp(records[j].country,country_name)==0){
	records[j].number ++;
	break;
      }
    }
    if(j==records_counter)
      {	
	
	strcpy(records[j].country,country_name);
	records[j].number = 1;
	records_counter++;
      }
  }
  qsort(records,records_counter,sizeof(dict),record_cmp);
  for(int i=0;i<records_counter;i++){
    printf("%s %d\n",records[i].country,records[i].number);
  }
  
  return 0;
}

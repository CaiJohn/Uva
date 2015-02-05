#include<iostream>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Card{
  char name[5];
  int num;
  int flower;
};
using namespace std;

int cmp(const void* a,const void* b){
  return ((Card*) a)->num-((Card*) b)->num;
}
bool strait_flush(Card inhand[]){
  //printf("inhand[0]:%d %d\n",inhand[0].num,inhand[0].flower);
  for(int i=1;i<5;i++){
    //printf("%s %d %d\n",inhand[i].name,inhand[i].num,inhand[i].flower);
    if(inhand[i].flower!=inhand[0].flower || !((inhand[i].num-inhand[0].num==i) || (inhand[0].num==1 && inhand[1].num==10 && inhand[2].num==11 && inhand[3].num==12 && inhand[4].num==13))){
      return false;
    }
  }
  return true;
}
 
bool four_of_a_kind(Card inhand[]){
  
  bool tag = false;
  for(int i=0;i<2;i++){
    int t = inhand[i].num;
    if(inhand[i+1].num==t && inhand[i+2].num==t && inhand[i+3].num==t){
      return true;
    }
  }
  return false;
}

bool full_house(Card inhand[]){
  if(inhand[0].num==inhand[1].num && inhand[2].num==inhand[3].num && inhand[2].num==inhand[4].num || inhand[3].num==inhand[4].num && inhand[0].num==inhand[1].num && inhand[1].num==inhand[2].num){
    return true;
  }
  else{
    return false;
  }
}

bool straight(Card inhand[]){
  for(int i=0;i<5;i++){
    if(!((inhand[i].num-inhand[0].num==i) || (inhand[0].num==1 && inhand[1].num==10 && inhand[2].num==11 && inhand[3].num==12 && inhand[4].num==13))){
      return false;
    }
  }
  return true;
}

bool flush(Card inhand[]){
  if(!(inhand[1].flower==inhand[0].flower && inhand[2].flower == inhand[0].flower && inhand[3].flower == inhand[0].flower && inhand[4].flower == inhand[0].flower))
    return false;
  
  return true;
}

bool three_of_a_kind(Card inhand[]){
  if((inhand[0].num==inhand[1].num && inhand[1].num==inhand[2].num) || (inhand[1].num==inhand[2].num && inhand[2].num==inhand[3].num) || (inhand[2].num==inhand[3].num && inhand[3].num==inhand[4].num))
    {
      return true;
    }
  return false;
}

bool two_paires(Card inhand[]){
  if((inhand[0].num==inhand[1].num && inhand[2].num==inhand[3].num) || (inhand[0].num==inhand[1].num && inhand[3].num==inhand[4].num) || (inhand[3].num==inhand[4].num && inhand[1].num==inhand[2].num)){
    return true;
  }
  return false;
}

bool one_pair(Card inhand[]){
  for(int i=0;i<4;i++){
    if(inhand[i].num==inhand[i+1].num){
      return true;
    }
  }
  return false;
}

int max_cards(Card inhand[]){
  if(strait_flush(inhand)){
    return 0;
  }
  if(four_of_a_kind(inhand)){
    return 1;
  }
  if(full_house(inhand)){
    return 2;
  }
  if(flush(inhand)){
    return 3;
  }
  if(straight(inhand)){
    return 4;
  }
  if(three_of_a_kind(inhand)){
    return 5;
  }
  if(two_paires(inhand)){
    return 6;
  }
  if(one_pair(inhand)){
    return 7;
  }
  return 8;
}

int main(){
  
  string input;
  istringstream iss;
  Card cards[20];
  while(getline(cin,input)){
    iss.clear();
    iss.str(input);
    
    string tmp;
    int counter = 0;
    while(iss>>tmp){
      strcpy(cards[counter].name,tmp.c_str());
      
      switch(tmp[1]){
      case 'C':
	cards[counter].flower = 0;
	break;
      case 'D':
	cards[counter].flower = 1;
	break;
      case 'H':
	cards[counter].flower = 2;
	break;
      case 'S':
	cards[counter].flower = 3;
	break;
      }
      
      switch(tmp[0]){
      case 'T':
	cards[counter].num = 10;
	break;
      case 'J':
	cards[counter].num = 11;
	break;
      case 'Q':
	cards[counter].num = 12;
	break;
      case 'K':
	cards[counter].num = 13;
	break;
      case 'A':
	cards[counter].num = 1;
	break;
      default:
	cards[counter].num = tmp[0]-'1'+1;
	break;
      }
      counter ++;
    }
    Card inhand[5];
    int max_hand = 10;
    for(int i=0;i<32;i++){
      
      int cur = i;
      int t_counter = 0;
      //printf("cur: %d\n",cur);
      for(int j=4;j>=0;j--){
	if(cur>=(1<<j)){
	  inhand[t_counter] = cards[j];
	  t_counter ++;
	  cur = cur - (1<<j) ;
	  //printf(" %d",j);
	}
      }
      //printf("\n");
      for(int j=0;j<5-t_counter;j++){
	inhand[t_counter+j] = cards[5+j];
      }
      // for(int j=0;j<5;j++){
      // 	printf("%s ",inhand[j].name);
      // }
      //printf("\n");
      qsort(inhand,5,sizeof(Card),cmp);

      int cur_hand = max_cards(inhand);
      if(max_hand>cur_hand){
	max_hand = cur_hand;
      }
    }
    printf("Hand:");
    for(int i=0;i<5;i++){
      printf(" %s",cards[i].name);
    }
    printf(" Deck:");
    for(int i=5;i<10;i++){
      printf(" %s",cards[i].name);
    }
    printf(" Best hand: ");
    switch(max_hand){
    case 0:
      printf("straight-flush\n");
      break;
    case 1:
      printf("four-of-a-kind\n");
      break;
    case 2:
      printf("full-house\n");
      break;
    case 3:
      printf("flush\n");
      break;
    case 4:
      printf("straight\n");
      break;
    case 5:
      printf("three-of-a-kind\n");
      break;
    case 6:
      printf("two-pairs\n");
      break;
    case 7:
      printf("one-pair\n");
      break;
    case 8:
      printf("highest-card\n");
      break;
    }
  }
  
  return 0;
}

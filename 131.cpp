#include<iostream>
#include<isstream>
struct Card{
  char name[5];
  int num;
  int flower;
};
using namespace std;

bool strait_flush(Card inhand[]){
  
  bool tag = true;
  int flower = inhand[0].flower;
  int start = inhand[0].num;
  for(int i=1;i<5;i++){
    if(inhand[i].flower!=flower || inhand[i].num-start!=i){
      tag = false;
      break;
    }
  }
  return tag;
}
 
bool four_of_a_kind(Card inhand[]){
  
  bool tag = false;
  for(int i=0;i<2;i++){
    int t = inhand[i];
    if(inhand[i+1].num==t && inhand[i+2].num==t && inhand[i+3].num==t){
      tag = true;
    }
  }
  return true;
}

bool full_house(Card inhand[]){
  if(inhand[0].num==inhand[1].num && inhand[2].num==inhand[3].num && inhand[2].num==inhand[4].num || inhand[3].num==inhand[4].num && inhand[0].num==inhand[1].num && inhand[1].num==inhand[2].num){
    return true;
  }
  else{
    return false;
  }
}

bool flush(Card inhand[]){
  if(inhand[0].flower==inhand[1].flower && inhand[0].flower==inhand[2].flower && inhand[0].flower==inhand[3].flower && inhand[0].flower==inhand[4].flower){
    return true;
  }
  else{
    return false;
  }
}

bool straight(Card inhand[]){
  for(int i=0;i<5;i++){
    if(inhand[i].num-inhand[0].num!=i){
      return false;
    }
  }
  return true;
}

bool three_of_a_kind(Card inhand[]){
  if((inhand[0].num==inhand.[1].num && inhand[1].num==inhand[2].num) || (inhand[1].num==inhand.[2].num && inhand[2].num==inhand[3].num) || (inhand[2].num==inhand.[3].num && inhand[3].num==inhand[4].num))
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
    iss.str(input);
    
    string tmp;
    int counter = 0;
    while(iss>>tmp){
      strcpy(cards[counter].name,iss.c_str());
      
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
      
    for(int i=0;i<32;i++){
      
      Cards inhand[5];
      int cur = i;
      int t_counter = 0;
      for(int j=4;j>=0;j--){
	if(cur>=(1<<j)){
	  inhand[4-j] = cards[j];
	  t_counter ++;
	  cur = cur - 1<<j ;
	}
      }
      for(int j=t_counter+1;j<5;j++){
	inhand[j] = cards[j-t_counter-1+4];
      }
      
      qsort(inhand,5,sizeof(Card),cmp);
      switch(max_cards(inhand)){
      case 0:
	printf("\n");
	break;
      case 1:
	printf("\n");
	break;
      case 2:
	printf("\n");
	break;
      case 3:
	printf("\n");
	break;
      case 4:
	printf("\n");
	break;
      case 5:
	printf("\n");
	break;
      case 6:
	printf("\n");
	break;
      case 7:
	printf("\n");
	break;
      case 8:
	printf("\n");
	break;
      }
    }
  }
  return 0;
}

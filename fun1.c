#include "fun1.h"
#include "string.h"
#include "stdlib.h"
int load_contact(struct contact *conts){
  conts->id = 1;
  strcpy(conts->name,"francesco");
  return 0;
}
int print_contact(struct contact *conts){
  printf("id = %d\n",conts->id);
  printf("name = %s\n",conts->name);
  return 0;
}

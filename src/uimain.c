#include <stdlib.h>
#include <stdio.h>

int main()
{
  char userIn[1001];
  while(1){
    puts("$");
    fgets(userIn, 100, stdin);
    printf("%s\n",userIn);
  }
  return 0;
}

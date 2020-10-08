#include <stdio.h>


int main(int argc,char *argv[]) 
{
  char ch;
  int count = 0;
  FILE *fp=fopen(argv[1], "r");
 
  if(fp == NULL) 
{
    printf("Could not open the file ");
    return 1;
  }
 
  while ((ch = fgetc(fp)) != EOF) 
  {
   
      if(ch >= '0' && ch <= '9') 
 	count++;
    
  }
 
  printf("Number of digits in file are %d",count);
  printf("\n");
  return 0;
}

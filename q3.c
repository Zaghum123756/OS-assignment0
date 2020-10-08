#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void reverse_string(char *t) 
{
  int l, a;
  char *c, d;

  l = strlen(t);
  c = t + l - 1;

  for (a = 0; a < l/2; a++) 
{
    d  = *t;
    *t = *c;
    *c = d;
    t++;
    c--;
  }
}

void reverse_words(char *s) 
{
  char b[100], *t, *z;
  int c = 0;
  int count=0;
int r=0;
  t = s;

  while(*t) 
  {                          
    while(*t != ' ' && *t != '\0' && *t!= '.') 
    {    
      b[c] = *t;
      t++;
      c++;
    }
    b[c] = '\0';
    c = 0;

while(b[r]!='\0')
{
if(b[r]=='a' || b[r]=='e'|| b[r]=='i'|| b[r]=='o'|| b[r]=='u'|| b[r]=='A'|| b[r]=='E'|| b[r]=='I'|| b[r]=='O'|| b[r]=='U')
{
count=1;
}
r++;
}

r=0;
if(count==1)
reverse_string(b);        
count=0;
    z = b;

    while (*z) 
    {    
      *s = *z;
      z++;
      s++;
    }


    while (*s == ' ' || *s=='.' ) 
    {             
      s++;
    }
    
    t = s;                              
  }

}

int main(int argc,char *argv[]) 
{

char a[1000];
char ch;
  
  FILE *fp;
fp=fopen(argv[1], "r");
 
  if(fp == NULL) 
  {
    printf("Could not open the file ");
    return 1;
  }

  else
  {
 int i=0;
  while ((ch = fgetc(fp)) != EOF) 
  {
   
    a[i]=ch;
    i++;
  }
 
 reverse_words(a);
a[i-1]='\0';
  printf("%s\n", a);
  }
fclose(fp);
  return 0;
}



#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void deleterecord(char *arr,int opt,char *fname)
{

if(opt==0)
{

int i=0;
int count=0;

  remove("output.txt");
FILE *fptr;   
   fptr = fopen("output.txt","w");

if(fptr == NULL)
 {
     printf("Error!");   
     exit(1);             
 }


char temp[500];
int index1=-1;
for(i;count!=3;i++)
 {
if(arr[i]=='\n')
count++;
index1=i;
}

int g=index1;
int b=0;
for(g=index1;arr[g]!='\0';g++)
	{
	  
	 temp[b]=arr[g];
	fprintf(fptr,"%c",temp[b]);
	b++;
	 		
	}
fclose(fptr);
}

else if(opt==1)
{

char temp1[500];
int index1=-1;
int i1=0;
int count1=0;
for(i1=0;count1!=4;i1++)
 {
if(arr[i1]=='\n')
count1++;
index1=i1;
 }
count1=0;
int index2=0;
for(i1=0;count1!=8;i1++)
 {
if(arr[i1]=='\n')
count1++;
index2=i1;
 }
remove("output.txt");
FILE *fp;   
 
    fp=fopen("output.txt","w");
    if(fp==NULL)
    {
        printf("File does not created!!!");
        exit(0); 
    }


char myarr[500];

int g=0;
int b=0;
for(g=0;arr[g]!='\0';g++)
	{
	if(g>=index1 && g<=(index2-2))
	{g++;}
	else
  
	{ myarr[b]=arr[g];
	fprintf(fp,"%c",myarr[b]);
	b++;
	 }		
	}
printf("\n\n\n");
	
fclose(fp);

}

else if(opt==2)
 {  

char temp1[500];
int index1=-1;
int i1=0;
int count1=0;

remove("output.txt");
FILE *fp;   
 
    fp=fopen("output.txt","w");

    if(fp==NULL)
    {
        printf("File does not created!!!");
        exit(0); 
    }

for(i1=0;count1!=7;i1++)
 {
if(arr[i1]=='\n')
count1++;
temp1[i1]=arr[i1];
fprintf(fp,"%c",temp1[i1]);
 }


 }


printf("\n changes appear in output.txt file\n");

}

void myrecord(char *arr,int opt)
{
if(opt==0)
{
char temp[500];
int i=0;
int count=0;
for(i;count!=3;i++)
 {
if(arr[i]=='\n')
count++;
temp[i]=arr[i];
 }
temp[i-1]='\0';
printf("\n");
printf("Your own record is \n");
printf("%s ",temp);
printf("\n");
}

else if(opt==1)
{
char temp[500];
int index=-1;
int i=0,count=0;
for(i;count!=4;i++)
 {
if(arr[i]=='\n')
count++;
index=i;
 }


count=0;
int j=index;
i=0;
for(j;count!=4;j++)
 {
if(arr[j]=='\n')
count++;
temp[i]=arr[j];
i++;
 }
printf("\n");
printf("Friend 1's record is \n");
printf("%s ",temp);
printf("\n");
}

else if(opt==2)
{

char temp[500];
int index=-1;
int i=0;
int count=0;
for(i=0;count!=8;i++)
 {
if(arr[i]=='\n')
count++;
index=i;
 }


count=0;
int j=index;
i=0;

for(j;count!=4;j++)
 {
if(arr[j]=='\n')
count++;
temp[i]=arr[j];
i++;
 }
printf("\n");
printf("Friend 2's record is \n");
printf("%s ",temp);
printf("\n");
}


}

int main(int argc,char *argv[]) 
{

char a[500];
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
a[i-1]='\0';
 
  }

int q=-1;
int w=-1;
label:
printf("\n");

mainmenu:
printf("enter 1 to view  records \n");
printf("enter 2 to delete records \n");
printf("enter 3 to add records \n");
printf("enter 4 to leave \n");

printf("enter choice");
scanf("%d",&w);
printf("\n");

if(w==1) //printing
{

printf("enter 0 to view own record \n");
printf("enter 1 to view friend 1's record \n");
printf("enter 2 to view friend 2's record \n");
printf("enter 3 to go to main menu \n");

printf("enter choice");
scanf("%d",&q);
printf("\n");


if(q==0)
myrecord(a,q);

else if(q==1)
myrecord(a,q);

else if(q==2) 
myrecord(a,q);

else if(q==3)
goto mainmenu;

}

else if(w==2) //deleting
{

printf("enter 0 to delete own record \n");
printf("enter 1 to delete friend 1's record \n");
printf("enter 2 to delete friend 2's record \n");
printf("enter 3 to go to main menu \n");

printf("enter choice");
scanf("%d",&q);
printf("\n");

if(q==0)
deleterecord(a,q,argv[1]);

else if(q==1)
deleterecord(a,q,argv[1]);

else if(q==2)
deleterecord(a,q,argv[1]);

else if(q==3)
goto mainmenu;

}


else if(w==3) //add 
{
char name[15];
char rollno[10];
char email[20];

printf("Enter data of user \n");
printf("enter name \n");
scanf("%s",name);

printf("enter Roll number \n");
scanf("%s",rollno);

printf("enter email address \n");
scanf("%s",email);
 
 FILE *fp;
fp=fopen(argv[1], "a");
 
  if(fp == NULL) 
  {
    printf("Could not open the file ");
    return 1;
  }
fprintf(fp,"\n");
fputs(name, fp);
fprintf(fp,"\n");
fputs(rollno, fp);
fprintf(fp,"\n");
fputs(email, fp);
fprintf(fp,"\n");

printf("\n input file has been updated\n");

fclose(fp);

int op=-1;

printf("\nEnter 0 to go to main menu\n");
printf("\nEnter 1 to exit\n");

scanf("%d",&op);

if(op==0)
goto mainmenu;

else if(op==1)
exit(0);
}

else if(w==4) //leaving
{
 exit(0);
}



fclose(fp);
  return 0;
}






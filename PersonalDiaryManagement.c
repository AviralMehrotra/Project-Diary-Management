#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warn-rvl  
int count=0;
char dsrch[10],psrch[20];//declaring search variables 
struct NODE 
{ 
  int time;
  char date[10],place[10],dur[10],note[50];//declaring variables to store data
  struct NODE *plink,*nlink;  //declaring previous node link and next node link
}*newnode,*first=NULL,*last=NULL,*found;
void ins_first()
{ 
  char find;int choice, index=0;
  struct NODE *temp=first;

  newnode=(struct NODE*)malloc(sizeof(struct NODE)); 
  printf("\n\t\t\t\t\t\t\tEnter the date of your record (yyyymmdd):  ");
  scanf("%s",&newnode->date);
  printf("\n\t\t\t\t\t\t\tEnter Time (24hr format)- ");
  scanf("%d",&newnode->time);
  printf("\n\t\t\t\t\t\t\tEnter Place- ");
  scanf("%s",&newnode->place);
  printf("\n\t\t\t\t\t\t\tEnter Duration of stay(in hrs)- ");
  scanf("%s",&newnode->dur);
  printf("\n\t\t\t\t\t\t\tNOTE:-  ");
  scanf("\n");
  scanf("%[^\n]%*c",&newnode->note);
  if(first==NULL&&last==NULL)
   {
    first=newnode;last=newnode;
    newnode->nlink=NULL;
    newnode->plink=NULL;
   }
  else
  {
    newnode->plink=NULL;newnode->nlink=first;
    first=newnode;
  }
  count++;
}

void display_dir(int item) //this function will be used to display the whole directory or a selected contact when editing or deleting it
{ int i=1;
  struct NODE*temp=first;
  if(item==0)
  {      if(temp!=NULL)//will work if directory is not empty
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t SAVED RECORDS\n");
            while(temp!=NULL)
            { 
              printf("\n\t\t\t\t=================================================================================================================================\n");
              printf("\t\t\t\t\t\t\t\t\tDate-  %s\n\t\t\t\t\t\t\t\t\tTime-  %d\n\t\t\t\t\t\t\t\t\tPlace- %s\n\t\t\t\t\t\t\t\t\tDuration- %s hours\n\t\t\t\t\t\t\t\t\tNote- %s",temp->date,temp->time,temp->place,temp->dur,temp->note);
              temp=temp->nlink; //saving value of next node to temp
              i++;
              printf("\n\t\t\t\t---------------------------------------------------------------------------------------------------------------------------------\n");
            }
        }
  }
  else//if no data is present
      printf("\t\t\t\t\tNo Contacts are present here !!!");
}

char search_data(int srch)//to search for an existing data 
{ 
  struct NODE *temp=first;
  int i=1,ch;
  if (srch==1)
  { 
    printf("\n\t\t\t\t\t\t\tEnter the date you want to search for\n\t\t\t\t\t\t\t-->");
    scanf("%s",&dsrch);
    srch=1;
  }
  switch(srch)
  {
         case 1:while(i<=count)//comparing the entered name to the saved data to check whether data exists or not
             {
               if(strcmp(temp->date,dsrch)==0)
                  {
                    found=temp;
                    return('Y');//if the data exists , it will return Y
                  }
               else
                temp=temp->nlink;
                i++;
             }
             display_dir(1);
              break;   
  }
    if (i==count+1)//if the data to search is not present in the directory 
    return('N');
}

int main()
{
    int choice;
    char find;
  do
  {
     printf("\n\t\t\t\t****************************************    PERSONAL DIARY MANAGEMENT SYSTEM    *************************************************");
     printf("\n\n\n \t\t\t\t\t\tENTER YOUR CHOICE:-\n\n\t\t\t\t\t\t\t1. New Record\n\t\t\t\t\t\t\t2. Search Record\n\t\t\t\t\t\t\t3. Display Data\n\t\t\t\t\t\t\t4. Exit\n\n");
     printf("\n\t\t\t\t*********************************************************************************************************************************");
     printf("\n\t\t\t\t-->");
     scanf("%d",&choice);
     printf("\n\t\t\t\t*********************************************************************************************************************************");
    switch(choice)
   {
       case 1: ins_first();
       break;
       case 2: find=search_data(1);
           if(find=='Y')
              printf("\t\t\t\t\t\t\t\t\t\t\tDATA FOUND !!!!");
           else
              printf("\t\t\t\t\t\t\t\t\t\t\tDATA NOT FOUND !!!!");
       break; 
       case 3: display_dir(0);
       break;
       case 4: return 0;
       break;
       default: printf("\n\t\t\t\t\t\t\tEnter a valid number !!!");
   }
   printf("\n\t\t\t\t*********************************************************************************************************************************");
   printf("\n\n\t\t\t\tIf you want to exit press any key...else press 1\n\t\t\t\t-->");
   scanf("%d",&choice);
  }
  while(choice==1);
}
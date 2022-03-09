#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warn-rvl  
int count=0;
char dsrch[10],psrch[20];//declaring search variables 
struct NODE 
{ 
  char date[10],time[10],place[10],dur[10],note[50];//declaring variables to store data
  struct NODE *plink,*nlink;  //declaring previous node link and next node link
}*newnode,*first=NULL,*last=NULL,*found;

void ins_first()
{ 
  char find;int choice, index=0;
  struct NODE *temp=first;

  newnode=(struct NODE*)malloc(sizeof(struct NODE)); 
  printf("\n\t\t\t\t\t\t\tEnter the date of your record:  ");
  scanf("%s",&newnode->date);
  printf("\n\t\t\t\t\t\t\tEnter Time- ");
  scanf("%s",&newnode->time);
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
void del_first() 
{ struct NODE *temp=first;
  if(first==NULL && last== NULL) 
  printf("\t\t\t\t\t\tNo data exist here");
  else 
  { 
    printf("\t\t\t\t\t\tDeleting record of date:  %s ",first->date);
    first=first->nlink;
    first->plink=NULL;
    free(temp);
  }
  count--;
}
void del_last() //this function will delete the contact which comes at last in the directory
{ struct NODE *temp=last;
  if(first==NULL && last== NULL) 
  printf("\t\t\t\t\t\tNo data exist here");
  else 
  { 
    printf("\t\t\t\t\t\tDeleting record of date:  %s ",last->date);
      last=last->plink;
      last->nlink=NULL;
      free(temp);
  }
  count--;
}
void del_mid(int index) 
{ struct NODE *temp=first,*temp1; 
  int i=1;
  
   if(index==1)
   del_first();
   else if(index==count)
   del_last();
   else if(index<1 ||index>count)
   printf("\t\t\t\t\t\tInvalid Position");
   else
   {
     while(i<index-1)
    {
      temp=temp->nlink;
      i++;
    }
    temp1=temp->nlink;
    temp->nlink=(temp->nlink)->nlink;
    (temp->nlink)->plink=temp;
    printf("\t\t\t\t\t\tDeleting record of date:  %s ",temp1->date);
    free(temp1);
    count--;
   }
}

void display_dir(int item) //this function will be used to display the whole directory or a selected contact when editing or deleting it
{ int i=1;
  struct NODE*temp=first;
  if(item==1)
  {
        printf("\n\n\t\t\t\t                          Data to be Deleted");
        printf("\n\t\t\t\t\t=================================================================================================================================\n");
        printf("\t\t\t\t\t\t\t\t\tDate-  %s\n\t\t\t\t\t\t\t\t\tTime-  %s\n\t\t\t\t\t\t\t\t\tPlace- %s\n\t\t\t\t\t\t\t\t\tDuration- %s\n\t\t\t\t\t\t\t\t\tNote- %s",found->date,found->time,found->place,found->dur,found->note);    
  }
  else if(item==0)
  {      if(temp!=NULL)//will work if directory is not empty
        {
            while(temp!=NULL)
            { 
              printf("\n\t\t\t\t=================================================================================================================================\n");
              printf("\t\t\t\t\t\t\t\t\tDate-  %s\n\t\t\t\t\t\t\t\t\tTime-  %s\n\t\t\t\t\t\t\t\t\tPlace- %s\n\t\t\t\t\t\t\t\t\tDuration- %s\n\t\t\t\t\t\t\t\t\tNote- %s",temp->date,temp->time,temp->place,temp->dur,temp->note);
              temp=temp->nlink; //saving value of next node to temp
              i++;
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
    printf("\n\t\t\t\t\tWhat do you want to search for: \n\t\t\t\t\t\t1. Place \n\t\t\t\t\t\t2. Date\n\t\t\t\t\t\t-->");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("\t\t\t\tEnter the phone number you want to find-");
        scanf("%s",&psrch);
        srch=1;
      break;      
      case 2:
        printf("\t\t\t\tEnter the name you want to find-");
        scanf("%s",&dsrch);
        srch=2;
      break;     
      default:
        printf("\t\t\t\t\t\tEnter a valid choice !!!!");
    }
  }
  switch(srch)
  {
     case 1:while(i<=count)//comparing the entered phone number to the saved data to check whether data exists or not
             {
               if(strcmp(temp->place,psrch)==0)
                  {
                    found=temp;
                    return('Y');//if the data exists , it will return Y
                  }
               else
                temp=temp->nlink;
                i++;
             }
             break;
      case 2:while(i<=count)//comparing the entered name to the saved data to check whether data exists or not
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
              break;   
  }
    if (i==count+1)//if the data to search is not present in the directory 
    return('N');
}
int del_data()
{ 
  int choice,d,index=1;
  char find;
  struct NODE*temp=first;
  printf("\n\t\t\t\tSearch for the record date you want to delete");
  find=search_data(1);
  if (find=='Y')
  { 
    display_dir(1);
    printf("\n \t\t\t\tAre you sure you want to delete?? Press 1 for YES or 0 for NO !!");
    scanf("%d",&d);
    switch(d)
    {
      case 0: return(0);
      break;
      case 1:
      if(first==NULL&&last==NULL)
      {
        del_first();
      }
      else
        {  
          while(temp!=NULL)
           { 
            if(((strcmp(found->date,temp->date)==0)&&(temp==first)))
              {
              del_first();
              break;
              }
              else if(temp!=last)
                {  
                index++;
                if(strcmp(found->date,temp->nlink->date)==0)
                {
                  del_mid(index);
                  break;
                }
                else 
                    temp=temp->nlink;
                } 
              else if((strcmp(found->date,temp->date)==0)&&(temp==last))
              {
                del_last();
                break;
              }
              else   
              temp=temp->nlink;
            }
        }
        break;
      default: printf("\n\t\t\t\tEnter a valid number...");
    }   
    }
    else
    printf("\n\t\t\t\tNo such contact exists");
}
void main()
{
    int choice;
    char find;
  do
  {
     printf("\n\t\t\t\t****************************************    PERSONAL DIARY MANAGEMENT SYSTEM    ********************************************");
     printf("\n\n\n \t\t\t\t\t\tENTER YOUR CHOICE:-\n\n\t\t\t\t\t\t\t1. New Record\n\t\t\t\t\t\t\t2. Search Record\n\t\t\t\t\t\t\t3. Delete Existing Record\n\t\t\t\t\t\t\t4. Display data\n\n");
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
       case 3: del_data();
       break;
       case 4: display_dir(0);
       break;
       default: printf("\n\t\t\t\t\t\t\tEnter a valid number !!!");
   }
   printf("\n\n\t\t\t\t*********************************************************************************************************************************");
   printf("\n\n\t\t\t\tIf you want to exit press any key...else press 1\n\t\t\t\t-->");
   scanf("%d",&choice);
  }
  while(choice==1);
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
struct player{ 	//initialise player objects
char n[51];
char p;
};

int check(int[],int);



int loop=1;		    
int main()
{
    while(loop)
    {
		
	struct player A,B;				   // initialise 2 palyers A and B
	char t[9];					// char array t for storing X and O
	int tt[9];	     // int array tt for storing 1 for X and 2 for O
	system("clear");	
    printf("\fPlayer 1 Enter your name :\n");   //input from players A and B
    scanf("%s",A.n);
    getc(stdin);
    printf("Player 1 choose X or O :\n");
    scanf("%c",&A.p);
    getc(stdin);
    printf("Player 2 Enter your name :\n");
    scanf("%s",B.n);
    if(A.p=='X' || A.p=='x'){
    B.p='O';A.p='X';}
    else
    B.p='X';
    int pos,i,k,x;
	char lp;
	x=k=0;
    memset(tt,0,sizeof(tt));		//setting initial value of all the elemnts of tt to 0. 
    for(i=0;i<9;++i)				//inserting 1 2 3 4 ....9 as characters into t
    {
       t[i]=('1'+ x++);
    }
    
    int round=9;
    int wd=0;
    while((round!=0) && (wd==0))		//at max 9 rounds or moves are made 
    {
        printf("\n");
        for(i=0;i<9;++i)				//printing char array t as 3 x 3 array 
          {
                if(i%3==0)
                printf("\n\t %c",t[i]);
                else
                printf(" %c",t[i]);
          }
			printf("\n\n");
	
       if((round%2)!=0)  //if round is odd then its player 1's turn
       {
	    printf("%s's turn (%c):\n",A.n,A.p);
        printf("Enter position :\n");
        scanf("%d",&pos);
         if(t[pos-1]>='1' && t[pos-1]<='9' && pos>=1 && pos<=9 && t[pos-1]!='X' && t[pos-1]!='Y')//condition necessary for a correct move else it a wrong move and needed to be re inserted!
           {
               t[pos-1]=A.p; //if move is possible then insert X or Y of player 1
               tt[pos-1]=1;  // insert 1 in the int tt array
				if(round<=5){
               k=check(tt,1); //returns 1 if there is any match out of 8 combinations
				//printf("%d\n",k);// jast fr debug
               if(k==1)
               wd=1;// flag for marking player 1 as winner
               }round--;// decrement round by 1 
           }
         else
            printf("Not possible Re-enter again!\n");
        }
        else{
	
        printf("%s's turn (%c):\n",B.n,B.p);
        printf("Enter position :\n");
        scanf("%d",&pos);
         if(t[pos-1]>='1' && t[pos-1]<='9' && pos>=1 && pos<=9 && t[pos-1]!='X' && t[pos-1]!='Y')
           {
               t[pos-1]=B.p;//if move is possible then insert X or Y of player 2
                tt[pos-1]=2;// insert 2 in the int tt array
               if(round<=6){
               k=check(tt,2);//returns 1 if there is any match out of 8 combinations
				//printf("%d\n",k);// jast fr debug
               if(k==1)
               wd=2;// flag for marking player 2 as winner
               }round--;// decrement round by 1 
           }
         else
            printf("Not possible Re-enter again!\n");
        }

    }
	
	printf("\n");
        for(i=0;i<9;++i)				//printing char array t as 3 x 3 array 
          {
                if(i%3==0)
                printf("\n\t %c",t[i]);
                else
                printf(" %c",t[i]);
          }
	printf("\n");
        

    if(wd==0)
    printf("\nMatch Drawn! :3 ");
    if(wd==2)
    printf("\n%s Won :) ",B.n);
    if(wd==1) 
    printf("\n%s Won :) ",A.n);
    getc(stdin);
	printf("\nTo play once again press Y\nTo Exit press any other key.\n");
	scanf("%c",&lp);
	//lp=getch();
	if(lp!='Y' && lp!='y')
	loop=0;
	}

   return 0;
}

int check(int tt[],int q)
{
	
if((tt[0]==tt[4] && tt[4]==tt[8] && tt[8]==tt[0] && tt[0]==q)||
(tt[2]==tt[4] && tt[4]==tt[6] && tt[6]==tt[2] && tt[2]==q)||
(tt[0]==tt[3] && tt[3]==tt[6] && tt[6]==tt[0] && tt[0]==q)||
(tt[1]==tt[4] && tt[4]==tt[7] && tt[7]==tt[1] && tt[1]==q)||
(tt[2]==tt[5] && tt[5]==tt[8] && tt[8]==tt[2] && tt[2]==q)||
(tt[0]==tt[1] && tt[1]==tt[2] && tt[2]==tt[0] && tt[0]==q)||
(tt[3]==tt[4] && tt[4]==tt[5] && tt[5]==tt[3] && tt[3]==q)||
(tt[6]==tt[7] && tt[7]==tt[8] && tt[8]==tt[6] && tt[6]==q))                 
return 1;
else
return 0;
 
}


#include<stdio.h>
#include<stdlib.h>

int board[3][11],n=3;

void printscreen();
void pdisk(int x);
int checkComp();
void move();
int validMove(int a,int b,int a1,int b1);
void initialize();

int main()
{
    printf("Enter the number of disks (2 to 10) : ");
    scanf("%d",&n);

    int count=0;
	initialize();

	for(;checkComp()==0;)
	{
		printscreen();
		move();
		count++;
	}
    printscreen();
	printf("\n----> Game complete.\nNumber of moves : %d\n\n",count);
	return 0;
}

int checkComp()
{
	for(int i=0;i<=n;++i)
		if(board[2][i]!=n-i)
			return 0;
	return 1;
}

int validMove(int a,int b,int a1,int b1)
{
    if(a<1||a>3||b<1||b>3)
        return 0;
    if(a1==0)
        return 0;
    if(b1!=0)
        if(board[a-1][a1-1]>board[b-1][b1-1])
            return 0;
    return 1;
}

void move()
{
	int a,b,a1,b1;
	printf("Enter the move : ");
    scanf("%d %d",&a,&b);

	for(a1=0;board[a-1][a1]!=0;++a1);
	for(b1=0;board[b-1][b1]!=0;++b1);

	for(;validMove(a,b,a1,b1)==0;)
    {
        printf("Invalid move.\nEnter again : ");
        scanf("%d %d",&a,&b);

        for(a1=0;board[a-1][a1]!=0;++a1);
        for(b1=0;board[b-1][b1]!=0;++b1);
    }

	board[b-1][b1]=board[a-1][a1-1];
	board[a-1][a1-1]=0;
}

void initialize()
{
	for(int i=0;i<=n;++i)
		board[0][i]=n-i;
	for(int i=0;i<=n;++i)
		board[1][i]=0;
	for(int i=0;i<=n;++i)
		board[2][i]=0;
}

void pdisk(int x)
{
    if(x==0)
    {
        for(int i=1;i<=n+1;++i)
            printf(" ");
        printf("|");
        return;
    }
    if(x==-1)
    {
        printf("______________________________________________________");
        for(int i=1;i<=n;++i)
            printf("________");
        return;
    }

    for(int i=1;i<=n+1-x;++i)
        printf(" ");
    printf("<=");
    for(int i=1;i<x;++i)
        printf("==");
    printf(">");
}

void printscreen()
{
    system("clear");
	printf("\t\t\t\tThe tower of Hanoi\n\n");

	printf("Tower 1");
    for(int i=1;i<=n+1;++i)
        printf("    ");
    if(n>3&&n<=10&&n!=6)printf("\t");
    if(n==3)printf("         ");
	printf("Tower 2");
    for(int i=1;i<=n+1;++i)
        printf("    ");
    if(n>3&&n<=10&&n!=6)printf("\t");
    if(n==3)printf("         ");
	printf("Tower 3\n");

        for(int i=0;i<=n;++i)
            {
                pdisk(board[0][n-i]);
                if(n>=3&&n<=5)if(board[0][n-i]<6-n)printf("\t");
                if(n>=7&&n<=10)if(board[0][n-i]<14-n)printf("\t");
                printf("\t\t\t");
                pdisk(board[1][n-i]);
                if(n>=3&&n<=5)if(board[1][n-i]<6-n)printf("\t");
                if(n>=7&&n<=10)if(board[1][n-i]<14-n)printf("\t");
                printf("\t\t\t");
                pdisk(board[2][n-i]);
                printf("\n");
            }
	pdisk(-1); printf("\n\n");
}


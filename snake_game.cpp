#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int x,y, fruitx, fruity, score,ntail=0;
int tailx[100],taily[100];
enum edirec{ STOP = 0,LEFT, RIGHT , UP, DOWN};
edirec dir;

void setup()
{
	gameover = false;
	dir = STOP;
	x=width/2;
	y=height/2;
	fruitx = rand() % width;
	fruity= rand() % height;
	score = 0;
	
}

void draw()
{
	system("cls");
	for (int i=0;i<width;i++)
	  cout<<"=";
	 // cout<<"=";
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==width-1))
			cout<<"|";
			else
			if(i==y&&j==x)
			cout<<"O"; 
			else if(i==fruity&& j==fruitx)
			cout<<"*";
			else
			{bool print=false;
			for(int k=0;k<ntail;k++)
			{
				if(tailx[k]==j&& taily[k]==i)
				{
					cout<<"o";
					print=true;
				}
			}
			if(!print)
			 cout<<" ";
			
			
		}
		}
		cout<<endl;
	}  
	
	for (int i=0;i<width;i++)
	  cout<<"=";
	 //cout<<"=" ;
	 cout<<endl;
	cout<<"SCORE = "<<score; 
	  
}

void input()
{
	if(_kbhit())
	{ 
	  switch(_getch())
	  {
	  	case 'w':
	  		dir =UP;
	  		break;
	  	case 'a':
	  		dir= LEFT;
	  		break;
		case 'd':
	  		dir =RIGHT;
	  		break;
		case 's':
	  		dir =DOWN;
	  		break;
		case 'x':
	  		gameover=true;
	  		break;	  	  	  	
	  }
	}
}

void logic()
{
	
	int prevx= tailx[0];
	int prevy= taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<ntail;i++)
	{
		prev2x= tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy = prev2y;
		
	}
	switch(dir)
	  {
	  	case RIGHT:
	  		x++;
	  		break;
	  	case UP:
	  		y--;
	  		break;
		case DOWN:
	  		y++;
	  		break;
		case LEFT:
	  		x--;
	  		break;
	  	default:
		  break;	
	}
	
	//if(x>width||x<0||y>height||y<0)
	 //gameover=true;
	 for(int i=0;i<ntail;i++)
	   if(x==tailx[i]&&y==taily[i])
	 	gameover=true;

	 if(x>width-2)
	  x=1;
	 if(x<1) 
	 x=width-2;
	 if(y>height-1)
	  y=0;
	  if(y<0)
	  y=height-1;
	if(x==fruitx&&y==fruity)
	{
		ntail++;
		score+=10;
		fruitx = rand() % width;
        fruity= rand() % height;
    }
    
    
    
    
}

int main()
{
    setup();
	while(!gameover)
	{
	   draw();
	   input();
	   logic();	
	}	
	return 0;
	
}


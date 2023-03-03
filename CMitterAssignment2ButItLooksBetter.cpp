#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
using namespace std;


void showBoard(int [][4]);
void initializeBoard(int [][4]);
void search(int [][4], int num,int &,int &, int & ,int & );

int main() {
	int m;
	int foundrow;//for finding the row of the value inputed
	int foundcol;//for finding the col of the value inputed
	int blankrow;//for finding the row of the value 16
    int blankcol;//for finding the col of the value 16
	srand (time(NULL));
	int Boardnumbers[4][4];
	
	initializeBoard(Boardnumbers);
	
	do{
	showBoard(Boardnumbers);
	cout<<"\n\n\tEnter the number you want to move : ";
	cin>>m;
	search(Boardnumbers,m,foundrow,foundcol,blankrow,blankcol);
	}while(!(Boardnumbers[0][0]==1 && Boardnumbers[0][1]==2 && Boardnumbers[0][2]==3 && Boardnumbers[0][3]==4 && Boardnumbers[1][0]==5 && Boardnumbers[1][1]==6 && Boardnumbers[1][2]==7 && Boardnumbers[1][3]==8 && Boardnumbers[2][0]==9 && Boardnumbers[2][1]==10 && Boardnumbers[2][2]==11 && Boardnumbers[2][3]==12 && Boardnumbers[3][0]==13 && Boardnumbers[3][1]==14 && Boardnumbers[3][2]==15 && Boardnumbers[3][3]==16));
	
	cout<< "\nYou Win!"<<endl;
	return 0;
}

// a function that generates 4x4 matrix having random numbers
// in 1-16. Let us assume 16 represents empty cell.
void initializeBoard(int nmbs [][4]) 
{
	// Generate random numbers that are different from each other !!!
	// You should review this part in your solution.
	const int size =16;
	bool used[size]={false};
	int num;
	
	
	for(int r=0;r<4;r++) 
	{
	
	   for(int c=0;c<4;c++)
	    {
	        do
	        {
	       nmbs[r][c]=rand()%16+1;
	        num = nmbs[r][c];
	        } while (used[num-1]);
	        used[num-1]=true;
	     
		}
	}
}


// a function that draws a board on the screen
void showBoard(int nums[][4])  
{
	cout << "\n\t";
	cout << "___" ;
	for(int i=0;i<3;i++)
		 cout << "___";

	for(int r=0;r<4;r++)
	{  
	   cout<<"\n\t";
	   for(int c=0;c<4;c++)
			 cout << "|" << (nums[r][c]<10?" ":"") << (nums[r][c]!=16 ? to_string(nums[r][c]):"  ");
	   cout<<"|";
	   
	   cout<<"\n\t|__";
	   for(int i=0;i<3;i++)
			 cout << "|__";
	   cout << "|";
	}
}
//swapping funcion
void search(int array[][4], int num,int & foundrow,int & foundcol, int & blankrow,int & blankcol)
{
    //for loop for finding where the array values are for the blank space and the number being moved
    for(int r = 0;r<4;r++)
    {
        for(int c = 0;c<4;c++)
        {
            if (array[r][c] == num)
            {
            foundrow = r;
            foundcol = c;
            }
            if (array[r][c] ==16)
            {
                blankrow = r;
                blankcol = c;
            }
        }
    }
    //checks to see if it can move up 
    if (array[blankrow][blankcol]==array[foundrow-1][foundcol])
    {
        system("clear");
        array[blankrow][blankcol]=array[foundrow][foundcol];
        array[foundrow][foundcol]=16;
        blankrow=foundrow;
    }
    //checks to see if it can move down
    else if(array[blankrow][blankcol]==array[foundrow+1][foundcol])
    {
        system("clear");
        array[blankrow][blankcol]=array[foundrow][foundcol];
        array[foundrow][foundcol]=16;
        blankrow=foundrow;
    }
    //check to see if it can move left
     else if(array[blankrow][blankcol]==array[foundrow][foundcol-1]&&foundrow==blankrow)
    {
        system("clear");
        array[blankrow][blankcol]=array[foundrow][foundcol];
        array[foundrow][foundcol]=16;
        blankcol=foundcol;
    }
    //checks to see if it can move right
     else if(array[blankrow][blankcol]==array[foundrow][foundcol+1]&&foundrow==blankrow)
    {
        system("clear");
        array[blankrow][blankcol]=array[foundrow][foundcol];
        array[foundrow][foundcol]=16;
        blankcol=foundcol;
    }
    else
    {
        system("clear");
        cout<< "\tcan't be moved try again"<<endl;
    }
}
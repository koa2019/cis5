/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on June 6, 2022 2:02 PM
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 passes tc 0, 1
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
#include <string.h>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX]={};      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    //print(array,rowIn,colIn);
    
    //cout << "rowIn  "<<rowIn<< " colIn  "<<colIn<<endl;
    //cout << "\nrowDet "<<rowDet<< " colDet "<<colDet<<endl<<endl;
   
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
       sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }
    else{
       if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

//Outputs row and columns detected from input
int read(char array[][COLMAX],int &rowDet){
   
    int r=0;
    while(cin >> array[r]) {
        r++;
    }
    rowDet = r;
    
    
    int size, maxCol=0;
    for(int i=0;i<rowDet;i++){
      
        size=strlen(array[i]);
        //cout<< "len "<<i<< " = "<<size<<endl;
        if(strcmp(array[i], array[0]) <0 )
        maxCol=size;
   }
   return maxCol;
}

//Sort by row
void sort(char array[][COLMAX],int rowIn,int colIn){
    
   int maxEle, row;
   int last=rowIn-1;
   
    // start at the last indx in array to the 2nd indx. starts at[last,1]
    for(maxEle=last; maxEle>0;maxEle--){
        
        for(row=0;row<maxEle;row++){ // starts at [0,last]
            
            if(strcmp(array[row],array[row+1])>0) // if its larger, then swap
                swap(array[row],array[row+1]);
        }
    }
      
}

void print(const char array[][COLMAX],int rowIn,int colIn){
 
    for(int row=0;row<rowIn;row++){
        cout << array[row]<<endl;
    }
}
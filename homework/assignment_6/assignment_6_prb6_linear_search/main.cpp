/* 
 * File:   main.cpp
 * Author:
 * Created on:
 * Purpose:  Linear Search
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Functions
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
bool linSrch(int [],int,int,int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,
        val;
    
    //Initialize or input i.e. set variable values
    val=50;
    fillAry(array,SIZE);
    
    //Display the outputs
    //prntAry(array,SIZE,10);
    
    if(linSrch(array,SIZE,val,indx))
        cout<<val<<" was found at indx = "<<indx<<endl;
    
    //Exit stage right or left!
    return 0;
}

//************* FUNCTION DEFINITIONS **************

// fill array with integers
void fillAry(int arr[],int SIZE){
    
    int min=1;
    for(int i=0;i<SIZE;i++){
        arr[i]=rand()%(100+1)+1;
    }
}

void prntAry(int arr[], int SIZE, int num){
  
    for(int i=0; i<SIZE; i++){
        cout << arr[i] << " ";
        
        if(i%num==(num-1)) cout << endl;
    }
    cout << endl;
}

// search for integer
bool linSrch(int arr[], int SIZE, int val, int &indx){
    
     for(int i=0; i<SIZE;i++){
        if(arr[i]==val){
            indx=i;
            return true;
        } 
     }
    return false;
}
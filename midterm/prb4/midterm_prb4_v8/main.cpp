/* 
 * File:   main.cpp
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 25, 2022,  1:20 PM
 * Purpose:  ISP charges v7
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float PLANA = 16.99;
const float PLANB = 26.99;
const float PLANC = 36.99;

//Function Prototypes Here
float pkgA(int);
float pkgB(int);
void displayMsg(float, string, float);

//Program Execution Begins Here

int main(int argc, char** argv) {

    //Declare all Variables Here
    const string A = "A";
    const string B = "B";
    const string C = "C";

    char package;
    unsigned short hrs;
    float cost = 0.0f,
            saving = 0.0f;
    string cheapst = "";
  
    //Input or initialize values Here
    cout << "ISP charges for service delivered." << endl;
    cout << "Input package A,B,C then hours used for the month" << endl;
    cin >> package>>hrs;

    // input validation
    if (((package == 'a') || (package == 'b') || (package == 'c') || (package == 'A') || (package == 'B') || (package == 'C')) && (hrs >= 1)) {

        
        switch (package) {
            case 'a':
            case 'A': {
                //Basic Charges
                cost = pkgA(hrs);

                //   CHEAPESET PLAN
                if ((hrs > 0) && (hrs <= 20)) {
                    cheapst = A;
                    saving = 0;
                } else if ((hrs >= 21) && (hrs <= 32)) {
                    cheapst = B;
                    saving = cost - PLANB;
                } else if (hrs >= 33) {
                    cheapst = C;
                    saving = cost - PLANC;
                } else cout << "Error in Case A else.\n";

                displayMsg(cost, cheapst, saving);
                
                break;
            }
            case 'b':
            case 'B': {
                //Basic Charges
                cost = pkgB(hrs);

                //   CHEAPESET PLAN
                if (hrs > 0 && hrs <= 20) {
                    cheapst = A;
                    saving = PLANB-pkgA(hrs); // 6
                } else if ((hrs >= 21) && (hrs <= 34)) {
                    cheapst = B;
                    saving = 0;
                } else if (hrs >= 35) {
                    cheapst = C;
                    saving = cost - PLANC;
                } else cout << "Error in Case B else.\n";

                displayMsg(cost, cheapst, saving);
                
                break;
            }
            case 'c':
            case 'C': {
                
                //Basic Charges
                if (hrs >= 0) cost = PLANC;
                else cout << "Error case C hrs<1\n";

                //   CHEAPESET PLAN
                if (hrs >= 35) {
                    cheapst = C;
                    saving = cost - PLANC;
                } else if ((hrs >= 1) && (hrs <= 20)) {
                    cheapst = A;
                    saving = cost - pkgA(hrs);
                } else if ((hrs >= 21) && (hrs <= 34)) {
                    cheapst = B;
                    saving = PLANC - pkgB(hrs);
                } else cout << "Error in Case C else.\n";

                displayMsg(cost, cheapst, saving);
                
                break;
            }
            default: cout << "Error in switch package default.\n";
        }
        // catches invalid inputs
    } else cout << "Invalid input \n";

    //Exit
    return 0;
}

//  ********** FUNCTION DEFITIONS  *************
// *********************************************

// render output
void displayMsg(float bill, string cheapst, float save) {
    //Output the Charge
    cout << fixed << showpoint << setprecision(2);
    cout << setw(1) << "$" << setw(6) << left << bill;

    //Output the cheapest package and the savings
    cout << setw(2) << cheapst << setw(1) << "$" << save << endl;
}

// ******* PACKAGE B Prices  ******
float pkgB(int hrs) {
        
        float cost;
    if (hrs > 0) cost = PLANB;
    else cout << "Error case B hrs<1\n";

    if (hrs > 30) {
        cost += (10 * .74);
        cost += ((hrs - 30)*.64);
    } else if (hrs >= 21 && hrs <= 30) cost += ((hrs - 20)*.74);
    return cost;
}

// ******* PACKAGE A Prices  ******
float pkgA(int hrs) {
    
    float cost;
    if (hrs > 0) cost = PLANA;
    else cout << "Error case A hrs<1\n";

    if (hrs >= 21) {
        cost += (10 * .95);
        cost += ((hrs - 20)*.85);
    } else if (hrs > 10 && hrs < 21) cost += ((hrs - 10)*.95);
    
    return cost;
                
}

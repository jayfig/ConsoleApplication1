//here's my code:
#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "customer.h"
using namespace std;

/////////////		TELLER STRUCTURE		////////////////////
struct Teller_s {
	bool active;
	int time_At;
	int id;
	int count;
};


/////////////////		Main Function			//////////////////////
int main() {

	//VARIABLES TO BE USED
	int trans_Time;
	int num_Tellers;
	int arriv_Time;
	int i; 
	int customers;
	int wait_Time; 


	srand(time(0));
	
		i = 0;
		customers = 0; 
		wait_Time = 0;

		Customer bankQ; //Create Customers for bank.
		
		
		//Menu information

		cout << "Enter Number of Tellers: ";
		cin >> num_Tellers;
		while (num_Tellers <= 0 || num_Tellers > 2147483647) {
			cout << "Invalid input. Please try again :  ";
			cin >> num_Tellers;
		}

		//array for the teller
		Teller_s * tellArray = new Teller_s[num_Tellers];

		//Set all tellers to empty
		for (i = 0; i < num_Tellers; i++) {
			tellArray[i].active = false;
			tellArray[i].time_At = 0;
			tellArray[i].id = 0;
			tellArray[i].count = 0;
		}

		int total_trans_time = 0;
		int tempCus = 0;

		cout << "Please Enter number of customers " << endl;
		cin >> customers;
		while (customers < 0 || customers > 2147483647)
		{
			cout << "Invalid input. Please try again : ";
			cin >> customers;
		}
		int counter1 = 0;
		int wait = 0;
		while (customers > 0 ) { //Run until simulation customers reached
		
			trans_Time = rand() %5 + 1; //  assign random service time to customer.
			
			bankQ.enqueue(customers, trans_Time);
			
			//Run test on each server .
			//If server is open dequeue the customer from queue
			for (i = 0; i < num_Tellers; i++) {
				if (tellArray[i].active == false && bankQ.getSize() != 0) { 
					
					total_trans_time += trans_Time;

					tellArray[i].active = true;
					tellArray[i].time_At = trans_Time;
					tellArray[i].id = bankQ.front()->id;
					tellArray[i].count++;
					wait += trans_Time;// + bankQ.front()->enqueue_Time;
										
					cout << " server " << i << "  is serving customer  : " << tellArray[i].id << " with transaction time " << trans_Time <<  endl << endl;
					cout << "Customer waited  " << wait << " time units  :" << endl;
					bankQ.dequeue();
					
				
				} 
				
			}


			for (i = 0; i < num_Tellers; i++) {
				if (tellArray[i].active == true) {
					tellArray[i].time_At--;  //Decrement time spent at teller
					
				}
				if (tellArray[i].time_At == 0) {
					tellArray[i].active = false; //Set teller to open when customer is served.
				}
			}
			wait_Time += bankQ.getSize(); //Set wait time to persons left in Queue*/
		
			--customers;
			tempCus++;
			
			

		}
		//Output user input data
		cout << "After simulation: " << endl;

		cout << "TOTAL TRANSACTION TIME " << total_trans_time << endl;

		cout << "AVERAGE TOTAL WAIT TIME " << (float) wait_Time / tempCus << endl;
		//Deallocate teller structure array
		delete[] tellArray;
	//}
	return 0;
}
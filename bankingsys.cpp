#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

inline void nodata(int total){ if(total==0) cout<<"DATABASE IS EMPTY"<<endl;}
inline void datasaved(){ cout<<" CHANGES SAVED SUCCESSFULLY "<<endl;}
inline void enter(){cout<<"Enter ID to ";}
inline void invalid(){cout<<"INVALID INPUT";}

class Bank{
	private: 
	    int total;
	    string id;
	    struct person
        {   string name,ID,address;
	    	int contact,cash;
		}person[100];
        
	public:
		Bank(){total=0;}

		void choice();
		void perData();
		void show();
		void update();
		void search();
        void transactions();
        void del();
};
 
void Bank::choice(){
	char ch;
	while(1){
		cout<<"\n\nPRESS..!!"<<endl;
		cout<<"_________________________"<<endl;
		cout<<"1.TO CREATE ACCOUNT."<<endl;
		cout<<"2.TO VIEW ACCOUNTS."<<endl;
		cout<<"3.TO UPDATE ACCOUNT."<<endl;
		cout<<"4.TO SEARCH ACCOUNT."<<endl;
		cout<<"5.FOR TRANSACTIONS."<<endl;
		cout<<"6.TO REMOVE ACCOUNT."<<endl;
		cout<<"7.TO EXIT "<<endl;
		cout<<"_________________________"<<endl;
		cout<<"Enter your choice : ";cin>>ch;
		system("CLS");

		switch(ch){
			case '1':Bank::perData();
			    	break;
			case '2':if(total==0) nodata(total) ;
                	else Bank::show();
			    	break;
			case '3':if(total==0) nodata(total);
			    	else Bank::update();
			    	break;
			case '4':if(total==0) nodata(total);
			    	else Bank::search();
			    	break;
			case '5':if(total==0) nodata(total);
			    	else Bank::transactions();
			    	break;
			case '6':if(total==0) nodata(total);
			    	else Bank::del();
			    	break;
			case '7':exit(0);
			    	break;
			default:invalid();
			    	break;
		}
    }
}
void Bank::perData()
{
	cout<<"Enter data of person "<<total+1<<endl;
	cout<<"_________________________"<<endl;
	cout<<"Enter name      : ";cin>>person[total].name;
	cout<<"Enter ID        : ";cin>>person[total].ID;
	cout<<"Enter Address   : ";cin>>person[total].address;
	cout<<"Enter Contact   : ";cin>>person[total].contact;
	cout<<"Enter Balance   : ";cin>>person[total].cash;
	total++;
    system("CLS");
    datasaved();
}
void Bank::show(){
	for(int i=0;i<total;i++){
	cout<<"Data of person "<<i+1<<endl;
	cout<<"1. Name     | "<<person[i].name<<endl;
        cout<<"2. ID       | "<<person[i].ID<<endl;
        cout<<"3. Address  | "<<person[i].address<<endl;
        cout<<"4. Contact  | "<<person[i].contact<<endl;
        cout<<"5. Balance  | "<<person[i].cash<<endl;
        cout<<"_________________________"<<endl;
	}
}
void Bank::update(){
	enter() ; cout<<"Update : ";
	cin>>id;
	for(int i=0;i<total;i++)
    {	bool flag = true ;
		if(id==person[i].ID)
        {
        	cout<<"_________________________"<<endl;
		cout<<"Present Data of person "<<i+1<<endl;
		cout<<"1. Name     |"<<person[i].name<<endl;
        	cout<<"2. ID       |"<<person[i].ID<<endl;
        	cout<<"3. Address  |"<<person[i].address<<endl;
        	cout<<"4. Contact  |"<<person[i].contact<<endl;
        	cout<<"5. Balance  |"<<person[i].cash<<endl;
        	cout<<"_________________________"<<endl;
		cout<<"\nEnter new data"<<endl;
		cout<<"1. Enter New Name    : "; cin>>person[i].name;
        	cout<<"3. Enter New Address : "; cin>>person[i].address;
        	cout<<"4. Enter New Contact : "; cin>>person[i].contact;
        	cout<<"_________________________"<<endl<<endl;
			datasaved();
			cout<<endl;
			cout<<"_________________________"<<endl<<endl;
			Sleep(1000);
			break;
		}

		if(i==total-1){ 
			cout<<"_________________________"<<endl<<endl;
			cout<<"ID NOT PRESENT" <<endl;
			cout<<"_________________________"<<endl<<endl;
			Sleep(1000); 
			
			}
	}
	system("CLS");
	
}
void Bank::search(){
	enter() ; cout<<"Search ";cin>>id;
	for(int i=0;i<total;i++)
	{
		if(id==person[i].ID)
    	{	cout<<"DATA IS PRESENT : "<<endl;
        	cout<<"_________________________"<<endl;
			cout<<"1. Name     |"<<person[i].name<<endl;
        	cout<<"2. ID       |"<<person[i].ID<<endl;
    		cout<<"3. Address  |"<<person[i].address<<endl;
    		cout<<"4. Contact  |"<<person[i].contact<<endl;
    		cout<<"5. Balance  |"<<person[i].cash<<endl;
        	cout<<"_________________________"<<endl;
			Sleep(2000);
			break;
			
		}
		if(i==total-1) {
        	cout<<"_________________________"<<endl<<endl;
			cout<<"ID NOT PRESENT"<<endl;
        	cout<<"_________________________"<<endl<<endl;
			Sleep(1000);}
	}
	system("CLS");
}
void Bank::transactions(){
	int cash;
    int i ; 
	char ch;
	back1 :
	enter();cout<<"Transaction : ";cin>>id;
     for(i=0;i<total;i++)
     {
     	if(id==person[i].ID)
        {	back:
			cout<<"Name		| "<<person[i].name<<endl;
        	cout<<"Balance		| "<<person[i].cash<<endl;
        	cout<<"_________________________"<<endl;
            	cout<<"Press 1 to DEPOSIT"<<endl;
		cout<<"Press 2 to WITHDRAW"<<endl;
		cout<<"Enter your choice : ";cin>>ch;
        	cout<<"_________________________"<<endl;

		    switch(ch){
		     	case '1':
		     		cout<<"deposit amount : ";cin>>cash;
		     		person[i].cash+=cash;
		     		cout<<"_________________________"<<endl;
					cout<<"NEW BALANCE : "<<person[i].cash<<endl;
					cout<<"_________________________"<<endl;
		     		break;

		     	case '2': cout<<"withdraw amount : ";cin>>cash;
		     			if(cash>person[i].cash){
        					cout<<"_________________________"<<endl;
		     				cout<<"INSUFFICIANT BALANCE "<<person[i].cash<<endl;
 				       		cout<<"_________________________"<<endl;
		     				Sleep(2000);
							system("CLS");
		     				goto back;
					 		}
					 	person[i].cash-=cash;
						cout<<"_________________________"<<endl;
					 	cout<<"NEW BALANCE : "<<person[i].cash<<endl;
						cout<<"_________________________"<<endl;
						break;
				default:
					invalid();
					break;
			 }
			break;
		}
		if( i ==total-1){
			int re  = 0; 
		 	cout<<"INVALID ID"<<endl;
			cout<<"Press 1..to Renter id "<<endl ;
			cout<<"Press other..to Exit "<<endl ;
        	cout<<"_________________________"<<endl;
        	cout<<"Enter your choice : "; cin>>re ; cout<<endl ;
			if(re == 1) goto back1 ;
		 }
	 }
	 Sleep(2000);
	 system("CLS");
}
void Bank::del(){
	char ch;
	cout<<"Press 1 to remove a record"<<endl;
	cout<<"Press 2 to remove ALL record"<<endl;
	cout<<"_________________________"<<endl;
	cout<<"Enter yor choice : ";cin>>ch ;cout<<endl;
	switch(ch)
    {
	        case '1':enter();cout<<"Remove : ";cin>>id;
                    for(int i=0;i<total;i++){
                     if(id==person[i].ID){
                        for(int j=i;j<total;j++){
                            person[j].name=person[j+1].name;
                            person[j].ID=person[j+1].ID;
                            person[j].address=person[j+1].address;
                            person[j].contact=person[j+1].contact;
                            person[j].cash=person[j+1].cash;
                            total--;
                            cout<<"_____________________"<<endl;
	 	            cout<<"RECORD DELETED"<<endl;
			    cout<<"_____________________"<<endl;
                            break;
                            }
                        } 
                        if(i==total-1) nodata(total) ;
                    }
	                break;
	        case '2':total=0;
			cout<<"_____________________"<<endl;
	 	        cout<<"All RECORDS DELETED"<<endl;
			cout<<"_____________________"<<endl;
	         	    break;
	        default: invalid();
                    break;
	}

}

int main(){
	Bank Ambikesh;
	system("CLS");
	Ambikesh.choice();
	return 0;
}


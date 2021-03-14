#include<iostream>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<sstream>//type cast cons char-int
using namespace std;
class pas
{
   int c=0;
   char pass[7];
   char r[7] ="maahii";
   int p;
   public:
   	void pwd()
   	{  p:
   		
	   cout << " enter password to access shop: \t";
		for ( int i = 0;i < 6;i++ )
	   {l:
          pass[i] = getch();
          cout << "*";
          if(int(pass[i]==8))
          {
		  cout<<"\b";
          i=i-1;
          if(c!=0)
          c=c-1;
		  system("cls");
		   cout << " enter password to access shop: \t"<<string(i,'*');
		   goto l;
	}
       }
        for ( int j = 0;j <6;j++ )
       {
           if ( pass[j] == r[j] )
           c = c + 1;
       }
        if ( c != 6 )
    
           {
		   cout << "   Invalid Password,try again\n";
		   c=0;
           goto p;}         
	}friend class display;
	friend class customer;  	
};
class display
{
public:
	void dis(pas q)
	{
		if(q.c==6)
		system("cls");
		system("color 7D");
		cout<<("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		cout<<"                                                                          WELCOME TO laptop gallery    \n";
		cout<<("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		cout<<("things that available in our shop: \n");
		cout<<("                                                               'COMPONENTS','CLEANING','SOFTWARES','GAMES '\n");
		cout<<("_____________________________________________________________________\n");
		cout<<("|enter below number to perform those specific options                |\n");
		cout<<("|____________________________________________________________________|\n\n");
		cout<<("    ____________________________________________________________________\n");
		cout<<("   |   1.Enter Customer Details in order as name,phone no,prob,date     |\n");
	    cout<<("   |____________________________________________________________________|\n");
		cout<<("   |   2.bill in order as solution,purchased item or type of work,price |\n");
	    cout<<("   |____________________________________________________________________|\n");
		cout<<("   |   3.search by tag no to know details and paid or not               |\n");
		cout<<("   |____________________________________________________________________|\n");
		cout<<("   |   4.search by date                                                 |\n");
        cout<<("   |____________________________________________________________________|\n");
		cout<<("   |   5.total collection upto now                                      |\n");		
        cout<<("   |____________________________________________________________________|\n"); 
	}
	friend class customer;
	friend class search;
	friend class collect;
};
class customer
{   
	char name[40],solution[90],purchased[150],prob[100];
	int val,phoneno,date,price,collection,tag;
	public:		
	void data(display d,pas q)
	{ first:
	  cin>>val;
	if(val==1)
	{   cout<<"name:-";
	    cin.ignore();
		
		 cout<<"______________________________________________________________________________\n";
		cout<<"|   type          |  hardware issuess |  software issuess  |    servecing     |\n";
		cout<<"|_________________|___________________|____________________|__________________|\n";
		cout<<"|   price         |        3,500      |       1,000        |        700       |\n";
		cout<<"|_________________|___________________|____________________|__________________|\n";
		cout<<"|   time          |       2-3 days    |     4-5 hours      |      1-2 days    |\n";
		cout<<"|_________________|___________________|____________________|__________________|\n";
		cin.getline(name,40);
		cout<<"prob:-";
		cin.getline(prob,100);
		cout<<"phone no:- ";
		cin>>phoneno;
		  time_t now = time(0);
	        tm *ltm = localtime(&now);
		 	int day=ltm->tm_mday;
	        int mont=1+ltm->tm_mon;
        	int year=1900+ltm->tm_year;
        	ofstream out("customer.json",ios::app|ios::out);	 
		 out<<name<<","<<phoneno<<","<<prob<<","<<day<<"/"<<mont<<"/"<<year<<",";
		 out.close(); 
		 ifstream in("customer.json");
	    string date,name,phone,prob,e,tag;
	    int col;
	      while(getline(in,name,','))
	      {    getline(in,phone,',');
		      getline(in,prob,',');
		      getline(in,date,',');
		      getline(in,tag,',');
		       getline(in,e,'\n');
		        stringstream strvalue;
	          strvalue<<tag;
	          signed int z;
	          strvalue>>z;
	          col=z;
			  }
			  
			  in.close();
			  	ofstream ou("customer.json",ios::in|ios::app);
			  if(col==0||col==NULL)
			  {
			  	cout << "YOUR assigned tage no is    "<<1223;
			  	ou<<1223<<","<<endl;
						   }
				else
				{
                  ou<<col+1<<","<<endl;
				  cout<<"your assigned tag no is"<<col+1<<endl;}
		     
	}
	if(val==2)
	{
		cout<<"solution:- ";
		cin.ignore();
		cin.getline(solution,90);
		cout<<"item purchased:- ";
		cin.getline(purchased,150);
		cout<<"price:- ";
		cin>>price;
        ofstream out("custbill.json",ios::app);	 
		 out<<solution<<","<<purchased<<","<<price<<","<<endl;
		 out.close(); 
	}
	if(val==3)
{ ifstream in("customer.json");
	    string date,name,phone,prob,e,tag,tagno;
	    cout<<"enter tag no to know your details  :-  ";
	    cin>>tagno;
	    
	      while(getline(in,name,','))
	      {    getline(in,phone,',');
		      getline(in,prob,',');
		      getline(in,date,',');
		      getline(in,tag,',');
		       getline(in,e,'\n');
		        if(tag==tagno)
			   cout<<"name is :-  "<<name<<"\n"<<"phone no is :-  "<<phone<<"\n"<<"prob is :-  "<<prob<<"\n"<<"date registered :-  "<<date
			   <<"\n"<<"tagno is :-  "<<tag<<"\n";
			   }		       
		       in.close();			  
			   }
	 if(val==4)
   		{
   		ifstream in("customer.json");
	    string date,name,phone,prob,e;
	    string dae;
	    cout<<"enter date in written format to search as dd/m/yyyy :-   ";
	    cin>>dae;
	      while(getline(in,name,','))
	      {    getline(in,phone,',');
		      getline(in,prob,',');
		      getline(in,date,',');
		      getline(in,e,'\n');
		      if(date==dae)
	              cout<<"name is :-  "<<name<<"\n"<<"phone no is :-  "<<phone<<"\n"<<"prob is :-  "<<prob<<"\n"<<"date registered :-  "<<date<<"\n"<<"\n";	
	}
	in.close();}
	if(val==5)
 	{    ifstream in("custbill.json",ios::in|ios::app);
	    string solution,purchased,e;
	    string price;
	    int col=0;
	      while(getline(in,solution,',')) 
	      {   getline(in,purchased,',');
	          getline(in,price,',');
	          getline(in,e,'\n');
	          stringstream strvalue;
	          strvalue<<price;
	          signed int z;
	          strvalue>>z;
	          col=col+z;	          
          }   cout<<"Total Collection upto now :)    --->    "<<"Rs."<<col<<endl;
	  }		
		int back;
	if(val==1|val==2|val==3|val==4|val==5)	
	{cout<<"press 0 to go back  :- ";	
	cin>>back;}
	if(back==0)
	{
	 d.dis(q);
	 goto first;	
		 }	
	}
};
 int main()
{
	system("color 5B");
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"  \t\t                                             _ _ _ _        _ _ _ _ _ _     _ _ _ _ _       _ _ _ _  \n";	
	cout<<"  \t\t                   |                /\\      |       |           |          |         |     |       | \n";
    cout<<"  \t\t                   |               /  \\     |       |           |          |         |     |_ _ _ _| \n";
    cout<<"  \t\t                   |              /____\\    |_ _ _ _|           |          |         |     |         \n";
    cout<<"  \t\t                   |             /      \\   |                   |          |         |     |         \n";                
    cout<<"  \t\t                   |_ _ _ _ _   /        \\  |                   |          |_ _ _ _ _|     |         \n"<<endl<<endl<<endl;
   cout<<"   \t\t                     _ _ _ _ _                                                                        \n";
   cout<<"   \t\t                    /                   /\\       |              /\\        \\    /     \\      /     \n";
   cout<<"   \t\t                   |                   /  \\      |             /  \\        \\  /       \\    /      \n";
   cout<<"   \t\t                   |       _ _ _      /____\\     |            /____\\        \\/         \\  /       \n";
   cout<<"   \t\t                   |      |     |    /      \\    |           /      \\       /\\          \\/        \n"; 
   cout<<"   \t\t                   |      |     |   /        \\   |          /        \\     /  \\         /          \n";                                               
   cout<<"   \t\t                   |_ _ _ |     |  /          \\  |_ _ _ _  /          \\   /    \\       /           \n"<<endl<<endl<<endl<<endl<<endl;
  
   pas s;
   display d;
   customer c;
   s.pwd();
   d.dis(s);
   c.data(d,s);  
}


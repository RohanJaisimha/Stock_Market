//Header Files
#include<iostream>
#include<limits.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<fstream>
using namespace std;
int user_count()
{
	int count_user;
	ifstream fout;
	fout.open("CountingUsers.txt",ios::in);
	fout>>count_user;
	fout.close();
	return count_user;
}
//returns number of users registered
//end of function
struct str
{
	char a;
}print;
//end of structure
unsigned int seedval;
time_t t;
int randnum,counting=0,MarketValue[3],FaceValue[3]={50,40,30},company,cost,Apple=0,Microsoft=0,IBM=0,budget1,comp,sharesone[3]={0,0,0},count_user=user_count();
char companyname[3][6]={"Apple","Acer","IBM"},ch,t1,t2,password[80],name_from_kb[80],pass_from_kb[80];
//end of global variables
class User
{
	//access specifier
	public:
		int budget,shares[3];
		char username[80];
		char encrypted_password[80];
		//encryption method
		//constructor
		User()
		{
			shares[0]=shares[1]=shares[2]=0;
		}                      
		//function for purchasing
		void p()
		{
			system("cls");
			cout<<"\t\t\t\tPurchasing\n";
			cout<<"\t\t\t\t^^^^^^^^^^\n";
			cout<<"\nPlease select which company to invest in\n";
			cout<<"Serial Number\t\tCompany\t\tFace Value(Rs.)\n";
			cout<<"^^^^^^ ^^^^^^\t\t^^^^^^^\t\t^^^^ ^^^^^\n";
			cout<<"1\t\t\t"<<companyname[0]<<"\t\t\t"<<FaceValue[0]<<"\n";
			cout<<"2\t\t\t"<<companyname[1]<<"\t\t\t"<<FaceValue[1]<<"\n";
			cout<<"3\t\t\t"<<companyname[2]<<"\t\t\t"<<FaceValue[2]<<"\n";
			cout<<"Enter your choice(1,2 or 3)\n";
			cin>>t1;
			if(t1>=48 && t1<=57)
			{
				company=t1-48;
			}
			if(company>3 || company <1)
			{
				cout<<"Error: Company number does not exist\n";
				cout<<endl;
				system("pause");
				p();
				return;
			}
			cout<<"Enter the number of shares\n";
			int temp4;
			cin>>temp4;
			cost=temp4*((FaceValue[(company-1)]));
			if(cost>budget)
			{
				cout<<"Error:Cost is in excess of budget by Rs."<<cost-budget;
				cout<<endl;
				system("pause");
				p();
				return;
			}
			budget-=cost;
			shares[company-1]+=temp4;
			cout<<"You purchased "<<shares[company-1]<<" shares in the company "<<companyname[company-1]<<" for a total cost of Rs."<<cost<<"\n";
			cout<<"You now have a budget of Rs."<<budget<<"\n";
			cout<<"Would you like to purchase(P) or sell shares(S) or quit(Q)?\n";
			cin>>ch;
			if(ch=='P' || ch=='p')
			{
				cout<<endl;
				system("pause");
				p();
				return;
			}
			if(ch=='S' || ch=='s')
			{
				cout<<endl;
				system("pause");
				s();
				return;
			}
			if(ch=='Q' || ch =='q')
			{
				cout<<endl;
				system("pause");
				return ;
			}
		} 
		//function for selling
		void s()
		{
			system("cls");
			cout<<"\t\t\t\tSelling\n";
			cout<<"\t\t\t\t^^^^^^^\n";
			cout<<"Serial Number\t\tCompany\t\tMarket Value(Rs.)\t\tNumber of Shares\n";       
			cout<<"^^^^^^ ^^^^^^\t\t^^^^^^^\t\t^^^^^^ ^^^^^     \t\t^^^^^^ ^^ ^^^^^^\n";
			int j=0;
			for(int i=0;i<3;i++)
			{
				randnum=(rand())%31;           
				int randnum1=rand();
				if((randnum1%2)==0)
				{
				    MarketValue[i]=FaceValue[i]+randnum;
				}
				else
				{
				    MarketValue[i]=FaceValue[i]-randnum;
				}
			}			   
			cout<<"1\t\t\t"<<companyname[0]<<"\t\t\t"<<MarketValue[0]<<"\t\t\t\t"<<shares[0]<<"\n";			   
			cout<<"2\t\t\t"<<companyname[1]<<"\t\t\t"<<MarketValue[1]<<"\t\t\t\t"<<shares[1]<<"\n";			    
			cout<<"3\t\t\t"<<companyname[2]<<"\t\t\t"<<MarketValue[2]<<"\t\t\t\t"<<shares[2]<<"\n";   
		    cout<<"Enter The company whose shares you would like to sell\n";               
		   	int comp,sharesone[3]={0,0,0};
		    cin>>t2;
			if(t2>=48 && t2<=57)
			{
				comp=t2-48;
			}
			if(comp!=1 && comp!=2 && comp!=3)
			{
				cout<<"Error:Company number does not exist\n";
				cout<<endl;
				system("pause");
				s();
				return;
			}
			cout<<"Enter the number of shares that you would like to sell\n";
			cin>>sharesone[comp-1];
			for(int i=0;i<3;i++)
			{
			// Checking if they have sold more shares than they have purchased
			    if(sharesone[i]>shares[i])    
			    {
				    cout<<"Error: Invalid number of shares\n";
				    cout<<endl;
				    system("pause");
				    s();
				    return;
			    }
			}
			budget=budget+((MarketValue[(comp-1)])*sharesone[(comp-1)]);
			cout<<"You just sold "<<sharesone[comp-1]<<" shares in the company "<<companyname[comp-1]<<"\n";
			cout<<"Your new budget is Rs."<<budget<<"\n";       
			cout<<"Would you like to purchase(P) or sell shares(S) or Quit(Q)?\n";
			cin>>ch;
			for(int j=0;j<3;j++)
			{
				FaceValue[j]=MarketValue[j];
				shares[j]-=sharesone[j];
			}     
			if(ch=='P' || ch=='p')
			{
				cout<<endl;
				system("pause");
			    p();
			    return;
			}
			if(ch=='S' || ch=='s')
			{   
				cout<<endl;
				system("pause");
			    s();
			    return;
			}
			if(ch=='Q'||ch=='q')
			{
				cout<<endl;
				system("pause");
				return;
			}
		}
		//function for already registered users
		void main_for_already_created()
		{
			system("cls");
			print.a='\n';
			cout<<"\n\t\t\tKNIGHTS OF THE STOCK MARKET"<<print.a;
			cout<<"\t\t\t^^^^^^^ ^^ ^^^ ^^^^^ ^^^^^^\n";
			budget1=budget;
			seedval=(unsigned) time (&t);
			srand(seedval);
			cout<<"You currently have Rs."<<budget<<"\n";
			for(int i=0;i<3;i++)
			{
				cout<<"You have "<<shares[i]<<" shares in "<<companyname[i]<<"\n";
			}
			cout<<"Would you like to: \n1.Sell Stocks\n2.Purchase Stocks\n";
			char ch;
			cin>>ch;
			if(ch>=48 && ch<=57)
			{
				if(ch=='1')
				{
					cout<<endl;
					system("pause");
					s();
				}
				else if(ch=='2')
				{
					cout<<endl;
					system("pause");
					p();
				}
				else
				{
					cout<<"Error: Invalid Choice\n";
					cout<<endl;
					system("pause");
					return ;
				}
			}
			else
			{
				cout<<"Error: Invalid Choice\n";
				cout<<endl;
				system("pause");
				return ;
			}
			//checking for profit
			if(budget>budget1)
			{
				cout<<"You made a profit of Rs."<<(budget-budget1);
			}
			//checking for loss
			else if(budget<budget1)
			{
				cout<<"You made a loss of Rs."<<(budget1-budget);
			}
			//checking if they broke even
			else if(budget==budget1)
			{
				cout<<"You made no loss or profit";
			}
			cout<<"\n";
			return ;
		}
		//function for new users
		void main_for_newly_created()
		{
			accept:
			{
				system("cls");
				print.a='\n';
				cout<<"\n\t\t\tKNIGHTS OF THE STOCK MARKET"<<print.a;
				cout<<"\t\t\t^^^^^^^ ^^ ^^^ ^^^^^ ^^^^^^\n";
				{
					cout<<"Enter your required budget(>=500)\n";
					cin>>budget;
					if(budget<500)
					{
					cout<<"\n\nPlease enter a valid budget\n";
					cout<<endl;
					system("pause");
					goto accept;
					}
				}
			}
			budget1=budget;
			seedval=(unsigned) time (&t);
			srand(seedval);
			cout<<"\n";
			cout<<endl;
			system("pause");
			p();
			if(budget>budget1)
			{
				cout<<"You made a profit of Rs."<<(budget-budget1);
			}
			else if(budget<budget1)
			{
			cout<<"You made a loss of Rs."<<(budget1-budget);
				}
			else if(budget==budget1)
			{
				cout<<"You made no loss or profit";
			}
			cout<<"\n";
			return ;
		}
		//function for creating an account
		bool Create_Account()
		{
			system("cls");
			User u2[10];
			if(count_user==10)
			{
				cout<<"\nError: Max. Login Limit Reached\n";
				cout<<endl;
				system("pause");
				return false;
			}
			cout<<"\t\t\t\tAccount Creation\n";
			cout<<"\t\t\t\t^^^^^^^ ^^^^^^^^\n";
			cout<<"Enter your required username and password (both max. 80)\n";
			cout<<"Username: ";
			cin>>username;
			ifstream fout1("Database.txt",ios::binary|ios::in);
			int i=0;
			while(i<count_user-1)
			{
				fout1>>u2[i].budget;
				for(int j=0;j<3;j++)
				fout1>>u2[i].shares[j];
				fout1>>u2[i].username>>u2[i].encrypted_password;
				i++;
			}
			fout1.close();
			for(int j=0;j<count_user-1;j++)
			{
				if(u2[i].username==username)
				{
					cout<<"Error:Username already exists\n";
					cout<<endl;
					system("pause");
					Create_Account();
					return true;
				}
			}
			//unique username
			int count_special_char=0,count_num=0,count_upper_alpha=0,count_lower_alpha=0;
			for(int j=0;j<strlen(username);j++)
			{
				if(username[j]>='0' && username[j]<='9')
					count_num++;
				else if(username[j]>='a' && username[j]<='z')
					count_lower_alpha++;
				else if(username[j]>='A' && username[j]<='Z')
					count_upper_alpha++;
				else
					count_special_char++;
			}
			if(count_num==0 || count_lower_alpha==0 || count_upper_alpha==0 || count_special_char==0)
			{
				cout<<"\nError: Username must have atleast one number,lowercase alphabet,uppercase alphabet and a special character\n";
				cout<<endl;
				system("pause");
				Create_Account();
			}
			cout<<"Password: ";
		    i=0;
		    while(password[i-1]!='\r')
		    {
				password[i]=getch();
				cout<<"*";
				i++;
		    }
			password[i-1]='\0';
			count_special_char=count_num=count_upper_alpha=count_lower_alpha=0;
			for(int j=0;j<strlen(password);j++)
			{
				if(password[j]>='0' && password[j]<='9')
					count_num++;
				else if(password[j]>='a' && password[j]<='z')
					count_lower_alpha++;
				else if(password[j]>='A' && password[j]<='Z')
					count_upper_alpha++;
				else
					count_special_char++;
			}
			strcpy(encrypted_password,strrev(password));
			for(int j=0;j<strlen(password);j++)
				encrypted_password[j]+=67;
			if(count_num==0 || count_lower_alpha==0 || count_upper_alpha==0 || count_special_char==0)
			{
				cout<<"\nError: Password must have atleast one number,lowercase alphabet,uppercase alphabet and a special character\n";
				cout<<endl;
				system("pause");
				Create_Account();
			}
			count_user++;
			return true;
		}
		//function to compare usernames and encrypted password
		bool Check()
		{
			counting+=1;
			int i=0;
			if(counting>1)
			{
				goto checking;
			}
			system("cls");
			cout<<"\t\t\t\tLogin\n";
			cout<<"\t\t\t\t^^^^^\n";
			cout<<"Username: ";
			cin>>name_from_kb;
			cout<<"Password: ";
			while(pass_from_kb[i-1]!='\r')
			{
			       pass_from_kb[i]=getch();
			       cout<<"*";
			       i++;
			}
			pass_from_kb[i-1]='\0';
			strrev(pass_from_kb);
			for(int j=0;j<strlen(pass_from_kb);j++)
				pass_from_kb[j]+=67;
			checking:
				if(strcmp(encrypted_password,pass_from_kb)==0 && strcmp(name_from_kb,username)==0)
				{
					cout<<"\n\nWelcome back!\n";
					cout<<endl;
					system("pause");
					return true;
				}
			return false;
		}
}u1[10];
//end of class
int main()
{
	//recieving data from file
	int i=0;
	if(count_user!=0)
	{
		ifstream fout1("Database.txt", ios::in);
		while(!fout1.eof())
		{
			fout1>>u1[i].budget;
			for(int j=0;j<3;j++)
			fout1>>u1[i].shares[j];
			fout1>>u1[i].username>>u1[i].encrypted_password;
			i++;
		}
		fout1.close();
	}
	accepting:
	    system("cls");
	    cout<<"\t\t\t\tWelcome\n";
	    cout<<"\t\t\t\t^^^^^^^\n";
	    cout<<"\nEnter your choice:\n";
	    cout<<"1.Create\n";
	    cout<<"2.Login\n";
	    char choice;
	    int pos=-1;
	    cin>>choice;
	    if(choice<48 || choice>58)
        {
         	cout<<"\nError: Invalid Choice(enter a number)\n";
         	system("pause");
         	goto accepting;
        }
        choice-=48;
	    if(choice==1)
	    {
		    if(u1[count_user].Create_Account()==false)
		    {
			    cout<<endl;
			    system("pause");
			    return 0;
		    }
		    cout<<"\n";
		    cout<<endl;
		    system("pause");
		    u1[count_user-1].main_for_newly_created();
	    }
	    else if (choice==2)
	    {
		    if(count_user==0)
		    {
			    cout<<"\nError:No users registered\n";
			    cout<<endl;
			    system("pause");
			    return 0;
		    }
		    for(int i=0;i<10;i++)
		    {
			    if(u1[i].Check()==true)
			    {
				    pos=i;
				    cout<<endl;
				    system("pause");
				    u1[pos].main_for_already_created();
				    break;
			    }
		    }
		    if(pos==-1)
		    {
			    cout<<"Error: No such record\n";
			    cout<<endl;
			    system("pause");
			    return 0;
		    }
	    }
	    else
	    {
		    cout<<"Error: Invalid Choice\n";
		    system("pause");
		    goto accepting;
	    }
	//re-storing all the data back into the files
	ofstream fin1("Database.txt", ios::out);
	i=0;
	while(i<count_user)
	{
		fin1<<u1[i].budget<<" ";
		for(int j=0;j<3;j++)
		fin1<<u1[i].shares[j]<<" ";
		fin1<<u1[i].username<<" "<<u1[i].encrypted_password<<"\n\n";
		i++;
	}
	ofstream fin2("CountingUsers.txt",ios::out);
	fin2<<count_user;
	fin1.close();
	fin2.close();
	cout<<endl;
	system("pause");
	return 0;
}
//end of program


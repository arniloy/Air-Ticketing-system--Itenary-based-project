//Arifur Niloy
//Professor Bill Slater
//Project Airline Ticketing system
//Date : 4/24/2014


#include<stdarg.h>
#include<iostream>
#include<string>
#include <time.h>

using namespace std;

void flightA(int,string[],int,int, int);

void flightB(int,string[],int,int, int);

void fly(string,int,int,string[]);

void flightReturn(string,int,int,string[]);


int main()
{
	string flightChoice;
	char ch;
	long int loungeA,loungeB;
	long int Lsize1,Lsize1Left,Lsize2,Lsize2Left;
	string passengerList1[100],passengerList2[100];
	int i=0,j=0;
	long long partySize;
	bool flightAlfa=true;
	bool flightAReturn=false,flightBReturn=false;
	cout<<"Welcome to Your Tree Top Airways Aka-- TTA"<<endl;
	cout<<"****=================================*****"<<endl;
	cout<<"ALPHA";
	cin>>Lsize1;
	Lsize1Left=Lsize1;
	cout<<endl;
	cout<<"BRAVO";
	cin>>Lsize2;
	Lsize2Left=Lsize2;
	cout<<endl;
	cout<<"Lounge Number: A";
	cin>>loungeA;
	cout<<"Lounge Number: B";
	cin>>loungeB;
	cout<<endl;
	do
	{
		cout<<"FLY";
		cin>>flightChoice;
		if(flightChoice=="ALPHA")
		{
			flightA(Lsize1,passengerList1,i,Lsize1Left,loungeA);
		}
		else if(flightChoice=="BRAVO")
		{
			flightB(Lsize2,passengerList2,j,Lsize2Left,loungeB);
		}
		else
		{
			cout<<"Not The correct flight choice/Number for you ";
			exit(0);
		}

	}while(flightChoice!="N");
	cout<<endl;
	cout<<"Want to fly without filling (Y/N):";
	cin>>ch;
	if(ch=='y')
		fly(flightChoice,0,0,0);
	system("pause");
	return 0;
}
void flightA(int Lsize1,string passengerList1[],int i,int Lsize1Left, int loungeA)
{
	int partySize=0;
	cout<<"Enter party name:";
	cin>>passengerList1[i];
	i++;
	cout<<"Enter passenger size";
	cin>>partySize;
	if(partySize>Lsize1)
		cout<<"Flight is full.";
	else if(partySize>Lsize1Left)
	{
		if(partySize<loungeA)
		{
			cout<<"Please wait in the lounge";
			loungeA-=partySize;
		}
		else
			cout<<"You are requested to plan your trip later as there is not enough space in the flight and lounge.! Have a good day! TTA";
	}
	else
	{
		cout<<"Your booking is confirmed! Have a safe journey!";
		Lsize1Left-=partySize;
	}
	fly("ALPHA", Lsize1Left, Lsize1, passengerList1);
}
void flightB(int Lsize2,string passengerList2[],int j,int Lsize2Left, int loungeB)
{
	int partySize;
	cout<<"Enter party name:";
	cin>>passengerList2[j];
	j++;
	cout<<"Enter passenger size";
	cin>>partySize;
	if(partySize>Lsize2)
		cout<<"Flight is full.";
	else if(partySize>Lsize2Left)
	{
		if(partySize<loungeB)
		{
			cout<<"Please wait in the lounge";
			loungeB-=partySize;
		}
		else
			cout<<"You are requested to plan your trip later as there is not enough space in the flight and lounge.! Have a good day!";
	}
	else
	{
		cout<<"Your booking is confirmed! Have a safe journey!";
		Lsize2Left-= partySize;
	}
	fly("ALPHA", Lsize2Left, Lsize2, passengerList2);
}
void fly(string flightChoice,int LsizeLeft,int Lsize,string passengerList[])
{
	if(LsizeLeft==0 && Lsize!=0)
	{
		if(flightChoice=="ALPHA")
			cout<<"ALPHA Flight ready to fly";
		else
			cout<<"BRAVO Flight ready to fly";
		cout<<"Passenger List:";
		for(int i=0;i<Lsize;i++)
		{
			cout<<passengerList[i];
		}
	}
	else
		cout<<"Flying as per clerk entREY: ";
}

void flightReture(int lounge,string flightChoice,int LsizeLeft,int Lsize,string passengerList[])
{
	if(lounge>0)
	{
		if(lounge<Lsize)
		{
			LsizeLeft=Lsize-lounge;
			lounge=0;
			//fly(flightChoice,LsizeLeft,Lsize,passengerList);
		}
		else if(lounge>Lsize ||lounge==Lsize)
		{
			lounge-=Lsize;
			LsizeLeft=0;
			fly(flightChoice,LsizeLeft,Lsize,passengerList);
		}
		else
		{
			cout<<"Flight available";
		}
	}
	else
	{
		cout<<"Flight available";
	}
}
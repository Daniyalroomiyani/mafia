
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime> // for std::time()
#include<iostream>
#include<string>
using namespace std;


bool MafiaFlag = false , GodfatherFlag = false , DoctorFlag= false , DetectiveFlag = false , CitizenFlag= false;
int MafiaNum=0 , CitizenNum , CurrentCitizenNum =0;


struct Persion
{
	string name;
	int role;
	/*
	roles : 
	1=>> Mafia(2)
	2=>> GodFather
	3=>> Citizen
	4=>> Doctor
	5=>> Detective
	*/};



int GetRole();
string printrole(int);
void SplitNames(string , string [] , int);

int main(){
	
	string  str , playerNames="";
	int playerNum= 0  ;

	//playerNames = "dani-ali-mmd-reza-hosein-hamid-end-";
	//playerNum = 6;

	do{
		cout << " Enetr The Player Name (Enter \"end\" To split roles) : ";
		cin >> str ;
		playerNames += str+ "-";
		playerNum++;
	}while(str != "end");
	playerNum--;//to make entered "end" not a persion
	if(playerNum < 8 )
	{
		cout << "Not Enough Players ....";
//		getch();
		return 0;
	}
	
	CitizenNum = playerNum -5;
	string *Names = new string[playerNum];
	
	Persion *Players = new Persion[playerNum];
	SplitNames(playerNames , Names , playerNum);
	
	for ( int i = 0 ; i< playerNum  ; i++ )
	{
	
		Players[i].name = Names[i];
		Players[i].role = GetRole();
		//cout << Names[i]<<endl;

	}

	for ( int i = 0 ; i< playerNum  ; i++ )
		cout <<"Player Name : " << Players[i].name << "	"<<"Role : "<<  printrole(Players[i].role)<<endl;




}

void SplitNames(string str, string fillarray[] , int len){
	
	//erase end in string
	str.erase(str.length() - 5 , 4);
	int counter = 0 ;//for array index

	for (int i = 0 ; i< str.length() ;i++)
	{
		if (str[i] == '-' )
		{
			fillarray[counter] = str.substr(0 , i); 
			str.erase(0 ,i+1);
			counter++;
			//cout << str <<endl;
			i =0;// to start in first index again
		}
	}

}

int GetRole(){
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	bool Accepted =false;
	int r ;
	int roleNum = -1 ;
	while (!Accepted)
	{
		r  =((rand()%1000) * rand()%1000) %1000;
		//cout << "	r = "<<r<<endl;
		if (r > 0 &&r<=200)
			if(!MafiaFlag)
			{
				Accepted =true;
				MafiaNum++;
				roleNum = 1;
				if(MafiaNum == 2 )
					MafiaFlag = true;

			}
		if(r >200 &&r<=400) 
			if(!GodfatherFlag)
			{
					Accepted  = true;
					GodfatherFlag = true;
					roleNum  = 2;
			}
		if(r >400 && r<=600)
				if(!CitizenFlag)
				{
					Accepted =true ; 
					CurrentCitizenNum++;
					roleNum = 3;
					if(CitizenNum == CurrentCitizenNum)
						CitizenFlag=true;
				}
		if (r >600 && r<= 800)
			if (!DoctorFlag)
			{
				Accepted =true;
				DoctorFlag =true;
				roleNum=4;
			}
		if(r >800 )
			if(!DetectiveFlag)
			{
				Accepted=true;
				DetectiveFlag=true;
				roleNum = 5;
			}
	}
	return roleNum;
}


string printrole(int r) {

	string role;
	switch(r){
	case	 1 : 
		role= "Mafia";
		break;
	case 2 : 
		role= "GodFather";
		break;
	case 3 : 
		role= "Citizen";
		break;
	case 4 : 
		role= "Doctor";
		break;
	case 5 : 
		role= "Detective";
		break;

	}
	return role;
}

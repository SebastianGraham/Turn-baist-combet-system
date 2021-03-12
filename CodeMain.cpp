#include <cstdlib>//arow key manu
#include <conio.h>//arow key manu
#include <dirent.h>
#include <iostream> //press enter funksjon og mer?
#include <limits> //press enter funksjon
#include <windows.h>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
//______FUNCSONS END gotoXY_________________
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for gotoXY
COORD CursorPosition; // used for gotoXY
	void gotoXY(int, int);//definer gotoXY funksjonen
	
void PressEnterToContinue(){ //enter to continu funsksonen
  bool EnterToStopWhile = true;
  printf( "Press ENTER to continue... " );
  fflush( stdin); //dette tømer allt in
  while(EnterToStopWhile){//veneter på enter tryk
	 if(GetAsyncKeyState(VK_RETURN)){  EnterToStopWhile=false;};
  } fflush( stdin);
  }
//________----________PLAYER Funcsons_______----___________
class player{ //dette er en klaseinfor coden
 	//private:
 	protected:
    	std::string name;
    	//double hp;
    	int def, atc, speed;
        
    public: //ting programe can bruke direkte
    			double hp;
    	std::string GetName(){return name;}
    		void SetName(std::string name){this->name = name;} 
 	 	double GetHp(){return hp;}
 			void SetHp(double hp){this->hp =hp;}
 		double GetDef(){return def;}
 			void SetDef(double def){this->def =def;}
 		double GetAtc(){return atc;}
 			void SetAtc(double atc){this->atc =atc;}
 		double GetSpeed(){return speed;}
 			void SetSpeed(double speed){this->speed =speed;}
 		int Dameag(){
 			return std::rand() % this-> atc;}
		int Block(){
		 	return std::rand() % this-> def;}
 	//construktor definert
 		void SetAll(std::string, double, double, double, double);
 		player(std::string, double, double, double, double);
 		player(); //overLode contruktor
 		~player(); //deconstruktor 
	void PrintStats();//definere print stats
	void GetAtcStat();
	void GetDefStat();
  	void GetSpeedStat();
  	void GetHpStat();
  	void GetNameStat();
 }; //funcsen for printing stats
 void player::GetAtcStat(){
 	std::cout << "Atc:" << this -> atc;
 }
  void player::GetDefStat(){
 	std::cout << "Def:" << this -> def;
 }
  void player::GetSpeedStat(){
 	std::cout << "Speed:" << this -> speed;
 } 
 void player::GetHpStat(){
 	std::cout << "HP:" << this -> hp;
 } 
 void player::GetNameStat(){
 	std::cout << "" << this -> name;
 }//koden under her er for at SettAll skal funker (name, hp, atc, def, speed)
 		void player::SetAll(std::string name, double hp, double atc, double def, double speed){
		 	this->name = name;
			this->hp = hp;
			this->def = def;
			this->atc = atc;
			this->speed = speed;
} //_____________player CONSTRUKTOR
 player::player(std::string name, double hp, double atc,
 				 double def, double speed){
	this->name = name;
	this->hp = hp;
	this->def = def;
	this->atc = atc;
	this->speed = speed;
} //______player PRE SETT STETS
 	player::player(){
 	this->name = "EnNaNon";
	this->hp = 0;
	this->def = 0;
	this->atc = 0;
	this->speed = 0;	
}//__________player DECONSTRUKTOR
	 player::~player(){
	 	std::cout <<this -> name <<
	 			" the Hero is dead";	 			
}//______________player PRINT ALL STETS
 	void player::PrintStats(){
 		std::cout <<this -> name <<" name of your fow\n" <<
					 " enemy stats:\n " <<
					 " HP: " <<
					 this -> hp <<
					 " Atc: " <<
					 this -> atc <<
					 " def: " <<
					 this -> def <<
					 " speed: " <<
					 this -> speed;
}
//________----________ENEMY________----___________
class enemy{ //dette er en klaseinfor coden
 	private:
 		
 	protected:
    	std::string name;
    	//double hp;
    	int def, atc, speed;
        
    public: //funksjoner som get og Set som lar meg bruke stetsene til
/*må vere publik for funke*/ double hp;	// construkson senere i coden,
    	std::string GetName(){return name;}
    		void SetName(std::string name){this->name = name;} 
 	 	double GetHp(){return hp;}
 			void SetHp(double hp){this->hp =hp;}
 		double GetDef(){return def;}
 			void SetDef(double def){this->def =def;}
 		double GetAtc(){return atc;}
 			void SetAtc(double atc){this->atc =atc;}
 		double GetSpeed(){return speed;}
 			void SetSpeed(double speed){this->speed =speed;}
 		int Dameag(){
 			return std::rand() % this->atc;}
		int Block(){
		 	return std::rand() % this->def;}
 	//construktor definert
 		void SetAll(std::string, double, double, double, double);
 		enemy(std::string, double, double, double, double);
 		enemy(); //overLode contruktor
 		~enemy(); //deconstruktor 
	void PrintStats();//definerer funsonen print enkel stats
	void GetAtcStat();
	void GetDefStat();
  	void GetSpeedStat();
  	void GetHpStat();
  	void GetNameStat();
 }; //prin enkel stats funksoner
 void enemy::GetAtcStat(){
 	std::cout << "Atc:" << this -> atc;
 }
  void enemy::GetDefStat(){
 	std::cout << "Def:" << this -> def;
 }
  void enemy::GetSpeedStat(){
 	std::cout << "Speed:" << this -> speed;
 } void enemy::GetHpStat(){
 	std::cout << "HP:" << this -> hp;
 } void enemy::GetNameStat(){
 	std::cout << "" << this -> name;
 }//koden under her er for at SettAll skal funker (height, weight, hp, def, atc)
 		void enemy::SetAll(std::string name, double hp, double def, double atc, double speed){
		 	this->name = name;
			this->hp = hp;
			this->def = def;
			this->atc = atc;
			this->speed = speed;
} //_____________ENEMY CONSTRUKTOR
 enemy::enemy(std::string name, double hp, double atc,
 				 double def, double speed){
	this->name = name;
	this->hp = hp;
	this->def = def;
	this->atc = atc;
	this->speed = speed;
} //______ENEMY PRE SETT STETS
 	enemy::enemy(){//om ikke du gir noke verdier
 	this->name = "EnNaNon";
	this->hp = 0;
	this->def = 0;
	this->atc = 0;
	this->speed = 0;	
}//__________ENEMY DECONSTRUKTOR
	 enemy::~enemy(){
	 	std::cout <<"you'r enemy " <<this -> name <<
	 			" was killd by you.";	 			
}//______________ENEMY PRINT ALL STETS
 	void enemy::PrintStats(){//printer alle stetsne ut.
 		std::cout <<this -> name <<" name of your fow\n" <<
					 " enemy stats:\n " <<
					 " HP: " <<
					 this -> hp <<
					 " Atc: " <<
					 this -> atc <<
					 " def: " <<
					 this -> def <<
					 " speed: " <<
					 this -> speed;
}//_____________________COMBET SYSTEM__________________________
	void StartCombet(){ //combet system V.1
		int menu_item=0, run, x=24, TurnTraker=0, CT=0, DamegeDelt;//turn traker 1 = enemy turn, 2 player turn
		bool WhilePlayerTurn = true, SpeedChek = false, PlayerBlock = false;
		srand(time(0)); int randNr;
		randNr = (rand() % 10) + 1;
		
			enemy Vilen("McEvil",20,10,5,8);
			player hero("Link",20,10,5,9);
			
		while(WhilePlayerTurn){
			system("color 0f"); 
			fflush( stdin); // meny idikatorer
			gotoXY(8,22); cout << "combet Menu"<< endl;
			gotoXY(12,24); cout << "Ateck" << endl;
			gotoXY(12,25); cout << "Block" << endl;
			gotoXY(12,26); cout << "Run" << endl;
			gotoXY(23,22); hero.GetNameStat();
			gotoXY(28,23); cout << "    ";
			gotoXY(24,23); hero.GetHpStat();
			gotoXY(24,24); hero.GetAtcStat();
			gotoXY(24,25); hero.GetDefStat();
			gotoXY(24,26); hero.GetSpeedStat();
			gotoXY(56,22); Vilen.GetNameStat();
			gotoXY(61,23); cout << "    ";
			gotoXY(57,23); Vilen.GetHpStat();
			gotoXY(57,24); Vilen.GetAtcStat();
			gotoXY(57,25); Vilen.GetDefStat();
			gotoXY(57,26); Vilen.GetSpeedStat();
			gotoXY(8,x); cout << "->";
			
		system("pause>nul");
			if(hero.hp <= 0){
				system("cls");
				gotoXY(44,10); cout << "The hero "; hero.GetName();
							   cout << "was kild by "; Vilen.GetNameStat();
				gotoXY(48,12); cout << "You'r Jurny ended in blood";
				gotoXY(0,0);
				Sleep ( 4000 );
				WhilePlayerTurn=false;
			}
			if(Vilen.hp <= 0){
				system("cls");
				gotoXY(44,10); cout << "you have defited "; Vilen.GetNameStat();
				gotoXY(0,0);
				Sleep ( 4000 );
				WhilePlayerTurn=false;
				break;
			}
			if(GetAsyncKeyState(VK_DOWN) && x !=26){//down buten press
				gotoXY(8,x); cout << "  "; x++;
				gotoXY(8,x); cout << "->";	menu_item++;
				continue;
				}
			if(GetAsyncKeyState(VK_UP) && x !=24){//up buten press
				gotoXY(8,x); cout << "  "; x--; 
				gotoXY(8,x); cout << "->"; menu_item--;
				continue;
				}
			if(TurnTraker == 0){//speed ceak
				if(Vilen.GetSpeed() < hero.GetSpeed()){
					TurnTraker=2;//player speed higest. player start
					gotoXY(75,CT); cout << "Its "; hero.GetNameStat(); cout << " turn"; CT=CT+1;
					continue;
				}
				if(Vilen.GetSpeed() > hero.GetSpeed()){
					TurnTraker=1;//enemy speed is higest. enemy starts
					gotoXY(75,CT); cout << "Its "; Vilen.GetNameStat(); cout << " turn"; CT=CT+1;
					continue;
				}
				if(Vilen.GetSpeed() == hero.GetSpeed()){
					TurnTraker=2;//edd rendom laiter
					gotoXY(75,CT); cout << "Its "; Vilen.GetNameStat(); cout << " turn"; CT=CT+1;
					continue;
				}
				//system("pause>nul");//press any key to continue?
			}//speed ceak|  tells how turn it is.
			if(TurnTraker == 1){//enemy turn//AI
				if (PlayerBlock == false){
					gotoXY(75,CT); cout << "Its "; hero.GetNameStat(); cout << " turn"; CT=CT+1;
					DamegeDelt = Vilen.Dameag();
					hero.SetHp(hero.GetHp() - DamegeDelt);
					gotoXY(75,CT); cout << Vilen.GetName(); cout << " did " << 
								DamegeDelt << " dameag to " << hero.GetName(); CT=CT+1;
					TurnTraker=2;
				}
				if (PlayerBlock == true){
					DamegeDelt = Vilen.Dameag();
					DamegeDelt = DamegeDelt - hero.GetDef();
					if (DamegeDelt < 0){
						gotoXY(75,CT); cout << hero.GetName() << " blockt " <<
										Vilen.GetName() << " perfectly "; CT=CT+1;
						}
					if (DamegeDelt > 1){
						gotoXY(75,CT); cout << Vilen.GetName(); cout << " did " << 
								DamegeDelt << " dameag to " << hero.GetName(); CT=CT+1;
						hero.SetHp(hero.GetHp() - DamegeDelt);
						}
					PlayerBlock=false; TurnTraker=2;
					}
				continue;
			}	//enemy turn if
			if(TurnTraker == 2){//player turn
				gotoXY(75,CT); cout << "Its "; Vilen.GetNameStat(); cout << " turn"; CT=CT+1;
				if(GetAsyncKeyState(VK_RETURN)){//if enter buten press
					switch(menu_item){
						case 0:{//_______ATECK
							DamegeDelt = hero.Dameag();
							Vilen.SetHp(Vilen.GetHp() - DamegeDelt);
							gotoXY(75,CT); cout << hero.GetName() << " did " << DamegeDelt <<
							 				" dameg to " << Vilen.GetName(); CT=CT+1;
							TurnTraker=1;//maik it enemy turn.
						break;
							}//case 0
						case 1:{//_______BLOCK
							gotoXY(75,CT); cout << hero.GetName() << " gets ready to block"; CT=CT+1;
							PlayerBlock=true; TurnTraker=1;
						break;
							}//case 1
						case 2:{//_______RUN/EXIT
							system("cls");
							gotoXY(20,4); cout << "You run away from combet";
							gotoXY(20,8); PressEnterToContinue();
							WhilePlayerTurn=false;
						break;
							}//case 2
						};//swhitc
					}//if enter/Player turn
				}//player turn if
			};//while player turn
		}//__________________COMBET______________________________
int main(){//________________INT MAIN__________________________
	int menu_item=0, run, x=7; 		//x = cursor starting point 
	bool while1 = true;
//__________________________
	system("color f4"); //start scren
	gotoXY(44,8); cout << "This program is coded by:";
	gotoXY(46,10); cout << "Sebastian S.G. Hegna";
	gotoXY(42,15); cout << "This was my first big protcekt";
	gotoXY(44,16); cout << "I hope you enjoi the simpel ";
	gotoXY(42,17); cout << "Game i have maid. if nott thats";
	gotoXY(48,18); cout << "Nott my problem";
	gotoXY(42,23); cout << "ths program includ flesing lighites.";
	gotoXY(43,24); cout << "";
	system("pause>nul");// or Sleep (5000);
	system("cls");
	system("color 0f"); //dene coden byter farge
	
	while(while1){ 
		system("color 0f"); 
		fflush( stdin); // meny idikatorer
		gotoXY(15,4); cout << "Seb's Combet/Adventur Game"<< endl;
		gotoXY(19,7); cout << "Start Game" << endl;
		gotoXY(19,8); cout << "combet test" << endl;
		gotoXY(19,9); cout << "gotoXY test" << endl;
		gotoXY(19,10); cout << "construktor test" << endl;
		gotoXY(19,11); cout << "Quit Program" << endl;
		gotoXY(15,x); cout << "->";
		
		system("pause>nul");
		
		if(GetAsyncKeyState(VK_DOWN) && x !=11){//down buten press
			gotoXY(15,x); cout << "  "; x++;
			gotoXY(15,x); cout << "->";	menu_item++;
			continue;
				}
		if(GetAsyncKeyState(VK_UP) && x !=7){//up buten press
			gotoXY(15,x); cout << "  "; x--; 
			gotoXY(15,x); cout << "->"; menu_item--;
			continue;
				}
		if(GetAsyncKeyState(VK_RETURN)){
			switch(menu_item){
				case 0:{//_______GAME
					system("cls");
					//StartCombet();		u brukt intil vidre
					enemy Vilen("McEvil",20,5,5,9);
					//bettal::BettleStart(main, Vilen);  u brukt intil vidre
				break;
					}//case 0
				case 1:{//_______COMBET DEMO
					system("cls");
					gotoXY(1,1); cout << "combet Start" << endl;
					
					system("color f4"); //start scren
					gotoXY(44,8); cout << "Your geting ateckt";
					gotoXY(47,10); cout << "By McEvil";
					system("color f4"); Sleep ( 40 ); system("color 40"); Sleep ( 40 );
					system("color f4"); Sleep ( 40 ); system("color 40"); Sleep ( 40 );
					system("color f4"); Sleep ( 40 ); system("color 40"); Sleep ( 40 );
					system("color f4"); Sleep ( 40 ); system("color 40"); Sleep ( 40 );
					system("color f4"); Sleep ( 40 ); system("color 40"); Sleep ( 40 );
					system("color f4"); Sleep ( 40 ); system("color 40"); Sleep ( 40 );
					system("color f4"); Sleep ( 40 ); system("color 40"); Sleep ( 40 );
					system("color f4"); Sleep ( 40 ); system("color 40"); Sleep ( 40 );
					system("color f4"); Sleep ( 40 ); system("color 40"); Sleep ( 40 );
					system("cls");
					system("color 0f"); 
					
					StartCombet();
				break;
					}//case 1
				case 2:{//_______gotoXY test
					system("cls");				
					gotoXY(20,4); cout <<  "gotoXY test";
					gotoXY(18,6); cout << "kepp X same, while Y gets +1 for evry line";
					gotoXY(20,8); PressEnterToContinue();
				break;
					}//case 2
				case 3:{//______CONSTRUKTOR TEST
					system("cls");
					system("color 8f");
					gotoXY(20,4); cout << "Construktor test\n";
						enemy Vilen("McEvil",20,5,5,9);
						Vilen.PrintStats();
						gotoXY(18,20); PressEnterToContinue();
					gotoXY(60, 25); PressEnterToContinue();
				break;
				};
				case 4:{//______QUIT PROGRAM
					system("cls");
					gotoXY(20,4); cout << "Program ends, thanks for testing";
					gotoXY(20,8); PressEnterToContinue();
					while1=false;
				break;
					}//case 3
				system("cls");
			}//swhitc
		system("cls");//ryder etter meny valg
		}//if enter ky
	}//While 1
	gotoXY(25,25);
	return 0;
}//int main________________
void gotoXY(int x, int y){//dette gir gotoXY som brukes til
	CursorPosition.X=x;	  //flyte skriver curseren
	CursorPosition.Y=y;
	SetConsoleCursorPosition(console,CursorPosition);
};

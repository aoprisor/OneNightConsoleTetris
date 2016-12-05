#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;
      
	   char mapMatrix[20][80]={"###############################################################################",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "###############################################################################",};
                               
      char copyMatrix[20][80]={"###############################################################################",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "#                                      #                                      #",
                               "###############################################################################",};
                    

int score1=0;
int score2=0;
int winner;

bool gameStatus(){if((score2-score1)>20){winner=2; return false;}//the player that has 20 points more than the other wins
                  if((score1-score2)>20){winner=1; return false;}
                  return true;
}



bool scoreP1(){int index=0;//when a line is complete disapears and the score increases//this is for player one
       int j;
	for( j=1;j<39;j++){
	index=0;
    	for(int i=1;i<19;i++){ if(mapMatrix[i][j]==char(178)) index++;
    	if(index==18)	break;}
    	if(index==18)	break;
		}
    	if(index==18){j--;
    		for(j;j>2;j--)
    		for(int i=0;i<19;i++){mapMatrix[i][j]=mapMatrix[i][j-1];}
    		int j=1;
    		for(int i=1;i<19;i++){mapMatrix[i][j]=' ';	}
    		return true;
			}
			else return false;
		}
		
bool scoreP2(){int index=0;//when a line is complete disapears and the score increases//this is for player two
       int j;
	for( j=39;j<78;j++){
	index=0;
    	for(int i=1;i<19;i++){ if(mapMatrix[i][j]==char(178)) index++;
    	if(index==18)	break;}
		if(index==18)	break;}
    	if(index==18){score2++;
    		for(j;j<78;j++) 
			
    		for(int i=1;i<19;i++){mapMatrix[i][j]=mapMatrix[i][j+1];}
    		int j=77;
    		for(int i=1;i<19;i++){mapMatrix[i][j]=' ';	}
    		return true;
			}
			else return false;
	}

//a function that replaces the unwanted characters-creates a clean map 
void clean(){
	for(int i=0; i<20;i++)
	  for(int j=0; j<80; j++){mapMatrix[i][j]=copyMatrix[i][j];
	  }}
	  
//when a shape hits the separation line or another shape it is looked in that position and it's saved in the mapMatrix//for the first fild//player one 
void keep1(){
	for(int i=0; i<20;i++)
	  for(int j=0; j<39; j++){copyMatrix[i][j]=mapMatrix[i][j];
	  }}
//when a shape hits the separation line or another shape it is looked in that position and it's saved in the mapMatrix//for the second fild//player two	  
void keep2(){
	for(int i=0; i<20;i++)
	  for(int j=39; j<80; j++){copyMatrix[i][j]=mapMatrix[i][j];
	  }
}

//function-used to print the map
void printMap(){int index=0;
    system("COLOR F8");
	for(char* i=&mapMatrix[0][0]; i<=&mapMatrix[19][78]; i++){ index++;
		if((*i)=='#') cout<<char(177); else cout<<*i; if(index==80){ cout<<endl; index=0;}
	}
	cout<<endl;
	cout<<"Player1:"<<score1<<"                               Player2:"<<score2;
}


class shape{//this class contains a set of functions
            int type;
            public:
            shape(){ type=1;}
            bool verify1(int type, int i, int g){//decideing if the shape can go further or has to stop//first player
            	switch(type){
            		case 1:
            			if((mapMatrix[i][g]==char(178)) || (mapMatrix[i+1][g]==char(178)))	return true; else return false;
            			break;
            		case 2:
            			if(mapMatrix[i][g]==char(178)) return true;else return false;
            			break;
            		case 3:
            			if((mapMatrix[i][g]==char(178)) || (mapMatrix[i+1][g-1]==char(178 ))) return true;else return false;
            			break;
            		case 4:
            			if((mapMatrix[i][g]==char(178)) || (mapMatrix[i+1][g-2]==char(178 ))) return true;else return false;
            			break;
            		case 5:
            			if((mapMatrix[i][g]==char(178)) || (mapMatrix[i+1][g-2]==char(178 ))) return true;else return false;
            			break;
            		case 6:
            			if((mapMatrix[i][g]==char(178)) || (mapMatrix[i+1][g]==char(178 ))) return true;else return false;
            			break;
            		case 7:
            			if((mapMatrix[i][g]==char(178)) || (mapMatrix[i-1][g-1]==char(178 )) || (mapMatrix[i+1][g]==char(178 )) ) return true;else return false;
            	}
            	
				}
				
				bool verify2(int type, int i, int g){//decideing if the shape can go further or has to stop//second player
            	switch(type){
            		case 1:
            			if((mapMatrix[i][g-1]==char(178)) || (mapMatrix[i+1][g-1]==char(178)) || (mapMatrix[i][g-1]=='#') || (mapMatrix[i+1][g-1]=='#'))	return true; else return false;
            			break;
            		case 2:
            			if((mapMatrix[i][g-3]==char(178)) || (mapMatrix[i][g-3]=='#')) return true;else return false;
            			break;
            		case 3:
            			if((mapMatrix[i][g-2]==char(178)) || (mapMatrix[i+1][g-1]==char(178 )) || (mapMatrix[i][g-2]=='#')) return true;else return false;
            			break;
            		case 4:
            			if((mapMatrix[i][g-1]==char(178)) || (mapMatrix[i+1][g-3]==char(178 )) || (mapMatrix[i+1][g-3]=='#')) return true;else return false;
            			break;
            		case 5:
            			if((mapMatrix[i][g-2]==char(178)) || (mapMatrix[i+1][g-2]==char(178 )) || (mapMatrix[i][g-2]=='#') || (mapMatrix[i+1][g-2]=='#')) return true;else return false;
            			break;
            		case 6:
            			if((mapMatrix[i][g-2]==char(178)) || (mapMatrix[i+1][g]==char(178 )) || (mapMatrix[i][g-2]=='#') ) return true;else return false;
            			break;
            		case 7:
            			if((mapMatrix[i+1][g]==char(178)) || (mapMatrix[i][g-1]==char(178 )) || (mapMatrix[i-1][g-1]==char(178 )) || (mapMatrix[i][g-1]=='#') || (mapMatrix[i-1][g-1]=='#') ) return true;else return false;
            	}
            	
				}
			
            void putshape(int type, int g, int i){// adds a shape on the map
            	switch(type){
            		case 1:
            			mapMatrix[i][g]=178;
            			mapMatrix[i][g-1]=178;
            			mapMatrix[i+1][g]=178;
            			mapMatrix[i+1][g-1]=178;
            		break;	
            		case 2:
            			mapMatrix[i][g]=178;
            			mapMatrix[i][g-1]=178;
            			mapMatrix[i][g-2]=178;
            			mapMatrix[i][g-3]=178;
            		break;	
            		case 3:
            			mapMatrix[i][g]=178;
            			mapMatrix[i][g-1]=178;
            			mapMatrix[i][g-2]=178;
            			mapMatrix[i+1][g-1]=178;
            		break;	
            		case 4:
            			mapMatrix[i][g]=178;
            			mapMatrix[i][g-1]=178;
            			mapMatrix[i+1][g-2]=178;
            			mapMatrix[i+1][g-3]=178;
            		break;
            		case 5:
            			mapMatrix[i][g]=178;
            			mapMatrix[i][g-1]=178;
            			mapMatrix[i][g-2]=178;
            			mapMatrix[i+1][g-2]=178;
            		break;
            		case 6:
            			mapMatrix[i][g]=178;
            			mapMatrix[i+1][g]=178;
            			mapMatrix[i][g-1]=178;
            			mapMatrix[i][g-2]=178;
            		break;
            			case 7:
            			mapMatrix[i][g]=178;
            			mapMatrix[i][g-1]=178;
            			mapMatrix[i+1][g]=178;
            			mapMatrix[i-1][g-1]=178;
            		break;
				}
            	
			}
};


int main(){
    shape shape1;
    shape *p;
    p=&shape1;
    int g1=0;//used as center for the shape//for first player
	int i1=10;//the line from where the shape will apear
	int g2=78;//same thing for second player
	int i2=10;//
    bool status=false;
    int type1=1;//shape type
    int type2=2;
	int speed=500;//used to set the speed
	
	system("COLOR 59");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"                                       Tetris PvP"<<endl;
	cout<<"                                        Controls"<<endl;
	cout<<"                              First player: ""w""-up , ""s""-down"<<endl;
	cout<<"                              Second player: ""i""-up , ""k""-down"<<endl;
	cout<<"                              Press any key to start the game!"<<endl;
	if(getch())
	status=true; 
	while(status){
    
	
	while(!kbhit()){
		{
		Sleep(speed);
		g2--;
		g1++;}
		
		if((g1==39 ) || p->verify1(type1,i1,g1)) {
		type1=rand()%7 + 1;
		keep1();
		g1=1; i1=10;}
		
		if(p->verify2(type2,i2,g2)) {
		type2=rand()%7 + 1;
		keep2();
		g2=78; i2=10;}
		
		clean();
		if(scoreP1()){ score1++; speed-=10;}
		scoreP2();
		p->putshape(type1,g1,i1);
		p->putshape(type2,g2,i2);
		status=gameStatus();
		system("cls");
		printMap();
		
		
	}
	if(kbhit()){char c;
	c=getch();
	switch(c){
		case 's'://down player one
			if(i1<18){
			 i1++; clean();}
			break;
		case 'w'://up player one
			if(i1>1){
			 i1--; clean();}
			break;
		case 'k'://down player two
			if(i2<18){
			 i2++; clean();}
			break;
		case 'i'://up player two
			if(i2>1) {
			i2--; clean();}
			default: break;}
	}
	}
	system("cls");
	system("COLOR F0");
	cout<<"Game over!"<<'\t'<<"The winner is player "<<winner;
	return 0;
	
}

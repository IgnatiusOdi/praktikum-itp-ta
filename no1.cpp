#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void PrintMap(int skor,char map[][10],char player,char musuh,int xp,int yp,int xm,int ym){
	cout<<"Score: "<<skor<<endl;
	for(int y=0;y<10;y++){
		for(int x=0;x<10;x++){
			if(xp==x && yp==y) cout<<player;
			else if(xm==x && ym==y) cout<<musuh;
			else cout<<map[y][x];
		}
		cout<<endl;
	}
}

void Move(bool powerup,char &player,int &counter,char key,char map[][10],int &xp,int &yp){
    if(key=='w' && map[yp-1][xp]!='#'){
		yp--;
    } else if(key=='s' && map[yp+1][xp]!='#'){
		yp++;
    } else if(key=='a' && map[yp][xp-1]!='#'){
        xp--;
        
    } else if(key=='d' && map[yp][xp+1]!='#'){
        xp++;
    }
    if(yp<0) yp=9;
    else if(yp>9) yp=0;
	else if(xp<0) xp=9;
	else if(xp>9) xp=0;
	
    if(powerup==true){
		counter--;
	}
}

void Eat(char &player,bool &powerup,int &counter,int &skor,char map[][10],int xp,int yp){
	if(map[yp][xp]=='.'){
		if(powerup==true){
			skor+=5;
		} else{
			skor++;
		}
		map[yp][xp]=' ';
	}
	if(counter==0){
		powerup=false;
		char player='p';
	}
	if(map[yp][xp]=='o' && powerup==false){
		powerup=true;
		skor++;
		player='P';
		counter=10;
		map[yp][xp]=' ';
	}
	if(powerup && map[yp][xp]=='m'){
		skor+=5;
	}
}

int RandomArah(){
	int arah=rand()%4+1;
	return arah;
}

void EnemyMove(char map[][10],int &xm,int &ym){
	int arah=RandomArah();
	int xarah=0;
	int yarah=0;
	while(map[ym-yarah][xm-xarah]=='#'){
		arah=RandomArah();
	}
	if(arah==1){ //^
		xarah=0;
		yarah=-1;
	} else if(arah==2){ //<
		xarah=-1;
		yarah=0;
	} else if(arah==3){ //v
		xarah=0;
		yarah=1;
	} else if(arah==4){ //>
		xarah=1;
		yarah=0;
	}
	
	ym-=yarah; xm-=xarah;
	if(ym<0) ym=9;
	else if(ym>9) ym=0;
	else if(xm<0) xm=9;
	else if(xm>9) xm=0;
}

int main()
{
	char map1[10][10]= {{'#','#','#','#','#','#','#','#','#','#'},
						{'#','.','.','.','.','.','.','.','.','#'},
						{'#','.','#','#','.','#','#','#','.','#'},
                        {'.','.','.','.','.','.','.','.','.','.'},
                        {'#','.','#','.','#','#','#','#','.','#'},
                        {'#','.','#','.','.','.','.','.','.','#'},
                        {'#','.','#','#','.','#','.','#','.','#'},
                        {'#','.','o','#','.','#','.','#','.','#'},
                        {'#','#','.','.','.','.','.','.','.','#'},
                        {'#','#','#','#','#','#','#','#','#','#'}};

	char map2[10][10]= {{'#','.','#','#','#','#','#','#','#','#'},
                        {'#','.','.','.','.','.','.','.','.','#'},
                        {'#','.','#','#','.','#','#','#','.','#'},
                        {'#','.','#','.','.','.','.','#','.','#'},
                        {'#','.','#','.','#','#','.','.','.','#'},
                        {'#','.','.','.','#','#','.','#','.','#'},
                        {'#','.','#','.','.','.','o','#','.','#'},
                        {'#','.','#','#','#','.','#','#','.','#'},
                        {'#','.','.','.','.','.','.','.','.','#'},
                        {'#','.','#','#','#','#','#','#','#','#'}};

	char map3[10][10]= {{'.','.','.','.','.','.','.','.','.','.'},
                        {'.','#','#','.','.','.','.','#','#','.'},
                        {'.','#','.','.','.','.','.','.','#','.'},
                        {'.','.','.','#','#','#','#','.','.','.'},
                        {'.','#','.','#','o','.','#','.','#','.'},
                        {'.','#','.','#','.','.','#','.','#','.'},
                        {'.','.','.','#','#','.','#','.','.','.'},
                        {'.','#','.','.','.','.','.','.','#','.'},
                        {'.','#','#','.','#','#','.','#','#','.'},
                        {'.','.','.','.','.','.','.','.','.','.'}};
    char map[10][10];
	srand(time(0));
	int choice,skor=0;
	bool gameover=false,mulai=false;
	bool powerup=false; int counter;
	char key;
	char player='p';
	char musuh='m';
	int xp=rand()%10;
	int yp=rand()%10;
	int xm=rand()%10;
	int ym=rand()%10;
	
	do{
		system("cls");
		cout<<"Pilih map : "; cin>>choice;
		if(choice==1){
			mulai=true;
			copy(&map1[0][0],&map1[0][0]+10*10,&map[0][0]);
		} else if(choice==2){
			mulai=true;
			copy(&map2[0][0],&map2[0][0]+10*10,&map[0][0]);
		} else if(choice==3){
			mulai=true;
			copy(&map3[0][0],&map3[0][0]+10*10,&map[0][0]);
		} else cout<<"Invalid!"<<endl;
		system("pause");
	}while(!mulai);
	
	while(map[yp][xp]=='#' || (yp==ym && yp==ym)){
		xp=rand()%10;
		yp=rand()%10;
	}
	while(map[ym][xm]=='#' || (ym==yp && xm==xp)){
		xm=rand()%10;
		ym=rand()%10;
	}
	
	do{
		system("cls");
		PrintMap(skor,map,player,musuh,xp,yp,xm,ym);
		cout<<counter<<endl;
		if(kbhit()){
			EnemyMove(map,xm,ym);
			key=getch();
			Move(powerup,player,counter,key,map,xp,yp);
			Eat(player,powerup,counter,skor,map,xp,yp);
		}
		Sleep(50);
	}while(!gameover);
	
    return 0;
}

/* 冯昊 2016060105007 基于c++的塔防游戏*/

#include"acllib.h"
#include"time.h"
#include<iostream>
#include<windows.h>
using namespace std;
const int mWindowWidth = 1500, mWindowHeight = 800;
const int maxNum = 20;
const int gunerWidth = 80, gunerHeight = 100;
int archerw = 70, archerh = 100;
int wizardw = 60, wizardh = 80;
int archerx1 = 1285, archerx3=1220,archerx4=1420,archery1 = 260;
int archerx2 = 1400, archery2 = 350, archery3 = 500, archery4 = 630, archery5 = 720;
int bnum = 0;   //子弹数量
const int bnummax = 10;   //子弹最大数量
int bw = 35, bh = 50;
int archnum = 0, archnum2 = 0, archnum3 = 0, archnum4 = 0, archnum5 = 0;
const int archmax = 4;
int archw = 60, archh = 15;
int powernum = 0, powernum2 = 0, powernum3 = 0, powernum4 = 0,powernum5=0;
const int powermax = 4;
int powerw = 50, powerh = 50;
int score = 0;   //分数,随着分数增多难度增大
int life = 100;  //玩家生命
int magic = 0;
int num1 = 0;const int maxnum1 = 20;   //敌人1数量
int num1x = 0, num1y = 260;
int num1w = 200,num1h=70;
int num2 = 0;const int maxnum2 = 30;
int num2x = 0, num2y = 260;
int num2w = 80, num2h = 80;
int num3 = 0;const int maxnum3 = 40;
int num3x = 0, num3y = 260;
int num3w = 50, num3h = 50;
int nmax = maxnum1 + maxnum2 + maxnum3;
ACL_Image backp;
ACL_Image lf;
ACL_Image open;
ACL_Image gameover;
ACL_Image win;
ACL_Sound op, archrush, powerrush, bombrush, bamm, wining, map, gm, reload;
void timerEvent(int id);
class person {                                                         //基本的单位类
protected:
	ACL_Image img;
	int x, y;
	int width, height;

	char name[50];

public:
	person( char *name,int w, int h, int ax, int ay) {
		strcpy_s(this->name, name);

		loadImage(this->name, &img);
	
		width = w;
		height = h;
		x = ax;
		y = ay;
	}

	virtual void drawImageScale()    //虚基类
	{
		putImageScale(&img, x, y, width, height);
		
	}
};

class player :public person {                                            //玩家人物
private:
	int load;//装弹
	int price;
public:
	int dd;   //方向
   player(char *name, int w, int h,  int ax, int ay, int pri,int dd) :person(name, w, h, ax,ay) {
		price = pri;
		this->dd = dd;
		load = 0;
	}
    void Move() {    //完成转向
		if (dd==0)
		{
			loadImage("p00.bmp", &img);	
		}
		else if(dd==1){
			loadImage("p+15.bmp", &img);
		}
		else if (dd==2) {
			loadImage("p+30.bmp", &img);
	
		}
		else if (dd==-1) {
			loadImage("p-15.bmp", &img);
		
		}
		else if (dd==-2) {
			loadImage("p-30.bmp", &img);
		}
	}
	friend void keyevent(int key, int event);

};
class bullet;
class pc :public person {
private:
	int lun;
	int lunm;
	int worth;
public:
	    int health;
	pc(char*name, int w, int h, int ax, int ay, int lun, int health, int worth,int lunm) :person(name, w, h, ax, ay) {
		this->lun = lun;
		this->health = health;
		this->worth = worth;
		this->lunm = lunm;
	}

	void move() {
		if (lunm == 0) {
			if (lun == 1) {
				loadImage("d31.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 2) {
				loadImage("d32.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 3) {
				loadImage("d33.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 4) {
				loadImage("d34.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 5) {
				loadImage("d35.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 6) {
				loadImage("d36.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 7) {
				loadImage("d37.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 8) {
				loadImage("d38.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 9) {
				loadImage("d39.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 10) {
				loadImage("d310.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 11) {
				loadImage("d311.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 12) {
				loadImage("d312.jpg", &img);
				x += 2;
				lun = 1;
			}
		}
		else if(lunm==1) {
           if (lun == 1) {
				loadImage("d21.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 2) {
				loadImage("d22.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 3) {
				loadImage("d23.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 4) {
				loadImage("d24.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 5) {
				loadImage("d25.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 6) {
				loadImage("d26.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 7) {
				loadImage("d27.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 8) {
				loadImage("d28.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 9) {
				loadImage("d29.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 10) {
				loadImage("d210.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 11) {
				loadImage("d211.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 12) {
				loadImage("d212.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 13) {
				loadImage("d213.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 14) {
				loadImage("d214.jpg", &img);
				x += 2;
				lun += 1;
			}
			else if (lun == 15) {
				loadImage("d215.jpg", &img);
				x += 2;
				lun = 1;
			}
		}
		else {
			if (lun == 1) {
				loadImage("d51.jpg", &img);
				x += 3;
				lun += 1;
			}
			else if (lun == 2) {
				loadImage("d52.jpg", &img);
				x += 3;
				lun += 1;
			}
			else if (lun == 3) {
				loadImage("d53.jpg", &img);
				x += 3;
				lun += 1;
			}
			else if (lun == 4) {
				loadImage("d52.jpg", &img);
				x += 3;
				lun = 1;
			}
		}
	
	}
	friend bool collision(int i, pc*robot[], int j, bullet*bomb[]);
	friend bool crash(int i, pc*robot[]);
};
class bullet {
private:
	ACL_Image img2;//子弹
	ACL_Image bam;//爆炸
	int  bamw , bamh ;   //炸弹变化效果
	int dx, dy;  //子弹轨迹
	int width2, height2;   //子弹
	char name2[50]; //子弹
	int dd;  //子弹方向
public:
	int bamnub;
	bullet(char*name2, int w2, int h2, int x, int y, int dd) {
		strcpy_s(this->name2, name2);
		loadImage(this->name2, &img2);
		loadImage("bam.jpg", &bam);
		bamnub = 0;
		bamw = 40;
		bamh = 20;
		width2 = w2;
		height2 = h2;
		dx = x;
		dy = y;
		this->dd = dd;
		
	}
	void shoot() {      //画子弹
		if (dd == 0) {
			dx -= 15;
		}
		else if (dd == 1) {
			dx -= 15;
			dy -= 3;
		}
		else if (dd == 2) {
			dx -= 15;
			dy -= 9;
		}
		else if (dd == -1) {
			dx -= 15;
			dy += 3;
		}
		else if (dd == -2) {
			dx -= 15;
			dy += 9;
		}
	}
	void drawImageScale(){
		putImageScale(&img2, dx, dy, width2, height2);
	}
	void drawImageScale2(int bamw,int bamh) {  //爆炸效果
		putImageScale(&bam, dx, dy, bamw,bamh);
	}
	friend bool collision(int i, pc*robot[], int j, bullet*bomb[]);
	friend bool crash(int i, bullet*robot[]);
};

player *guner = NULL;
bullet* bomb[bnummax] = { NULL };    //同屏子弹数量最多bnummax个
player *archer[5] = { NULL };
bullet*arch[5][archmax] = { NULL };   //同屏最多箭矢,二维数组
player *wizard[5] = { NULL };
bullet*power[5][powermax] = { NULL };   //同屏最多波
pc* robot[maxnum1] = { NULL };
pc* robot2[maxnum2] = { NULL };
pc*robot3[maxnum3] = { NULL };
char s[20], b[20];
char sc[100]={"虽然村庄失守了，但你为保护村子而付出的努力村民们不会忘记。"};
char sccc[100] = { "你逃跑了，村子被外界势力占领，再也没有村民去你的杂货店了。" };   
char scc[30] = {"你的分数为："};

int Setup()
{
    srand((unsigned)time(NULL));
	initWindow("新手村突袭", 0, 0, mWindowWidth, mWindowHeight);
	loadImage("1.bmp", &backp);
	loadImage("health.bmp", &lf);
	loadImage("win.jpg", &win);
	loadImage("gameover.jpg", &gameover);
	loadImage("open.jpg", &open);
	loadSound("open.mp3", &op);
	loadSound("map.wav", &map);
	loadSound("win.wav", &wining);
	loadSound("gameover.wav", &gm);
	loadSound("archrush.wav", &archrush);
	loadSound("powerrush.wav", &powerrush);
	loadSound("bombrush.wav", &bombrush);
	loadSound("reload.wav", &reload);
	loadSound("bamm.wav", &bamm);
	guner = new player( "p00.bmp", gunerWidth, gunerHeight, mWindowWidth - 190, mWindowHeight -300, 100,0);
	registerKeyboardEvent(keyevent);
	registerTimerEvent(timerEvent);
	beginPaint();
	putImageScale(&open, 0, 0, mWindowWidth, mWindowHeight);
	playSound(op, 1);

	endPaint();
	return 0;
}
   
void timerEvent(int id) {
	int p = rand() % 5;
    if (p == 0) { num1y = 260; }
	else if (p == 1) {
		num1y = 350;
	}
	else if (p == 2) {
		num1y = 500;
	}
	else if (p == 3) {
		num1y = 650;
	}
	else if (p == 4) {
		num1y = 700;
	}
	switch (id) {
	

	case 0:
			if (num3 < maxnum3)
			{
				robot3[num3] = new pc("d51.jpg", num3w, num3h, num3x, num1y, 1, 100, 100, 2);
				if (robot3[num3] == NULL)
				{
					cancelTimer(0);
					return;
				}
				++num3;
			}
			
			if (num3 > maxnum3 -20) {
				if (num2 < maxnum2)
				{
					robot2[num2] = new pc("d21.jpg", num2w, num2h, num2x, num1y, 1, 400, 100, 1);
					if (robot2[num2] == NULL)
					{
						cancelTimer(1);
						return;
					}
					++num2;
				}
			}
			if (num2 > maxnum2 / 2) {
				if (num1 < maxnum1)
				{
					robot[num1] = new pc("d39.jpg", num1w, num1h, num1x, num1y, 1, 600, 100, 0);
					if (robot[num1] == NULL)
					{
						cancelTimer(2);
						return;
					}
					++num1;
				}
			}
		break;

	case 1:
		guner->Move();
		for(int i=0;i<bnummax;++i)
		if (bomb[i] != NULL) {
			bomb[i]->shoot();
		}
		for (int j = 0; j < 5; ++j) {
			for (int i = 0; i < archmax; ++i) {
				if (arch[j][i] != NULL) {
					arch[j][i]->shoot();
				}
			}
		}
		for (int j = 0; j < 5; ++j) {
			for (int i = 0; i < powermax; ++i) {
				if (power[j][i] != NULL) {
					power[j][i]->shoot();
				}
			}
		}
	    break;


	case 2:
		if (archer[0] != NULL) {
			if (archnum < archmax)
			{
				playSound(archrush, 0);
				arch[0][archnum] = new bullet("arch.jpg", archw, archh, archerx1-50, archery1+45,  0);
				if (arch[0][archnum] == NULL)
				{
					cancelTimer(0);
					return;
				}
				++archnum;
			}
			else archnum = 0;
		}
		if (archer[1] != NULL) {
			if (archnum2 < archmax)
			{
				playSound(archrush, 0);
				arch[1][archnum2] = new bullet("arch.jpg", archw, archh, archerx1-50, archery2+45, 0);
				if (arch[1][archnum2] == NULL)
				{
					cancelTimer(0);
					return;
				}
				++archnum2;
			}
			else archnum2 = 0;
		}
		if (archer[2] != NULL) {
			if (archnum3 < archmax)
			{
				playSound(archrush, 0);
				arch[2][archnum3] = new bullet("arch.jpg", archw, archh, archerx1-50, archery3+45, 0);
				if (arch[2][archnum3] == NULL)
				{
					cancelTimer(0);
					return;
				}
				++archnum3;
			}
			else archnum3 = 0;
		}
		if (archer[3] != NULL) {
			if (archnum4 < archmax)
			{
				playSound(archrush, 0);
				arch[3][archnum4] = new bullet("arch.jpg", archw, archh, archerx1-50, archery4+45, 0);
				if (arch[3][archnum4] == NULL)
				{
					cancelTimer(0);
					return;
				}
				++archnum4;
			}
			else archnum4 = 0;
		}
		if (archer[4] != NULL) {
			if (archnum5 < archmax)
			{
				playSound(archrush, 0);
				arch[4][archnum5] = new bullet("arch.jpg", archw, archh, archerx1-50, archery5+45,  0);
				if (arch[4][archnum5] == NULL)
				{
					cancelTimer(0);
					return;
				}
				++archnum5;
			}
			else archnum5 = 0;
		}
		if (wizard[0] != NULL) {
			if (powernum < powermax)
			{
				playSound(powerrush, 0);
				power[0][powernum] = new bullet("magic.jpg", powerw, powerh, archerx2-40, archery1+20, 0);
				if (power[0][powernum] == NULL)
				{
					cancelTimer(0);
					return;
				}
				++powernum;
			}
			else powernum = 0;
		}
		if (wizard[1] != NULL) {
			if (powernum2 < powermax)
			{
				playSound(powerrush, 0);
				power[1][powernum2] = new bullet("magic.jpg", powerw, powerh, archerx2-40, archery2+20, 0);
				if (power[1][powernum2] == NULL)
				{
					cancelTimer(0);
					return;
				}
				++powernum2;
			}
			else powernum2 = 0;
		}
		if (wizard[2] != NULL) {
			if (powernum3 < powermax)
			{
				playSound(powerrush, 0);
				power[2][powernum3] = new bullet("magic.jpg", powerw, powerh, archerx2-40, archery3+20, 0);
				if (power[2][powernum3] == NULL)
				{
					cancelTimer(0);
					return;
				}
				++powernum3;
			}
			else powernum3 = 0;
		}
		if (wizard[3] != NULL) {
			if (powernum4 < powermax)
			{
				playSound(powerrush, 0);
				power[3][powernum4] = new bullet("magic.jpg", powerw, powerh, archerx2-40, archery4+20, 0);
				if (power[3][powernum4] == NULL)
				{
					cancelTimer(0);
					return;
				}
				++powernum4;
			}
			else powernum4 = 0;
		}
		if (wizard[4] != NULL) {
			if (powernum5 < powermax)
			{
				playSound(powerrush, 0);
				power[4][powernum5] = new bullet("magic.jpg", powerw, powerh, archerx2-40, archery5+20, 0);
				if (power[4][powernum5] == NULL)
				{
					cancelTimer(0);
					return;
				}
				++powernum5;
			}
			else powernum5 = 0;
		}
		break;
	}

	
	beginPaint();
	clearDevice();
	setPenColor(BLACK);
	setBrushColor(WHITE);
	setTextSize(25);
	putImageScale(&backp, 0, 0, mWindowWidth, mWindowHeight);
	if(life==100)
	    putImageScale(&lf, 130, 10, 600, 50);
	else if(life==75)
        putImageScale(&lf, 130, 10, 450, 50);
	else if (life == 50)
		putImageScale(&lf, 130, 10, 300, 50);
	else if (life == 25)
		putImageScale(&lf, 130, 10, 150, 50);
	else if (life == 0)
		putImageScale(&lf, 130, 10, 10, 50);

	guner->drawImageScale();
	for (int i = 0; i < 5; ++i) {
		if (!archer[i])continue;
		else archer[i]->drawImageScale();
	}
	for (int i = 0; i < 5; ++i) {
		if (!wizard[i])continue;
		else wizard[i]->drawImageScale();
	}
	for (int j = 0; j <bnummax; ++j) {
		if (!bomb[j])continue;
		if (crash(j, bomb) == true) {
			delete bomb[j];
			bomb[j] = NULL;
		}
	}
	
	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < archmax; ++i) {
			if (!arch[j][i])continue;
			if (crash(i,arch[j] ) == true) {
				delete arch[j][i];
				arch[j][i] = NULL;
			}
		}
	}
	
	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < powermax; ++i) {
			if (!power[j][i])continue;
			if (crash(i, power[j]) == true) {
				delete power[j][i];
				power[j][i] = NULL;
			}
		}
	}

	for (int i = 0; i < num1; ++i)
	{
		if (!robot[i])continue;
		robot[i]->move();
		robot[i]->drawImageScale();
		for (int j = 0; j <= bnummax; ++j) {         //判断和炸弹的相撞
			if (crash(i, robot) == true) {
				delete robot[i];
				robot[i] = NULL;
				life -= 25;
				nmax -= 1;
			}
			if (!bomb[j] || !robot[i])continue;
			else {
				if (collision(i, robot, j, bomb) == true) {
					playSound(bamm, 0);
					robot[i]->health -= 50;
					bomb[j]->bamnub = 4;
					if (robot[i]->health <= 0) {
						bomb[j]->bamnub = 1;
						delete robot[i];
						robot[i] = NULL;
						nmax -= 1;
						score += 75;
						magic += 75;
					}
				}
			}
		}
	}

		for (int k = 0; k < num1; ++k) {                        //判断与箭矢的相撞
		if (!robot[k])continue;    
		for (int j = 0; j < 5; ++j) {
			for (int i = 0; i < archmax; ++i) {
				if (!arch[j][i])continue;
				if (collision(k,robot, i, arch[j]) == true) {
					playSound(bamm, 0);
					robot[k]->health -= 80;
					arch[j][i]->bamnub = 4;
					if (robot[k]->health <= 0) {
						arch[j][i]->bamnub = 1;
						delete robot[k];
						robot[k] = NULL; nmax -= 1;
						score += 75;
						magic += 75;
					}
				}
			}
		}
	}
	
		for (int k = 0; k < num1; ++k) {                        //判断与魔法波的相撞
			if (!robot[k])continue;
			for (int j = 0; j < 5; ++j) {
				for (int i = 0; i < powermax; ++i) {
					if (!power[j][i])continue;
					if (collision(k, robot, i, power[j]) == true) {
						playSound(bamm, 0);
						robot[k]->health -= 150;
						power[j][i]->bamnub = 4;
						if (robot[k]->health <= 0) {
							power[j][i]->bamnub = 1;
							delete robot[k];
							robot[k] = NULL; nmax -= 1;
							score += 75;
							magic += 75;
						}
					}
				}
			}
		}


		for (int i = 0; i < num2; ++i)
		{
			if (!robot2[i])continue;
			robot2[i]->move();
			robot2[i]->drawImageScale();
			for (int j = 0; j < bnummax; ++j) {              //判断与炸弹的碰撞

				if (crash(i, robot2) == true) {
					delete robot2[i];
					robot2[i] = NULL; nmax -= 1;
					life -= 25;
				}	
				if (!bomb[j] || !robot2[i])continue;
				else {
					if (collision(i, robot2, j, bomb) == true) {
						playSound(bamm, 0);
						robot2[i]->health -= 50;
						bomb[j]->bamnub = 4;
						if (robot2[i]->health <= 0) {
							bomb[j]->bamnub = 1;
							delete robot2[i];
							robot2[i] = NULL; nmax -= 1;
							score += 50;
							magic += 50;
						}
					}
				}
			}
		}

	for (int k = 0; k < num2; ++k) {                        //判断与箭矢的相撞
		if (!robot2[k])continue;
		for (int j = 0; j < 5; ++j) {
			for (int i = 0; i < archmax; ++i) {
				if (!arch[j][i])continue;
				if (collision(k, robot2, i, arch[j]) == true) {
					playSound(bamm, 0);
					robot2[k]->health -= 80;
					arch[j][i]->bamnub =4;
					if ((robot2[k]->health) <= 0) {
						arch[j][i]->bamnub = 1;
						delete robot2[k];
						robot2[k] = NULL; nmax -= 1;
						score += 50;
						magic += 50;
					}
				}
			}
		}
	}
	
	for (int k = 0; k < num2; ++k) {                        //判断与魔法波的相撞
		if (!robot2[k])continue;
		for (int j = 0; j < 5; ++j) {
			for (int i = 0; i < powermax; ++i) {
				if (!power[j][i])continue;
				if (collision(k, robot2, i, power[j]) == true) {
					playSound(bamm, 0);
					robot2[k]->health -=150;
					power[j][i]->bamnub =4;
					if (robot2[k]->health <= 0) {
						power[j][i]->bamnub = 1;
						delete robot2[k];
						robot2[k] = NULL; nmax -= 1;
						score += 50;
						magic += 50;
					}
				}
			}
		}
	}

	for (int i = 0; i < num3; ++i)
	{
		if (!robot3[i])continue;
		robot3[i]->move();
		robot3[i]->drawImageScale();
		for (int j = 0; j < bnummax; ++j) {              //判断与炸弹的碰撞
			if (crash(i, robot3) == true) {
				delete robot3[i];
				robot3[i] = NULL; nmax -= 1;
				life -= 25;
			}
			if (!bomb[j]||!robot3[i])continue;
			else {
				if (collision(i, robot3, j, bomb) == true) {
					playSound(bamm, 0);
					bomb[j]->bamnub = 1;
					delete robot3[i];
					robot3[i] = NULL; nmax -= 1;
					score += 25;
					magic += 25;
				}
			}
		}
	}

	for (int k = 0; k < num3; ++k) {                        //判断与箭矢的相撞
		if (!robot3[k])continue;
		for (int j = 0; j < 5; ++j) {
			for (int i = 0; i < archmax; ++i) {
				if (!arch[j][i])continue;
				if (collision(k, robot3, i, arch[j]) == true) {
					playSound(bamm, 0);
					arch[j][i]->bamnub = 1;
					delete robot3[k];
					robot3[k] = NULL; nmax -= 1;
					score += 25;
					magic += 25;
				}
			}
		}
	}

	for (int k = 0; k < num3; ++k) {                        //判断与魔法波的相撞
		if (!robot3[k])continue;
		for (int j = 0; j < 5; ++j) {
			for (int i = 0; i < powermax; ++i) {
				if (!power[j][i])continue;
				if (collision(k, robot3, i, power[j]) == true) {
					playSound(bamm, 0);
					power[j][i]->bamnub = 1;
					delete robot3[k];
					robot3[k] = NULL; nmax -= 1;
					score += 25;
					magic += 25;
				}
			}
		}
	}

	for (int i = 0; i <= bnummax; ++i)     //画炸弹爆炸
	{
		if (bomb[i] != NULL) {
			if (bomb[i]->bamnub == 0) {
				bomb[i]->drawImageScale();
			}
			else if (bomb[i]->bamnub == 1) {
				bomb[i]->drawImageScale2(80,50);
				++(bomb[i]->bamnub);
			}
			else if (bomb[i]->bamnub == 2) {
				bomb[i]->drawImageScale2(100, 60);
				++(bomb[i]->bamnub);
			}
			else if (bomb[i]->bamnub == 3) {
				bomb[i]->drawImageScale2(150, 80);
				++(bomb[i]->bamnub);
			}
			else if (bomb[i]->bamnub == 4) {
				bomb[i]->drawImageScale2(180, 100);		
				delete bomb[i];
				bomb[i] = NULL;
			}
		}
	}
	
	for (int j = 0; j <= 5; ++j) {
		for (int i = 0; i <=archmax; ++i)     //画箭矢爆炸
		{
			if (arch[j][i] != NULL) {
				if (arch[j][i]->bamnub == 0) {
					arch[j][i]->drawImageScale();
				}
				else if (arch[j][i]->bamnub == 1) {
					arch[j][i]->drawImageScale2(80, 50);
					++(arch[j][i]->bamnub);
				}
				else if (arch[j][i]->bamnub == 2) {
					arch[j][i]->drawImageScale2(100, 60);
					++(arch[j][i]->bamnub);
				}
				else if (arch[j][i]->bamnub == 3) {
					arch[j][i]->drawImageScale2(150, 80);
					++(arch[j][i]->bamnub);
				}
				else if (arch[j][i]->bamnub == 4) {
					arch[j][i]->drawImageScale2(180, 100);
					delete arch[j][i];
					arch[j][i] = NULL;
				}
			}
		}
	}
	for (int j = 0; j <= 5; ++j) {
		for (int i = 0; i <= powermax; ++i)     //画魔法弹爆炸
		{
			if (power[j][i] != NULL) {
				if (power[j][i]->bamnub == 0) {
					power[j][i]->drawImageScale();
				}
				else if (power[j][i]->bamnub == 1) {
					power[j][i]->drawImageScale2(80, 50);
					++(power[j][i]->bamnub);
				}
				else if (power[j][i]->bamnub == 2) {
					power[j][i]->drawImageScale2(100, 60);
					++(power[j][i]->bamnub);
				}
				else if (power[j][i]->bamnub == 3) {
					power[j][i]->drawImageScale2(150, 80);
					++(power[j][i]->bamnub);
				}
				else if (power[j][i]->bamnub == 4) {
					power[j][i]->drawImageScale2(180, 100);
					delete power[j][i];
					power[j][i] = NULL;
				}
			}
		}
	}
	sprintf_s(s, "%d", score);
	sprintf_s(b, "%d", magic);
	paintText(130, 93, s);
	paintText(130, 160, b);
	
	if (life <= 0) {   //失败
		stopSound(map);
		cancelTimer(0);
		cancelTimer(1);
		cancelTimer(2);
		playSound(gm, 0);
		clearDevice();
		putImageScale(&gameover, 350, 50, 800, 650);
		paintText(370, 300, sc);
		paintText(650, 400, scc);
		paintText(800, 400, s);
	}

	else if (nmax<=0) {      //胜利
		stopSound(map);
		cancelTimer(0);
		cancelTimer(1);
		cancelTimer(2);
		playSound(wining, 0);
		clearDevice();
		putImageScale(&win, 0, 0, 1500, 700);
	}

	endPaint();
}

 void keyevent(int key, int event){
	if (event != KEY_DOWN)return;
	switch (key)
	{
	case VK_SPACE:
		stopSound(op);
		startTimer(0, 8500);
		startTimer(1, 80);
		startTimer(2, 5000);
		playSound(map, 1);
		break;
	case VK_ESCAPE:
		stopSound(map);
		cancelTimer(0);
		cancelTimer(1);
		cancelTimer(2);
		playSound(gm, 0);
		beginPaint();
	    clearDevice();
		putImageScale(&gameover, 350, 50, 800, 650);
		paintText(370, 300, sccc);
		paintText(650, 400, scc);
		paintText(800, 400, s);
		endPaint();
		break;
	case VK_UP:
		if (guner->dd >= 2);
		else
		guner->dd += 1;
		break;
	case VK_DOWN:
		if (guner->dd <= -2);
		else
		guner->dd -= 1;
		break;
	case VK_LEFT:
		if (guner->load == 1) {
			playSound(bombrush, 0);
			bomb[bnum] = new bullet("bomb.jpg", bw, bh, mWindowWidth - 220, mWindowHeight - 300, guner->dd);
			bnum += 1;	
		    if (bnum >= bnummax) {	bnum = 0; 	}
			guner->load = 0;
		}
		break;
	case VK_RIGHT:
		playSound(reload, 0);
		guner->load = 1;
		break;
	case VK_F1:
		if (wizard[0] != NULL||magic<300);else {
			wizard[0] = new player("wizard.jpg", wizardw, wizardh, archerx2, archery1, 300, 0);
			magic -= 300;
		}
		break;
	case VK_F2:
		if (wizard[1] != NULL||magic<300);else {
			wizard[1] = new player("wizard.jpg", wizardw, wizardh, archerx2, archery2, 300, 0);
			magic -= 300;
		}break;
	case VK_F3:		
		if (wizard[2] != NULL || magic < 300); else {
			wizard[2] = new player("wizard.jpg", wizardw, wizardh, archerx4, archery3, 300, 0);
			magic -= 300;
		}break;
	case VK_F4:
		if (wizard[3] != NULL || magic < 300); else {
			wizard[3] = new player("wizard.jpg", wizardw, wizardh, archerx2, archery4, 300, 0);
			magic -= 300;
		}break;
	case VK_F5:
		if (wizard[4] != NULL || magic < 300); else {
			wizard[4] = new player("wizard.jpg", wizardw, wizardh, archerx2, archery5, 300, 0);
			magic -= 300;
		}break;
	case VK_F6:
		if (archer[0] != NULL || magic < 100); else {
			archer[0] = new player("archer.jpg", archerw, archerh, archerx1, archery1, 100, 0);
			magic -= 100;
		}break;
	case VK_F7:
		if (archer[1] != NULL || magic < 100); else {
			archer[1] = new player("archer.jpg", archerw, archerh, archerx1, archery2, 100, 0);
			magic -= 100;
		}break;
	case VK_F8:
		if (archer[2] != NULL || magic < 100); else {
			archer[2] = new player("archer.jpg", archerw, archerh, archerx3, archery3, 100, 0);
		}break;
	case VK_F9:
		if (archer[3] != NULL || magic < 100); else {
			archer[3] = new player("archer.jpg", archerw, archerh, archerx1 + 10, archery4, 100, 0);
			magic -= 100;
		}break;
	case VK_SHIFT:     //不明原理，F10键无法使用
		if (archer[4] != NULL || magic < 100); else {
			archer[4] = new player("archer.jpg", archerw, archerh, archerx1, archery5, 100, 0);
			magic -= 100;
		}break;
	default:
		break;
	}
}

 bool collision(int i,pc*robot[] , int j, bullet *bomb[])
 {
	 bool c = true;
	 if (robot[i] == NULL || bomb[j] == NULL)return false;
     if (robot[i]->x <bomb[j]->dx &&robot[i]->x + robot[i]->width>bomb[j]->dx) {
		 if (robot[i]->y >= bomb[j]->dy && robot[i]->y<=bomb[j]->dy + bomb[j]->height2)return c;
		 if (robot[i]->y <bomb[j]->dy && robot[i]->y + robot[i]->height >bomb[j]->dy)return c;
	 }
	 else {
		 if (robot[i]->x >bomb[j]->dx && bomb[j]->dx + bomb[j]->width2 > robot[i]->x)
		 {
			 if (robot[i]->y > bomb[j]->dy && robot[i]->y<bomb[j]->dy +bomb[j]->height2)return c;
			 if (robot[i]->y <bomb[j]->dy && robot[i]->y + robot[i]->height >bomb[j]->dy)return c;
		 }
	 }
	 c = false;
	 return c;
 }

 bool crash(int i, pc*robot[]) {     //碰撞边框检测
	 bool c = true;
	 if (robot[i] == NULL )return false;
	 if (robot[i]->x + robot[i]->width>= mWindowWidth-328)return c;
	 c = false;
	 return c;
 }
 bool crash(int i, bullet*bomb[]) {     //碰撞边框检测,重载
	 bool c = true;
	 if (bomb[i] == NULL)return false;
	 if (bomb[i]->dx > mWindowWidth || bomb[i]->dx<0 || bomb[i]->dy+bomb[i]->height2>mWindowHeight || bomb[i]->dy < 259)return c;
	 c = false;
	 return c;
 }



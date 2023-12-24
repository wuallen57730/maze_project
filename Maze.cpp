#include <iostream>
#include <fstream>
#include <stack>

#define N 13

using namespace std;
const int Up=0,Down=1,Left=2,Right=3;

struct point{
	int x;
	int y;
	int dir;
	point(int _x,int _y){
		x=_x;
		y=_y;
		dir=Up;
	}
};

bool operator==(const point& p1,const point& p2){
	// 過載判別p1和p2的座標是否重疊
	return p1.x==p2.x && p1.y ==p2.y;	
}

stack<point>s;
bool solve(int maze[N][N],bool visited[N][N],point start,point finish){
	//放入起點
	s.push(start);
	visited[start.x][start.y]=true;
	// 若找不到出口才停下(中斷while迴圈)
	while(!s.empty()){
		if(s.top()==finish) return true;
		int Px=s.top().x;
		int Py=s.top().y;
		int Pd=s.top().dir;
		s.top().dir++;
		switch(Pd){
		// 1.得在迷宮內 2.非牆壁 3.沒走過的格子
			case Up:
				if(Px-1>=0 && maze[Px-1][Py]==0 && !visited[Px-1][Py]){
					point p(Px-1,Py);
					s.push(p);
					visited[Px-1][Py]=true;
				}
				break;
			case Down:
				if(Px+1<N && maze[Px+1][Py]==0 && !visited[Px+1][Py]){
					point p(Px+1,Py);
					s.push(p);
					visited[Px+1][Py]=true;
				}
				break;
			case Left:
				if(Px-1>=0 && maze[Px][Py-1]==0 && !visited[Px][Py-1]){
					point p(Px,Py-1);
					s.push(p);
					visited[Px][Py-1]=true;
				}
				break;
			case Right:
				if(Px+1<N && maze[Px][Py+1]==0 && !visited[Px][Py+1]){
					point p(Px,Py+1);
					s.push(p);
					visited[Px][Py+1]=true;
				}
				break;
			default:
				s.pop();
				break;
		}
	}
	return false;
}
int main(){
	fstream fin;
	int maze[N][N];
	bool visited[N][N]={{0}};
	fin.open("maze.txt",ios::in);
	if(!fin){
		cout << "file cannot be opened!" << endl;
		return 0;
	}else{
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					fin>>maze[i][j];
				} 
			}
		}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			switch(maze[i][j]) {
	            case 0 : cout << "  "; break;
	            case 1 : cout << "# "; break;
        	}
		}
		cout << endl;
	}
	//宣告起點終點
	point start(1,0);
	point finish(11,12);
	if(solve(maze,visited,start,finish)){
		cout<<"Finish the Maze!!"<<'\n';
		cout<<'\n';
		while(!s.empty()){
			int X=s.top().x;
			int Y =s.top().y;
			s.pop();
			maze[X][Y]=2;
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				switch(maze[i][j]) {
					case 0 : cout << "  "; break;
					case 1 : cout << "# "; break;
					case 2 : cout << "* "; break;
				}
			}
		cout << '\n';
	}
	}
	else{
		cout<<"Cannot finish the Maze."<<'\n';
	}
	return 0;
}

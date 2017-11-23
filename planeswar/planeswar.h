#pragma once
#include <assert.h>
#include <mmsystem.h>

#include "resource.h"

#pragma comment(lib,"msimg32.lib")
#pragma comment(lib,"winmm.lib")

#define MAX_LOADSTRING 100

//定义窗口尺寸
#define WNDWIDTH	380
#define WNDHEIGHT	550

//bmp数量
#define BMPCOUNT	  9


//声明结构体
typedef enum {
	WELCOME,
	RUNING,
	OVER,
}GAMESTATUS;//游戏所处状态

typedef enum {
	BIG = 0,
	MIDDLE = 1,
	SMALL = 2,
}PLANETYPE;

typedef struct {
	GAMESTATUS		g_status;
	UINT			g_score;
	UINT			g_plNum;
}GAME;

typedef struct plane{
	PLANETYPE		p_type;
	POINT			p_point;
	UINT			p_speed;
	UINT			p_maxHP;
	UINT			p_hitCount;
	HBITMAP			p_hbmp;
	struct plane	*next;
}PLANE;

typedef struct {
	UINT			t_speed;
	UINT			t_maxHP;
	HBITMAP			t_hbmp;
}TYPEINFO;

// 全局变量: 
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
HBITMAP hbBmp[BMPCOUNT];						// 储存位图句柄的数组
int uiBmpName[BMPCOUNT] = {						// 储存位图ID的数组
	IDB_BackColor,
	IDB_BIG,
	IDB_EXIT,
	IDB_GAMEOVER,
	IDB_LOGO,
	IDB_MIDDLE,
	IDB_RESTART,
	IDB_SMALL,
	IDB_START,
};
GAME s_game;
TYPEINFO big_info, middle_info, small_info;
PLANE *p_head;

// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
//init:
VOID				initgame(LPARAM);							//初始化全局变量

//scence:
VOID				drawSenceUI(HDC, PLANE*);					//分场景画出界面
VOID				drawbackground(HDC, HDC, HBITMAP*);			//画背景
VOID				drawSenceI(HDC, HDC, HBITMAP*, BITMAP);		//画场景一：WELCOME
VOID				drawSenceII(PLANE*, HDC, HDC, BITMAP);		//画场景二：RUNING

//opreate:
VOID				lButtondownProc(HWND, LPARAM);				//鼠标左键按下事件
BOOL				checkbutton_start(POINT);					//检测开始按钮是否被按下

//enime:
VOID				createHeadPlane(PLANE*);					//构造出出头结点飞机
VOID				getRandomPlaneInfo(PLANE*);					//获得一个随机的飞机信息



#pragma once
#include <assert.h>
#include <mmsystem.h>
#include <time.h>
#include "resource.h"

#pragma comment(lib,"msimg32.lib")
#pragma comment(lib,"winmm.lib")

#define MAX_LOADSTRING	100

//定义窗口尺寸
#define WNDWIDTH		380
#define WNDHEIGHT		550

#define BMPCOUNT		9		//bmp数量
#define TIMER			1		//timer ID
#define PLANENUM		10		//飞机数量

#define WM_START (WM_USER + 1)	//自定义开始事件




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
	BOOL			g_bigAdd;
}GAME;

typedef struct {
	PLANETYPE		p_type;
	SIZE			p_size;
	POINT			p_point;
	UINT			p_speed;
	UINT			p_maxHP;
	UINT			p_hitCount;
}PLANE;

typedef struct {
	UINT			t_speed;
	UINT			t_maxHP;
	SIZE			t_size;
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
PLANE planes[PLANENUM];

// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

//init:
VOID				initgame(LPARAM);							//初始化全局变量

//scence:
VOID				drawSenceUI(HDC);							//分场景画出界面
VOID				drawbackground(HDC, HDC, HBITMAP*);			//画背景
VOID				drawSenceI(HDC, HDC, HBITMAP*, BITMAP);		//画场景一：WELCOME
VOID				drawSenceII(HDC, HDC, HBITMAP*, BITMAP);	//画场景二：RUNING

//message event:
VOID				lButtondownProc(HWND, LPARAM);				//鼠标左键按下事件
BOOL				checkbutton_start(POINT);					//检测开始按钮是否被按下
VOID				timerProc(HWND);							//计时器事件

//enime:
VOID				updatePlaneInfo(BOOL, UINT);



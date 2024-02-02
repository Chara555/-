
//
#include<conio.h>
#include<stdlib.h>
#include <iostream>
#include<easyx.h>
#include<stdio.h>
int main()
{
    //创建一个窗体，并把窗体变为绿色
    initgraph(800, 600);
    setorigin(400, 300);
    setaspectratio(1, -1);
    setbkcolor(RGB(164, 225, 202));
    cleardevice();
    //创建圆的初始值
    int x = 0;//小球横坐标
    int y = 0;//小球纵坐标
    int vx = 5, vy = 5;//小球水平方向和竖直方向的运动速度
    int r = 40;//半径
    //绘制一个由玩家控制的挡板
    int barLeft, barTop, barRight, barBottom;
    barLeft = -150;
    barRight = 150;
    barTop = -280;
    barBottom = -300;
   //赋予小球随机值，开始游戏
    x = rand() % (400 + 1) - 200;
    y = rand() % (300 + 1) - 150;
    //速度方向随机
    if (rand() % 2 == 0) {
        vy = -vy;

    }
    if (rand() % 2 == 0) {
        vx = -vx;
    }
    //绘制挡板，圆
    while (1) {
        cleardevice();
        solidcircle(x, y, r);
        solidrectangle(barLeft, barTop, barRight, barBottom);
        Sleep(40);
        //小球碰到上边或者两边进行反弹
        if (y >= 300-r) {
            vy = -1 * vy;

        }
        if (x <= -400+r || x >= 400-r) {
            vx = -1 * vx;
        }
        //小球碰到挡板反弹
        if (barLeft <= x && x <= barRight && y <= barTop + r) {
            vy = -vy;
        }
        x += vx;
        y += vy;
        /*使用kbhit函数与getch函数保证游戏的交互性
        kbhit返回值不为0,即为用户按下键盘.然后通过getch函数
        获取用户按下的按键,当按下a或d时，挡板移动
        */
        if (_kbhit() != 0) {
            char c = _getch();
            if (c == 'a') {
                if (barLeft >= -400)//确保挡板不会越出屏幕
                {
                    barLeft -= 20;
                    barRight -= 20;
                }
            }
                else if (c == 'd') {
                    if (barRight < 400) {//确保挡板不会越出屏幕
                        barLeft += 20;
                        barRight += 20;
                    }
                }
            
        }
        //如果小球掉出屏幕，游戏结束，随机值重新开始
        if (y <= -300) {
            //小球初始位置随机
            x = rand() % (400 + 1) - 200;
            y = rand() % (300 + 1) - 150;
            vx = 5;
            vy = 5;
            //速度方向随机
            if (rand() % 2 == 0) {
                vy = -vy;

            }
            if (rand() %2==0) {
                vx = -vx;
            }
            barLeft = -150;
            barRight = 150;
            barTop = -280;
            barBottom = -300;
        }
    }
   

    getchar();
    closegraph();

}


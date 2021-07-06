#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <wingdi.h>
#include <gdiplus.h>
#include <future>
#include <QtGui/qpainter.h>
#include <QApplication>
#include <Qt>
#undef _UNICODE_
#pragma comment(lib, "gdiplus.lib")

void draw(HDC dc) {
    int x, y;
    POINT p;
    SelectObject(dc, GetStockObject(DC_PEN));
    SetDCPenColor(dc, RGB(255, 255, 255));
    while (true) {
        if (GetAsyncKeyState(VK_RBUTTON) < 0) {
            break;
        }
        GetCursorPos(&p);
        x = p.x;
        y = p.y;
//        printf("clicked");

        TextOutA(dc, x, y, "Hola camilo", 12);
//        LineTo(dc, x, y);
//        Sleep(100);
    }

}

void drawObject(HDC hdc) {
    using namespace Gdiplus;

    GdiplusStartupInput ginput;
    u_long token;
    GdiplusStartup(reinterpret_cast<ULONG_PTR *>(&token), &ginput, NULL);
    Graphics *g = new Graphics(hdc);
    POINT point;
    Pen pen(Color(255, 0, 0), 2);


    while (true) {
//        auto dc = GetDC(0);
        GetCursorPos(&point);


        Rect rect(point.x, point.y, 80, 40);
//        RECT myrect;
//        myrect.top=40;
//        myrect.right=80;
//        myrect.left=point.x;
//        myrect.bottom=point.y;
//        InvalidateRect(0,&myrect,false);
        g->DrawRectangle(&pen, rect);
        g->DrawLine(&pen, 100, 200, 100, 100);
//        QPainter p;
//        p.begin(reinterpret_cast<QPaintDevice *>(QApplication::desktop()));
//        QPen pen;
//        pen.setColor(QColor().red());
//        p.setPen(pen);
//        p.drawRect(point.x, point.y, 250, 400);
        if (GetAsyncKeyState(VK_RBUTTON) < 0) {
            break;
        }

//        ReleaseDC(0, hdc);

    }

}

void deleteDC(){

    while(true) {
        InvalidateRect(0, nullptr, false);
        Sleep(200);
    }
}

int main(int argc,char*argv[]) {

//    auto dc=CreateDC("DISPLAY",nullptr,0,0);
    auto dc = GetDC(0);
    RECT rect = {30, 50, 100, 200};
    //auto brush = CreateSolidBrush(RGB(0, 0, 0));


//    FillRect(dc,&rect,brush);
//    CreateThread(nullptr,0,(LPTHREAD_START_ROUTINE)&drawObject,&dc,0, nullptr);
    auto future = std::async(std::launch::async, drawObject, dc);
//    auto f1 = std::async(std::launch::async, deleteDC);

    system("pause");

    return 0;
}

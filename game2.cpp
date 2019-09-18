#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<dos.h>
#include<string.h>
#include<iostream>
#include<ctime>

int carlefttopx,carlefttopy,carrighttopx,carrighttopy,carleftdownx,carleftdowny,carrightdownx,carrightdowny;
int ex1carlefttopx,ex1carlefttopy,ex1carrightdownx,ex1carrightdowny,ex1speed;
int ex2carlefttopx,ex2carlefttopy,ex2carrightdownx,ex2carrightdowny,ex2speed;
int crash,points;
char a[100];

void ask_to_start_the_game()
{

    while(1)
    {
        setcolor(2);
        rectangle(getmaxx()/2-100,getmaxy()/2-50,getmaxx()/2+100,getmaxy()/2+30);
        setcolor(15);
        outtextxy(getmaxx()/2-25,getmaxy()/2-15,"START");
        delay(20);
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x,y;
            getmouseclick(WM_LBUTTONDOWN,x,y);
            //printf("%d %d\n",x,y);
            if(x>getmaxx()/2-100 && x<getmaxx()/2+100 && y<getmaxy()/2+30 && y>getmaxy()/2-50)
                break;
        }
        int p,q;
        p=mousex();
        q=mousey();
        //printf("%d %d\n",p,q);
        if(p>getmaxx()/2-100 && p<getmaxx()/2+100 && q<getmaxy()/2+30 && q>getmaxy()/2-50)
        {

            setfillstyle(INTERLEAVE_FILL,GREEN);
            floodfill(getmaxx()/2,getmaxy()/2,2);
            setcolor(15);
            outtextxy(getmaxx()/2-25,getmaxy()/2-15,"START");
        }
        else
            clearviewport();

    }

}
void game_instruc()
{
    outtextxy(getmaxx()/2-130,getmaxy()/2-15,"Use Keyboard Arrow Keys To Move The CAR" );

    delay(4500);

}
void evenroad()
{

    int i;
    for(i=0; i<=450; i+=100)
    {
        line(getmaxx()/2-110,5+i,getmaxx()/2-110,15+i);
        line(getmaxx()/2-100,0+i,getmaxx()/2-100,30+i);
        line(getmaxx()/2,0+i,getmaxx()/2,30+i);
        line(getmaxx()/2+100,0+i,getmaxx()/2+100,30+i);
        line(getmaxx()/2+110,5+i,getmaxx()/2+110,15+i);
    }

    delay(50);
    clearviewport();

}
void oddroad()
{

    int i;
    for(i=0; i<=450; i+=100)
    {
        line(getmaxx()/2-110,22+i,getmaxx()/2-110,35+i);
        line(getmaxx()/2-100,45+i,getmaxx()/2-100,70+i);
        line(getmaxx()/2,45+i,getmaxx()/2,70+i);
        line(getmaxx()/2+100,45+i,getmaxx()/2+100,70+i);
        line(getmaxx()/2+110,22+i,getmaxx()/2+110,35+i);
    }
    delay(50);
    clearviewport();

}
int green_fld()
{
//grass
    setcolor(15);
    line(getmaxx()/2+130,0,getmaxx()/2+130,getmaxy());
    setfillstyle(SOLID_FILL,2);
    floodfill(getmaxx()-20,getmaxy()-20,15);

    setcolor(15);
    line(getmaxx()/2-130,0,getmaxx()/2-130,getmaxy());
    setfillstyle(SOLID_FILL,2);
    floodfill(5,5,15);
    delay(10);
//grass
}

void car_body()
{
    char c;
    //car move

    green_fld();
    if (kbhit())
    {
        c= getch();
        //printf("%d\n",c);
        if(c==75 && carlefttopx>(getmaxx()/2-90))
        {
            carleftdownx=carleftdownx-10;
            carlefttopx=carlefttopx-10;
            carrighttopx=carrighttopx-10;
            carrightdownx=carrightdownx-10;

        }
        if(c==77 && carrighttopx<(getmaxx()/2+90))
        {
            carleftdownx=carleftdownx+10;
            carlefttopx=carlefttopx+10;
            carrighttopx=carrighttopx+10;
            carrightdownx=carrightdownx+10;

        }
        if(c==72 && carlefttopy>10)
        {
            carleftdowny=carleftdowny-15;
            carlefttopy=carlefttopy-15;
            carrighttopy=carrighttopy-15;
            carrightdowny=carrightdowny-15;

        }
        if(c==80 && carleftdowny<(getmaxy()-10))
        {
            carleftdowny=carleftdowny+15;
            carlefttopy=carlefttopy+15;
            carrighttopy=carrighttopy+15;
            carrightdowny=carrightdowny+15;

        }
        clearviewport();

    }
// car move
//carbody
    ///bumper
    line(carlefttopx,carlefttopy+5,carrighttopx,carrighttopy+5);
    ///bumper
    ///outer part
    line(carlefttopx,carlefttopy,carleftdownx,carleftdowny);
    line(carrighttopx,carrighttopy,carrightdownx,carrightdowny);
    line(carlefttopx,carlefttopy,carrighttopx,carrighttopy);
    line(carleftdownx,carleftdowny,carrightdownx,carrightdowny);
    ///outer part

    ///iner part
    //sideline

    line(carlefttopx+7,carlefttopy+10,carleftdownx+7,carleftdowny+4);
    line(carrighttopx-7,carrighttopy+10,carrightdownx-7,carrightdowny+4);
    //squre
    line(carlefttopx+15,carlefttopy+15,carleftdownx+15,carleftdowny-15);
    line(carrighttopx-15,carrighttopy+15,carrightdownx-15,carrightdowny-15);
    line(carlefttopx+15,carlefttopy+15,carrighttopx-15,carrighttopy+15);
    line(carleftdownx+15,carleftdowny-15,carrightdownx-15,carrightdowny-15);

    ///iner part

    setfillstyle(SOLID_FILL,BLUE);
    floodfill(carlefttopx+3,carlefttopy+3,15);
    setfillstyle(SOLID_FILL,4);
    floodfill(carlefttopx+7,carlefttopy+7,15);//outer
    setfillstyle(SOLID_FILL,9);
    floodfill(carlefttopx+17,carlefttopy+17,15);//iner
    //carbody
    delay(20);
}


ex_car1()
{
    rectangle(ex1carlefttopx,ex1carlefttopy,ex1carrightdownx,ex1carrightdowny);//outer rextangle

    setfillstyle(SOLID_FILL,3);//outer rextangle color
    floodfill(ex1carlefttopx+2,ex1carlefttopy+2,15);
    setfillstyle(SOLID_FILL,3);
    floodfill(ex1carrightdownx-2,ex1carrightdowny-2,15);

    rectangle(ex1carlefttopx+10,ex1carlefttopy+10,ex1carrightdownx-10,ex1carrightdowny-10);//inner rextangle

    setfillstyle(SOLID_FILL,14);//inner rextangle color
    floodfill(ex1carlefttopx+12,ex1carlefttopy+12,15);
    setfillstyle(SOLID_FILL,14);
    floodfill(ex1carrightdownx-11,ex1carrightdowny-11,15);


    ex1carlefttopy=ex1carlefttopy+ex1speed;

    ex1carrightdowny=ex1carrightdowny+ex1speed;


}
ex_car2()
{

    rectangle(ex2carlefttopx,ex2carlefttopy,ex2carrightdownx,ex2carrightdowny);//outer rextangle

    setfillstyle(SOLID_FILL,6);//outer rextangle color
    floodfill(ex2carlefttopx+2,ex2carlefttopy+2,15);
    setfillstyle(SOLID_FILL,6);
    floodfill(ex2carrightdownx-2,ex2carrightdowny-2,15);


    rectangle(ex2carlefttopx+10,ex2carlefttopy+10,ex2carrightdownx-10,ex2carrightdowny-10);//inner rextangle


    setfillstyle(SOLID_FILL,5);//inner rextangle color
    floodfill(ex2carlefttopx+12,ex2carlefttopy+12,15);
    setfillstyle(SOLID_FILL,5);
    floodfill(ex2carrightdownx-12,ex2carrightdowny-12,15);


    ex2carlefttopy=ex2carlefttopy+ex2speed;
    ex2carrightdowny=ex2carrightdowny+ex2speed;

}

int check_crash()
{
    if(carlefttopx-2<ex1carrightdownx)///for 1st extra car
    {
        if(carlefttopy>ex1carlefttopy && carlefttopy<ex1carrightdowny-5)
        {
            return 1;
        }
        if(carleftdowny>ex1carlefttopy-6 && carleftdowny<ex1carrightdowny)
        {
            return 1;
        }
    }

    if(carrighttopx+2>ex2carlefttopx)///for 2nd extra car
    {
        if(carrighttopy>ex2carlefttopy && carrighttopy<ex2carrightdowny)
        {
            return 1;
        }
        if(carrightdowny>ex2carlefttopy-6 && carrightdowny<ex2carrightdowny)
        {
            return 1;
        }
    }


    else
        return 0;


}
int main(void)
{



    /* request auto detection */
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
    /***********************************/
    int i;

    ask_to_start_the_game();
    clearviewport();
    game_instruc();
    cleardevice();


    ///start from here

sfh:

//my car
    carlefttopx=getmaxx()/2+10;
    carlefttopy=getmaxy()-80;
    carrighttopx=getmaxx()/2+60;
    carrighttopy=getmaxy()-80;
    carleftdownx=getmaxx()/2+10;
    carleftdowny=getmaxy()-10;
    carrightdownx=getmaxx()/2+60;
    carrightdowny=getmaxy()-10;
//my car

//extra car
    ex1carlefttopx=getmaxx()/2-70;
    ex1carlefttopy=-350;
    ex1carrightdownx=getmaxx()/2-30;
    ex1carrightdowny=-290;
    ex1speed=12;


    ex2carlefttopx=getmaxx()/2+30;
    ex2carlefttopy=-65;
    ex2carrightdownx=getmaxx()/2+70;
    ex2carrightdowny=-5;
    ex2speed=10;
//extra car


    points=0;
    crash=0;

    for(i=-1000;; i++)
    {


        green_fld();
//car_road
        car_body();
        if(i%2==0)
        {
            evenroad();
            ex_car1();
        }
        if(i%2!=0)
        {
            oddroad();
            ex_car2();
        }




        crash=check_crash();/// check the car crashed or not . for (crashed- 1) , (not crashed- 0.)
        if(crash==1)
        {
            //to every thing visible

            for(i=0; i<=450; i+=100)
            {
                line(getmaxx()/2-110,22+i,getmaxx()/2-110,35+i);
                line(getmaxx()/2-100,45+i,getmaxx()/2-100,70+i);
                line(getmaxx()/2,45+i,getmaxx()/2,70+i);
                line(getmaxx()/2+100,45+i,getmaxx()/2+100,70+i);
                line(getmaxx()/2+110,22+i,getmaxx()/2+110,35+i);
            }
            ex_car2();
            ex_car1();
            car_body();
            green_fld();
            //to every thing visible

            outtextxy(getmaxx()/2-20,getmaxy()/2,"THE CAR CRASHED");
            break;
        }                  /// check the car crashed or not . for (crashed- 1) , (not crashed- 0.)





        car_body();
        green_fld();


        ///extra car reset
        if(ex1carlefttopy>550)
        {
            ex1carlefttopx=getmaxx()/2-70;
            ex1carlefttopy=-310;
            ex1carrightdownx=getmaxx()/2-30;
            ex1carrightdowny=-250;
            ex1speed++;
            if(ex1speed==14)
            {

                ex1speed=20;
            }
            if(ex1speed==11)
            {

                ex1speed=12;
            }

            points++;

        }

        if(ex2carlefttopy>540)
        {
            ex2carlefttopx=getmaxx()/2+30;
            ex2carlefttopy=-100;
            ex2carrightdownx=getmaxx()/2+70;
            ex2carrightdowny=-40;
            ex2speed--;
            if(ex2speed==6)
                ex2speed=12;
            points++;

        }
        ///extra car reset


        car_body();
        green_fld();

    }

///print points
int m,n,t;
        for(m=points,n=0;m>0;m=m/10,n++)
        {
            t=m%10;
            t+=48;
            a[n]=t;
        }
        a[n]='\0';
        setcolor(15);
        outtextxy(20,50,"points:");

        if(points==0)
            outtextxy(65,50,"00");
        else
        {
           strrev(a);
           outtextxy(65,50,a);
        }
///print points

    while(1)
    {

        setcolor(15);
        rectangle(50,getmaxy()/2-50,150,getmaxy()/2+30);
        setcolor(4);
        outtextxy(55,getmaxy()/2-15,"PLAY AGAIN");
        delay(20);

        setcolor(15);
        rectangle(getmaxx()/2+150,getmaxy()/2-50,getmaxx()/2+250,getmaxy()/2+30);
        setcolor(4);
        outtextxy(getmaxx()/2+182,getmaxy()/2-18,"EXIT");
        delay(20);
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x,y;
            getmouseclick(WM_LBUTTONDOWN,x,y);
            //printf("%d %d\n",x,y);
            if(x>50 && x<150 && y<getmaxy()/2+30 && y>getmaxy()/2-50)
                goto sfh;
            else if(x>getmaxx()/2+150 && x<getmaxx()/2+250 && y<getmaxy()/2+30 && y>getmaxy()/2-50)
            {
                cleardevice();
                settextstyle(2,HORIZ_DIR,10);
                outtextxy(0,getmaxy()/2,"THANK     YOU");
                break;
            }

        }
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    getch();
    closegraph();
    return 0;
}

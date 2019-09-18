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



#define S_N_L (radius-10)        // Second Needle Length
#define S_N_C RED                   // Second needle Color
#define M_N_L (radius-20)           // Minute Needle Length
#define M_N_C LIGHTRED              // Minute Needle Color
#define H_N_L (radius-(radius/2))       // Hour Needle Length
#define H_N_C CYAN                     // Hour Needle Color

int main(void)
{
    int i,k,points=0;
    /* request auto detection */
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
    /***********************************/
    int ball_centerx=150,ball_centery=300,ball_rd=15;

    int roadleftx=0,roadlefty=316,roadrightx=getmaxx(),roadrighty=316;

    int road2leftx=0+10,road2lefty=322,road2rightx=getmaxx()/2-10,road2righty=322;//road2

    int road3leftx=getmaxx()/2+10,road3lefty=322,road3rightx=getmaxx()-10,road3righty=322;//road3

    char c;

    int m=0,n=0;

    int obs1xtop=getmaxx()+10,obs2xtop=getmaxx()+15,obs3xtop=getmaxx()+19;
    int obs1ytop=265,obs2ytop=244;
    int obs1ydown=315,obs2ydown=315;
    int obs1speed=5,obs2speed=6;

    for(i=0;; i++)
    {
        outtextxy(50,430,"Press space to jump,but don't hold down");
        ///rewrite obs
        if(obs1xtop<0)//1
        {
            obs1xtop=getmaxx()+10;
        points++;
        }
            else
                obs1xtop-=obs1speed;
        if(obs2xtop<0)//2
        {
            obs2xtop=getmaxx()+15;
            points++;
        }

        else
            obs2xtop-=obs2speed;



        ///rewrite obs
        ///road
        line(roadleftx,roadlefty,roadrightx,roadrighty);
        ///road

        //road2
        if(i%2==0)
            line(road2leftx,road2lefty,road2rightx,road2righty);
        else
            line(road3leftx,road3lefty,road3rightx,road3righty);

        //road2

        ///bostacles
           line(obs1xtop,obs1ytop,obs1xtop,obs1ydown) ;//1
           line(obs2xtop,obs2ytop,obs2xtop,obs2ydown) ;//2
        ///obstacles

        ///game over
        //1
        //printf("%d  ",obs2xtop);
           //1
            if((ball_centerx-1)==obs1xtop && ball_centery>obs1ytop && ball_centery<obs1ydown)
            {

                settextstyle(1,HORIZ_DIR,50);
                setcolor(RED);
                outtextxy(50,200,"game over");
                break;
            }
        //1

        //2
            if(ball_centerx==obs2xtop && ball_centery>obs2ytop && ball_centery<obs2ydown)
            {

                settextstyle(1,HORIZ_DIR,50);
                setcolor(RED);
                outtextxy(50,200,"game over");
                break;
            }
        //2
        ///game over

        ///key

        if(m>=17)
        {
            n=16;
            m=0;
        }

        if(kbhit())
        {
            c=getch();
           //printf("%d",c);
         if(c==32 && m<18)
         {


                    ball_centerx=150,ball_centery=ball_centery-m,ball_rd=15;
                    m++;



         }

        }
        if(m>0){
            ball_centerx=150,ball_centery=ball_centery-m,ball_rd=15;
            m++;
            }
        if(m>=17)
        {

            n=m-1 ;
            m=0;
        }

        if(n>0 )
        {
            ball_centerx=150,ball_centery=ball_centery+n,ball_rd=15;
            n--;
        }

        ///key





        ///wheel
        setcolor(15);
        circle (ball_centerx, ball_centery, ball_rd);
        if(i%2==0)
        {
        setfillstyle(SOLID_FILL,RED);
        floodfill(ball_centerx-7,ball_centery-7,15);
        delay(10);
        }
        else
        {
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(ball_centerx-7,ball_centery-7,15);
        delay(10);
        }


        if(abs(i)%2==0)
        {
            setcolor(15);
            line(ball_centerx,ball_centery-15,ball_centerx,ball_centery+15);


        }
        else if(i%5==0)
        {
            setcolor(15);
            line(ball_centerx+8,ball_centery-10,ball_centerx-8,ball_centery+10);


        }
        else
        {
            setcolor(15);
            line(ball_centerx-15,ball_centery,ball_centerx+15,ball_centery);
        }
        ///wheel






        delay(30);
        cleardevice();
    }
 ///wheel
        setcolor(15);
        circle (ball_centerx, ball_centery, ball_rd);

        setfillstyle(SOLID_FILL,RED);
        floodfill(ball_centerx-7,ball_centery-7,15);
        delay(10);





            setcolor(15);
            line(ball_centerx,ball_centery-15,ball_centerx,ball_centery+15);
///wheel

    ///print points
int t;
char a[100];
        for(m=points,n=0;m>0;m=m/10,n++)
        {
            t=m%10;
            t+=48;
            a[n]=t;
        }
        a[n]='\0';

        settextstyle(1,HORIZ_DIR,5);
        setcolor(15);
        outtextxy(10,20,"points:");

        if(points==0){
            settextstyle(1,HORIZ_DIR,5);
                setcolor(15);
            outtextxy(200,20,"00");
            }
        else
        {
           strrev(a);
           outtextxy(200,20,a);
        }
 ///print points
    getch();
    closegraph();
    return 0;

}


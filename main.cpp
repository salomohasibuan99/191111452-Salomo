#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <math.h>

using namespace std;

struct point2D{
    int x;
    int y;
};

struct garis{
    struct point2D t1;
    struct point2D t2;
};

void gambar(point2D ttk[], int n, int color ){
        setcolor(color);
        int data[2*n];
        for(int i=0;i<n;i++){
            data[2*i]=ttk[i].x + getmaxx()/2;
            data[2*i+1] = getmaxy()/2 - ttk[i].y;
            printf("%d %d\n", data[i], data[i+1]);
        }
        drawpoly(n, data);
}
void gambar_garis(struct garis grs, int color){
    setcolor(color);
    line(grs.t1.x,grs.t1.y,grs.t2.x,grs.t2.y);
}

void kotak (struct point2D t1, struct point2D t2, int color)
{	struct garis grs[4];
	struct point2D ttk[4]; //T1: 100,50 T2:250, 150
    ttk[0].x=t1.x; ttk[0].y=t1.y; //T0 100,50
    ttk[1].x=t2.x; ttk[1].y=t1.y; //T1 250,50
    ttk[2].x=t2.x; ttk[2].y=t2.y; //T2 250,150
    ttk[3].x=t1.x; ttk[3].y=t2.y; //T3 100,150

    grs[0].t1.x = ttk[0].x; grs[0].t1.y = ttk[0].y;
	grs[0].t2.x = ttk[1].x; grs[0].t2.y = ttk[1].y;
	//100,50..............250,50
	grs[1].t1.x = ttk[1].x; grs[1].t1.y = ttk[1].y;
	grs[1].t2.x = ttk[2].x; grs[1].t2.y = ttk[2].y;
	//250,50..............250,150
	grs[2].t1.x = ttk[2].x; grs[2].t1.y = ttk[2].y;
	grs[2].t2.x = ttk[3].x; grs[2].t2.y = ttk[3].y;
	//250,150............100,150
	grs[3].t1.x = ttk[3].x; grs[3].t1.y = ttk[3].y;
	grs[3].t2.x = ttk[0].x; grs[3].t2.y = ttk[0].y;
	//100,150.............100,50
 	gambar_garis(grs[0], color);
	gambar_garis(grs[1], color);
	gambar_garis(grs[2], color);
	gambar_garis(grs[3], color);
}
void isi_kotak_x(struct point2D t1, struct point2D t2, int color, int count)
{	int len, incr, i;
	struct garis grs;
	grs.t1.x=t1.x; grs.t1.y=t1.y;
	grs.t2.x=t1.x; grs.t2.y=t2.y;
    //100,50 dan 250,150
    //len = 150
    //150/30 =5
	len = abs(t2.x - t1.x);
	incr = abs(len/count);

	for (i=1; i<=count; i++)
	{
		grs.t1.x += incr;
		grs.t2.x += incr;
		gambar_garis(grs, color);
	}
}
void isi_kotak_y(struct point2D t1, struct point2D t2, int color, int count)
{	int len, incr, i;
	struct garis grs;
	grs.t1.x=t1.x; grs.t1.y=t1.y;
	grs.t2.x=t2.x; grs.t2.y=t1.y;

	len = abs(t2.y - t1.y);
	incr = abs(len/count);

	for (i=1; i<=count; i++)
	{
		grs.t1.y += incr;
		grs.t2.y += incr;
		printf("%d %d %d %d\n", grs.t1.x,grs.t1.y,grs.t2.x,grs.t2.y);
		gambar_garis(grs, color);
	}
}

void lingkaran(int r, int start, int end, float step)
{
	double midx, midy, rad, angle=0.0;
	double x,y,scr_x,scr_y;
	midx=getmaxx()/2;
	midy=getmaxy()/2;
	rad=3.14/180; //Hasil = 0.174
	do {
		angle+=step;

	//menghitung nilai sumbu dalam koordinat sistem
		x=r*cos(angle*rad);
		y=r*sin(angle*rad);
		//konversi ke koordinat layar
		scr_x=x+midx;
		scr_y=midy-y;
		putpixel(scr_x,scr_y,7);
	}while (angle<=end);
}

void isiLingkaran(int r, int start, int end, float step)
{
    double midx, midy, rad, angle=0.0;
	double x,y,scr_x,scr_y;
	rad=3.14/180;
	while (r>=0)
	{ 	angle=start;  //set kembali ke sudut awal
		do {
			angle+=step;
			x=r*cos(angle*rad);
			y=r*sin(angle*rad);

			scr_x=x+midx;
			scr_y=midy-y;
			putpixel(scr_x,scr_y,7);
		}while (angle<=end);
		r -= 1;   //jari-jari berkurang hingga sama dengan 0
	}
}


int main()
{
    initwindow(400, 640);
    lingkaran(200,0,360,1);
    isiLingkaran(200,0,360,1);
    circle(100,100,20);
    /*point2D ttk [] = {{100,50},{250,150}};
    kotak(ttk[0],ttk[1],7);
    isi_kotak_y(ttk[0],ttk[1],7,10);

    setcolor(7);
    rectangle(10,10,320,200);
    setfillstyle(4,7);
    floodfill(10,50,7);*/
    getch();
    closegraph();
    return 0;
}

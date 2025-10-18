#include<math.h>
void write_pixel(int x,int y,short color)
{
	if(x<320 && y<240)
	{
	volatile short *vga_addr = (volatile short*)(0x08000000+(y<<10)+(x<<1));
	*vga_addr = color;
	}
}
 
//Write a pixel
void write_char(int x,int y,char c)
{
	if(x<79&&y<59)
	{
	volatile char* char_buff = (char*) (0x09000000+(y<<7)+x);
	*char_buff = c;
	}
}
 
 
//Clear screen
void clear_screen(short color)
{
	int x,y;
	for(x=0;x<320;x++)
	{
		for(y=0;y<240;y++)
		{
			write_pixel(x,y,color);
		}
	}
}
 
//Clear character buffer
void clear_text()
{
	int x,y;
	for(x=0;x<79;x++)
	{
		for(y=0;y<59;y++)
		{
			write_char(x,y,' ');
		}
	}
}
//Complete clear function
void clear(short color)
{
	clear_screen(color);
	clear_text();
}
 
void draw_line(int x1,int y1,int x2,int y2,short color)
{
	//Slope of the line
	if(x2!=x1)
	{
		float slope = (float)(y2-y1)/(float)(x2-x1);
		//increment (is the line going from right to left or vice versa)
		int inc;
		//(if x1>x2)
		if(x1>x2)
		{
			inc =-1;
		}
		else
		{
			inc =+1;
		}
 
 
		for(int x = x1;x!=x2;x+=inc)
		{
			int y = y1 + (int)round(slope*(float)(x-x1));
			write_pixel(x,y,color);
		}
	}
	else
	{
		
		int inc;
		if(y1>y2)
		{
			inc =-1;
		}
		else
		{
			inc =+1;
		}
		
		for(int y= y1;y!=y2;y+=inc)
		{
			
			write_pixel(x1,y,color);		
		}
	}
}
 
void draw_rect(int x1,int y1,int width,int height,short color)
{
	for(int i=y1;i<y1+height;i++)
	{
		draw_line(x1,i,x1+width,i,color);
	}
}
 
void draw_circle(int cx,int cy,int r,short color)
{
	int ymin = cy - r;
	int ymax = cy +r;
	
	for(int y=ymin;y<=ymax;y++)
	{
		int dy = abs(y-cy);
		int dx = sqrt(r*r - dy*dy);
		
		draw_line(cx-dx,y,cx+dx,y,color);
	}
}
 
void draw_image(short img[],int x,int y,int width,int height)
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			int pos = i*width +j;
			write_pixel(x+j,y+i,img[pos]);
		}
	}
}
 
void draw_image_scale(short img[],int x,int y,int width,int height,int sx,int sy)
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			int pos = i*width +j;
			draw_rect(x+j*sx,y+i*sy,sx,sy,img[pos]);
		}
	}
}
 
short vc[] = {0xF800,0x07E0,0x001F,0xFFFF,0xFFE0,0xF81F,0x07FF};
int vx[] = {0,50,75,200,310,50,283};
int vy[] = {43,195,121,85,190,51,5};
int SIZE =7;
float dist(float x1,float y1,float x2,float y2)
{
	return sqrt((float)(x1-x2)*(x1-x2) + (float)(y1-y2)*(y1-y2));
}
 
void voronoi(int s)
{
	int x,y;
	for(x=0;x<320;x+=s)
	{
		for(y=0;y<240;y+=s)
		{
			float mx = x+(float)s/2;
			float my = y + (float)s/2;
			float d = dist(mx,my,vx[0],vy[0]);
			int index =0;
			for(int i=1;i<SIZE;i++)
			{
				float d2 =dist(x,y,vx[i],vy[i]);
				if(d>d2)
				{
					index = i;
					d =d2; 
				}
			}
			draw_rect(x,y,s,s,vc[index]);
		}
	}
}
 
 
int main()
{
	clear(0);
	voronoi(1);
	
	return 0;
	
	
}

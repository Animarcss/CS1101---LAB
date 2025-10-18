/* set a single pixel on the screen at x,y
 * x in [0,319], y in [0,239], and colour in [0,65535]  */

#define WHITE 0XFFFF
#define YELLOW 0XFFE0
#define RED 0XF800
#define GREEN 0X0FE0
#define BLUE 0X001F
#define CYAN 0X07FF
#define MAGENTA 0XF81F
#define GREY 0XC618
#define PINK 0XFC18
#define ORANGE 0XFC00

void write_pixel(int x, int y, short colour) {
  volatile short *vga_addr=(volatile short*)(0x08000000 + (y<<10) + (x<<1));
  *vga_addr=colour;
}
 
/* use write_pixel to set entire screen to black (does not clear the character buffer) */
void clear_screen() {
  int x, y;
  for (x = 0; x < 320; x++) {
    for (y = 0; y < 240; y++) {
	  write_pixel(x,y,0x0000);
	}
  }
}
/* use write_pixel to set entire screen to a custom colour */
void setColor(short colour) {
  int x, y;
  for (x = 0; x < 320; x++) {
    for (y = 0; y < 240; y++) {
	  write_pixel(x,y,colour);
	}
  }
}
/* write a single character to the character buffer at x,y
 * x in [0,79], y in [0,59]
 */
void write_char(int x, int y, char c) {
  // VGA character buffer
  volatile char * character_buffer = (char *) (0x09000000 + (y<<7) + x);
  *character_buffer = c;
}
 
int main () {
 
   clear_screen();
	setColor(WHITE);
	setColor(YELLOW);
	setColor(RED);
   return 0;
}

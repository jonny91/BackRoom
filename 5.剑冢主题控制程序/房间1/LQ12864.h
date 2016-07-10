#ifndef _LQOLED_H
#define _LQOLED_H

#include"STC12C5A60S2.h"
#include "intrins.h" 
 	#define byte  unsigned char
	#define word  unsigned int
	#define dword unsigned long  
extern void LCD_Init(void);
extern void LCD_CLS(void);
extern void LCD_P6x8Str(byte x,byte y,byte ch[]);
extern void LCD_P8x16Str(byte x,byte y,byte ch[]);
extern void LCD_P14x16Ch(byte x,byte y,byte N);  	  
extern void LCD_Fill(byte dat);
extern void LCD_Print(byte x, byte y, byte ch[]);
extern void LCD_P14x16Str(byte x,byte y,byte ch[]);
extern void Draw_BMP(byte x0,byte y0,byte x1,byte y1,byte bmp[]);
extern void Draw_LQLogo(void);
extern void display_BMP(void);
extern void display_heart(void);
extern void display_jiao(void);
extern void display_tem(void);


#endif


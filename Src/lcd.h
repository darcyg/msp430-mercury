#ifndef _LCD_H
#define _LCD_H

#include "type.h"

/************************************************************
		LCD部分
*************************************************************/
#define LCD_LIGHT_ON    P9OUT&=~BIT2
#define LCD_LIGHT_OFF   P9OUT|=BIT2

#define LCD_WIDTH      30       //显示区宽度
#define LCD_TXT_ADDR   0x0000   //文本显示区首地址
#define LCD_IMG_ADDR   0x01e0   //图形显示区首地址

extern const unsigned char zimo240128[30*64];

void LCD_Init(void);
void Clr_LCDRam(void);
void Clr_RamBlock(INT8U X0,INT8U Y0,INT8U nbyte);
void Disp_Img(INT16U addr,INT8U xl,INT8U yl,const INT8U *img);
void Disp_Chn1616_Char(INT8U X0,INT8U Y0,INT8U Index,INT8U PoN);
void Disp_Chn1616_Str(INT8U X0,INT8U Y0,const INT8U *Index,INT8U PoN);
void Disp_Chn816_Char(INT8U X0,INT8U Y0,INT8U Index,INT8U PoN);
void Disp_Chn816_Str(INT8U X0,INT8U Y0,const INT8U *Index,INT8U PoN);
void Disp_Yline(INT8U X0,INT8U Y0);
void Disp_Xline(INT8U Y0);
/* 画水平线段 */
void Disp_Xline_Seg(INT8U X0, INT8U Y0, INT8U Len);

/************************************************************
		键盘部分
*************************************************************/
#define KEY_NONE	0
#define KEY_UP		1
#define KEY_DOWN	2
#define KEY_LEFT	3
#define KEY_RIGHT	4
#define KEY_ENTER 	5
#define KEY_CANCEL	6
#define KEY_RESET   7
#define LCD_RESET   8
#define BACK_DOOR0  9
#define BACK_DOOR1  10

#define KEYREAD() 		P8IN | 0XC0
#define KEY_UP_MASK		0xFD
#define KEY_DOWN_MASK	0xfb
#define KEY_LEFT_MASK	0xf7
#define KEY_RIGHT_MASK	0xEF
#define KEY_ENTER_MASK 	0xDF
#define KEY_CANCEL_MASK	0xFE
#define KEY_RESET_MASK  KEY_CANCEL_MASK & KEY_DOWN_MASK & KEY_LEFT_MASK & KEY_ENTER_MASK//0xE8
#define LCD_RESET_MASK  KEY_ENTER_MASK & KEY_CANCEL_MASK     //0xEE
#define BACK_DOOR0_MASK KEY_LEFT_MASK & KEY_RIGHT_MASK       //0xDD
#define BACK_DOOR1_MASK KEY_LEFT_MASK & KEY_RIGHT_MASK & KEY_CANCEL_MASK   //0xCD

INT8U Get_KeyVal(void);

#endif  //end of _LCD_H

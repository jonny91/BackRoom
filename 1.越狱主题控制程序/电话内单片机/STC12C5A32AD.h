#ifndef __STC12C5A32AD_H__
#define __STC12C5A32AD_H__

/*  BYTE Register  */
sfr CLK_DIV   = 0x97;	     //时钟分频寄存器
sfr AUXR      = 0X8E;		 //备用寄存器，可控制定时器速度等
sfr WAKE_CLKO = 0X8f;		 //时钟输出、掉电唤醒控制寄存器
sfr BUS_SPEED =	0XA1;        //控制外部数据总线速度
sfr IE2       =	0XAF;        //SPI/串口中断控制
sfr IPH       = 0XB7;		 //中断优先级控制寄存器高
sfr IP2H      = 0XB6;		
sfr IP2       = 0XB5;		 //IP2和IP2H共同控制SPI中断的优先级

/*PCA相关寄存器*/

/*CCON */
sfr CCON      = 0XD8;
sbit CCF0     = CCON^0;
sbit CCF1     = CCON^1;
sbit CR       = CCON^6;
sbit CF       = CCON^7;

sfr CMOD      = 0XD9;
sfr CCAPM0    = 0XDA;
sfr CCAPM1    = 0XDB;
sfr CL        = 0XE9;
sfr CH        = 0XF9;
sfr CCAP0L    = 0XEA;
sfr CCAP0H    = 0XFA;
sfr CCAP1L    = 0XEB;
sfr CCAP1H    = 0XFB;
sfr PCA_PWM0  = 0XF2;
sfr PCA_PWM2  = 0XF3;
sfr AUXR1     = 0XA2;

/*  AD相关寄存器     */
sfr P1ASF     = 0X9D;
sfr ADC_CONTR = 0XBC;
sfr ADC_RES   = 0XBD;
sfr ADC_RESL  = 0XBE;

/*  IAP相关寄存器    */
sfr IAP_DATA  =0XC2;
sfr IAP_ADDRH =0XC3;
sfr IAP_ADDRL =0XC4;
sfr IAP_CMD   =0XC5;
sfr IAP_TRIG  =0XC6;
sfr IAP_CONTR =0XC7;

/*  P4口相关寄存器   */
sfr P4        =0XC0;
sfr P4SW      =0XBB;
sfr P4M1      =0XB3;
sfr P4M0      =0XB4;

/*  P3口相关寄存器   */
sfr P3M1      =0XB1;
sfr P3M0      =0XB2;

/*  P2口相关寄存器   */
sfr P2M1      =0X95;
sfr P2M0      =0X96;

/*  P1口相关寄存器   */
sfr P1M1      =0X91;
sfr P1M0      =0X92;

/*  P0口相关寄存器   */
sfr P0M1      =0X93;
sfr P0M0      =0X94;

/*  SPI相关寄存器    */
sfr SPCTL     = 0XCE;
sfr SPSTAT    = 0XCD;
sfr SPDAT     = 0XCF;


/*  BIT Register  */
/*  IE   */
sbit ELVD = IE^6;
sbit EADC = IE^5;
/*  IP   */ 
sbit PADC = 0xBD;
sbit PLVD = 0xBE;
sbit PPCA = 0xBF;
#endif
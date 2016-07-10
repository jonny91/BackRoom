#ifndef __STC12C5A32AD_H__
#define __STC12C5A32AD_H__

/*  BYTE Register  */
sfr CLK_DIV   = 0x97;	     //ʱ�ӷ�Ƶ�Ĵ���
sfr AUXR      = 0X8E;		 //���üĴ������ɿ��ƶ�ʱ���ٶȵ�
sfr WAKE_CLKO = 0X8f;		 //ʱ����������绽�ѿ��ƼĴ���
sfr BUS_SPEED =	0XA1;        //�����ⲿ���������ٶ�
sfr IE2       =	0XAF;        //SPI/�����жϿ���
sfr IPH       = 0XB7;		 //�ж����ȼ����ƼĴ�����
sfr IP2H      = 0XB6;		
sfr IP2       = 0XB5;		 //IP2��IP2H��ͬ����SPI�жϵ����ȼ�

/*PCA��ؼĴ���*/

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

/*  AD��ؼĴ���     */
sfr P1ASF     = 0X9D;
sfr ADC_CONTR = 0XBC;
sfr ADC_RES   = 0XBD;
sfr ADC_RESL  = 0XBE;

/*  IAP��ؼĴ���    */
sfr IAP_DATA  =0XC2;
sfr IAP_ADDRH =0XC3;
sfr IAP_ADDRL =0XC4;
sfr IAP_CMD   =0XC5;
sfr IAP_TRIG  =0XC6;
sfr IAP_CONTR =0XC7;

/*  P4����ؼĴ���   */
sfr P4        =0XC0;
sfr P4SW      =0XBB;
sfr P4M1      =0XB3;
sfr P4M0      =0XB4;

/*  P3����ؼĴ���   */
sfr P3M1      =0XB1;
sfr P3M0      =0XB2;

/*  P2����ؼĴ���   */
sfr P2M1      =0X95;
sfr P2M0      =0X96;

/*  P1����ؼĴ���   */
sfr P1M1      =0X91;
sfr P1M0      =0X92;

/*  P0����ؼĴ���   */
sfr P0M1      =0X93;
sfr P0M0      =0X94;

/*  SPI��ؼĴ���    */
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
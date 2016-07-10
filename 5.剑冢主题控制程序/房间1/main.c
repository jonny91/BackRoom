
#include "STC12C5A60S2.h"
#include "intrins.h" 
#include "stdio.h"
#include"uart.h"

#define uchar unsigned char
#define uint unsigned int

sbit OUT1   =  P4^2;		//输出IO口1，    触摸灯带1
sbit OUT2   =  P1^0;	    //输出2，        触摸灯带2
sbit OUT3   =  P1^1;		//输出3，        触摸灯带3
sbit OUT4   =  P1^2;        //输出4，        触摸灯带4
sbit OUT5   =  P1^3;	    //输出5，        角落上部分灯带
sbit OUT6   =  P1^4;		//输出6，        大圆盘灯箱片
sbit OUT7   =  P1^5;		//输出7，        柜子电缸
sbit OUT8   =  P1^6;		//输出8，         电机1+
sbit OUT9   =  P1^7;		//输出9，         电机1-
sbit OUT10  =  P4^3;		//输出10，       移动电缸门

sbit M10     =  P3^2;		 //电缸1+		 电缸2+
sbit M11     =  P3^3;		 //电缸1-		  NC
sbit M20     =  P3^4;		 //电缸2+		 电缸2-
sbit M21     =  P3^5;		 //电缸2-		  NC
sbit M30     =  P3^6;		 //电缸3+
sbit M31     =  P3^7;		 //电缸3-

sbit OUT21   =  P4^0;		//输出IO控制口21
sbit OUT22   =  P2^0;	    //输出22
sbit OUT23   =  P2^1;		//输出23
sbit OUT24   =  P2^2;       //输出24
sbit OUT25   =  P2^3;	    //输出25
sbit OUT26   =  P2^4;		//输出26
sbit OUT27   =  P2^5;		//输出27
sbit OUT28   =  P2^6;		//输出26
sbit OUT29   =  P2^7;		//输出27


sbit INPUT16   =  P4^4;		//输入IO控制口16，    
sbit INPUT15   =  P4^5;	    //输入15，                  触摸开关2
sbit INPUT14   =  P4^1;		//输入14					触摸开关3
sbit INPUT13   =  P4^6;     //输入13			 		触摸开关4
sbit INPUT12   =  P0^7;	    //输入12			 		大圆盘触摸开关5
sbit INPUT11   =  P0^6;		//输入11，按键类型	 		四圣兽触摸开关1

sbit INPUT10   =  P0^5;		//输入10，门禁类型	 	   霍尔开关1
sbit INPUT9    =  P0^4;		//输入9，门禁			   霍尔开关2
sbit INPUT8    =  P0^3;		//输入8，门禁		 	   霍尔开关3
sbit INPUT7    =  P0^2;		//输入7，门禁		 	   霍尔开关4
sbit INPUT6    =  P0^1;	 	//输入6，门禁		 
sbit INPUT5    =  P0^0;	    //输入5，门禁类型	 

sbit RXD   =  P3^0;	    
sbit TXD   =  P3^1;

#define uchar unsigned char
#define uint unsigned int

sfr P4sw=0xbb;

void sys_init(void);
void delay_ms(int count);
void mp3_init();
void mp3(unsigned char comd);

unsigned char Game_Start=0,door1=0,door2=0,door3=0;
unsigned char flag_step1=0,flag_step2=0,flag_step3=0,flag_step4=0,flag_step5=0,flag_step6=0;



/************************************************************************
    函数名称：   void main(void)		
    函数功能：   
    调用函数：  void delay(unsigned int loop_time)	
*************************************************************************/
void main()
{
	sys_init();	        

	 delay_ms(2000);
	  mp3(0x33);	  //音效8
	  mp3(0x01);
	 delay_ms(500);
	while(1)
	  {					
			 
			 if((INPUT12==1)&&(flag_step1==0))			// 中间的触摸开关
			 {
			   delay_ms(50);
			   if(INPUT12==1)
			   {
			   	   mp3(0x33);	  //音效2
				   mp3(0x02); 
				   delay_ms(3000);
				   OUT6=1;        //大圆盘灯箱片
				   flag_step1=1;  
				   delay_ms(3000);
				   mp3(0x33);	  //音效1
				   mp3(0x01);
			   }
			 }			 
			
			if((INPUT10==0)&&(flag_step2==0)&&(flag_step1==1))		 //霍尔开关1
			{
			  delay_ms(50);
			  if(INPUT10==0)
			  {
			  	   mp3(0x33);	  //音效3
				   mp3(0x03);
				   OUT1=1;
				   flag_step2=1;
				   
				   delay_ms(3000);
				   mp3(0x33);	  //音效1
				   mp3(0x09);
				   
			  }
	
			}
			
			if((INPUT9==0)&&(flag_step3==0)&&(flag_step1==1))		 //霍尔开关2
			{
			  delay_ms(50);
			  if(INPUT9==0)
			  {
			  	   mp3(0x33);	  //音效4
				   mp3(0x04);
				   OUT2=1;
				   flag_step3=1;
				   delay_ms(3000);
				   mp3(0x33);	  //音效1
				   mp3(0x09);

			  }
	
			}
			if((INPUT8==0)&&(flag_step4==0)&&(flag_step1==1))		 //霍尔开关3
			{
			  delay_ms(50);
			  if(INPUT8==0)
			  {
			  	   mp3(0x33);	  //音效5
				   mp3(0x05);
				   OUT3=1;
				   flag_step4=1;
				   delay_ms(3000);
				   mp3(0x33);	  //音效1
				   mp3(0x09);
			  }
	
			}
			if((INPUT7==0)&&(flag_step5==0)&&(flag_step1==1))		 //霍尔开关4
			{
			  delay_ms(50);
			  if(INPUT7==0)
			  {
			  	   mp3(0x33);	  //音效6
				   mp3(0x06);
				   OUT4=1;
				   flag_step5=1;
				   delay_ms(3000);
				   mp3(0x33);	  //音效1
				   mp3(0x09);
			  }
	
			}
			if((flag_step2==1)&&(flag_step3==1)&&(flag_step4==1)&&(flag_step5==1)&&(flag_step6==0))
			{
				   flag_step1=2;
				   flag_step6=1;
				  delay_ms(3000);
				   mp3(0x33);	  //音效7
				   mp3(0x07);
				    OUT6=0;  
				   delay_ms(5000);
				   OUT7=1;		//柜子电缸升起

				   delay_ms(5000); 				   
				   mp3(0x33);	  //音效8
				   mp3(0x08);
				   OUT10=1;
			}	 
			
			 	
	  }                											  
}
																					    
void sys_init()
{
	P0M1=0X00;
	P0M0=0Xff;      //设置P0为推挽输出
	
	P1M1=0X00;
	P1M0=0XFF;	    //设置P1为推挽输出
	
	P2M1=0X00;
	P2M0=0XFF;		//设置P2口为推挽输出
	
	P3M1=0X00;
	P3M0=0XFC;	    //设置P3为推挽输出

	P4M1=0X00;
	P4M0=0XFF;      //设置P4为推挽输出
	
	P4sw = 0x70;	
	//
	OUT1=0;
	OUT2=0;
	OUT3=0;
	OUT4=0;
	OUT5=0;

	OUT6=0;		// 
	OUT7=0;		//	
	OUT8=0;		//  
	OUT9=0;		//	
	OUT10=0;	//	
	
	M10=0; 		//
	M11=0;
	M20=0; 		//
	M21=0;  
	
	INPUT16=1;  //触摸开关4个
	INPUT15=1; 	//
	INPUT14=1; 
	INPUT13=1; 
	INPUT12=1; //触摸开关 最开始的
	INPUT11=1;	 
	OUT29=1;
	OUT28=1;
	OUT27=1;
	OUT26=1;

	
	INPUT10=1;
	INPUT9=1;
	INPUT8=1;
	INPUT7=1;
	INPUT6=1;
	INPUT5=1;
	 	  
	uart_init();               //串口初始化 
	mp3_init();                //MP3初始化	*/

}



void delay_ms(int count)  // /* X1ms */
{
        int i,j;
        for(i=0;i<count;i++)
                for(j=0;j<1000;j++);
} 



/*********************************************************/
/*                                                       */
/* MP3操作指令                                           */
/*                                                       */
/*********************************************************/
void mp3(unsigned char comd)
{
  switch(comd)
	  {
	    
	    case 0X01: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x01);//播放第1个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X02: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x02);//播放第2个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
	    case 0X03: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x03);//播放第3个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X04: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x04);//播放第4个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X05: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x05);//播放第5个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
	    case 0X06: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x06);//播放第6个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X07: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x07);//播放第7个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X08: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x08);//播放第8个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
	    case 0X09: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x09);//播放第9个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X0A: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x0A);//播放第10个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X0B: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x0B);//播放第11个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
	    case 0X0C: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x0C);//播放第12个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X0D: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x0D);//播放第13个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X0E: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x0E);//播放第14个音频文件
				   send(0XEF);//指令结束位 
		   	       break;
	    case 0X0F: send(0X7E);//指令开始位
				   send(0X04);//说明指令长度
				   send(0X42);//指定文件夹播放
				   send(0X01);//定位到名称为“01”的文件夹
				   send(0x0F);//播放第15个音频文件
				   send(0XEF);//指令结束位 
		   	       break;

		case 0X31: send(0X7E);//指令开始位
				   send(0X03);//说明指令长度
				   send(0X31);//设置音量
				   send(0X20);//20
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X32: send(0X7E);//指令开始位
				   send(0X03);//说明指令长度
				   send(0X31);//设置音量
				   send(0X10);//20
				   send(0XEF);//指令结束位 
		   	       break;

		case 0X33: send(0X7E);//指令开始位
				   send(0X03);//说明指令长度
				   send(0X33);//设置循环模式
				   send(0X04);//单曲播放
				   send(0XEF);//指令结束位 
		   	       break;
		
		case 0X34: send(0X7E);//指令开始位
				   send(0X03);//说明指令长度
				   send(0X33);//设置循环模式
				   send(0X02);//单曲循环！
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X35: send(0X7E);//指令开始位
				   send(0X03);//说明指令长度
				   send(0X31);//设置音量
				   send(0X07);//20
				   send(0XEF);//指令结束位 
		   	       break;
		case 0X36: send(0X7E);//指令开始位
				   send(0X03);//说明指令长度
				   send(0X31);//设置音量
				   send(0X10);//20
				   send(0XEF);//指令结束位 
		   	       break;
	  }
  
}
/*********************************************************/
/*                                                       */
/* MP3初始化                                             */
/*                                                       */
/*********************************************************/
void mp3_init()
{
  mp3(0x33);                 //设置循环模式为文件夹循环
  mp3(0x31);                 //设置音量为20
  //mp3(0x00);                 //开机播放

  /*不关闭串行中断的话一上电就会发送STOP，这样会影响曲名和播放歌曲的对应关系*/
  ES=0;					   //串行中断禁止
  delay_ms(100);			   //等待MP3准备好
  ES=1;
}


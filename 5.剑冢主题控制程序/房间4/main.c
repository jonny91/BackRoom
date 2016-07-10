
#include "STC12C5A60S2.h"
#include "intrins.h" 
#include "stdio.h"
#include"uart.h"

#define uchar unsigned char
#define uint unsigned int

sbit OUT1   =  P4^2;		//输出IO口1，    激光1
sbit OUT2   =  P1^0;	    //输出2，        激光2
sbit OUT3   =  P1^1;		//输出3，        激光3
sbit OUT4   =  P1^2;        //输出4，        激光4
sbit OUT5   =  P1^3;	    //输出5，        激光5
sbit OUT6   =  P1^4;		//输出6，        激光6
sbit OUT7   =  P1^5;		//输出7，        激光7
sbit OUT8   =  P1^6;		//输出8，        R4电磁锁 最终逃生门
sbit OUT9   =  P1^7;		//输出9，        
sbit OUT10  =  P4^3;		//输出10，       



sbit M10     =  P3^2;		 //电缸1+		      
sbit M11     =  P3^3;		 //电缸1-
sbit M20     =  P3^4;		 //电缸2+
sbit M21     =  P3^5;		 //电缸2-
sbit M30     =  P3^6;		 //电缸3+
sbit M31     =  P3^7;		 //电缸3-

sbit OUT21   =  P4^0;		//输出IO控制口21   激光接收部分灯带1
sbit OUT22   =  P2^0;	    //输出22		   灯带2
sbit OUT23   =  P2^1;		//输出23		   灯带3
sbit OUT24   =  P2^2;       //输出24		   灯带4
sbit OUT25   =  P2^3;	    //输出25		   灯带5
sbit OUT26   =  P2^4;		//输出26		   灯带6
sbit OUT27   =  P2^5;		//输出27

sbit OUT28   =  P2^6;	    //				   第七把剑
sbit OUT29   =  P2^7;		//				   金属接近7

sbit INPUT16   =  P4^4;		//输入IO控制口16，  激光接收1
sbit INPUT15   =  P4^5;	    //输入15，          激光接收2 
sbit INPUT14   =  P4^1;		//输入14			激光接收3
sbit INPUT13   =  P4^6;     //输入13			激光接收4 
sbit INPUT12   =  P0^7;	    //输入12			激光接收5 
sbit INPUT11   =  P0^6;		//输入11，按键类型	激光接收6 

sbit INPUT10   =  P0^5;		//输入10，门禁类型	 金属接近1
sbit INPUT9    =  P0^4;		//输入9，门禁		 金属接近2
sbit INPUT8    =  P0^3;		//输入8，门禁		 金属接近3
sbit INPUT7    =  P0^2;		//输入7，门禁		 金属接近4
sbit INPUT6    =  P0^1;	 	//输入6，门禁		 金属接近5
sbit INPUT5    =  P0^0;	    //输入5，门禁类型	 金属接近6

sbit RXD   =  P3^0;	    
sbit TXD   =  P3^1;

#define uchar unsigned char
#define uint unsigned int

sfr P4sw=0xbb;

void sys_init(void);
void delay_ms(int count);
void mp3_init();
void mp3(unsigned char comd);

unsigned char Game_Start=0,laser1=0,laser2=0,laser3=0,laser4=0,laser5=0,laser6=0,i1=0,i2=0,i3=0,i4=0,k=0,count=0,count_step1=0,count_step2=0,count_step3=0;
unsigned char flag_step1=0,flag_step2=0,flag_step3=0,flag_step4=0,flag_step5=0,flag_step6=0,flag_step7=0,flag_step8=0,flag_step9=0,flag_step10=0,flag_step11=0;



/************************************************************************
    函数名称：   void main(void)		
    函数功能：   
    调用函数：  void delay(unsigned int loop_time)	
*************************************************************************/
void main()
{
	sys_init();	        
	P4sw = 0x70;

	while(1)
	  {					
			 if((INPUT10==0)&&(flag_step2==0))
			 {
			 	delay_ms(100);
				mp3(0x33);
				mp3(0x01);
			    delay_ms(500);
				flag_step2=1;
			 }
			 if((INPUT9==0)&&(flag_step3==0))
			 {
			 	delay_ms(100);
				mp3(0x33);
				mp3(0x02);
				delay_ms(500);
				flag_step3=1;
			 }
			 if((INPUT8==0)&&(flag_step4==0))
			 {
			 	delay_ms(100);
				mp3(0x33);
				mp3(0x03);
				delay_ms(500);
				flag_step4=1;
			 }
			 if((INPUT7==0)&&(flag_step5==0))
			 {
			 	delay_ms(100);
				mp3(0x33);
				mp3(0x04);
				delay_ms(500);
				flag_step5=1;
			 }
			 if((INPUT6==0)&&(flag_step6==0))
			 {
			 	delay_ms(100);
				mp3(0x33);
				mp3(0x05);
				delay_ms(500);
				flag_step6=1;
			 }
			 if((INPUT5==0)&&(flag_step7==0))
			 {
			 	delay_ms(100);
				mp3(0x33);
				mp3(0x06);
				delay_ms(500);
				flag_step7=1;
			 }
			 if((OUT28==0)&&(flag_step8==0))
			 {
			 	delay_ms(100);
				mp3(0x33);
				mp3(0x07);
				delay_ms(500);
				flag_step8=1;
			 }

			 if((flag_step2 == 1) && (flag_step3 == 1) && (flag_step4 == 1) && (flag_step5 == 1)&& (flag_step6 == 1) && (flag_step7 == 1) && (flag_step8 == 1) &&(flag_step1==0))
		//	 if((INPUT10==0)&&(INPUT9==0)&&(INPUT8==0)&&(INPUT7==0)&&(INPUT6==0)&&(INPUT5==0)&&(flag_step1==0))	  //全部的剑插入剑槽中
			 {
				mp3(0x33);
				mp3(0x08);			   //剑阵启动
			
				OUT1=1;
				delay_ms(500);
				OUT2=1;
				delay_ms(500);
				OUT3=1;
				delay_ms(500);
				OUT4=1;
				delay_ms(500);
				OUT5=1;
				delay_ms(500);
				OUT6=1;
				delay_ms(500);
				OUT7=1;

				flag_step1=1;		
				delay_ms(5000);
				OUT21=0;			   //打开六芒星灯带
				OUT22=0;
				OUT23=0;
				OUT24=0;
				OUT25=0;
				OUT26=0;
				OUT1=0;
				OUT2=0;
				OUT3=0;
				OUT4=0;
				OUT5=0;
				OUT6=0;
				OUT7=0;
				delay_ms(5000);	

			//	OUT21=1;
			//	OUT1=1;
			//	while(!INPUT16);
			//	OUT21=0;
		//		OUT1=0;
				OUT2=1;
				OUT3=1;
				OUT22=1;
				while(!INPUT15);
				OUT22=0;
						OUT2=0;
						OUT3=0;
						OUT4=1;
						OUT5=1;
				OUT23=1;
				while(!INPUT14);
				OUT23=0;
						OUT4=0;
						OUT5=0;
						OUT7=1;
						OUT2=1;
				OUT24=1;
				while(!INPUT13);
				OUT24=0;
						OUT7=0;
						OUT2=0;
						OUT6=1;
				OUT25=1;
				while(!INPUT12);
				OUT25=0;
					OUT6=0;
						OUT3=1;
						OUT5=1;
				OUT26=1;
				while(!INPUT11);
				OUT26=0;
					OUT3=0;
						OUT5=0;
					  		 
			 }
			
		   while((count_step1==0)&&(flag_step1==1))
		   {
			  if(flag_step11==0)
			  {

					OUT24=1;
					OUT2=1;
					OUT3=1;
					for(i1=0;i1<80;i1++)
					{
					  if(INPUT13==1)
					  {
					    delay_ms(50);
						if(INPUT13==1)
						{
						   count++;
						   OUT24=0;
						}
					  }
					  delay_ms(100);
					}
					OUT24=0;
					OUT2=0;
					OUT3=0;				
						delay_ms(500);

					OUT24=1;
					OUT26=1;
					OUT2=1;
					OUT3=1;
					OUT5=1;
					for(i1=0;i1<80;i1++)
					{
					  if(INPUT13==1)
					  {
					    delay_ms(50);
						if(INPUT13==1)
						{
						   count++;
						   OUT24=0;
						}
					  }
					  if(INPUT11==1)
					  {
					    delay_ms(50);
						if(INPUT11==1)
						{
						   count++;
						   OUT26=0;
						}
					  }
					  delay_ms(100);
					}
					OUT24=0;
					OUT26=0;
					OUT2=0;
					OUT3=0;
					OUT5=0;
					delay_ms(500);

					OUT22=1;
					OUT25=1;
					OUT1=1;
					OUT4=1;
					OUT7=1;
					for(i1=0;i1<80;i1++)
					{
					  if(INPUT15==1)
					  {
					    delay_ms(50);
						if(INPUT15==1)
						{
						   count++;
						   OUT22=0;
						}
					  }
					  if(INPUT12==1)
					  {
					    delay_ms(50);
						if(INPUT12==1)
						{
						   count++;
						   OUT25=0;
						}
					  }
					  delay_ms(100);
					}
					OUT22=0;
					OUT25=0;
					OUT1=0;
					OUT4=0;
					OUT7=0;
					delay_ms(500);
					OUT23=1;
					OUT24=1;
					OUT25=1;
					OUT1=1;
					OUT2=1;
					OUT4=1;
					OUT6=1;

					for(i1=0;i1<120;i1++)
					{
					  if(INPUT14==1)
					  {
					    delay_ms(50);
						if(INPUT14==1)
						{
						   count++;
						   OUT23=0;
						}
					  }
					  if(INPUT13==1)
					  {
					    delay_ms(50);
						if(INPUT13==1)
						{
						   count++;
						   OUT24=0;
						}
					  }
					  if(INPUT12==1)
					  {
					    delay_ms(50);
						if(INPUT12==1)
						{
						   count++;
						   OUT25=0;
						}
					  }
					  delay_ms(100);
					}
					OUT23=0;
					OUT24=0;
					OUT25=0;
					OUT1=0;
					OUT2=0;
					OUT4=0;
					OUT6=0;
					delay_ms(500);
					OUT22=1;
					OUT23=1;
					OUT26=1;
					OUT2=1;
					OUT4=1;
					OUT5=1;
					OUT7=1;
					for(i1=0;i1<120;i1++)
					{
					  if(INPUT15==1)
					  {
					    delay_ms(50);
						if(INPUT15==1)
						{
						   count++;
						   OUT22=0;
						}
					  }
					  if(INPUT14==1)
					  {
					    delay_ms(50);
						if(INPUT14==1)
						{
						   count++;
						   OUT23=0;
						}
					  }
					  if(INPUT11==1)
					  {
					    delay_ms(50);
						if(INPUT11==1)
						{
						   count++;
						   OUT26=0;
						}
					  }
					  delay_ms(100);
					}

				    OUT22=0;
					OUT23=0;
					OUT26=0;
					OUT2=0;
					OUT4=0;
					OUT5=0;
					OUT7=0;

					OUT22=1;
					OUT24=1;
					OUT25=1;
					OUT1=1;
					OUT2=1;
					OUT3=1;
					OUT6=1;
					OUT7=1;
					for(i1=0;i1<150;i1++)
					{
					  if(INPUT16==1)
					  {
					    delay_ms(50);
						if(INPUT16==1)
						{
						   count++;
						   OUT21=0;
						}
					  }
					  if(INPUT15==1)
					  {
					    delay_ms(50);
						if(INPUT15==1)
						{
						   count++;
						   OUT22=0;
						}
					  }
					  if(INPUT13==1)
					  {
					    delay_ms(50);
						if(INPUT13==1)
						{
						   count++;
						   OUT24=0;
						}
					  }
					  if(INPUT12==1)
					  {
					    delay_ms(50);
						if(INPUT12==1)
						{
						   count++;
						   OUT25=0;
						}
					  }
					  delay_ms(100);
					}

				    OUT21=0;
					OUT22=0;
					OUT24=0;
					OUT25=0;
					OUT1=0;
					OUT2=0;
					OUT3=0;
					OUT6=0;
					OUT7=0;
					delay_ms(500);
					OUT21=1;
					OUT22=1;
					OUT23=1;
					OUT24=1;
					OUT25=1;
					OUT26=1;
					OUT1=1;
					OUT2=1;
					OUT3=1;
					OUT4=1;
					OUT5=1;
					OUT6=1;
					OUT7=1;
					for(i1=0;i1<150;i1++)
					{
					  if(INPUT16==1)
					  {
					    delay_ms(50);
						if(INPUT16==1)
						{
						   count++;
						   OUT21=0;
						}
					  }
					  if(INPUT15==1)
					  {
					    delay_ms(50);
						if(INPUT15==1)
						{
						   count++;
						   OUT22=0;
						}
					  }
					   if(INPUT14==1)
					  {
					    delay_ms(50);
						if(INPUT14==1)
						{
						   count++;
						   OUT23=0;
						}
					  }
					  if(INPUT13==1)
					  {
					    delay_ms(50);
						if(INPUT13==1)
						{
						   count++;
						   OUT24=0;
						}
					  }
					  if(INPUT12==1)
					  {
					    delay_ms(50);
						if(INPUT12==1)
						{
						   count++;
						   OUT25=0;
						}
					  }
					   if(INPUT11==1)
					  {
					    delay_ms(50);
						if(INPUT11==1)
						{
						   count++;
						   OUT26=0;
						}
					  }
					  delay_ms(100);
					}

				    OUT21=0;
					OUT22=0;
					OUT23=0;
					OUT24=0;
					OUT25=0;
					OUT26=0;
					OUT1=0;
					OUT2=0;
					OUT3=0;
					OUT4=0;
					OUT5=0;
					OUT6=0;
					OUT7=0;

					flag_step11=1;
			  }
			      if(count>=10)
					{
						        delay_ms(500);
								OUT21=1;			   //打开六芒星灯带
								OUT22=1;
								OUT23=1;
								OUT24=1;
								OUT25=1;
								OUT26=1;
							   delay_ms(500);
							    OUT21=0;			   //关闭六芒星灯带
								OUT22=0;
								OUT23=0;
								OUT24=0;
								OUT25=0;
								OUT26=0;
								delay_ms(500);
								OUT21=1;			   //打开六芒星灯带
								OUT22=1;
								OUT23=1;
								OUT24=1;
								OUT25=1;
								OUT26=1;
							   delay_ms(500);
							    OUT21=0;			   //关闭六芒星灯带
								OUT22=0;
								OUT23=0;
								OUT24=0;
								OUT25=0;
								OUT26=0;
						   mp3(0x33);
				           mp3(0x0a);
						   	delay_ms(8000);
						   	OUT21=1;			   //打开六芒星灯带
							OUT22=1;
							OUT23=1;
							OUT24=1;
							OUT25=1;
							OUT26=1;
							OUT1=1;
							OUT2=1;
							OUT3=1;
							OUT4=1;
							OUT5=1;
							OUT6=1;
							OUT7=1;
						   delay_ms(8000);
						   delay_ms(8000);
						   delay_ms(8000);
						   delay_ms(8000);
						   delay_ms(8000);
						   delay_ms(8000);
						   OUT8=0;				  //开最终门
						   while(1);
					}
					else
					{
						      mp3(0x33);
				              mp3(0x09);
							flag_step11=0;
							count=0;

							OUT21=0;			   //打开六芒星灯带
							OUT22=0;
							OUT23=0;
							OUT24=0;
							OUT25=0;
							OUT26=0;
							OUT1=0;
							OUT2=0;
							OUT3=0;
							OUT4=0;
							OUT5=0;
							OUT6=0;
							OUT7=0;
							delay_ms(8000);
							delay_ms(8000);
					}	
			
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
	
		
	//R1-R5所有电磁锁吸合
	OUT1=0;
	OUT2=0;
	OUT3=0;
	OUT4=0;
	OUT5=0;
	OUT6=0;		//  
	OUT7=0;		//	

	OUT8=1;		//  最终逃生门

	OUT9=0;		//	
	OUT10=0;	//	

	

	INPUT16=1;  // 激光接收器 *6
	INPUT15=1; 	//
	INPUT14=1; 
	INPUT13=1; 
	INPUT11=1;	
	INPUT12=1;

	INPUT10=1;	//金属接近开关	*7
	INPUT9=1;
	INPUT8=1;
	INPUT7=1;
	INPUT6=1;
	INPUT5=1;
	OUT28=1;
	OUT29=1;

	OUT21=0;	//激光接收器的灯带
	OUT22=0;
	OUT23=0;
	OUT24=0;
	OUT25=0;
	OUT26=0;
	OUT27=0;
	 	  
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


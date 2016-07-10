
#include "STC12C5A60S2.h"
#include "intrins.h" 
#include "stdio.h"
#include"uart.h"

#define uchar unsigned char
#define uint unsigned int

sbit OUT1   =  P4^2;		//���IO��1��    �����ƴ�1
sbit OUT2   =  P1^0;	    //���2��        �����ƴ�2
sbit OUT3   =  P1^1;		//���3��        �����ƴ�3
sbit OUT4   =  P1^2;        //���4��        �����ƴ�4
sbit OUT5   =  P1^3;	    //���5��        �����ϲ��ֵƴ�
sbit OUT6   =  P1^4;		//���6��        ��Բ�̵���Ƭ
sbit OUT7   =  P1^5;		//���7��        ���ӵ��
sbit OUT8   =  P1^6;		//���8��         ���1+
sbit OUT9   =  P1^7;		//���9��         ���1-
sbit OUT10  =  P4^3;		//���10��       �ƶ������

sbit M10     =  P3^2;		 //���1+		 ���2+
sbit M11     =  P3^3;		 //���1-		  NC
sbit M20     =  P3^4;		 //���2+		 ���2-
sbit M21     =  P3^5;		 //���2-		  NC
sbit M30     =  P3^6;		 //���3+
sbit M31     =  P3^7;		 //���3-

sbit OUT21   =  P4^0;		//���IO���ƿ�21
sbit OUT22   =  P2^0;	    //���22
sbit OUT23   =  P2^1;		//���23
sbit OUT24   =  P2^2;       //���24
sbit OUT25   =  P2^3;	    //���25
sbit OUT26   =  P2^4;		//���26
sbit OUT27   =  P2^5;		//���27
sbit OUT28   =  P2^6;		//���26
sbit OUT29   =  P2^7;		//���27


sbit INPUT16   =  P4^4;		//����IO���ƿ�16��    
sbit INPUT15   =  P4^5;	    //����15��                  ��������2
sbit INPUT14   =  P4^1;		//����14					��������3
sbit INPUT13   =  P4^6;     //����13			 		��������4
sbit INPUT12   =  P0^7;	    //����12			 		��Բ�̴�������5
sbit INPUT11   =  P0^6;		//����11����������	 		��ʥ�޴�������1

sbit INPUT10   =  P0^5;		//����10���Ž�����	 	   ��������1
sbit INPUT9    =  P0^4;		//����9���Ž�			   ��������2
sbit INPUT8    =  P0^3;		//����8���Ž�		 	   ��������3
sbit INPUT7    =  P0^2;		//����7���Ž�		 	   ��������4
sbit INPUT6    =  P0^1;	 	//����6���Ž�		 
sbit INPUT5    =  P0^0;	    //����5���Ž�����	 

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
    �������ƣ�   void main(void)		
    �������ܣ�   
    ���ú�����  void delay(unsigned int loop_time)	
*************************************************************************/
void main()
{
	sys_init();	        

	 delay_ms(2000);
	  mp3(0x33);	  //��Ч8
	  mp3(0x01);
	 delay_ms(500);
	while(1)
	  {					
			 
			 if((INPUT12==1)&&(flag_step1==0))			// �м�Ĵ�������
			 {
			   delay_ms(50);
			   if(INPUT12==1)
			   {
			   	   mp3(0x33);	  //��Ч2
				   mp3(0x02); 
				   delay_ms(3000);
				   OUT6=1;        //��Բ�̵���Ƭ
				   flag_step1=1;  
				   delay_ms(3000);
				   mp3(0x33);	  //��Ч1
				   mp3(0x01);
			   }
			 }			 
			
			if((INPUT10==0)&&(flag_step2==0)&&(flag_step1==1))		 //��������1
			{
			  delay_ms(50);
			  if(INPUT10==0)
			  {
			  	   mp3(0x33);	  //��Ч3
				   mp3(0x03);
				   OUT1=1;
				   flag_step2=1;
				   
				   delay_ms(3000);
				   mp3(0x33);	  //��Ч1
				   mp3(0x09);
				   
			  }
	
			}
			
			if((INPUT9==0)&&(flag_step3==0)&&(flag_step1==1))		 //��������2
			{
			  delay_ms(50);
			  if(INPUT9==0)
			  {
			  	   mp3(0x33);	  //��Ч4
				   mp3(0x04);
				   OUT2=1;
				   flag_step3=1;
				   delay_ms(3000);
				   mp3(0x33);	  //��Ч1
				   mp3(0x09);

			  }
	
			}
			if((INPUT8==0)&&(flag_step4==0)&&(flag_step1==1))		 //��������3
			{
			  delay_ms(50);
			  if(INPUT8==0)
			  {
			  	   mp3(0x33);	  //��Ч5
				   mp3(0x05);
				   OUT3=1;
				   flag_step4=1;
				   delay_ms(3000);
				   mp3(0x33);	  //��Ч1
				   mp3(0x09);
			  }
	
			}
			if((INPUT7==0)&&(flag_step5==0)&&(flag_step1==1))		 //��������4
			{
			  delay_ms(50);
			  if(INPUT7==0)
			  {
			  	   mp3(0x33);	  //��Ч6
				   mp3(0x06);
				   OUT4=1;
				   flag_step5=1;
				   delay_ms(3000);
				   mp3(0x33);	  //��Ч1
				   mp3(0x09);
			  }
	
			}
			if((flag_step2==1)&&(flag_step3==1)&&(flag_step4==1)&&(flag_step5==1)&&(flag_step6==0))
			{
				   flag_step1=2;
				   flag_step6=1;
				  delay_ms(3000);
				   mp3(0x33);	  //��Ч7
				   mp3(0x07);
				    OUT6=0;  
				   delay_ms(5000);
				   OUT7=1;		//���ӵ������

				   delay_ms(5000); 				   
				   mp3(0x33);	  //��Ч8
				   mp3(0x08);
				   OUT10=1;
			}	 
			
			 	
	  }                											  
}
																					    
void sys_init()
{
	P0M1=0X00;
	P0M0=0Xff;      //����P0Ϊ�������
	
	P1M1=0X00;
	P1M0=0XFF;	    //����P1Ϊ�������
	
	P2M1=0X00;
	P2M0=0XFF;		//����P2��Ϊ�������
	
	P3M1=0X00;
	P3M0=0XFC;	    //����P3Ϊ�������

	P4M1=0X00;
	P4M0=0XFF;      //����P4Ϊ�������
	
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
	
	INPUT16=1;  //��������4��
	INPUT15=1; 	//
	INPUT14=1; 
	INPUT13=1; 
	INPUT12=1; //�������� �ʼ��
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
	 	  
	uart_init();               //���ڳ�ʼ�� 
	mp3_init();                //MP3��ʼ��	*/

}



void delay_ms(int count)  // /* X1ms */
{
        int i,j;
        for(i=0;i<count;i++)
                for(j=0;j<1000;j++);
} 



/*********************************************************/
/*                                                       */
/* MP3����ָ��                                           */
/*                                                       */
/*********************************************************/
void mp3(unsigned char comd)
{
  switch(comd)
	  {
	    
	    case 0X01: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x01);//���ŵ�1����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X02: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x02);//���ŵ�2����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X03: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x03);//���ŵ�3����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X04: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x04);//���ŵ�4����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X05: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x05);//���ŵ�5����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X06: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x06);//���ŵ�6����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X07: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x07);//���ŵ�7����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X08: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x08);//���ŵ�8����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X09: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x09);//���ŵ�9����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X0A: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x0A);//���ŵ�10����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X0B: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x0B);//���ŵ�11����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X0C: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x0C);//���ŵ�12����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X0D: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x0D);//���ŵ�13����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X0E: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x0E);//���ŵ�14����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X0F: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x0F);//���ŵ�15����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;

		case 0X31: send(0X7E);//ָ�ʼλ
				   send(0X03);//˵��ָ���
				   send(0X31);//��������
				   send(0X20);//20
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X32: send(0X7E);//ָ�ʼλ
				   send(0X03);//˵��ָ���
				   send(0X31);//��������
				   send(0X10);//20
				   send(0XEF);//ָ�����λ 
		   	       break;

		case 0X33: send(0X7E);//ָ�ʼλ
				   send(0X03);//˵��ָ���
				   send(0X33);//����ѭ��ģʽ
				   send(0X04);//��������
				   send(0XEF);//ָ�����λ 
		   	       break;
		
		case 0X34: send(0X7E);//ָ�ʼλ
				   send(0X03);//˵��ָ���
				   send(0X33);//����ѭ��ģʽ
				   send(0X02);//����ѭ����
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X35: send(0X7E);//ָ�ʼλ
				   send(0X03);//˵��ָ���
				   send(0X31);//��������
				   send(0X07);//20
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X36: send(0X7E);//ָ�ʼλ
				   send(0X03);//˵��ָ���
				   send(0X31);//��������
				   send(0X10);//20
				   send(0XEF);//ָ�����λ 
		   	       break;
	  }
  
}
/*********************************************************/
/*                                                       */
/* MP3��ʼ��                                             */
/*                                                       */
/*********************************************************/
void mp3_init()
{
  mp3(0x33);                 //����ѭ��ģʽΪ�ļ���ѭ��
  mp3(0x31);                 //��������Ϊ20
  //mp3(0x00);                 //��������

  /*���رմ����жϵĻ�һ�ϵ�ͻᷢ��STOP��������Ӱ�������Ͳ��Ÿ����Ķ�Ӧ��ϵ*/
  ES=0;					   //�����жϽ�ֹ
  delay_ms(100);			   //�ȴ�MP3׼����
  ES=1;
}


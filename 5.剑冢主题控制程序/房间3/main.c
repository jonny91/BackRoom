
#include "STC12C5A60S2.h"
#include "intrins.h" 
#include "stdio.h"
#include"uart.h"

#define uchar unsigned char
#define uint unsigned int

sbit OUT1   =  P4^2;		//���IO��1��    ����5�����
sbit OUT2   =  P1^0;	    //���2��        ���еĵ��
sbit OUT3   =  P1^1;		//���3��        ����1�ĵƴ�
sbit OUT4   =  P1^2;        //���4��        ����2�ĵƴ�
sbit OUT5   =  P1^3;	    //���5��        R3��R4�ĵ����
sbit OUT6   =  P1^4;		//���6��        ���ϵ�С�����
sbit OUT7   =  P1^5;		//���7��        
sbit OUT8   =  P1^6;		//���8��       
sbit OUT9   =  P1^7;		//���9��        
sbit OUT10  =  P4^3;		//���10��       
sbit OUT11  =  P3^2;	    //���11��
sbit OUT12  =  P3^3;	    //���12��


sbit M10     =  P2^6;		 //���1+		 
sbit M11     =  P2^7;		 //���1-
sbit M20     =  P3^4;		 //���2+
sbit M21     =  P3^5;		 //���2-
sbit M30     =  P3^6;		 //���3+
sbit M31     =  P3^7;		 //���3-

sbit OUT21   =  P4^0;		//���IO���ƿ�21
sbit OUT22   =  P2^0;	    //���22
sbit OUT23   =  P2^1;		//���23
sbit OUT24   =  P2^2;       //���24
sbit OUT25   =  P2^3;	    //���25
sbit OUT26   =  P2^4;		//���26
sbit OUT27   =  P2^5;		//���27
//sbit OUT28   =  P2^6;	    ��׿��ƿڸ���
//sbit OUT29   =  P2^7;		��׿��ƿڸ���

sbit INPUT16   =  P4^4;		//����IO���ƿ�16��   ����5
sbit INPUT15   =  P4^5;	    //����15��           ���еĻ��أ��ݶ�����
sbit INPUT14   =  P4^1;		//����14			
sbit INPUT13   =  P4^6;     //����13			 
sbit INPUT12   =  P0^7;	    //����12			 
sbit INPUT11   =  P0^6;		//����11����������	 

sbit INPUT10   =  P0^5;		//����10���Ž�����	 ����1����
sbit INPUT9    =  P0^4;		//����9���Ž�		 ����2����
sbit INPUT8    =  P0^3;		//����8���Ž�		 ����1
sbit INPUT7    =  P0^2;		//����7���Ž�		 ����2
sbit INPUT6    =  P0^1;	 	//����6���Ž�		 ����3
sbit INPUT5    =  P0^0;	    //����5���Ž�����	 ����4

sbit RXD   =  P3^0;	    
sbit TXD   =  P3^1;

#define uchar unsigned char
#define uint unsigned int

sfr P4sw=0xbb;

void sys_init(void);
void delay_ms(int count);
void mp3_init();
void mp3(unsigned char comd);

unsigned char Game_Start=0,num1=0,num2=0,i=0,j=0;
unsigned char flag_step1=0,flag_step2=0,flag_step3=0,flag_step4=0,flag_step5=0,flag_step6=0,flag_step7=0,flag_step8=0,flag_step9=0,flag_step10=0;
unsigned int  flag_num1=1,flag_num2=1;


/************************************************************************
    �������ƣ�   void main(void)		
    �������ܣ�   
    ���ú�����  void delay(unsigned int loop_time)	
*************************************************************************/
void main()
{
	sys_init();	        
	P4sw = 0x70;
	mp3(0x33);
	mp3(0x01);
	delay_ms(500);
	mp3(0x33);
	mp3(0x01);
	delay_ms(500);
	mp3(0x33);
	mp3(0x01);
	delay_ms(500);

	while(1)
	  {					
		 
		 while(flag_step1==0)
		 {
				 if((INPUT10==0)&&(flag_step10==0))			   //����Ļ�������1
				  {
				  	 delay_ms(50);
					 if(INPUT10==0)
					 {
							while(!INPUT10);
								mp3(0x33);
	                            mp3(0x02);
						flag_num1+=1;
						if(flag_num1<=30)
						{						
							OUT3=1;
							delay_ms(150);
							OUT3=0;
						}
						else if(flag_num1>=31)
						{
							OUT3=1;
							num1=1;
								delay_ms(500);
								mp3(0x33);
                            	mp3(0x01); 
								delay_ms(500);
								flag_step10=1;
						}
					 } 
				  }
		
				 if((INPUT9==0)&&(flag_step9==0))			   //����Ļ�������2
				  {
				  	 delay_ms(50);
					 if(INPUT9==0)
					 {
						while(!INPUT9);
							mp3(0x33);
	                        mp3(0x02);
						flag_num2+=1;
						if(flag_num2<=30)
						{
							OUT4=1;
							  delay_ms(150); 
							OUT4=0;
						}
						else if(flag_num2>=31)
						{
							OUT4=1;			//�ƴ�2��
							num2=1;
							delay_ms(500);
								mp3(0x33);
                            	mp3(0x01);
								delay_ms(500);
							flag_step9=1;
						}
					 } 
				  }
				
				 if((num1==1)&&(num2==1))
				 {
				   flag_step1=1;
				   flag_step2=1;
				   OUT2=1;         //�򿪶��еĵ��
				   delay_ms(500);
				   mp3(0x33);
                   mp3(0x08);
				   delay_ms(8000);
				   mp3(0x33);
                   mp3(0x01);
				 }
		 }

		 while((flag_step2==1)&&(flag_step3==0))
		 {
		   	 if((INPUT8==0)&&(flag_step4==0))
			 {
			   flag_step4=1;
			   delay_ms(500);
			   mp3(0x33);
               mp3(0x03);
			   delay_ms(500);
			 }
			 if((INPUT7==0)&&(flag_step5==0))
			 {
			   flag_step5=1;
			   delay_ms(500);
			   mp3(0x33);
               mp3(0x04);
			   delay_ms(500);
			 }
			 if((INPUT6==0)&&(flag_step6==0))
			 {
			   flag_step6=1;
			   delay_ms(500);
			   mp3(0x33);
               mp3(0x05);
			   delay_ms(500);
			 }
			 if((INPUT5==0)&&(flag_step7==0))
			 {
			   flag_step7=1;
			   delay_ms(500);
			   mp3(0x33);
               mp3(0x06);
			   delay_ms(500);
			 }
			 if((INPUT16==0)&&(flag_step8==0))
			 {
			   flag_step8=1;
			   delay_ms(500);
			   mp3(0x33);
               mp3(0x07);
			   delay_ms(500);
			 }


		   
		   
		   if((flag_step4==1)&&(flag_step5==1)&&(flag_step6==1)&&(flag_step7==1)&&(flag_step8==1))
		   {
		   	 OUT1=1;	 //5���������
			 OUT6=0;	 //���еĵ������
			 flag_step3=1;
			 delay_ms(500);
			 mp3(0x33);
             mp3(0x09);	 
			 delay_ms(500);	  
		   }
		 }
		 while(flag_step3==1)
		 {
		   if(INPUT15==0)
		   {
		   	 OUT5=0;   //��Ҫ����һ�����زſ���
		   }	
			
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
	
		
	//R1-R5���е��������
	OUT1=0;
	OUT2=0;
	OUT3=0;
	OUT4=0;
	OUT5=1;
	OUT6=1;
			
	OUT7=0;		//	
	OUT8=0;		//  
	OUT9=0;		//	
	OUT10=0;	//	

	
	INPUT16=1;  //��������,�绰���ߵ�Ƭ����R5����

	INPUT15=1; 	//�����1����
	INPUT14=1; 
	INPUT13=1; 

	INPUT11=1;	//������չ�
	INPUT12=1;

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


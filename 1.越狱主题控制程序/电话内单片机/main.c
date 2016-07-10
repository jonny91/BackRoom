
#include "STC12C5A60S2.h"
#include "intrins.h" 
#include "stdio.h"
#include"uart.h"

#define uchar unsigned char
#define uint unsigned int

sbit OUT1   =  P4^2;		//���IO��1��   
sbit OUT2   =  P1^0;	    //���2��        ���ߵ�Ƭ����R5���ţ������� 
sbit OUT3   =  P1^1;		//���3��       
sbit OUT4   =  P1^2;        //���4��       
sbit OUT5   =  P1^3;	    //���5��       
sbit OUT6   =  P1^4;		//���6��       
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

sbit INPUT16   =  P4^4;		//����IO���ƿ�16��  
sbit INPUT15   =  P4^5;	    //����15��           
sbit INPUT14   =  P4^1;		//����14			 
sbit INPUT13   =  P4^6;     //����13			 
sbit INPUT12   =  P0^7;	    //����12			 �绰��Ͳ���𣡣�
sbit INPUT11   =  P0^6;		//����11����������	 

sbit INPUT10   =  P0^5;		//����10���Ž�����	 
sbit INPUT9    =  P0^4;		//����9���Ž�		 
sbit INPUT8    =  P0^3;		//����8���Ž�		 
sbit INPUT7    =  P0^2;		//����7���Ž�		 �������!
sbit INPUT6    =  P0^1;	 	//����6���Ž�		 ������ȷ!
sbit INPUT5    =  P0^0;	    //����5���Ž�����	 ����Ƭ���źŴ�����

sbit RXD   =  P3^0;	    
sbit TXD   =  P3^1;

#define uchar unsigned char
#define uint unsigned int

sfr P4sw=0xbb;

void sys_init(void);
void delay_ms(int count);
void mp3_init();
void mp3(unsigned char comd);
void key_scan(void);

unsigned char flag=0,flag1=1,flag3=1,flag4=1,STEP=1,PICK_UP=0,num=0;
int i=0;



/************************************************************************
    �������ƣ�   void main(void)		
    �������ܣ�   
    ���ú�����  void delay(unsigned int loop_time)	
*************************************************************************/
void main()
{
	sys_init();	        
	P4sw = 0x70;
	STEP=1;
	PICK_UP=0;
   while(1)
	 {				
		if(STEP==1)
		{
		  if((INPUT5==0)||(flag==1))		 //����Ƭ���źŴ������
			{
			  delay_ms(50);
			  if((INPUT5==0)||(flag==1))	
			  {
			   mp3(0X01);                  //��һ�ε绰����
			   flag=1;
			   INPUT5=1;
			   delay_ms(3000);
			  }
			}
			
			if((INPUT12==0)&&(flag1==1))		            //�绰������,�����ڶ�����Ч
			{
			  delay_ms(50);
			  if((INPUT12==0)&&(flag1==1))
			  {
			     flag=0;
				 flag1=0;
				 mp3(0X33);	
				 mp3(0X02);					//�ڶ��ε绰��
				 delay_ms(3000);
				 STEP=2;
			  }
			}
		}
	if(STEP==2)
	{	 
	/*	   if(flag1==0)
		  {
		  	delay_ms(5000);
			delay_ms(5000);
			delay_ms(5000);
			delay_ms(5000);
			delay_ms(5000);
			delay_ms(5000);
		  }*/
		for(i=1;i<120;i++)
		{
		 key_scan();
		 delay_ms(250);
		}

		if(num==1)
		 {
		 	while(INPUT12==1)
			{
			  	 mp3(0X01);
			     delay_ms(3500);

			} 
			mp3(0X04);
			for(i=1;i<120;i++)
			{
			 key_scan();
			 delay_ms(250);
			}	 
		 }
		else if(num==3) 
		  {
		  	while(INPUT12==1)
			{
			  	 mp3(0X01);
			     delay_ms(3500);

			}
			mp3(0X03);
			delay_ms(8000);
			OUT2=0;						//���ߵ�Ƭ����R5�ĵ��������
			STEP=3;						//�����ڶ��׶�
			delay_ms(8000);
			delay_ms(8000);
			delay_ms(8000);
			mp3(0X35);
			for(i=1;i<1200;i++)
			{
			// key_scan();
			 delay_ms(5000);
			}
		  }
		 
		 
		 
/*		 
		 if((INPUT7==0)&&(INPUT12==1)&&(PICK_UP==0))					//���˴����η����ţ������ҵ绰�����ˣ����������
			{ 
			 delay_ms(50);
			 if((INPUT7==0)&&(INPUT12==1))
			 {
			   mp3(0X01);					                           //��1������,�绰������
			   flag4=0;
			   delay_ms(3000);
			   flag1=1;
			 }
			}
		else if((INPUT7==0)&&(INPUT12==0)&&(PICK_UP==0))
			{
			   flag4=0;
			   flag1=1;
			}
		else if((INPUT6==0)&&(INPUT7!=0)&&(INPUT12==1)&&(PICK_UP==0))					//������ȷ�η����ţ������ҵ绰������
			{ 
			 delay_ms(50);
			 if((INPUT6==0)&&(INPUT7!=0)&&(INPUT12==1))
			 {
			   mp3(0X01);					//��1������,�绰��
			   flag3=0;
			    delay_ms(3000);
				flag1=1;
				//PICK_UP=1;
			 }
			}
		else if((INPUT6==0)&&(INPUT7!=0)&&(INPUT12==0)&&(PICK_UP==0))
			{
			   flag1=1;
			}
		
		 delay_ms(5000);

		if((flag4==0)&&(INPUT12==0))							   //�������ĵ绰
			{
			   mp3(0X04);               //���Ķ����������Ǵ��󣡣�
			   flag4=1;
			   flag1=0;
			 //  PICK_UP=0;
			   delay_ms(5000);		    // �ӳ�һ����
			   delay_ms(5000);
			   delay_ms(5000);
			   delay_ms(5000);
			   delay_ms(5000);
			   delay_ms(5000);
			}
		else if((flag3==0)&&(INPUT12==0))					   //������ȷ�ĵ绰
			{
			  // PICK_UP=0;
			   mp3(0X33);
			   mp3(0X03);				                     	//��3������,���ǳɹ��ˣ�
			   flag3=1;
			   flag1=0;
			   delay_ms(8000);
			     OUT2=0;						//���ߵ�Ƭ����R5�ĵ��������
				 STEP=3;						//�����ڶ��׶�
			}		   	*/
	}					
	  			  				
 }                											  
}
																					    
void key_scan(void)
{
        if((INPUT7==0)&&(INPUT12==1))					//���󣡲��ҵ绰�����ˣ����������
			{ 
			   num=1;
			}
		else if((INPUT7==0)&&(INPUT12==0))
			{
			   num=2;
			}
		else if((INPUT6==0)&&(INPUT7!=0)&&(INPUT12==1))	//������ȷ�η����ţ������ҵ绰������
			{ 
				num=3;
			
			}
		else if((INPUT6==0)&&(INPUT7!=0)&&(INPUT12==0))	   //��ȷ���绰û��
			{
			  	num=4;
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
	
		
	
	
	INPUT16=1;  
	INPUT15=1; 	
	INPUT14=1; 
	INPUT13=1; 
	INPUT11=1;	
	INPUT12=1;
	INPUT10=1;
	INPUT9=1;
	INPUT8=1;
	INPUT7=1;
	INPUT6=1;
	INPUT5=1;

	OUT2=1;
	 	  
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
				   send(0X00);//20
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


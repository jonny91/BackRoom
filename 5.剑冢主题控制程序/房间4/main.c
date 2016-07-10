
#include "STC12C5A60S2.h"
#include "intrins.h" 
#include "stdio.h"
#include"uart.h"

#define uchar unsigned char
#define uint unsigned int

sbit OUT1   =  P4^2;		//���IO��1��    ����1
sbit OUT2   =  P1^0;	    //���2��        ����2
sbit OUT3   =  P1^1;		//���3��        ����3
sbit OUT4   =  P1^2;        //���4��        ����4
sbit OUT5   =  P1^3;	    //���5��        ����5
sbit OUT6   =  P1^4;		//���6��        ����6
sbit OUT7   =  P1^5;		//���7��        ����7
sbit OUT8   =  P1^6;		//���8��        R4����� ����������
sbit OUT9   =  P1^7;		//���9��        
sbit OUT10  =  P4^3;		//���10��       



sbit M10     =  P3^2;		 //���1+		      
sbit M11     =  P3^3;		 //���1-
sbit M20     =  P3^4;		 //���2+
sbit M21     =  P3^5;		 //���2-
sbit M30     =  P3^6;		 //���3+
sbit M31     =  P3^7;		 //���3-

sbit OUT21   =  P4^0;		//���IO���ƿ�21   ������ղ��ֵƴ�1
sbit OUT22   =  P2^0;	    //���22		   �ƴ�2
sbit OUT23   =  P2^1;		//���23		   �ƴ�3
sbit OUT24   =  P2^2;       //���24		   �ƴ�4
sbit OUT25   =  P2^3;	    //���25		   �ƴ�5
sbit OUT26   =  P2^4;		//���26		   �ƴ�6
sbit OUT27   =  P2^5;		//���27

sbit OUT28   =  P2^6;	    //				   ���߰ѽ�
sbit OUT29   =  P2^7;		//				   �����ӽ�7

sbit INPUT16   =  P4^4;		//����IO���ƿ�16��  �������1
sbit INPUT15   =  P4^5;	    //����15��          �������2 
sbit INPUT14   =  P4^1;		//����14			�������3
sbit INPUT13   =  P4^6;     //����13			�������4 
sbit INPUT12   =  P0^7;	    //����12			�������5 
sbit INPUT11   =  P0^6;		//����11����������	�������6 

sbit INPUT10   =  P0^5;		//����10���Ž�����	 �����ӽ�1
sbit INPUT9    =  P0^4;		//����9���Ž�		 �����ӽ�2
sbit INPUT8    =  P0^3;		//����8���Ž�		 �����ӽ�3
sbit INPUT7    =  P0^2;		//����7���Ž�		 �����ӽ�4
sbit INPUT6    =  P0^1;	 	//����6���Ž�		 �����ӽ�5
sbit INPUT5    =  P0^0;	    //����5���Ž�����	 �����ӽ�6

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
    �������ƣ�   void main(void)		
    �������ܣ�   
    ���ú�����  void delay(unsigned int loop_time)	
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
		//	 if((INPUT10==0)&&(INPUT9==0)&&(INPUT8==0)&&(INPUT7==0)&&(INPUT6==0)&&(INPUT5==0)&&(flag_step1==0))	  //ȫ���Ľ����뽣����
			 {
				mp3(0x33);
				mp3(0x08);			   //��������
			
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
				OUT21=0;			   //����â�ǵƴ�
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
								OUT21=1;			   //����â�ǵƴ�
								OUT22=1;
								OUT23=1;
								OUT24=1;
								OUT25=1;
								OUT26=1;
							   delay_ms(500);
							    OUT21=0;			   //�ر���â�ǵƴ�
								OUT22=0;
								OUT23=0;
								OUT24=0;
								OUT25=0;
								OUT26=0;
								delay_ms(500);
								OUT21=1;			   //����â�ǵƴ�
								OUT22=1;
								OUT23=1;
								OUT24=1;
								OUT25=1;
								OUT26=1;
							   delay_ms(500);
							    OUT21=0;			   //�ر���â�ǵƴ�
								OUT22=0;
								OUT23=0;
								OUT24=0;
								OUT25=0;
								OUT26=0;
						   mp3(0x33);
				           mp3(0x0a);
						   	delay_ms(8000);
						   	OUT21=1;			   //����â�ǵƴ�
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
						   OUT8=0;				  //��������
						   while(1);
					}
					else
					{
						      mp3(0x33);
				              mp3(0x09);
							flag_step11=0;
							count=0;

							OUT21=0;			   //����â�ǵƴ�
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
	OUT5=0;
	OUT6=0;		//  
	OUT7=0;		//	

	OUT8=1;		//  ����������

	OUT9=0;		//	
	OUT10=0;	//	

	

	INPUT16=1;  // ��������� *6
	INPUT15=1; 	//
	INPUT14=1; 
	INPUT13=1; 
	INPUT11=1;	
	INPUT12=1;

	INPUT10=1;	//�����ӽ�����	*7
	INPUT9=1;
	INPUT8=1;
	INPUT7=1;
	INPUT6=1;
	INPUT5=1;
	OUT28=1;
	OUT29=1;

	OUT21=0;	//����������ĵƴ�
	OUT22=0;
	OUT23=0;
	OUT24=0;
	OUT25=0;
	OUT26=0;
	OUT27=0;
	 	  
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


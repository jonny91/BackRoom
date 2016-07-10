
#include "STC12C5A60S2.h"
#include "intrins.h" 
#include "stdio.h"
#include"uart.h"

#define uchar unsigned char
#define uint unsigned int

sbit OUT1   =  P4^2;		//���IO��1��    �Ųȵƴ�1��
sbit OUT2   =  P1^0;	    //���2��        �Ųȵƴ�2
sbit OUT3   =  P1^1;		//���3��        �Ųȵƴ�3��
sbit OUT4   =  P1^2;        //���4��        �Ųȵƴ�4��
sbit OUT5   =  P1^3;	    //���5��        �Ųȵƴ�5��
sbit OUT6   =  P1^4;		//���6��        �Ųȵƴ�6��
sbit OUT7   =  P1^5;		//���7��        �Ųȵƴ�7��
sbit OUT8   =  P1^6;		//���8��        �Ųȵƴ�8��
sbit OUT9   =  P1^7;		//���9��        �Ųȵƴ�9��

sbit OUT10  =  P4^3;		//���10��       �����µ��������

sbit M10     =  P3^2;		 //���1+		 ����Ƭ1
sbit M11     =  P3^3;		 //���1-		 ����Ƭ2
sbit M20     =  P3^4;		 //���2+		 ����Ƭ3
sbit M21     =  P3^5;		 //���2-		 ����Ƭ4
sbit M30     =  P3^6;		 //���3+		 ����Ƭ5
sbit M31     =  P3^7;		 //���3-		 ����Ƭ6

sbit OUT21   =  P4^0;		//���IO���ƿ�21	����Ƭ7
sbit OUT22   =  P2^0;	    //���22			����Ƭ8
sbit OUT23   =  P2^1;		//���23			����˵���Ƭ

sbit OUT24   =  P2^2;       //���24			  ��ʥ�� �ĸ��ɻɹܴ���

sbit OUT25   =  P2^3;	    //���25			  ���԰���8

sbit OUT26   =  P2^4;		//���26			  �ŲȰ���9
sbit OUT27   =  P2^5;		//���27			  �ŲȰ���8
sbit OUT28   =  P2^6;		//���26			  �ŲȰ���7
sbit OUT29   =  P2^7;		//���27			  �ŲȰ���6


sbit INPUT16   =  P4^4;		//����IO���ƿ�16��    	   ���԰���1
sbit INPUT15   =  P4^5;	    //����15��                 ���԰���2
sbit INPUT14   =  P4^1;		//����14				   ���԰���3	
sbit INPUT13   =  P4^6;     //����13			 	   ���԰���4	
sbit INPUT12   =  P0^7;	    //����12			 	   ���԰���5
sbit INPUT11   =  P0^6;		//����11����������	 	   ���԰���6
sbit INPUT10   =  P0^5;		//����10���Ž�����	 	   ���԰���7


sbit INPUT9    =  P0^4;		//����9���Ž�			   �ŲȰ���1
sbit INPUT8    =  P0^3;		//����8���Ž�		 	   �ŲȰ���2
sbit INPUT7    =  P0^2;		//����7���Ž�		 	   �ŲȰ���3
sbit INPUT6    =  P0^1;	 	//����6���Ž�		 	   �ŲȰ���4
sbit INPUT5    =  P0^0;	    //����5���Ž�����	 	   �ŲȰ���5

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
void key_scan2(void);

unsigned char i=0,count1=0,count2=0;
unsigned char flag_step1=0,flag_step2=1,flag_step3=1,flag_step4=1,flag_step5=1,flag_step6=1,flag_step7=1,flag_step8=1,flag_step9=1,flag_step10=1;
char code1[18]={7,8,1,5,3,2,9,4,6,9,8,1,4,6,2,3,5,7};
char num[18]={0};
char num1[8]={0};

char code2[8]={0,0,0,0,0,0,1,5};
char code3[8]={0,0,0,0,0,0,3,2};
char code4[8]={0,0,0,0,0,4,6,1};
char code5[8]={0,0,0,0,0,6,8,7};
char code6[8]={0,0,0,0,8,2,6,3};
char code7[8]={1,2,3,4,5,6,7,8};


/************************************************************************
    �������ƣ�   void main(void)		
    �������ܣ�   
    ���ú�����  void delay(unsigned int loop_time)	
*************************************************************************/
void main()
{
	sys_init();	        


	while(1)
	  {					
			 if((OUT24==0)&&(flag_step1==0))			// ��ʥ�޷�����ָ��λ��
			 {
			   delay_ms(50);
			   if(OUT24==0)
			   {

				   mp3(0x33);	  //��Ч1
				   mp3(0x01); 
				   flag_step1=1;
				   for(i=0;i<100;i++)
				   {
				   	 delay_ms(350);
				   }
				   mp3(0x33);	  //��Ч2	ľ׮����1
				   mp3(0x02); 
 				   OUT1=1;
				   
				   while(INPUT9);
				   while(!INPUT9);
				   mp3(0x33);	  //��Ч10	��ľ׮��Ч
				   mp3(0x0A);  
				   OUT1=0;
				   OUT2=1;
				   delay_ms(2000);
				   mp3(0x33);	  //��Ч3	ľ׮����2
				   mp3(0x03);
				   
				   while(INPUT8);
				   while(!INPUT8);
				   mp3(0x33);	  //��Ч10	��ľ׮��Ч
				   mp3(0x0A); 
				   OUT2=0;
				   OUT3=1;
				   delay_ms(2000);
				   mp3(0x33);	  //��Ч4	ľ׮����3
				   mp3(0x04);
				   
				   while(INPUT7);
				   while(!INPUT7);
				   mp3(0x33);	  //��Ч10	��ľ׮��Ч
				   mp3(0x0A);  
				   OUT3=0;
				   OUT4=1;
				   delay_ms(2000);
				   mp3(0x33);	  //��Ч5	ľ׮����4
				   mp3(0x05);
				   
				   while(INPUT6);
				   while(!INPUT6);
				   mp3(0x33);	  //��Ч10	��ľ׮��Ч
				   mp3(0x0A); 
				   OUT4=0;
				   OUT5=1;
				   delay_ms(2000);         
				   mp3(0x33);	  //��Ч6	ľ׮����5
				   mp3(0x06);
				   
				   while(INPUT5);
				   while(!INPUT5);
				   mp3(0x33);	  //��Ч10	��ľ׮��Ч
				   mp3(0x0A); 
                   OUT5=0;
				   OUT6=1; 
				   delay_ms(2000);
				   mp3(0x33);	  //��Ч7	ľ׮����6
				   mp3(0x07);
				   
				   while(OUT29);
				   while(!OUT29);
				   mp3(0x33);	  //��Ч10	��ľ׮��Ч
				   mp3(0x0A); 
				   OUT6=0;
				   OUT7=1;
				   delay_ms(2000);
				   mp3(0x33);	  //��Ч8	ľ׮����7
				   mp3(0x08);
				   
				   while(OUT28);
				   while(!OUT28);
				   mp3(0x33);	  //��Ч10	��ľ׮��Ч
				   mp3(0x0A); 
				   OUT7=0;
				   OUT8=1;
				   OUT9=1;
				   delay_ms(2000);
				    
				   mp3(0x33);	  //��Ч9	ľ׮����8
				   mp3(0x09);
				   
				   while((OUT27!=0)||(OUT26!=0));
				   mp3(0x33);	  //��Ч10	��ľ׮��Ч
				   mp3(0x0A); 
				   OUT8=0;
				   OUT9=0;
				   delay_ms(2000);
				   mp3(0x33);	  //��Ч11	���������ʾ��
				   mp3(0x0B); 	  //
				    delay_ms(5000);
				   mp3(0x33);	  //��Ч12	
				   mp3(0x0C); 	  //��������
				   delay_ms(5000);
				   OUT7=1;
				   delay_ms(2000);
				   OUT7=0;
				   OUT8=1;
				   delay_ms(1000);
				   OUT8=0;
				   OUT1=1;
				   delay_ms(800);
				   OUT1=0;
				   OUT5=1;
				   delay_ms(500);
				   OUT5=0;
				   OUT3=1;
				   delay_ms(500);
				   OUT3=0;
				   OUT2=1;
				   delay_ms(800);
				   OUT2=0;
				   OUT9=1;
				   delay_ms(1000);
				   OUT9=0;
				   OUT4=1;
				   delay_ms(1000);
				   OUT4=0;
				   OUT6=1;
				   delay_ms(2000);
				   OUT6=0;
				   OUT9=1;
				   delay_ms(200);
				   OUT9=0;
				   OUT8=1;
				   delay_ms(200);
				   OUT8=0;
				   OUT1=1;
				   delay_ms(200);
				   OUT1=0;
				   OUT4=1;
				   delay_ms(200);
				   OUT4=0;
				   OUT6=1;
				   delay_ms(200);
				   OUT6=0;
				   OUT2=1;
				   delay_ms(200);
				   OUT2=0;
				   OUT3=1;
				   delay_ms(500);
				   OUT3=0;
				   OUT5=1;
				   delay_ms(1000);
				   OUT5=0;
				   OUT7=1;
				   delay_ms(3000);
				   OUT7=0;
				   	   
				   while(flag_step2==1)
				   {
				   	  key_scan();
					  if(count1==18)
					  {
					  	if((code1[0]==num[0])&&(code1[1]==num[1])&&(code1[2]==num[2])&&(code1[3]==num[3])&&(code1[4]==num[4])&&(code1[5]==num[5])&&(code1[6]==num[6])&&(code1[7]==num[7])&&(code1[8]==num[8])&&(code1[9]==num[9])&&(code1[10]==num[10])&&(code1[11]==num[11])&&(code1[12]==num[12])&&(code1[13]==num[13])&&(code1[14]==num[14])&&(code1[15]==num[15])&&(code1[16]==num[16])&&(code1[17]==num[17]))//����˳���Ǻ�
						{
						   	flag_step2=0;
							num[0]=0;
							num[1]=0;
							num[2]=0;
							num[3]=0;
							num[4]=0;
							num[5]=0;
							num[6]=0;
							num[7]=0;
							num[8]=0;
							num[9]=0;
							num[10]=0;
							num[11]=0;
							num[12]=0;
							num[13]=0;
							num[14]=0;
							num[15]=0;
							num[16]=0;
							num[17]=0;
							delay_ms(500);
							 mp3(0x33);	  //��Ч15	������ȷ,������һʽ     1��5(7)   
				             mp3(0x0F); 	  //
							delay_ms(500);
							 OUT23=1;
							 OUT1=1;
							 OUT2=1;
							 OUT3=1;
							 OUT4=1;
							 OUT5=1;
							 OUT6=1;
							 OUT7=1;
							 OUT8=1;
							 OUT9=1;
							 delay_ms(8000);
						}
						else
						{
							OUT1=0;
							 OUT2=0;
							 OUT3=0;
							 OUT4=0;
							 OUT5=0;
							 OUT6=0;
							 OUT7=0;
							 OUT8=0;
							 OUT9=0;
						    num[0]=0;
							num[1]=0;
							num[2]=0;
							num[3]=0;
							num[4]=0;
							num[5]=0;
							num[6]=0;
							num[7]=0;
							num[8]=0;
							num[9]=0;
							num[10]=0;
							num[11]=0;
							num[12]=0;
							num[13]=0;
							num[14]=0;
							num[15]=0;
							num[16]=0;
							num[17]=0;
							delay_ms(500);
							 mp3(0x33);	  //��Ч14	�������� ������ʾһ��
				             mp3(0x0E); 	  //
							  delay_ms(5000);
								   OUT7=1;
								   delay_ms(2000);
								   OUT7=0;
								   OUT8=1;
								   delay_ms(1000);
								   OUT8=0;
								   OUT1=1;
								   delay_ms(800);
								   OUT1=0;
								   OUT5=1;
								   delay_ms(500);
								   OUT5=0;
								   OUT3=1;
								   delay_ms(500);
								   OUT3=0;
								   OUT2=1;
								   delay_ms(800);
								   OUT2=0;
								   OUT9=1;
								   delay_ms(1000);
								   OUT9=0;
								   OUT4=1;
								   delay_ms(1000);
								   OUT4=0;
								   OUT6=1;
								   delay_ms(2000);
								   OUT6=0;
								   OUT9=1;
								   delay_ms(200);
								   OUT9=0;
								   OUT8=1;
								   delay_ms(200);
								   OUT8=0;
								   OUT1=1;
								   delay_ms(200);
								   OUT1=0;
								   OUT4=1;
								   delay_ms(200);
								   OUT4=0;
								   OUT6=1;
								   delay_ms(200);
								   OUT6=0;
								   OUT2=1;
								   delay_ms(200);
								   OUT2=0;
								   OUT3=1;
								   delay_ms(500);
								   OUT3=0;
								   OUT5=1;
								   delay_ms(1000);
								   OUT5=0;
								   OUT7=1;
								   delay_ms(3000);
								   OUT7=0;
							   
							   count1=0;
					    	}
					    }	  
				    }
				  while(flag_step3==1)			  //���԰�����ʼ 
				  {
				  	  key_scan2();
					  if(count2==2)
					  {
					  	if((code2[0]==num1[0])&&(code2[1]==num1[1])&&(code2[2]==num1[2])&&(code2[3]==num1[3])&&(code2[4]==num1[4])&&(code2[5]==num1[5])&&(code2[6]==num1[6])&&(code2[7]==num1[7]))//����˳���Ǻ�
						{
						   	count2=0;
							delay_ms(1000);
							flag_step3=0;
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;
							delay_ms(500);
							mp3(0x33);	  //��Ч17	��һʽ��ȷ�������ڶ�ʽ�� 3��2(5)
				            mp3(0x11); 	  //
							delay_ms(500); 
						}
						else
						{
							delay_ms(1000);
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;

								M10=0; 		//
								M11=0;
								M20=0; 		//
								M21=0;
								M30=0;
								M31=0;
								OUT21=0;
								OUT22=0;
								delay_ms(500);
							 mp3(0x33);	  //��Ч16��������һʽ����	
				             mp3(0x10); 	  //
							 delay_ms(500);
							   count2=0;
					    	}
					    }	
				  
				  }

				  while(flag_step4==1)
				  {
				  	 key_scan2();
					  if(count2==2)
					  {
					  	if((code3[0]==num1[0])&&(code3[1]==num1[1])&&(code3[2]==num1[2])&&(code3[3]==num1[3])&&(code3[4]==num1[4])&&(code3[5]==num1[5])&&(code3[6]==num1[6])&&(code3[7]==num1[7]))//����˳���Ǻ�
						{
						   	count2=0;
							delay_ms(1000);
							flag_step4=0;
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;
							delay_ms(500);
							 mp3(0x33);	  //��Ч19	��������ʽ��
				             mp3(0x13); 	  //				
							 delay_ms(500); 
							

						}
						else
						{
							delay_ms(1000);
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;

								M10=0; 		//
								M11=0;
								M20=0; 		//
								M21=0;
								M30=0;
								M31=0;
								OUT21=0;
								OUT22=0;
							delay_ms(500);
							 mp3(0x33);	   //��Ч18	�����ڶ�ʽ����
				             mp3(0x12);    //
					
							 delay_ms(500);
							   
							   count2=0;
					    	}
					    }	
				  
				  }

				  while(flag_step5==1)
				  {
				  	 key_scan2();
					  if(count2==3)
					  {
					  	if((code4[0]==num1[0])&&(code4[1]==num1[1])&&(code4[2]==num1[2])&&(code4[3]==num1[3])&&(code4[4]==num1[4])&&(code4[5]==num1[5])&&(code4[6]==num1[6])&&(code4[7]==num1[7]))//����˳���Ǻ�
						{
						   	count2=0;
							delay_ms(1000);
							flag_step5=0;
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;
							delay_ms(500);
							 mp3(0x33);	  //��Ч21	��������ʽ��  6(2)��8��7(6)
				             mp3(0x15); 	  //
							 delay_ms(500); 
						}
						else
						{
							delay_ms(1000);
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;

								M10=0; 		//
								M11=0;
								M20=0; 		//
								M21=0;
								M30=0;
								M31=0;
								OUT21=0;
								OUT22=0;
							delay_ms(500);
							 mp3(0x33);	   //��Ч20	��������ʽ����
				             mp3(0x14);    // 
							   count2=0;
							 delay_ms(500); 
					    	}
					    }	
				  
				  }

				  while(flag_step6==1)
				  {
				  	 key_scan2();
					  if(count2==3)
					  {
					  	if((code5[0]==num1[0])&&(code5[1]==num1[1])&&(code5[2]==num1[2])&&(code5[3]==num1[3])&&(code5[4]==num1[4])&&(code5[5]==num1[5])&&(code5[6]==num1[6])&&(code5[7]==num1[7]))//����˳���Ǻ�
						{
						   	count2=0;
							delay_ms(1000);
							flag_step6=0;
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;
							delay_ms(500);
							 mp3(0x33);	  //��Ч23	��������ʽ��  8,2(5),6(2),3
				             mp3(0x17); 	  //
							 delay_ms(500);					 
						}
						else
						{
							delay_ms(1000);
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;

								M10=0; 		//
								M11=0;
								M20=0; 		//
								M21=0;
								M30=0;
								M31=0;
								OUT21=0;
								OUT22=0;
								delay_ms(500);
							 mp3(0x33);	   //��Ч22	��������ʽ����
				             mp3(0x16);    //					
							   count2=0;
							 delay_ms(500); 
					    	}
					    }	
				  
				  }


				  while(flag_step7==1)
				  {
				  	 key_scan2();
					  if(count2==4)
					  {
					  	if((code6[0]==num1[0])&&(code6[1]==num1[1])&&(code6[2]==num1[2])&&(code6[3]==num1[3])&&(code6[4]==num1[4])&&(code6[5]==num1[5])&&(code6[6]==num1[6])&&(code6[7]==num1[7]))//����˳���Ǻ�
						{
						   	count2=0;
							delay_ms(1000);
							flag_step7=0;
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;
							delay_ms(500);
							 mp3(0x33);	  //��Ч25	����ʽ�� 1,2(6),3,4,5(2),6(7),7(5),8
				             mp3(0x19); 	  //
							 delay_ms(500);	
						}
						else
						{
							delay_ms(1000);
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;

								M10=0; 		//
								M11=0;
								M20=0; 		//
								M21=0;
								M30=0;
								M31=0;
								OUT21=0;
								OUT22=0;
							 delay_ms(500);
							 mp3(0x33);	   //��Ч24	����ʽ����
				             mp3(0x18);    //						
							   count2=0;						
							 delay_ms(500);
					    	}
					    }	
				  
				  }

				   while(flag_step8==1)
				  {
				  	 key_scan2();
					  if(count2==8)
					  {
					  	if((code7[0]==num1[0])&&(code7[1]==num1[1])&&(code7[2]==num1[2])&&(code7[3]==num1[3])&&(code7[4]==num1[4])&&(code7[5]==num1[5])&&(code7[6]==num1[6])&&(code7[7]==num1[7]))//����˳���Ǻ�
						{
						   	count2=0;
							delay_ms(1000);
							flag_step8=0;
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;
							delay_ms(500);
							mp3(0x33);	  //��Ч34	����ʽ��ȷ���������
				            mp3(0x22); 	  //
							delay_ms(500); 
								M10=1; 		//
								M11=1;
								M20=1; 		//
								M21=1;
								M30=1;
								M31=1;
								OUT21=1;
								OUT22=1;
						   delay_ms(8000);
						    delay_ms(8000);
							 delay_ms(4000);
							 OUT10=1;        //�������

						  while(1);

							 
						}
						else
						{
							delay_ms(1000);
							num1[0]=0;
							num1[1]=0;
							num1[2]=0;
							num1[3]=0;
							num1[4]=0;
							num1[5]=0;
							num1[6]=0;
							num1[7]=0;

								M10=0; 		//
								M11=0;
								M20=0; 		//
								M21=0;
								M30=0;
								M31=0;
								OUT21=0;
								OUT22=0;
							 delay_ms(500);
							 mp3(0x33);	   //��Ч36	����ʽ����
				             mp3(0x24);    //
							 delay_ms(600);  
							   count2=0;				
					    	}
					    }	
				  
				  }



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
	M30=0;
	M31=0;
	OUT21=0;
	OUT22=0;
	OUT23=0;  

	OUT24=1;	 //��ʥ�޷���
	OUT25=1;
	OUT26=1;
	OUT27=1;
	OUT28=1;
	OUT29=1;
	
	INPUT16=1;  //��������4��
	INPUT15=1; 	//
	INPUT14=1; 
	INPUT13=1; 
	INPUT12=1; //�������� �ʼ��
	INPUT11=1;	 
	
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

		case 0X10: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x10);//���ŵ�16����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X11: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x11);//���ŵ�17����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X12: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x12);//���ŵ�18����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X13: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x13);//���ŵ�19����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X14: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x14);//���ŵ�20����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X15: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x15);//���ŵ�21����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X16: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x16);//����22����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X17: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x17);//���ŵ�23����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X18: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x18);//���ŵ�24����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X19: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x19);//���ŵ�25����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X1A: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x1A);//���ŵ�26����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X1B: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x1B);//���ŵ�27����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X1C: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x1C);//���ŵ�28����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X1D: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x1D);//���ŵ�29����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X1E: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x1E);//���ŵ�30����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X1F: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x1F);//���ŵ�31����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X20: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x20);//���ŵ�32����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X21: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x21);//���ŵ�33����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X22: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x22);//���ŵ�34����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
		case 0X23: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x23);//���ŵ�35����Ƶ�ļ�
				   send(0XEF);//ָ�����λ 
		   	       break;
	    case 0X24: send(0X7E);//ָ�ʼλ
				   send(0X04);//˵��ָ���
				   send(0X42);//ָ���ļ��в���
				   send(0X01);//��λ������Ϊ��01�����ļ���
				   send(0x24);//���ŵ�36����Ƶ�ļ�
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

void key_scan(void)
{
  
    if(INPUT9==0)							 //���� 1 
	  {
	  	delay_ms(50);
		if(INPUT9==0)
		{
	   	 	OUT1=1;	
			OUT2=0;			       //��� 
			OUT3=0;
			OUT4=0;
			OUT5=0;
			OUT6=0;
			OUT7=0;
			OUT8=0;
			OUT9=0;
	    while(!INPUT9);	
			
			num[0]=num[1];
	    	num[1]=num[2];
	    	num[2]=num[3];
	    	num[3]=num[4];
			num[4]=num[5];
			num[5]=num[6];
			num[6]=num[7];
			num[7]=num[8];
			num[8]=num[9];
	    	num[9]=num[10];
	    	num[10]=num[11];
	    	num[11]=num[12];
			num[12]=num[13];
			num[13]=num[14];
			num[14]=num[15];
			num[15]=num[16];
	    	num[16]=num[17];
			num[17]=1;

			count1++;


		}	
	  }
	else if(INPUT8==0)							 //���� 2 
	  {
	  	delay_ms(50);
		if(INPUT8==0)
		{
	    	OUT1=0;	
			OUT2=1;			       //��� 
			OUT3=0;
			OUT4=0;
			OUT5=0;
			OUT6=0;
			OUT7=0;
			OUT8=0;
			OUT9=0;
			while(!INPUT8);	
			num[0]=num[1];
	    	num[1]=num[2];
	    	num[2]=num[3];
	    	num[3]=num[4];
			num[4]=num[5];
			num[5]=num[6];
			num[6]=num[7];
			num[7]=num[8];
			num[8]=num[9];
	    	num[9]=num[10];
	    	num[10]=num[11];
	    	num[11]=num[12];
			num[12]=num[13];
			num[13]=num[14];
			num[14]=num[15];
			num[15]=num[16];
	    	num[16]=num[17];
			num[17]=2;


			

			count1++;
		}	
	  }
	else if(INPUT7==0)							 //���� 3 
	  {
	  	delay_ms(50);
		if(INPUT7==0)
		{
	    	 	OUT1=0;	
			OUT2=0;			       //��� 
			OUT3=1;
			OUT4=0;
			OUT5=0;
			OUT6=0;
			OUT7=0;
			OUT8=0;
			OUT9=0;
			while(!INPUT7);	
			num[0]=num[1];
	    	num[1]=num[2];
	    	num[2]=num[3];
	    	num[3]=num[4];
			num[4]=num[5];
			num[5]=num[6];
			num[6]=num[7];
			num[7]=num[8];
			num[8]=num[9];
	    	num[9]=num[10];
	    	num[10]=num[11];
	    	num[11]=num[12];
			num[12]=num[13];
			num[13]=num[14];
			num[14]=num[15];
			num[15]=num[16];
	    	num[16]=num[17];
			num[17]=3;


		

			count1++;
		}	
	  }
	else if(INPUT6==0)							 //���� 4 
	  {
	  	delay_ms(50);
		if(INPUT6==0)
		{
	    	 	OUT1=0;	
			OUT2=0;			       //��� 
			OUT3=0;
			OUT4=1;
			OUT5=0;
			OUT6=0;
			OUT7=0;
			OUT8=0;
			OUT9=0;
			while(!INPUT6);	
			num[0]=num[1];
	    	num[1]=num[2];
	    	num[2]=num[3];
	    	num[3]=num[4];
			num[4]=num[5];
			num[5]=num[6];
			num[6]=num[7];
			num[7]=num[8];
			num[8]=num[9];
	    	num[9]=num[10];
	    	num[10]=num[11];
	    	num[11]=num[12];
			num[12]=num[13];
			num[13]=num[14];
			num[14]=num[15];
			num[15]=num[16];
	    	num[16]=num[17];
			num[17]=4;

		

			count1++;
		}	
	  }
	 else if(INPUT5==0)							 //���� 5 
	  {
	  	delay_ms(50);
		if(INPUT5==0)
		{
	    	OUT1=0;	
			OUT2=0;			       //��� 
			OUT3=0;
			OUT4=0;
			OUT5=1;
			OUT6=0;
			OUT7=0;
			OUT8=0;
			OUT9=0; 
			while(!INPUT5);	
			num[0]=num[1];
	    	num[1]=num[2];
	    	num[2]=num[3];
	    	num[3]=num[4];
			num[4]=num[5];
			num[5]=num[6];
			num[6]=num[7];
			num[7]=num[8];
			num[8]=num[9];
	    	num[9]=num[10];
	    	num[10]=num[11];
	    	num[11]=num[12];
			num[12]=num[13];
			num[13]=num[14];
			num[14]=num[15];
			num[15]=num[16];
	    	num[16]=num[17];
			num[17]=5;
			

			count1++;
		}	
	  }
	 else if(OUT29==0)							 //���� 6 
	  {
	  	delay_ms(50);
		if(OUT29==0)
		{
	    	 OUT1=0;	
			OUT2=0;			       //��� 
			OUT3=0;
			OUT4=0;
			OUT5=0;
			OUT6=1;
			OUT7=0;
			OUT8=0;
			OUT9=0;
			while(!OUT29);	
			num[0]=num[1];
	    	num[1]=num[2];
	    	num[2]=num[3];
	    	num[3]=num[4];
			num[4]=num[5];
			num[5]=num[6];
			num[6]=num[7];
			num[7]=num[8];
			num[8]=num[9];
	    	num[9]=num[10];
	    	num[10]=num[11];
	    	num[11]=num[12];
			num[12]=num[13];
			num[13]=num[14];
			num[14]=num[15];
			num[15]=num[16];
	    	num[16]=num[17];
			num[17]=6;

			

			count1++;
		}	
	  }
	 else if(OUT28==0)							 //���� 7 
	  {
	  	delay_ms(50);
		if(OUT28==0)
		{
	    	 	OUT1=0;	
			OUT2=0;			       //��� 
			OUT3=0;
			OUT4=0;
			OUT5=0;
			OUT6=0;
			OUT7=1;
			OUT8=0;
			OUT9=0;
			while(!OUT28);	
			num[0]=num[1];
	    	num[1]=num[2];
	    	num[2]=num[3];
	    	num[3]=num[4];
			num[4]=num[5];
			num[5]=num[6];
			num[6]=num[7];
			num[7]=num[8];
			num[8]=num[9];
	    	num[9]=num[10];
	    	num[10]=num[11];
	    	num[11]=num[12];
			num[12]=num[13];
			num[13]=num[14];
			num[14]=num[15];
			num[15]=num[16];
	    	num[16]=num[17];
			num[17]=7;

		

			count1++;
		}	
	  }
	 else if(OUT27==0)							 //���� 8 
	  {
	  	delay_ms(50);
		if(OUT27==0)
		{
	    	OUT1=0;	
			OUT2=0;			       //��� 
			OUT3=0;
			OUT4=0;
			OUT5=0;
			OUT6=0;
			OUT7=0;
			OUT8=1;
			OUT9=0; 
			while(!OUT27);	
			num[0]=num[1];
	    	num[1]=num[2];
	    	num[2]=num[3];
	    	num[3]=num[4];
			num[4]=num[5];
			num[5]=num[6];
			num[6]=num[7];
			num[7]=num[8];
			num[8]=num[9];
	    	num[9]=num[10];
	    	num[10]=num[11];
	    	num[11]=num[12];
			num[12]=num[13];
			num[13]=num[14];
			num[14]=num[15];
			num[15]=num[16];
	    	num[16]=num[17];
			num[17]=8;
			count1++;
		}	
	  }
	else if(OUT26==0)							 //���� 9 
	  {
	  	delay_ms(50);
		if(OUT26==0)
		{
	    	OUT1=0;	
			OUT2=0;			       //��� 
			OUT3=0;
			OUT4=0;
			OUT5=0;
			OUT6=0;
			OUT7=0;
			OUT8=0;
			OUT9=1; 
			while(!OUT26);			
			num[0]=num[1];
	    	num[1]=num[2];
	    	num[2]=num[3];
	    	num[3]=num[4];
			num[4]=num[5];
			num[5]=num[6];
			num[6]=num[7];
			num[7]=num[8];
			num[8]=num[9];
	    	num[9]=num[10];
	    	num[10]=num[11];
	    	num[11]=num[12];
			num[12]=num[13];
			num[13]=num[14];
			num[14]=num[15];
			num[15]=num[16];
	    	num[16]=num[17];
			num[17]=9;

			count1++;
		}	
	  }

}



void key_scan2(void)
{
  
    if(INPUT16==0)							 //���� 1 
	  {
	  	delay_ms(50);
		if(INPUT16==0)
		{
	        while(!INPUT16);	
		    num1[0]=num1[1];
	    	num1[1]=num1[2];
	    	num1[2]=num1[3];
	    	num1[3]=num1[4];
			num1[4]=num1[5];
			num1[5]=num1[6];
			num1[6]=num1[7];
			num1[7]=1;

			
			M10=1; 		//
			M11=0;
			M20=0; 		//
			M21=0;
			M30=0;
			M31=0;
			OUT21=0;
			OUT22=0;

			count2++;

			mp3(0x33);	  //��Ч26	�������
		    mp3(0x1A); 	  //

		}	
	  }
	else if(INPUT15==0)							 //���� 2 
	  {
	  	delay_ms(50);
		if(INPUT15==0)
		{
	    	 while(!INPUT15);	
			num1[0]=num1[1];
	    	num1[1]=num1[2];
	    	num1[2]=num1[3];
	    	num1[3]=num1[4];
			num1[4]=num1[5];
			num1[5]=num1[6];
			num1[6]=num1[7];
			num1[7]=2;


			M10=0; 		//
			M11=0;
			M20=0; 		//
			M21=0;
			M30=0;
			M31=1;
			OUT21=0;
			OUT22=0;

			count2++;
			mp3(0x33);	  //��Ч27	�������
		    mp3(0x1B); 	  //
		}	
	  }
	else if(INPUT14==0)							 //���� 3 
	  {
	  	delay_ms(50);
		if(INPUT14==0)
		{
	    	 while(!INPUT14);	
			num1[0]=num1[1];
	    	num1[1]=num1[2];
	    	num1[2]=num1[3];
	    	num1[3]=num1[4];
			num1[4]=num1[5];
			num1[5]=num1[6];
			num1[6]=num1[7];
			num1[7]=3;


			M10=0; 		//
			M11=0;
			M20=1; 		//
			M21=0;
			M30=0;
			M31=0;
			OUT21=0;
			OUT22=0;

			count2++;
		    mp3(0x33);	  //��Ч28	�������
		    mp3(0x1C); 	  //
		}	
	  }
	else if(INPUT13==0)							 //���� 4 
	  {
	  	delay_ms(50);
		if(INPUT13==0)
		{
	    	 while(!INPUT13);	
			num1[0]=num1[1];
	    	num1[1]=num1[2];
	    	num1[2]=num1[3];
	    	num1[3]=num1[4];
			num1[4]=num1[5];
			num1[5]=num1[6];
			num1[6]=num1[7];
			num1[7]=4;


			M10=0; 		//
			M11=0;
			M20=0; 		//
			M21=1;
			M30=0;
			M31=0;
			OUT21=0;
			OUT22=0;

			count2++;
			mp3(0x33);	  //��Ч29	�������
		    mp3(0x1D); 	  //
		}	
	  }
	 else if(INPUT12==0)							 //���� 5 
	  {
	  	delay_ms(50);
		if(INPUT12==0)
		{
	    	 while(!INPUT12);	
			num1[0]=num1[1];
	    	num1[1]=num1[2];
	    	num1[2]=num1[3];
	    	num1[3]=num1[4];
			num1[4]=num1[5];
			num1[5]=num1[6];
			num1[6]=num1[7];
			num1[7]=5;


			M10=0; 		//
			M11=1;
			M20=0; 		//
			M21=0;
			M30=0;
			M31=0;
			OUT21=0;
			OUT22=0;

			count2++;
		    mp3(0x33);	  //��Ч30	�������
		    mp3(0x1E); 	  //
		}	
	  }
	 else if(INPUT11==0)							 //���� 6 
	  {
	  	delay_ms(50);
		if(INPUT11==0)
		{
	    	 while(!INPUT11);	
			num1[0]=num1[1];
	    	num1[1]=num1[2];
	    	num1[2]=num1[3];
	    	num1[3]=num1[4];
			num1[4]=num1[5];
			num1[5]=num1[6];
			num1[6]=num1[7];
			num1[7]=6;


			M10=0; 		//
			M11=0;
			M20=0; 		//
			M21=0;
			M30=0;
			M31=0;
			OUT21=1;
			OUT22=0;

			count2++;
				mp3(0x33);	  //��Ч31	�������
		    mp3(0x1F); 	  //
		}	
	  }
	 else if(INPUT10==0)							 //���� 7 
	  {
	  	delay_ms(50);
		if(INPUT10==0)
		{
	    	 while(!INPUT10);	
			num1[0]=num1[1];
	    	num1[1]=num1[2];
	    	num1[2]=num1[3];
	    	num1[3]=num1[4];
			num1[4]=num1[5];
			num1[5]=num1[6];
			num1[6]=num1[7];
			num1[7]=7;


			M10=0; 		//
			M11=0;
			M20=0; 		//
			M21=0;
			M30=1;
			M31=0;
			OUT21=0;
			OUT22=0;

			count2++;
			mp3(0x33);	  //��Ч32	
		    mp3(0x20); 	  //
		}	
	  }
	 else if(OUT25==0)							 //���� 8 
	  {
	  	delay_ms(50);
		if(OUT25==0)
		{
	    	 while(!OUT25);	
			num1[0]=num1[1];
	    	num1[1]=num1[2];
	    	num1[2]=num1[3];
	    	num1[3]=num1[4];
			num1[4]=num1[5];
			num1[5]=num1[6];
			num1[6]=num1[7];
			num1[7]=8;

			M10=0; 		//
			M11=0;
			M20=0; 		//
			M21=0;
			M30=0;
			M31=0;
			OUT21=0;
			OUT22=1;

			count2++;
			mp3(0x33);	  //��Ч33	
		    mp3(0x21); 	  //
		}	
	  }

}
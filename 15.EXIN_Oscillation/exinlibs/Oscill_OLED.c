#include "headfile.h"
#include "Oscill_OLED.h"
#include "math.h"
//screen_buf[128][64]
//Oscill Oscill1;

int  Oscill_data_buff[128]={0};
Oscill oscill1;

void Oscill_Title()
{
    static uint8 n;
    n++;
    if(n==20)
    {
        OLED_ShowString(0, 0, "t:");  //首行标签打印
        OLED_ShowString(64, 0,"val:");  //首行标签打印
        n=0;
    }
}


void Oscill_Init(Oscill*oscill,uint8 x_max,uint8 x_min,uint8 y_max,uint8 y_min,uint8 Fre)
{
    OLED_Init();                   //初始化OLED
    //示波器参数初始化
    oscill->P_line=0;//指针默认第0列
    oscill->x_label_max=x_max; //最大行第63行
    oscill->x_label_min=x_min; //最小行第10行
    oscill->y_label_max=y_max;//最大列127列
    oscill->y_label_min=y_min;  //最小列0列
    oscill->num_ini=oscill->y_label_max-oscill->y_label_min;//归一化数值
    oscill->Oscil_damax=1500;//归一化数值
    oscill->Oscil_damin=0;//归一化数值
    oscill->P_line=6;
    oscill->busy=0;
    oscill->Fre=Fre;//归一化数值
}
void Oscill_Show_Menu(Oscill*oscill)
{
    if((oscill->configure&YLABEL_ON))
    {
        OLED_ShowString(0, 2 , "8");
        OLED_PutPixel(0, 2);
        OLED_ShowString(0, 0 , "24");
        OLED_PutPixel(0, 0 );
        OLED_ShowString(0, 4 , "-8");
        OLED_PutPixel(0, 4);
        OLED_ShowString(0, 6 , "-24");
        OLED_PutPixel(0,6);
    }
    if((oscill->configure&TITLE_ON))
    {
        Oscill_Title();
    }
}
void set_Oscill_label(Oscill*oscill,float xlabel,float ylabel)
{
    oscill->Xlabel_Enlarge=xlabel;//x轴坐标倍率
    oscill->Ylabel_Enlarge=ylabel;//y轴坐标倍率
}


void set_Oscill_middle(Oscill*oscill,int middle)
{
    oscill->middle_line=middle;
}

void set_Oscill_Enlar(Oscill*oscill, float Enlarge)
{
    oscill->middle_line=Enlarge;
}

int max=0;
int min=999;
int OLED_DATASHOW=0;
void Oscill_dataget(Oscill*oscill,int data)
{
    int i=0;
    /*
    static uint8 datanum;//最大最小值采样长度

    datanum++;

    if(max<data)
    {
        max=data;
    }
    if(min>data)
    {
        min=data;
    }

    if(datanum==255)
    {
        datanum=0;
        oscill->Oscil_damax=max;
        oscill->Oscil_damin=min;
        max=0;
        min=999;
    }*/

    for(i=127;i>=1;i--)
    {
        Oscill_data_buff[127-i]=Oscill_data_buff[127-i+1];
    }
    //归一化
    if((oscill->Oscil_damax-oscill->Oscil_damin)!=0)
    {
        Oscill_data_buff[127]=(int)(((float)data/(oscill->Oscil_damax-oscill->Oscil_damin))*(oscill->num_ini));//归一化
    }
    else
    {
        if(data<oscill->y_label_max&&data>oscill->x_label_min)
            Oscill_data_buff[127]=data;
    }
    /*
    char tttxt[10]="";
   sprintf(tttxt,"%d\n",oscill->num_ini);
   UART_send_string(EUSCI_A0_BASE,tttxt);*/
}

void screen_buff_clr()
{
    int i=0;
    int j=0;
    for(i=0;i<128;i++)
    {
        for(j=0;j<64;j++)
        {
            screen_buf[i][j]=0;
            if(j<8)
                bmp[i + j*128]=0;
        }
    }
}


void Oscill_updata(Oscill *oscill)
{
    int i,j,k;

    static uint8 num;
    if(num==oscill->Fre)
    {
        for(i=0;i<128;i++)
        {
            if(Oscill_data_buff[i]!=0)
            {
                screen_buf[i][oscill->y_label_max-Oscill_data_buff[i]]=1;
            }

        }
        for(j=oscill->y_label_min;j<oscill->y_label_max;j++)
        {
            screen_buf[oscill->P_line-(j-oscill->y_label_min)/8][j]=1;
        }
        for (j = 0; j < 8; ++j)
            for (i = 0; i < 128; ++i)
            {
                for (k = 0; k < 8; ++k)
                    if (screen_buf[i][j * 8 + k])
                        bmp[i + 128 * j] |= 1 << k;
            }
        OLED_DrawBMP(0, 0, 127, 7, bmp);
        num=0;
    }
    else
        num++;
}


void Oscill_show(Oscill *oscill,int data)//显示当前波形
{
    oscill->busy=1;
    screen_buff_clr();
    Oscill_dataget(oscill,data);
    Oscill_updata(oscill);
    //OLED_ShowNum(50, 0,GET_ADC_VALUE(ADC_CHA), 4, 12);
   // OLED_ShowNum(50, 0,Oscill_data_buff[oscill->P_line], 4, 12); //GET_ADC_VALUE(ADC_CHA)
    oscill->busy=0;
}

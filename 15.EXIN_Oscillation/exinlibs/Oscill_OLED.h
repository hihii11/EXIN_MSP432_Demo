#ifndef _Oscill_OLED_h
#define _Oscill_OLED_h
#ifdef __cplusplus
extern "C"
{
#endif


#define OLED_Y_mid 32
#define OLED_X_mid 64


/************************示波器配置选项**********************/
//#define XLABEL_ON    (0x01<<0)
#define YLABEL_ON    (0x01<<1)
#define TITLE_ON     (0x01<<2)
//#define MAX_SHOW_ON  (0x01<<3)
//#define MIN_SHOW_ON  (0x01<<4)
/************************示波器配置选项**********************/
typedef struct{
    int middle_line;//中线
    float Enlarge;//倍率
    float Xlabel_Enlarge;//x轴分度值
    float Ylabel_Enlarge;//y轴分度值
    uint8 configure;
    uint8 *txt;
    uint8 P_line;
    int x_label_max;//波形显示范围
    int x_label_min;
    int y_label_max;
    int y_label_min;

    uint8 num_ini;//归一化数值
    int   Oscil_damax;//示波器数据输入输出最大值
    int   Oscil_damin;

    uint8 Fre;//示波器刷新周期
    uint8 busy;//繁忙标志位
}Oscill;//示波器结构体定义
extern Oscill oscill1;
extern int  Oscill_data_buff[128];


//void Oscill_test1();
void Oscill_Show_Menu(Oscill*oscill);
void Oscill_Init(Oscill*oscill,uint8 x_max,uint8 x_min,uint8 y_max,uint8 y_min,uint8 Fre);
void Oscill_Title();
void set_Oscill_label(Oscill*oscill,float xlabel,float ylabel);
void set_Oscill_middle(Oscill*oscill,int middle);
void set_Oscill_Enlar(Oscill*oscill, float Enlarge);
void Oscill_dataget(Oscill*oscill,int data);
void Oscill_show(Oscill *oscill,int data);//显示当前波形
//void Oscill_test2();
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_GPIO_H__

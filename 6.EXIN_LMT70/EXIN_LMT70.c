/*-----------------------------------------------------------------------------------------------------
【平    台】CCS
【适 用 单 片 机】msp432P401R
【底 层 库】TIVA WARE /msp432p4xx
【开 发】e芯工作室
/*@@ 库仅供参考 后果自负
 *
 * 版本 v1.0
 * 时间 2020年10月23日22:29:47
-------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------
LMT70温度传感器
端口:P5.5
-------------------------------------------------------------------------------------------------------*/
#include "exinlibs\headfile.h"
void OLED_SHOWTEMPTURE()
{
    OLED_ShowString(0,0,"TMP:");
    OLED_ShowNum(43,0,  LMT_DataHandle(),4,16);
}
void main()
{
    system_init(0);
    OLED_Init();

    LMT_Init();
    while(1)
    {
        OLED_SHOWTEMPTURE();
    }
}

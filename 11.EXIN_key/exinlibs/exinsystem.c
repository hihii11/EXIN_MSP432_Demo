/*-----------------------------------------------------------------------------------------------------
【平    台】CCS
【适 用 单 片 机】msp432P401R
【底 层 库】TIVA WARE /msp432p4xx
【开 发】e芯工作室
/*@@ 库仅供参考 后果自负
 *
 * 版本 v1.0
 * 时间 2019年1月23日22:29:47
-------------------------------------------------------------------------------------------------------*/
#include"headfile.h"
#include"exinsystem.h"
long int sysc=0;
long int systim=0;
/***********************************/
/* set_clock_period
 *
 * 计数器LOAD寄存器置数
 */
/**********************************/
void set_clock_period()
{
    SysTick->LOAD =0xFFFFFF;
}
/***********************************/
/* systic_init
 *
 * 滴答计时器初始化
 */
/**********************************/
void systic_init()
{
    set_clock_period();
    SysTick->CTRL= SYSTIC_CONFIGURE;
    SysTick->VAL = 0x01;
    MPU->CTRL = MPU_CTRL_ENABLE_Msk | MPU_CTRL_PRIVDEFENA_Msk;
    __enable_interrupt();
    systic_clr();
    systic_end();

}
/***********************************/
/* systic_start
 *
 * 开始计时
 *
 *可用于记录高电平或低电平持续时长
 *与systic_end 配合使用
 */
/**********************************/
void systic_start()
{
    systic_clr();
    SysTick->LOAD =0xFFFFFF;
    SysTick->CTRL= SYSTIC_CONFIGURE;
}

/***********************************/
/* systic_end
 *
 * 停止计时
 *
 *可用于记录高电平或低电平持续时长
 *与systic_start 配合使用
 */
/**********************************/
void systic_end()
{
    SysTick->CTRL ^= SysTick->CTRL;
}
/***********************************/
/*  systic_read
 *
 * 读取当前计时
 *
 * 参数可填:us ms s,分别以us ms s为单位
 * 返回当前计时值
 */
/**********************************/
int systic_read(unsigned int ss)
{
    static long int sys_us;
    sys_us=((0x1000000-SysTick->VAL)+0x1000000 * systim )/(F_Div);
    switch(ss)
    {
        case(us):return sys_us;
        case(ms):return sys_us/1000;
        case(s): return sys_us/1000/1000;
        default: return 0;
    }
}
/***********************************/
/* systic_clr
 *
 * 清零当前计时值
 */
/**********************************/
void systic_clr()
{
    SysTick->VAL = 0x01; systim=0;
}


/***********************************/
/* system_init
 *
 * 系统初始化，EN=0不使用滴答计时器
 *             EN=1使用滴答计时器
 */
/**********************************/
char EN;//滴答计时器使能
void system_init(char EN)
{
    WDT_A->CTL = WDT_A_CTL_PW |             // 关闭看门狗
    WDT_A_CTL_HOLD;
    delay_ms(100);//等待外设上电
    if(EN)
    {
        systic_init();
    }
}
/***********************************/
/* SysTick_Handler
 *
 * SysTick->VAL减为0触发一次中断
 */
/**********************************/
void SysTick_Handler(void)
{
    systim++;
}

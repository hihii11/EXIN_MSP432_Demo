/*-----------------------------------------------------------------------------------------------------
��ƽ    ̨��CCS
���� �� �� Ƭ ����msp432P401R
���� �� �⡿TIVA WARE /msp432p4xx
���� ����eо������
/*@@ ������ο� ����Ը�
 *
 * �汾 v1.0
 * ʱ�� 2019��1��23��22:29:47
-------------------------------------------------------------------------------------------------------*/
#include"headfile.h"
#include"exinsystem.h"
long int sysc=0;
long int systim=0;
/***********************************/
/* set_clock_period
 *
 * ������LOAD�Ĵ�������
 */
/**********************************/
void set_clock_period()
{
    SysTick->LOAD =0xFFFFFF;
}
/***********************************/
/* systic_init
 *
 * �δ��ʱ����ʼ��
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
 * ��ʼ��ʱ
 *
 *�����ڼ�¼�ߵ�ƽ��͵�ƽ����ʱ��
 *��systic_end ���ʹ��
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
 * ֹͣ��ʱ
 *
 *�����ڼ�¼�ߵ�ƽ��͵�ƽ����ʱ��
 *��systic_start ���ʹ��
 */
/**********************************/
void systic_end()
{
    SysTick->CTRL ^= SysTick->CTRL;
}
/***********************************/
/*  systic_read
 *
 * ��ȡ��ǰ��ʱ
 *
 * ��������:us ms s,�ֱ���us ms sΪ��λ
 * ���ص�ǰ��ʱֵ
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
 * ���㵱ǰ��ʱֵ
 */
/**********************************/
void systic_clr()
{
    SysTick->VAL = 0x01; systim=0;
}


/***********************************/
/* system_init
 *
 * ϵͳ��ʼ����EN=0��ʹ�õδ��ʱ��
 *             EN=1ʹ�õδ��ʱ��
 */
/**********************************/
char EN;//�δ��ʱ��ʹ��
void system_init(char EN)
{
    WDT_A->CTL = WDT_A_CTL_PW |             // �رտ��Ź�
    WDT_A_CTL_HOLD;
    delay_ms(100);//�ȴ������ϵ�
    if(EN)
    {
        systic_init();
    }
}
/***********************************/
/* SysTick_Handler
 *
 * SysTick->VAL��Ϊ0����һ���ж�
 */
/**********************************/
void SysTick_Handler(void)
{
    systim++;
}

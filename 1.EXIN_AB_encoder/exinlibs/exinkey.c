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
#include "headfile.h"
#include "exinkey.h"
/***********************************/
/* key_init
 *
 * ������ʼ��
 *
 *
 *key_init(uint8 key1|key2|key3|key4)//�ĸ�����ȫ����ʼ��
 *
 */
/**********************************/
void key_init(uint8 key)
{
    if(key&KEY1 )
    {
        gpio_init(GPIO_PORT_P8,GPIO_PIN5,GPO,1);
    }
    else if(key&KEY2 )
    {
        gpio_init(GPIO_PORT_P9,GPIO_PIN0,GPO,1);
    }
    else if(key&KEY3 )
    {
        gpio_init(GPIO_PORT_P8,GPIO_PIN4,GPO,1);
    }
    else if(key&KEY4 )
    {
        gpio_init(GPIO_PORT_P8,GPIO_PIN2,GPO,1);
    }
}

/***********************************/
/*  key_get()
 *
 * ����״̬��ȡ
 *
 *
 *key_init(uint8 key1)//�ĸ�����ȫ����ʼ��
 *
 */
/**********************************/
uint8 key_get(uint8 key)
{
        if(key&KEY1 )
        {
            return gpio_get(GPIO_PORT_P8,GPIO_PIN5);
        }
        else if(key&KEY2 )
        {
            return gpio_get(GPIO_PORT_P9,GPIO_PIN0);
        }
        else if(key&KEY3 )
        {
            return gpio_get(GPIO_PORT_P8,GPIO_PIN4);
        }
        else if(key&KEY4 )
        {
            return gpio_get(GPIO_PORT_P8,GPIO_PIN2);
        }
}

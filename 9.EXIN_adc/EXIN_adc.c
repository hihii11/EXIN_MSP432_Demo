/*-----------------------------------------------------------------------------------------------------
��ƽ    ̨��CCS
���� �� �� Ƭ ����msp432P401R
���� �� �⡿TIVA WARE /msp432p4xx
���� ����eо������
/*@@ ������ο� ����Ը�
 *
 * �汾 v1.0
 * ʱ�� 2020��10��23��22:29:47
-------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------
ADC������
-------------------------------------------------------------------------------------------------------*/
#include "exinlibs\headfile.h"

void main()
{
    system_init(0);
    ADC_TEST();
    while(1);
}
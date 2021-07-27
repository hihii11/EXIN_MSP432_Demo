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
volatile uint8_t UART3_RXDat= 0;
volatile uint8_t UART2_RXDat= 0;
volatile uint8_t UART0_RXDat= 0;
/*******************/
/*���ڲ�������
 *
 * ��ѡ����
 * 115200��
 *   BRDIV_115200,
    UCxBRF_115200,
    UCxBRS_115200,
    9600��
 *   BRDIV_9600,
    UCxBRF_9600,
    UCxBRS_9600,
 */
/********************/
const eUSCI_UART_Config  UART0 =
{
    EUSCI_A_UART_CLOCKSOURCE_SMCLK,
    BRDIV_115200,//115200������ �������������ò鿴exinuart.h
    UCxBRF_115200,
    UCxBRS_115200,
    EUSCI_A_UART_NO_PARITY,
    EUSCI_A_UART_LSB_FIRST,
    EUSCI_A_UART_ONE_STOP_BIT,
    EUSCI_A_UART_MODE,
    EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION,
};
void UART0_init()
{
        FlashCtl_setWaitState(FLASH_BANK0, 2);
        FlashCtl_setWaitState(FLASH_BANK1, 2);
        PCM_setCoreVoltageLevel(PCM_VCORE1);
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_24);
        GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
        UART_initModule(EUSCI_A0_BASE, & UART0);
        UART_enableModule(EUSCI_A0_BASE);
        UART_enableInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
        UART_enableInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_TRANSMIT_INTERRUPT  );
        Interrupt_enableInterrupt(INT_EUSCIA0);
}
/*******************/
/*���ڲ�������
 *
 * ��ѡ����
 * 115200��
 *   BRDIV_115200,
    UCxBRF_115200,
    UCxBRS_115200,
    9600��
 *   BRDIV_9600,
    UCxBRF_9600,
    UCxBRS_9600,
 */
/********************/
const eUSCI_UART_Config  UART2 =
{
    EUSCI_A_UART_CLOCKSOURCE_SMCLK,
    BRDIV_115200,//115200������ �������������ò鿴exinuart.h
    UCxBRF_115200,
    UCxBRS_115200,
    EUSCI_A_UART_NO_PARITY,
    EUSCI_A_UART_LSB_FIRST,
    EUSCI_A_UART_ONE_STOP_BIT,
    EUSCI_A_UART_MODE,
    EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION,
};
/******************************

 *****************************/
void UART2_init()
{
       FPU_enableModule();
       GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_PJ,GPIO_PIN3 | GPIO_PIN2, GPIO_PRIMARY_MODULE_FUNCTION);
       CS_setExternalClockSourceFrequency(32000,48000000);
       PCM_setPowerState(PCM_AM_DCDC_VCORE1);
       FlashCtl_setWaitState(FLASH_BANK0, 3);
       FlashCtl_setWaitState(FLASH_BANK1, 3);
       CS_startHFXT(false);
       CS_initClockSignal(CS_MCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_1);
       CS_initClockSignal(CS_HSMCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_1);
       CS_initClockSignal(CS_SMCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_2);
       GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3, GPIO_PIN2| GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
       UART_initModule(EUSCI_A2_BASE, & UART2);
       UART_enableModule(EUSCI_A2_BASE);
       UART_enableInterrupt(EUSCI_A2_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
       UART_enableInterrupt(EUSCI_A2_BASE, EUSCI_A_UART_TRANSMIT_INTERRUPT);
       Interrupt_enableInterrupt(INT_EUSCIA2);
}

const eUSCI_UART_Config UART3 =
{
    EUSCI_A_UART_CLOCKSOURCE_SMCLK,
    BRDIV_9600,//115200������ �������������ò鿴exinuart.h
    UCxBRF_9600,
    UCxBRS_9600,
    EUSCI_A_UART_NO_PARITY,
    EUSCI_A_UART_LSB_FIRST,
    EUSCI_A_UART_ONE_STOP_BIT,
    EUSCI_A_UART_MODE,
    EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION,
};

/*******************/
/*���ڲ�������
 *
 * ��ѡ����
 * 115200��
 *   BRDIV_115200,
    UCxBRF_115200,
    UCxBRS_115200,
    9600��
 *   BRDIV_9600,
    UCxBRF_9600,
    UCxBRS_9600,
 */
/********************/
void UART3_init()
{
       FlashCtl_setWaitState(FLASH_BANK0, 2);
       FlashCtl_setWaitState(FLASH_BANK1, 2);
       PCM_setCoreVoltageLevel(PCM_VCORE1);
       CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_24);
       GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P9, GPIO_PIN6 | GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);
       UART_initModule(EUSCI_A3_BASE, & UART3);
       UART_enableModule(EUSCI_A3_BASE);
       UART_enableInterrupt(EUSCI_A3_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
       UART_enableInterrupt(EUSCI_A3_BASE, EUSCI_A_UART_TRANSMIT_INTERRUPT  );
       Interrupt_enableInterrupt(INT_EUSCIA3);
}

/******************************
 * UART_send_string
 *
 * ����һ���ַ���
 *
 *****************************/
void UART_send_string(uint32_t moduleInstance,char*txt)
{
    int i;
    for(i=0;txt[i];i++)
    {
        delay_us(500);
        UART_transmitData(moduleInstance,txt[i]);
    }
}
/******************************
 * UART_send_string
 *
 * ����һ��8λ����
 *****************************/
void UART_send_Num(uint32_t moduleInstance,unsigned int num)
{
        UART_transmitData(moduleInstance,num);
}
void EUSCIA0_IRQHandler(void)
{
    uint32_t status = UART_getEnabledInterruptStatus(EUSCI_A0_BASE);
    UART_clearInterruptFlag(EUSCI_A0_BASE, status);

    if (status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
    {
          UART0_RXDat = UART_receiveData(EUSCI_A0_BASE);
    }
}

void EUSCIA2_IRQHandler(void)
{
    uint32_t status = UART_getEnabledInterruptStatus(EUSCI_A2_BASE);
    UART_clearInterruptFlag(EUSCI_A2_BASE, status);

    //�����ж�,uart���յ��ֽ�,�����жϱ�־λ����1
    if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
    {
        UART_clearInterruptFlag(EUSCI_A2_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG);
        /**********����***************/
    }
}


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
#ifndef _exinuart_h
#define _exinuart_h
#ifdef __cplusplus
extern "C"
{
#endif

/******************
 * 常用波特率配置
 *****************/
/*
#define UART_HIGH_115200 0x06
#define UART_LOW_115200 0x0080
#define UART_HIGH_9600 0x4E
#define UART_LOW_9600 0x0020
#define UART_HIGH_4800 0x9C
#define UART_LOW_4800 0x0040*/
#define BRDIV_115200        13
#define UCxBRF_115200       0
#define UCxBRS_115200       37
//9600
#define BRDIV_9600          156
#define UCxBRF_9600         0
#define UCxBRS_9600         12
//4800
#define BRDIV_4800          312
#define UCxBRF_4800         1
#define UCxBRS_4800         7
extern void UART_send_string(uint32_t moduleInstance,char*txt);
extern void UART_send_Num(uint32_t moduleInstance,unsigned int num);
extern void UART0_init();
extern void UART2_init();
extern void UART0_TEST();
extern void UART3_init();
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_GPIO_H__

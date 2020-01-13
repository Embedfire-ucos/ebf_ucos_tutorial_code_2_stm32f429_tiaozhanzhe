/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   用1.5.1版本库建的工程模板
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
	
#include "stm32f4xx.h"
#include "bsp_led.h"



static void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}


/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main ( void )
{	
	LED_GPIO_Config ();	          //初始化 LED
 

	while ( 1 )
	{
		LED1_ON;			  // 亮
		Delay ( 0x0FFFFFF );
		LED1_OFF;		    // 灭

		LED2_ON;			  // 亮
		Delay ( 0x0FFFFFF );
		LED2_OFF;		    // 灭

		LED3_ON;			  // 亮
		Delay ( 0x0FFFFFF );
		LED3_OFF;		    // 灭	   
		
	}

}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

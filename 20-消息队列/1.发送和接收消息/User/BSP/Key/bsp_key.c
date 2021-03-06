#include "bsp_key.h" 
#include <includes.h>   //使用uC/OS内核机制须包含该头文件



static void Key1_Config ( void );
static void Key2_Config ( void );
//static void Key_Delay   ( volatile uint32_t ulCount );



void Key_Initial ( void )
{
	Key1_Config ();
	Key2_Config ();
}


static void Key1_Config ( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	

	KEY1_GPIO_xClock_FUN ( KEY1_GPIO_CLK, ENABLE );
	
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN; 

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 

  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init ( KEY1_GPIO_PORT, & GPIO_InitStructure );
}


static void Key2_Config ( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	

	KEY2_GPIO_xClock_FUN ( KEY2_GPIO_CLK, ENABLE );
	
	GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN; 

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 

  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init ( KEY2_GPIO_PORT, & GPIO_InitStructure );
}


//static void Key_Delay ( volatile uint32_t ulCount )
//{
//	for(; ulCount != 0; ulCount--);
//} 


/**
  * @brief  检测按键是否被单击
  * @param  GPIOx ：按键所在的端口
  * @param  GPIO_Pin ：按键所在的管脚
  * @param  ucPushState ：按键被按下时的电平极性
  *   该参数为以下值之一：
  *     @arg 1 :高电平
  *     @arg 0 :低电平
  * @param  pKeyPress ：用于存放按键是否被按下过，须是静态变量	
  * @retval 按键是否被单击
	*   该返回值为以下值之一：
  *     @arg 1 :按键被单击
  *     @arg 0 :按键未被单击
  */
uint8_t Key_Scan ( GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, uint8_t ucPushState, uint8_t * pKeyPress )
{			
	uint8_t ucKeyState, ucRet = 0;
	
	OS_ERR      err;
	
	
	ucKeyState = GPIO_ReadInputDataBit ( GPIOx, GPIO_Pin );
	
	if ( ucKeyState == ucPushState )
	{
//		Key_Delay( 10000 );	         //改成uC/OS的延时函数
		OSTimeDlyHMSM ( 0, 0, 0, 20, OS_OPT_TIME_DLY, & err );
		
		ucKeyState = GPIO_ReadInputDataBit ( GPIOx, GPIO_Pin );
		
		if ( ucKeyState == ucPushState )
			* pKeyPress = 1;
	}

	if ( ( ucKeyState != ucPushState ) && ( * pKeyPress == 1 ) )
	{
		ucRet = 1;
		* pKeyPress = 0;
	}
	
	return ucRet;
	
}


/*********************************************END OF FILE**********************/


#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"

#include "FreeRTOS.h"
#include "task.h"

//task prototype
void TASK1(void *pv);
void TASK2(void *pv);
void main()
{
	PORT_voidInit();
	CLCD_voidInit();

	//create the tasks
	xTaskCreate(&TASK1,0,100,0,0,0);
	xTaskCreate(&TASK2,0,100,0,1,0);

	vTaskStartScheduler();
	while(1)
	{

	}
}

void TASK1(void *pv)
{
	while(1)
	{
		CLCD_voidSendString("taher");
			vTaskDelay(1000);
	}
}
void TASK2(void *pv)
{
	while(1)
	{
		CLCD_voidSendString("111111");
		vTaskDelay(2000);
	}
}


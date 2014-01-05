/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f4_system.h"
#include "stm32f4_sdio.h"
#include "QCopterRC.h"
#include "QCopterRC_board.h"
#include "QCopterRC_transport.h"
#include "module_nrf24l01.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
void SysTick_Handler( void )
{
//  static u16 SysTick_Cnt = 0;

//  /* Time Count */
//  SysTick_Cnt++;
//  if(SysTick_Cnt == 100) {
//    SysTick_Cnt = 0;
//    Time_Sec++;
//    if(Time_Sec == 60) {	// 0~59
//      Time_Sec = 0;
//      Time_Min++;
//      if(Time_Sec == 60)
//      Time_Min = 0;
//    }
//  }
  KeyBoard_ReadKEY();
}
/*=====================================================================================================*/
/*=====================================================================================================*/
void EXTI9_5_IRQHandler( void )
{
  if(EXTI_GetITStatus(EXTI_Line7) != RESET) {
    if(FSM_State != FSM_TX) {
      nRF_Recv_IRQ();
      Transport_Recv(RxBuf);
    }
    EXTI_ClearITPendingBit(EXTI_Line7);
  }
}
/*=====================================================================================================*/
/*=====================================================================================================*/
void SDIO_IRQHandler( void )
{
  SD_ProcessIRQSrc();
}
/*=====================================================================================================*/
/*=====================================================================================================*/
void DMA2_Stream3_IRQHandler( void )
{
  SD_ProcessDMAIRQ();
}
/*=====================================================================================================*/
/*=====================================================================================================*/
void HardFault_Handler( void )
{
  while(1);
}
void MemManage_Handler( void )
{
  while(1);
}
void BusFault_Handler( void )
{
  while(1);
}
void UsageFault_Handler( void )
{
  while(1);
}
void SVC_Handler( void )
{
  while(1);
}
void DebugMon_Handler( void )
{
  while(1);
}
void PendSV_Handler( void )
{
  while(1);
}
void NMI_Handler( void )
{
  while(1);
}
/*=====================================================================================================*/
/*=====================================================================================================*/

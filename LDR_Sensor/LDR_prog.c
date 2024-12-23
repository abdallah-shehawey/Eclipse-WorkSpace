/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Abdelmoemen Shehawey
 *  Layer  : HAL
 *  SWC    : LDR
 *
 */

#include "STD_TYPES.h"
#include "STD_MACROS.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

#include "LDR_interface.h"
#include "LDR_private.h"
#include "LDR_config.h"

u8 LDR_u8GetLightPres                  (LDR_Config * LDR, u8 *Copy_u8LightPres     )
{
  u8 Local_u8ErrorState = OK;

  u16 Local_u16ADCResult;
  u16 Local_u16AnalogSignal;

  /* ADC Digital Reading */
  ADC_u8GetResultSync(LDR->Copy_u8LDRChannel, &Local_u16ADCResult);

  /* Check for ADC Resolution */
  if (LDR->Copy_u8ADCRes == ADC_RES_10_BIT)
  {
    *Copy_u8LightPres =  (Local_u16ADCResult / 1024.0) * 100 ;
  }
  else if (LDR->Copy_u8ADCRes == ADC_RES_8_BIT)
  {
    *Copy_u8LightPres =  (Local_u16ADCResult / 256.0) * 100 ;
  }

  return Local_u8ErrorState;
}

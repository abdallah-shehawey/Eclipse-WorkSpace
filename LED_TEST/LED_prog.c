/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LED_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Abdelmoemen Shehawey
 *  Layer  : HAL
 *  SWC    : LED
 *
 */

#include "STD_MACROS.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "LED_interface.h"
/*___________________________________________________________________________________________________________________*/

/*
* Breif : This Function initialize the pin which connected to led as output pin
* Parameters :
            => struct has the led port , pin, status
* return : void
*/
void LED_vInit(LED_config LED_Configutation)
{
  DIO_enumSetPinDir(LED_Configutation.PortName, LED_Configutation.PinNumber, DIO_PIN_OUTPUT);
}

/*___________________________________________________________________________________________________________________*/

/*
* Breif : This Function set high on led pin ( led on )
* Parameters :
            => struct has the led port , pin, status
* return : void
*/
void LED_vTurnOn(LED_config LED_Configutation)
{
  if (LED_Configutation.ActiveState == ACTIVE_HIGH)
  {
  DIO_enumWritePinVal(LED_Configutation.PortName, LED_Configutation.PinNumber, DIO_PIN_HIGH);
  }
  else if(LED_Configutation.ActiveState == ACTIVE_LOW)
  {
    DIO_enumWritePinVal(LED_Configutation.PortName, LED_Configutation.PinNumber, DIO_PIN_LOW);
  }
}

/*___________________________________________________________________________________________________________________*/

/*
* Breif : This Function set low on led pin ( led off )
* Parameters :
             => struct has the led port , pin , status
* return : void
*/
void LED_vTurnOff(LED_config LED_Configutation)
{
  if (LED_Configutation.ActiveState == ACTIVE_HIGH)
  {
    DIO_enumWritePinVal(LED_Configutation.PortName, LED_Configutation.PinNumber, DIO_PIN_LOW);
  }
  else if (LED_Configutation.ActiveState == ACTIVE_LOW)
  {
    DIO_enumWritePinVal(LED_Configutation.PortName, LED_Configutation.PinNumber, DIO_PIN_HIGH);
  }
}

/*___________________________________________________________________________________________________________________*/

/*
* Breif : This Function toggle led pin
* Parameters :
             => struct has the led port , pin , status
* return : void
*/
void LED_vTog(LED_config LED_Configutation)
{
  DIO_enumTogglePinVal(LED_Configutation.PortName, LED_Configutation.PinNumber);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
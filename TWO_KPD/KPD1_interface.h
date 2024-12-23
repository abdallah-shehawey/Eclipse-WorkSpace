/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Abdelmoemen Shehawey
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */

#ifndef KPD1_INTERFACE_H_
#define KPD1_INTERFACE_H_

#define NOTPRESSED  0xFF

void KPD1_vInit       (void);
u8   KPD1_u8GetPressed(void);

#endif /* KPD1_INTERFACE_H_ */

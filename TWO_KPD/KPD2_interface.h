/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Abdelmoemen Shehawey
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */

#ifndef KPD2_INTERFACE_H_
#define KPD2_INTERFACE_H_

#define NOTPRESSED  0xFF

void KPD2_vInit       (void);
u8   KPD2_u8GetPressed(void);

#endif /* KPD2_INTERFACE_H_ */

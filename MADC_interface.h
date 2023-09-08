/*********************************************************************************
* Author   : 	Ali Mamdouh
*
* Version  : 	V1.1
*
* Date     : 	18 AUG 2023
*
* File Name: 	MADC_interface.h
*
* Description: 	ADC file.h
*
*********************************************************************************/


/**
 * \mainpage
 * \section Brief
 * This is file includes headers and functions for thhe ADC
 * \section Details
 * We have five functions explaind in the SoftwareContext
 * \section SoftwareContext
 * This service initialize adc with its diffrent modes, enable adc, select continous or single conversion,converting and reading adc value.
 *
 * \section Creation
 * @startuml
 * json "<b>Creation" as J {
 * "Name": "Ali Mamdouh",
 * "Date": "8/26/2023",
 * "Driver type": "ADC",
 * "Version": "V1.1" 
 * }
 * @enduml
 
 *
 * \section Refrences
 * @startuml
 * json "<b>Refrences" as J {
 * "First refrence": "Reference manual STM32F103xx",
 * "Second refrence": "Programming manual Cortex®-M3 ",
 * "Third refrence": "Web page plantuml.com"
 * }
 * @enduml
 *
 * \section Reviews
 * @startuml
 * json "<b>Reviews" as J {
 * "Ahmed El-shamy": "Waiting for review",
 * "Karim Ahmed": "Accepted ",
 * "Mahmoud Abou-Yousef": "Waiting for review"
 * }
 * @enduml
 *
 * \section List_Of_Approval
 * @startuml
 * json "<b>List of approval" as J {
 * "Ahmed El-shamy": "Waiting for approve",
 * "Karim Ahmed": "Approved ",
 * "Mahmoud Abou-Yousef": "Waiting for approve"
 * }
 * @enduml

 *
 * \section Functions_Usage 
 * @startuml
 * agent ADC
 * ADC --> MADC_VidInit #line:green;line.bold;text:green  : Settable function 
 * ADC --> MADC_VidEnableState #line:green;line.bold;text:green  : Settable function
 * ADC --> MADC_VidDisableState #line:green;line.bold;text:green  : Settable function 
 * ADC --> MADC_VidModeSelect #line:green;line.bold;text:green  : Settable function
 * ADC --> MADC_VidStartConversion #line:green;line.bold;text:green  : Settable function
 * ADC --> MADC_VidGetSWVersion #line:blue;line.bold;text:blue  : Application function
 * ADC --> MADC_VidReadChannel #line:blue;line.bold;text:blue  : Application function 
 * @enduml
 *
 */


#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
#include "STD_TYPES.h"

void MADC_VidGetSWVersion(SW_Ver *VersionInfo);
void MADC_VidInit();
void MADC_VidEnableState(MADC_Peripheral PeripheralID);
void MADC_VidDisableState(MADC_Peripheral PeripheralID);
void MADC_VidModeSelect(MADC_Peripheral PeripheralID,
		MADC_Conversion ConversionType);
void MADC_VidStartConversion(MADC_Peripheral PeripheralID);
u16 MADC_VidReadChannel(MADC_Peripheral PeripheralID, MADC_Channel Channel,
		MADC_SampleTime SampleTime_Cycles);
#endif

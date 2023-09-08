/*********************************************************************************
* Author   : 	Ahmed Sayed
*
* Version  : 	V1.1
*
* Date     : 	18 AUG 2023
*
* File Name: 	ADC.c
*
* Description: 	ADC file.c
*
*********************************************************************************/

/**
 * \file ADC_file.c
 * \section Brief
 * This is ADC services Prg
 * \section Details
 * The module implement ADC functions
 * \section Scope
 * Public
 *
 *
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_private.h"
#include "RCC_cfg.h"
#include "RCC_interface.h"
#include "MADC_private.h"
#include "MADC_cfg.h"
#include "MADC_interface.h"
#include "DET.h"


/***********************************[1]***********************************************
 * Service Name: MADC_VidGetSWVersion
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): VersionInfo
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Set the Software Version of ADC_Driver.
 ************************************************************************************/
 
 /**
 * \section Service_Name
 * MADC_VidGetSWVersion
 *
 * \section Description
 *  Store in a structure the version of ADC driver.
 * 
 * \section Req_ID
 * ADC_0x01
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Reentrant
 *
 * \section Parameters
 * \param[in] None
 * \param[inout] None
 * \param[out] SW_Ver (pointer to struct)\ VersionInfo--->Hold the Task's minor and major versions
 *
 * \section Return_value
 * None
 *
 * \section Rational
 * Set the Software Version of ADC_Driver.
 *
 * 
 * \section Activity_Diagram
 *
 * @startuml 
 *   start
 *  :Take major version;
 *  :Take minor version;
 * end
 * @enduml
 *
 *
 *
 * \section Sequence_Diagram
 *
 * @startuml
 * MADC_VidGetSWVersion_function -> MADC_private_file: MADC_SW_MAJOR_VERSION Enumerator value Request
 * MADC_private_file --> MADC_VidGetSWVersion_function: MADC_SW_MAJOR_VERSION Enumerator value Response
 * MADC_VidGetSWVersion_function -> MADC_private_file: MADC_SW_MINOR_VERSION Enumerator value Request
 * MADC_private_file --> MADC_VidGetSWVersion_function: MADC_SW_MINOR_VERSION Enumerator value Response
 * @enduml
*/
 
 
 
 

#if API_ADC_GET_SET_VERSION == API_ENABLE
void MADC_VidGetSWVersion(SW_Ver *VersionInfo) {

	VersionInfo->Major = MADC_SW_MAJOR_VERSION; /*assign value*/
	VersionInfo->Minor = MADC_SW_MINOR_VERSION;
}
#endif

/***********************************[2]***********************************************
 * Service Name: MADC_VidInit
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): None
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Set ADC clock prescaler & Alignement of data Options.
 ************************************************************************************/
 
 
 /**
 * \section Service_Name
 * MADC_VidInit
 *
 * \section Description
 * This function initializes the ADC by configuring the clock prescaler,
 * enabling the ADC clock for the specified peripheral, setting the data
 * alignment, and configuring the ADC channel.
 * 
 * \section Req_ID
 * ADC_0x02
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Reentrant
 *
 * \section Parameters
 * \param[in] None
 * \param[inout] None
 * \param[out] None
 *
 * \section Return_value
 * None
 *
 * \section Rational
 * initialize ADC_Driver.
 *
 * 
 * \section Activity_Diagram
 *
 * @startuml 
 *   start
 *  :ADC clock prescaler(based on configration);
 *  :Choose which adc to adjust(based on configration);
 *  :Select ADC Data Alignement;
 * @enduml
 *
 *
 *
 * \section Sequence_Diagram
 *
 * @startuml
 * MADC_VidInit_function -> BIT_MATH_file: CLR_BIT Macro Request
 * BIT_MATH_file --> MADC_VidInit_function: Clearing dedecated bit Response
 * MADC_VidInit_function -> BIT_MATH_file: SET_BIT Macro Request
 * BIT_MATH_file --> MADC_VidInit_function: Setting dedecated bit Response
 * @enduml
*/


#if API_ADC_INIT == API_ENABLE
void MADC_VidInit() {
	/*ADC clock prescaler*/
#if ADC_clock_prescaler == PCLK2_divided_by_2
	CLR_BIT(RCC->CFGR, ADCPRE1);
	CLR_BIT(RCC->CFGR, ADCPRE2);
#elif ADC_clock_prescaler == PCLK2_divided_by_4,
  SET_BIT(RCC->CFGR, ADCPRE1);
  CLR_BIT(RCC->CFGR, ADCPRE2);
#elif ADC_clock_prescaler == PCLK2_divided_by_6,
  CLR_BIT(RCC->CFGR, ADCPRE1);
  SET_BIT(RCC->CFGR, ADCPRE2);
#elif ADC_clock_prescaler == PCLK2_divided_by_8,
  SET_BIT(RCC->CFGR, ADCPRE1);
  SET_BIT(RCC->CFGR, ADCPRE2);
#endif

#if ADC1_STATE == ENABLE_ADC

#if ADC1_DATA_ALIGN == RIGHT_ALIGNEMENT
	CLR_BIT(ADC_1->CR2, ALIGN);

#elif ADC1_DATA_ALIGN == LEFT_ALIGNEMENT,
	SET_BIT(ADC_1->CR2, ALIGN);
	#endif
#endif

#if ADC2_STATE == ENABLE_ADC
#if ADC2_DATA_ALIGN == RIGHT_ALIGNEMENT
	CLR_BIT(ADC_2->CR2, ALIGN);
#elif ADC2_DATA_ALIGN == LEFT_ALIGNEMENT,
SET_BIT(ADC_2->CR2, ALIGN);
#endif
#endif

#if ADC3_STATE == ENABLE_ADC
#if ADC3_DATA_ALIGN == RIGHT_ALIGNEMENT
	CLR_BIT(ADC_3->CR2, ALIGN);
#elif ADC3_DATA_ALIGN == LEFT_ALIGNEMENT,
SET_BIT(ADC_3->CR2, ALIGN);
#endif
#endif

}
#endif

/***********************************[3]***********************************************
 * Service Name: MADC_EnableState
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): PeripheralID
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Enable ADC
 ************************************************************************************/
 
 
 /**
 * \section Service_Name
 * MADC_EnableState
 *
 * \section Description
 * This function Set the enable bit in CR2 register for ADC1 or ADC2 or ADC3 based on the input enum value.
 * 
 * \section Req_ID
 * ADC_0x03
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Reentrant
 *
 * \section Parameters
 * \param[in]  MADC_Peripheral (enum)\ PeripheralID--->Hold which ADC to enable
 * \param[inout] None
 * \param[out] None
 *
 * \section Return_value
 * None
 *
 * \section Rational
 * Enable required ADC.
 *
 * \section Activity_Diagram
 *
 * @startuml 
 * start
 *   switch (Which ADC to turn on?)
 *   case ( condition ADC1 )
 *    :ADC ON;
 *    :Wait 100ms for stabillity;
 *    #green:ADC ON(again);
 *
 *   case ( condition ADC2 )
 *    :ADC ON;
 *    :Wait 100ms for stabillity;
 *    #green:ADC ON(again);
 *
 *   case ( condition ADC3 )
 *    :ADC ON;
 *    :Wait 100ms for stabillity;
 *    #green:ADC ON(again);
 *
 *   case ( default )
 *     #red:Det_ReportError(infinite loop);
 *     end   
 * endswitch
 * end
 * @enduml
 *
 *
 *
 * \section Sequence_Diagram
 *
 * @startuml
 *
 * == In_Range_Switching ==
 *
 * "MADC_VidEnableState\nFunction" -> "SET_BIT\nMacro": Register and required bit to be set Request
 * "SET_BIT\nMacro" -[#0000FF]-> "MADC_VidEnableState\nFunction": Setting dedecated bit Response
 *
 * == OutOf_Range_Switching ==
 *
 * "MADC_VidEnableState\nFunction" -[#red]> "Det_ReportError\nFunction": ADC_MODULE_ID, INVALID_ADC_PERIPHERAL
 *
 * @enduml
 *
 *
 *
 * \section Timing_Diagram
 *
 * @startuml
 * robust "ADC" as ADC
 * concise "Function" as Func
 *
 * Func is running
 * ADC is idle
 * 
 * @Func
 * 0 is Waiting
 * Func -> ADC : Enable  
 * +100 is running
 *
 * @ADC
 * 0 is Processing
 * +100 is idle
 * @enduml
 *
*/

 
 

#if API_ADC_ENABLE_STATE == API_ENABLE
void MADC_VidEnableState(MADC_Peripheral PeripheralID) {

	switch (PeripheralID) {
	case ADC1:
		SET_BIT(ADC_1->CR2, ADON);
		break;
	case ADC2:
		SET_BIT(ADC_2->CR2, ADON);
		break;
	case ADC3:
		SET_BIT(ADC_3->CR2, ADON);
		break;
	default:
		Det_ReportError(ADC_MODULE_ID, INVALID_ADC_PERIPHERAL);
		break;
	}

}
#endif

/***********************************[4]***********************************************
 * Service Name: MADC_DisableState
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): PeripheralID
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Disable ADC
 ************************************************************************************/
 
 /**
 * \section Service_Name
 * MADC_DisableState
 *
 * \section Description
 * This function clear the enable bit in CR2 register for ADC1 or ADC2 or ADC3 based on the input enum value.
 * 
 * \section Req_ID
 * ADC_0x04
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Reentrant
 *
 * \section Parameters
 * \param[in]  MADC_Peripheral (enum)\ PeripheralID--->Hold which ADC to Disable
 * \param[inout] None
 * \param[out] None
 *
 * \section Return_value
 * None
 *
 * \section Rational
 * Disable dedicated ADC.
 *
 * \section Activity_Diagram
 *
 * @startuml 
 *   start
 *   switch (Which ADC to turn off?)
 *   case ( condition ADC1 )
 *     #green:Set ADC1 turn off;
 *   case ( condition ADC2 )
 *     #green:Set ADC2 turn off;
 *   case ( condition ADC3 )
 *     #green:Set ADC3 turn off;
 *   case ( default )
 *     #red:Det_ReportError(infinite loop);
 *     end   
 * endswitch
 * end
 * @enduml
 *
 *
 *
 * \section Sequence_Diagram
 *
 * @startuml
 *
 * == In_Range_Switching ==
 *
 * "MADC_VidDisableState\nFunction" -> "CLR_BIT\nMacro": Register and required bit to be Cleares Request
 * "CLR_BIT\nMacro" -[#0000FF]-> "MADC_VidDisableState\nFunction": Clearing dedecated bit Response
 *
 * == OutOf_Range_Switching ==
 *
 * "MADC_VidDisableState\nFunction" -[#red]> "Det_ReportError\nFunction": ADC_MODULE_ID, INVALID_ADC_PERIPHERAL
 *
 * @enduml
 *
 *
 *
 *
*/



#if API_ADC_DISABLE_STATE == API_ENABLE
void MADC_VidDisableState(MADC_Peripheral PeripheralID) {

	switch (PeripheralID) {
	case ADC1:
		CLR_BIT(ADC_1->CR2, ADON);
		break;
	case ADC2:
		CLR_BIT(ADC_2->CR2, ADON);
		break;
	case ADC3:
		CLR_BIT(ADC_3->CR2, ADON);
		break;
	default:
		Det_ReportError(ADC_MODULE_ID, INVALID_ADC_PERIPHERAL);
		break;
	}

}
#endif

/***********************************[5]***********************************************
 * Service Name: MADC_VidModeSelect
 * Service ID[hex]: 0x05
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): PeripheralID,ConversionType
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Select ADC Mode
 ************************************************************************************/
 
 /**
 * \section Service_Name
 * MADC_VidModeSelect
 *
 * \section Description
 * This function select continous or single modes for ADC1 or ADC2 or ADC3 based on the input enum value.
 * 
 * \section Req_ID
 * ADC_0x05
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Reentrant
 *
 * \section Parameters
 * \param[in] MADC_Peripheral(enum)\PeripheralID--->enum that have information which adc to install
 * \param[in] MADC_Conversion(enum)\ConversionType--->enum that have information which adc with its dedicated mode
 * \param[inout] None
 * \param[out] None
 *
 * \section Return_value
 * None
 *
 * \section Rational
 * Select mode for dedicated ADC.
 *
 * \section Activity_Diagram
 *
 * @startuml 
 *   start
 *  if (PeripheralID = ADC1?) then (Yes)
 *  if (ConversionType = SINGLE?) then (Yes)
 * 	#green:Set ADC1 Single Conversion;
 *  end
 *  else (no)
 *	if (ConversionType = CONTINOUS?) then (Yes)
 *	#green:Set ADC1 Continous Conversion;
 *  else (no)
 *  #red:Det_ReportError(infinite loop);
 *  end 
 *  endif 
 *  endif
 *
 *  elseif (PeripheralID = ADC2?) then (Yes)
 *  if (ConversionType = SINGLE?) then (Yes)
 * 	#green:Set ADC2 Single Conversion;
 *  end
 *  else (no)
 *	if (ConversionType = CONTINOUS?) then (Yes)
 *	#green:Set ADC2 Continous Conversion;
 *  else (no)
 *  #red:Det_ReportError(infinite loop);
 *  end 
 *  endif 
 *  endif  
 *
 *  elseif (PeripheralID = ADC3?) then (Yes) 
 *  if (ConversionType = SINGLE?) then (Yes)
 * 	#green:Set ADC3 Single Conversion;
 *  end
 *  else (no)
 *	if (ConversionType = CONTINOUS?) then (Yes)
 *	#green:Set ADC3 Continous Conversion;
 *  else (no)
 *  #red:Det_ReportError(infinite loop);
 *  end 
 *  endif
 *  endif 
 *
 *  elseif (PeripheralID != any ADC?) then (Yes)
 *  #red:Det_ReportError(infinite loop);
 *  end 
 *  endif
 *  end
 * @enduml
 *
 *
 *
 * \section Sequence_Diagram
 *
 * @startuml
 *
 * == In_Range_Switching ==
 *
 * "MADC_VidModeSelect\nFunction" -> "CLR_BIT\nMacro": Register and required bit to be Cleares Request
 * "CLR_BIT\nMacro" -[#0000FF]-> "MADC_VidModeSelect\nFunction": Clearing dedecated bit Response
 * "MADC_VidModeSelect\nFunction" -> "SET_BIT\nMacro": Register and required bit to be set Request
 * "SET_BIT\nMacro" -[#0000FF]-> "MADC_VidModeSelect\nFunction": Setting dedecated bit Response
 *
 * == OutOf_Range_Switching ==
 *
 * "MADC_VidModeSelect\nFunction" -[#red]> "Det_ReportError\nFunction": ADC_MODULE_ID, INVALID_ADC_PERIPHERAL
 *
 * @enduml
 *
 *
 *
 *
*/


#if API_ADC_MODE == API_ENABLE
void MADC_VidModeSelect(MADC_Peripheral PeripheralID,
		MADC_Conversion ConversionType) {

	switch (PeripheralID) {
	case ADC1:
		if (ConversionType == ADC_SINGLE_CONVERSION) {
			CLR_BIT(ADC_1->CR2, CONT);
		} else if (ConversionType == ADC_CONTINOUS_CONVERSION) {
			SET_BIT(ADC_1->CR2, CONT);
		} else {
			Det_ReportError(ADC_MODULE_ID, INVALID_ADC_CONVERSION);
		}
		break;
	case ADC2:
		if (ConversionType == ADC_SINGLE_CONVERSION) {
			CLR_BIT(ADC_2->CR2, CONT);
		} else if (ConversionType == ADC_CONTINOUS_CONVERSION) {
			SET_BIT(ADC_2->CR2, CONT);
		} else {
			Det_ReportError(ADC_MODULE_ID, INVALID_ADC_CONVERSION);
		}
		break;
	case ADC3:
		if (ConversionType == ADC_SINGLE_CONVERSION) {
			CLR_BIT(ADC_3->CR2, CONT);
		} else if (ConversionType == ADC_CONTINOUS_CONVERSION) {
			SET_BIT(ADC_3->CR2, CONT);
		} else {
			Det_ReportError(ADC_MODULE_ID, INVALID_ADC_CONVERSION);}
		break;
	default:
		Det_ReportError(ADC_MODULE_ID, INVALID_ADC_PERIPHERAL);
		break;
	}
}
#endif

/***********************************[6]***********************************************
 * Service Name: MADC_VidStartConversion
 * Service ID[hex]: 0x06
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): PeripheralID
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Starts Conversion of Analog signal
 ************************************************************************************/
 
 
 
 /**
 * \section Service_Name
 * MADC_VidStartConversion
 *
 * \section Description
 * This function initialize and start calibration for ADC1 or ADC2 or ADC3 based on the input enum value.
 * 
 * \section Req_ID
 * ADC_0x06
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Reentrant
 *
 * \section Parameters
 * \param[in] MADC_Peripheral(enum)\PeripheralID--->enum that have information which adc to install
 * \param[inout] None
 * \param[out] None
 *
 * \section Return_value
 * None
 *
 * \section Rational
 * Start calibration to optimize the ADC's performance and reduce errors for dedicated ADC.
 *
 * \section Activity_Diagram
 *
 * @startuml 
 *   start
 *   switch (Which ADC to calibrate?)
 *   case ( condition ADC1 )
 *     :initialize Calibration;
 *     :wait until initialization finish;
 *     :Start Calibration; 
 *     #green:Wait until Calibration finish; 
 *   case ( condition ADC2 )
 *     :initialize Calibration;
 *     :wait until initialization finish;
 *     :Start Calibration; 
 *     #green:Wait until Calibration finish; 
 *   case ( condition ADC3 )
 *     :initialize Calibration;
 *     :wait until initialization finish;
 *     :Start Calibration; 
 *     #green:Wait until Calibration finish; 
 *   case ( default )
 *     #red:Det_ReportError(infinite loop);
 *     end   
 * endswitch
 * end
 * @enduml
 *
 *
 *
 * \section Sequence_Diagram
 *
 * @startuml
 *
 * == In_Range_Switching ==
 *
 * "MADC_VidStartConversion\nFunction" -> "GET_BIT\nMacro": Register and required bit needed to be known Request
 * "GET_BIT\nMacro" -[#0000FF]-> "MADC_VidStartConversion\nFunction": Getting dedecated bit Response
 * "MADC_VidStartConversion\nFunction" -> "SET_BIT\nMacro": Register and required bit to be set Request
 * "SET_BIT\nMacro" -[#0000FF]-> "MADC_VidStartConversion\nFunction": Setting dedecated bit Response
 *
 * == OutOf_Range_Switching ==
 *
 * "MADC_VidStartConversion\nFunction" -[#red]> "Det_ReportError\nFunction": ADC_MODULE_ID, INVALID_ADC_PERIPHERAL
 *
 * @enduml
 *
 *
 *
 *
*/


#if API_ADC_START_CONVERSION == API_ENABLE
void MADC_VidStartConversion(MADC_Peripheral PeripheralID) {

	switch (PeripheralID) {
	case ADC1:
		/*Initialize calibration register.*/
		SET_BIT(ADC_1->CR2, RSTCAL);
		while (GET_BIT(ADC_1->CR2, RSTCAL))
			;
		/*start the calibration*/
		SET_BIT(ADC_1->CR2, CAL);
		while (GET_BIT(ADC_1->CR2, CAL))
			;
		break;

	case ADC2:
		/*Initialize calibration register.*/
		SET_BIT(ADC_2->CR2, RSTCAL);
		while (GET_BIT(ADC_2->CR2, RSTCAL))
			;
		/*start the calibration*/
		SET_BIT(ADC_2->CR2, CAL);
		while (GET_BIT(ADC_2->CR2, CAL))
			;
		break;

	case ADC3:

		/*Initialize calibration register.*/
		SET_BIT(ADC_3->CR2, RSTCAL);
		while (GET_BIT(ADC_3->CR2, RSTCAL))
			;
		/*start the calibration*/
		SET_BIT(ADC_3->CR2, CAL);
		while (GET_BIT(ADC_3->CR2, CAL))
			;
		break;

	default:
		Det_ReportError(ADC_MODULE_ID, INVALID_ADC_PERIPHERAL);
		break;
	}
}
#endif

/***********************************[7]***********************************************
 * Service Name: MADC_VidReadChannel
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): PeripheralID,Channel,SampleTime_Cycles
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Read the result of conversion
 ************************************************************************************/
 
 /**
 * \section Service_Name
 * MADC_VidReadChannel
 *
 * \section Description
 * This function Set the channel to be converted, select sample time and returnning converted value for ADC1 or ADC2 or ADC3 based on the input enum value.
 * 
 * \section Req_ID
 * ADC_0x07
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Reentrant
 *
 * \section Parameters
 * \param[in] MADC_Peripheral(enum)\PeripheralID--->enum that have information which adc to install
 * \param[in] MADC_Channel(enum)\Channel--->enum that have information which channel to install 
 * \param[in] MADC_SampleTime(enum)\SampleTime_Cycles--->enum that have information about dedicated sample time  
 * \param[inout] None
 * \param[out] None
 *
 * \section Return_value
 * LOC_ADC value whch have the converted value.
 *
 * \section Rational
 * Reading ADC converted value for dedicated ADC.
 *
 * \section Activity_Diagram
 *
 * @startuml 
 *   start
 *   switch (Which ADC to install?)
 *   case ( condition ADC1 )
 *     :Configure the ADC channel;
 *     :Sample time selection;
 *     :Wait unti conversion of ADC completed;
 *     :Start new conversion in ADC;
 *     #green:return converted value LOC_ADCvalue ; 
 *   case ( condition ADC2 )
 *     :Configure the ADC channel;
 *     :Sample time selection;
 *     :Wait unti conversion of ADC completed;
 *     :Start new conversion in ADC;
 *     #green:return converted value LOC_ADCvalue ; 
 *   case ( condition ADC3 )
 *     :Configure the ADC channel;
 *     :Sample time selection;
 *     :Wait unti conversion of ADC completed;
 *     :Start new conversion in ADC;
 *     #green:return converted value LOC_ADCvalue ; 
 *   case ( default )
 *     #red:Det_ReportError(infinite loop);
 *     end   
 * endswitch
 * end
 * @enduml
 *
 *
 *
 * \section Sequence_Diagram
 *
 * @startuml
 *
 * == In_Range_Switching ==
 *
 * "MADC_VidReadChannel\nFunction" -> "GET_BIT\nMacro": Register and required bit needed to be known Request
 * "GET_BIT\nMacro" -[#0000FF]-> "MADC_VidReadChannel\nFunction": Getting dedecated bit Response
 * "MADC_VidReadChannel\nFunction" -> "SET_BIT\nMacro": Register and required bit to be set Request
 * "SET_BIT\nMacro" -[#0000FF]-> "MADC_VidReadChannel\nFunction": Setting dedecated bit Response
 *
 * == OutOf_Range_Switching ==
 *
 * "MADC_VidReadChannel\nFunction" -[#red]> "Det_ReportError\nFunction": ADC_MODULE_ID, INVALID_ADC_PERIPHERAL
 *
 * @enduml
 *
 *
 *
 *
*/


#if API_ADC_READ == API_ENABLE
u16 MADC_VidReadChannel(MADC_Peripheral PeripheralID, MADC_Channel Channel,

		MADC_SampleTime SampleTime_Cycles) {
	u16 LOC_ADCvalue;
	switch (PeripheralID) {
	case ADC1:
		/* Clear All CR2 */
		/*Configure the ADC channel*/
		ADC_1->SQR1 = 0x00000000;  // Clear register
		ADC_1->SQR2 = 0x00000000;
		ADC_1->SQR3 = Channel;  // Set the channel to be converted
		/* Sample time selection*/
		ADC_1->SMPR2 &= ~((u32) (0b111) << (Channel * 3));
		ADC_1->SMPR2 |= ((u32) (SampleTime_Cycles) << (Channel * 3));
		while ((GET_BIT(ADC_1->SR,EOC) == 0))
			;  // If conversion has finished
		LOC_ADCvalue = ADC_1->DR & 0x0FFF; // Read AD converted value
		SET_BIT(ADC_1->CR2, 0); // Start new conversion
		break;
	case ADC2:
		/* Clear All CR2 */
		/*Configure the ADC channel*/
		ADC_2->SQR1 = 0x00000000;  // Clear register
		ADC_2->SQR2 = 0x00000000;
		ADC_2->SQR3 = Channel;  // Set the channel to be converted
		/* Sample time selection*/
		ADC_2->SMPR2 &= ~((u32) (0b111) << (Channel * 3));
		ADC_2->SMPR2 |= ((u32) (SampleTime_Cycles) << (Channel * 3));
		while ((GET_BIT(ADC_2->SR,EOC) == 0))
			;  // If conversion has finished
		LOC_ADCvalue = ADC_2->DR & 0x0FFF; // Read AD converted value
		SET_BIT(ADC_2->CR2, 0); // Start new conversion
		break;
	case ADC3:
		/* Clear All CR2 */
		/*Configure the ADC channel*/
		ADC_3->SQR1 = 0x00000000;  // Clear register
		ADC_3->SQR2 = 0x00000000;
		ADC_3->SQR3 = Channel;  // Set the channel to be converted
		/* Sample time selection*/
		ADC_3->SMPR2 &= ~((u32) (0b111) << (Channel * 3));
		ADC_3->SMPR2 |= ((u32) (SampleTime_Cycles) << (Channel * 3));
		while ((GET_BIT(ADC_3->SR,EOC) == 0))
			;  // If conversion has finished
		LOC_ADCvalue = ADC_3->DR & 0x0FFF; // Read AD converted value
		SET_BIT(ADC_3->CR2, 0); // Start new conversion
		break;
	default:
		Det_ReportError(ADC_MODULE_ID, INVALID_ADC_PERIPHERAL);
		break;
	}

	return LOC_ADCvalue;
}
#endif

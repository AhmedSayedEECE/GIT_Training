/*********************************************************************************/
/* Author   : 	Team AAWAN                                               */
/* Version  : 	V01                                                               */
/* Date      : 	22 AUG 2023                                                     */
/*********************************************************************************/

#ifndef MADC_CFG_H_
#define MADC_CFG_H_

#define ADC_MODULE_ID 				123	/*First time to Release*/


#define MADC_SW_RELEASE_VERSION 	1	/*First time to Release*/
#define MADC_SW_MAJOR_VERSION		1 /*Major Changes: adding new API*/
#define MADC_SW_MINOR_VERSION		4 /*Minor Changes: adding new if condition or case*/

#define    ADC1_DATA_ALIGN              		RIGHT_ALIGNEMENT
#define    ADC2_DATA_ALIGN              		RIGHT_ALIGNEMENT
#define    ADC3_DATA_ALIGN              		RIGHT_ALIGNEMENT

#define    Conversion_Mode         		ADC_CONTINOUS_CONVERSION
#define    ADC_clock_prescaler     		PCLK2_divided_by_2

#define    ADC1_STATE          					ENABLE_ADC
#define    ADC2_STATE          					DISABLE_ADC
#define    ADC3_STATE          					DISABLE_ADC

#define    API_ADC_GET_SET_VERSION  	API_ENABLE
#define    API_ADC_INIT  				API_ENABLE
#define    API_ADC_MODE  				API_ENABLE
#define    API_ADC_START_CONVERSION  	API_ENABLE
#define    API_ADC_READ  				API_ENABLE
#define    API_ADC_ENABLE_STATE  		API_ENABLE
#define    API_ADC_DISABLE_STATE  		API_ENABLE

#define    API_ADC_GET_SET_VERSION_ID  		0x00
#define    API_ADC_INIT_ID  				0x01
#define    API_ADC_MODE_ID  				0x02
#define    API_ADC_ENABLE_STATE_ID  		0x03
#define    API_ADC_DISABLE_STATE_ID  		0x04
#define    API_ADC_START_CONVERSION_ID  	0x05
#define    API_ADC_READ_ID  				0x06

#endif 

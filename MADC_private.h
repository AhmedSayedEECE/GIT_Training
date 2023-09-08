/*********************************************************************************/
/* Author   : 	Team AAWAN                                               */
/* Version  : 	V01                                                               */
/* Date      : 	22 AUG 2023                                                     */
/*********************************************************************************/

#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_



typedef struct
{
	u8 Major;
	u8 Minor;

}SW_Ver;


/*ADC Register */
typedef struct
{
	u32 SR;
	u32 CR1;
	u32 CR2;
	u32 SMPR1;
	u32 SMPR2;
	u32 JOFR1;
	u32 JOFR2;
	u32 JOFR3;
	u32 JOFR4;
	u32 HTR;
	u32 LTR;
	u32 SQR1;
	u32 SQR2;
	u32 SQR3;
	u32 JSQR;
	u32 JDR1;
	u32 JDR2;
	u32 JDR3;
	u32 JDR4;
	u32 DR;
}MADC_t;

/*ADC Base Address*/
#define ADC1_BASE 					0x40012400
#define ADC2_BASE					0x40012800
#define ADC3_BASE					0x40013C00


#define ADC_1                ((volatile MADC_t *)ADC1_BASE)
#define ADC_2                ((volatile MADC_t *)ADC2_BASE)
#define ADC_3                ((volatile MADC_t *)ADC3_BASE)

typedef enum
{
	INVALID_ADC_CHANNEL,
	INVALID_ADC_PERIPHERAL,
	INVALID_ADC_CONVERSION
}ADC_Error_State;


typedef enum
{
	ENABLE_ADC,
	DISABLE_ADC
}MADC_State;

typedef enum
{
	RIGHT_ALIGNEMENT,
	LEFT_ALIGNEMENT
}MADC_Alignement;

typedef enum
{
	ADC1,
	ADC2,
	ADC3
}MADC_Peripheral;

typedef enum
{
	PCLK2_divided_by_2,
	PCLK2_divided_by_4,
	PCLK2_divided_by_6,
	PCLK2_divided_by_8
}MADC_clock_prescaler;

typedef enum
{
	Channel_0,
	Channel_1,
	Channel_2,
	Channel_3,
	Channel_4,
	Channel_5,
	Channel_6,
	Channel_7,
	Channel_8,
	Channel_9,
	Channel_10,
	Channel_11,
	Channel_12,
	Channel_13,
	Channel_14,
	Channel_15,
	Channel_16,
	Channel_17
}MADC_Channel;

typedef enum
{
	ADC_SINGLE_CONVERSION,
	ADC_CONTINOUS_CONVERSION
}MADC_Conversion;

typedef enum
{
	ADC_1_ORDER=0,
	ADC_2_ORDER=5,
	ADC_3_ORDER=10,
	ADC_4_ORDER=15,
	ADC_5_ORDER=20,
	ADC_6_ORDER=25,
	ADC_7_ORDER=0,
	ADC_8_ORDER=5,
	ADC_9_ORDER=10,
	ADC_TEN_ORDER=15,
	ADC_11_ORDER=20,
	ADC_12_ORDER=25,
	ADC_13_ORDER=0,
	ADC_14_ORDER=5,
	ADC_15_ORDER=10,
	ADC_16_ORDER=15
}MADC_Channel_ORDER;

typedef enum
{
	CONVERSION_1,
	CONVERSION_2,
	CONVERSION_3,
	CONVERSION_4,
	CONVERSION_5,
	CONVERSION_6,
	CONVERSION_7,
	CONVERSION_8,
	CONVERSION_9,
	CONVERSION_10,
	CONVERSION_11,
	CONVERSION_12,
	CONVERSION_13,
	CONVERSION_14,
	CONVERSION_15,
	CONVERSION_16
}MADC_Channel_Length;

typedef enum
{
	ADC_1_5_CYCLE,
	ADC_7_5_CYCLE,
	ADC_13_5_CYCLE,
	ADC_28_5_CYCLE,
	ADC_41_5_CYCLE,
	ADC_55_5_CYCLE,
	ADC_71_5_CYCLE,
	ADC_239_5_CYCLE
}MADC_SampleTime;

#define ADCPRE1     14
#define ADCPRE2     15
/*SR*/
#define EOC		1
#define STRT	4
/*CR1*/
#define EOCIE		5
#define SCAN		8
#define DISCEN		11
#define DISCNUM		13
/*CR2*/
#define ADON     0
#define CONT     1
#define CAL      2
#define RSTCAL   3
#define DMA      8
#define ALIGN    11
#define EXTSEL   17
#define EXTTRIG  20
#define SWSTART  22
/*SMPR1 Register*/
#define SMP10    0
#define SMP11    3
#define SMP12    6
#define SMP13    9
#define SMP14    12
#define SMP15    15
#define SMP16    18
#define SMP17    21
/*SMPR2*/
#define SMP0     0
#define SMP1     3
#define SMP2     6
#define SMP3     9
#define SMP4     12
#define SMP5     15
#define SMP6     18
#define SMP7     21
#define SMP8     24
#define SMP9     27
/*SQR1*/
#define SQ13     0
#define SQ14     5
#define SQ15     10
#define SQ16     15
#define L0       20
/*SQR2*/
#define SQ7      0
#define SQ8      5
#define SQ9      10
#define SQ10     15
#define SQ11     20
#define SQ12     25
/*SQR3*/
#define SQ1      0
#define SQ2      5
#define SQ3      10
#define SQ4      15
#define SQ5      20
#define SQ6      25


#endif 

#ifndef __MYADC_H__
#define __MYADC_H__

/* Analog capable DIO's */
#define Board_DIO23_ANALOG                  IOID_23
#define Board_DIO24_ANALOG                  IOID_24
#define Board_DIO25_ANALOG                  IOID_25
#define Board_DIO26_ANALOG                  IOID_26
#define Board_DIO27_ANALOG                  IOID_27
#define Board_DIO28_ANALOG                  IOID_28
#define Board_DIO29_ANALOG                  IOID_29
#define Board_DIO30_ANALOG                  IOID_30

//
// Defines for input parameter to the HapiSelectADCCompBInput function.
// The define values can not be changed!
//
#define ADC_COMPB_IN_NC        0x00
#define ADC_COMPB_IN_DCOUPL    0x03
#define ADC_COMPB_IN_VSS       0x04
#define ADC_COMPB_IN_VDDS      0x05
#define ADC_COMPB_IN_AUXIO7    0x09
#define ADC_COMPB_IN_AUXIO6    0x0A
#define ADC_COMPB_IN_AUXIO5    0x0B
#define ADC_COMPB_IN_AUXIO4    0x0C
#define ADC_COMPB_IN_AUXIO3    0x0D
#define ADC_COMPB_IN_AUXIO2    0x0E
#define ADC_COMPB_IN_AUXIO1    0x0F
#define ADC_COMPB_IN_AUXIO0    0x10

/*
 *  Constraints
 */
#define PowerCC26XX_SB_VIMS_CACHE_RETAIN    0
#define PowerCC26XX_SD_DISALLOW             1
#define PowerCC26XX_SB_DISALLOW             2
#define PowerCC26XX_IDLE_PD_DISALLOW        3
#define PowerCC26XX_NEED_FLASH_IN_IDLE      4
#define PowerCC26XX_NUMCONSTRAINTS          5

typedef enum CC2650DK_7ID_ADCName {
    CC2650DK_7ID_ADCALS = 0,
    CC2650DK_7ID_ADCDCOUPL = 1,
    CC2650DK_7ID_ADCVSS = 2,
    CC2650DK_7ID_ADCVDDS = 3,
    CC2650DK_7ID_ADCCOUNT = 4,
    CC2650DK_7ID_TDDS = 5
} CC2650DK_7ID_ADCName;

#endif //__MYADC_H__
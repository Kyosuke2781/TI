/*
 * Copyright (c) 2015-2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ====================== CC2650DK_7ID.c =============================================
 *  This file is responsible for setting up the board specific items for the
 *  SRF06EB with the CC2650EM_7ID board.
 */


/*
 *  ====================== Includes ============================================
 */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/drivers/PIN.h>
#include <ti/drivers/pin/PINCC26XX.h>
#include <ti/drivers/PWM.h>
//#include <ti/drivers/pwm/PWMTimerCC26XX.h>
//#include <ti/drivers/timer/GPTimerCC26XX.h>
//#include <ti/drivers/Power.h>
//#include <ti/drivers/power/PowerCC26XX.h>

#include <inc/hw_memmap.h>
#include <inc/hw_ints.h>
#include <driverlib/ioc.h>
#include <driverlib/udma.h>

#include <Board.h>

 /*
 *  ========================== ADC begin =========================================
 */
/* Place into subsections to allow the TI linker to remove items properly */
#if defined(__TI_COMPILER_VERSION__)
#pragma DATA_SECTION(ADC_config, ".const:ADC_config")
#pragma DATA_SECTION(adcCC26xxHWAttrs, ".const:adcCC26xxHWAttrs")
#endif

/* Include drivers */
//#include <packages/ti/drivers/ADC.h>
//#include <packages/ti/drivers/adc/ADCCC26XX.h>
#include <ADC/ADC.h>
#include <ADC/ADCCC26XX.h>

#include <ADC/CC2650DK_7ID.h>
#include <ADC/MyADC.h>

/* ADC objects */
ADCCC26XX_Object adcCC26xxObjects[CC2650DK_7ID_TDDS/*CC2650DK_7ID_ADCCOUNT*/];


const ADCCC26XX_HWAttrs adcCC26xxHWAttrs[CC2650DK_7ID_TDDS/*CC2650DK_7ID_ADCCOUNT*/] = {
   {
        .adcDIO = Board_DIO23_ANALOG,
        .adcCompBInput = ADC_COMPB_IN_AUXIO7,
        .refSource = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource = ADCCC26XX_TRIGGER_MANUAL
    },
    {
        .adcDIO = Board_DIO24_ANALOG,
        .adcCompBInput = ADC_COMPB_IN_AUXIO6, //ADC_COMPB_IN_DCOUPL,
        .refSource = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource = ADCCC26XX_TRIGGER_MANUAL
    },
    {
        .adcDIO = Board_DIO25_ANALOG,
        .adcCompBInput = ADC_COMPB_IN_AUXIO5, //ADC_COMPB_IN_VSS,
        .refSource = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource = ADCCC26XX_TRIGGER_MANUAL
    },
    {
        .adcDIO = Board_DIO26_ANALOG,
        .adcCompBInput = ADC_COMPB_IN_AUXIO4,
        .refSource = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource = ADCCC26XX_TRIGGER_MANUAL
    },
    {
        .adcDIO = Board_DIO27_ANALOG,
        .adcCompBInput = ADC_COMPB_IN_AUXIO3,
        .refSource = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource = ADCCC26XX_TRIGGER_MANUAL
    }
};

const ADC_Config ADC_config[] = {
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[0], &adcCC26xxHWAttrs[0]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[1], &adcCC26xxHWAttrs[1]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[2], &adcCC26xxHWAttrs[2]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[3], &adcCC26xxHWAttrs[3]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[2], &adcCC26xxHWAttrs[4]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[3], &adcCC26xxHWAttrs[5]},
    {NULL, NULL, NULL},
};

/*
 *  ========================== ADC end =========================================
 */


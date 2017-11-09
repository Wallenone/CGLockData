//
//  BGMValue.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/16.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    BGMUnitKg_L                             = 0,            // kg/L
    BGMUnitMol_L                            = 1             // mol/L
} BGMUnit;

typedef enum {
    BGMTypeReserved_TYPE                    = 0,            // 保留供将来使用
    BGMTypeCapillary_WHOLE_BLOOD            = 1,            // 毛细血管全血
    BGMTypeCapillary_PLASMA                 = 2,            // 毛细血管
    BGMTypeVenous_WHOLE_BLOOD               = 3,            // 静脉全血
    BGMTypeVenous_PLASMA                    = 4,            // 静脉血浆
    BGMTypeArterial_WHOLE_BLOOD             = 5,            // 动脉全血
    BGMTypeArterial_PLASMA                  = 6,            // 动脉血浆
    BGMTypeUndetermined_WHOLE_BLOOD         = 7,            // 未确定全血
    BGMTypeUndetermined_PLASMA              = 8,            // 未确定的血浆
    BGMTypeInterstitial_FLUID               = 9,            // 间质液（ISF）
    BGMTypeControl_SOLUTION_TYPE            = 10            // 对照溶液
} BGMType;

typedef enum {
    BGMLocationReserved_LOCATION            = 0,            //
    BGMLocationFinger                       = 1,            // 手指
    BGMLocationAlternate_SITE_TEST          = 2,            // 替代现场测试（AST）
    BGMLocationEarlobe                      = 3,            // 耳垂
    BGMLocationControl_SOLUTION_LOCATION    = 4,            // 对照溶液
    BGMLocationLocation_NOT_AVAILABLE       = 15            // 样品位置值不可用
} BGMLocation;

typedef enum {
    BgmMedicationUnitKilograms              = 0,
    BgmMedicationUnitLiters                 = 1
} BgmMedicationUnit;

typedef enum {
    BgmCarbohydrateIdReserved_CARBOHYDRATE  = 0,
    BgmCarbohydrateIdBreakfest              = 1,
    BgmCarbohydrateIdLunch                  = 2,
    BgmCarbohydrateIdDinner                 = 3,
    BgmCarbohydrateIdSnack                  = 4,
    BgmCarbohydrateIdDrink                  = 5,
    BgmCarbohydrateIdSupper                 = 6,
    BgmCarbohydrateIdBrunch                 = 7
} BgmCarbohydrateId;

typedef enum {
    BgmMealReserved_MEAL                    = 0,
    BgmMealPreprandial                      = 1,
    BgmMealPostprandial                     = 2,
    BgmMealFasting                          = 3,
    BgmMealCasual                           = 4,
    BgmMealBedtime                          = 5
} BgmMeal;

typedef enum {
    BgmTesterReserved_TESTER                = 0,
    BgmTesterSelf                           = 1,
    BgmTesterHealth_CARE_PROFESSIONAL       = 2,
    BgmTesterLab_TEST                       = 3,
    BgmTesterTester_NOT_AVAILABLE           = 15
} BgmTester;

typedef enum {
    BgmHealthReserved_HEALTH                = 0,
    BgmHealthMinor_HEALTH_ISSUES            = 1,
    BgmHealthMajor_HEALTH_ISSUES            = 2,
    BgmHealthDuring_MENSES                  = 3,
    BgmHealthUnder_STRESS                   = 4,
    BgmHealthNo_HEALTH_ISSUES               = 5,
    BgmHealthHealth_NOT_AVAILABLE           = 15
} BgmHealth;

typedef enum {
    BgmMedicationIdReserved_MEDICATON       = 0,
    BgmMedicationIdRapid_ACTING_INSULIN     = 1,
    BgmMedicationIdShort_ACTING_INSULIN     = 2,
    BgmMedicationIdIntermediate_ACTING_INSULIN = 3,
    BgmMedicationIdLong_ACTING_INSULINE     = 4,
    BgmMedicationIdPre_MIXED_INSULINE       = 5
} BgmMedicationId;

typedef enum {
    BGMResponseCodeReserved                 = 0,
    BGMResponseCodeSuccess                  = 1,
    BGMResponseCodeOp_CODE_NOT_SUPPORTED    = 2,
    BGMResponseCodeInvalid_OPERATOR         = 3,
    BGMResponseCodeOperator_NOT_SUPPORTED   = 4,
    BGMResponseCodeInvalid_OPERAND          = 5,
    BGMResponseCodeNo_RECORDS_FOUND         = 6,
    BGMResponseCodeAbort_UNSUCCESSFUL       = 7,
    BGMResponseCodeProcedure_NOT_COMPLETED  = 8,
    BGMResponseCodeOperand_NOT_SUPPORTED    = 9
} BGMResponseCode;


@interface LLBLEBGMValue : NSObject

#pragma mark - measurement

/**
 *  是否有timeOffset值
 */
@property (nonatomic, assign) BOOL timeOffsetPresent;

/**
 *  葡萄糖浓度，类型和样品位置是否存在
 */
@property (nonatomic, assign) BOOL glucoseConcentrationTypeAndLocationPresent;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BOOL sensorStatusAnnunciationPresent;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) Float32 glucoseConcentration;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) UInt16 sequenceNumber;

/**
 *  <#Annotations#>
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) int16_t timeOffset;

/**
 *  葡萄糖浓度单位
 */
@property (nonatomic, assign) BGMUnit unit;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BGMType type;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BGMLocation location;

/**
 *  传感器状态通知
 */
@property (nonatomic, assign) UInt16 sensorStatusAnnunciation;


#pragma mark - context

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BgmMedicationUnit medicationUnit;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BOOL carbohydratePresent;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BOOL mealPresent;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BOOL testerAndHealthPresent;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BOOL exercisePresent;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BOOL medicationPresent;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BOOL HbA1cPresent;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BgmCarbohydrateId carbohydrateId;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) Float32 carbohydrate;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BgmMeal meal;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BgmTester tester;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BgmHealth health;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) UInt16 exerciseDuration;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) UInt8 exerciseIntensity;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) BgmMedicationId medicationId;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) Float32 medication;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) Float32 HbA1c;

@end

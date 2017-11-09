//
//  CGMFeatureData.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/15.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LLBLECGMFeature : NSObject

/**
 *  支持校准
 */
@property (nonatomic, assign, getter=isCalibrationSupported) BOOL calibrationSupported;

/**
 *  支持患者高/低警报
 */
@property (nonatomic, assign, getter=isPatientHighLowAlertsSupported) BOOL patientHighLowAlertsSupported;

/**
 *  支持Hypo警报
 */
@property (nonatomic, assign, getter=isHypoAlertsSupported) BOOL hypoAlertsSupported;

/**
 *  支持超级警报
 */
@property (nonatomic, assign, getter=isHyperAlertsSupported) BOOL hyperAlertsSupported;

/**
 *  支持增加/减少警报
 */
@property (nonatomic, assign, getter=isRateOfIncreaseDecreaseAlertsSupported) BOOL rateOfIncreaseDecreaseAlertsSupported;

/**
 *  支持设备特定警报
 */
@property (nonatomic, assign, getter=isDeviceSpecificAlertSupported) BOOL deviceSpecificAlertSupported;

/**
 *  支持传感器故障检测
 */
@property (nonatomic, assign, getter=isSensorMalfunctionDetectionSupported) BOOL sensorMalfunctionDetectionSupported;

/**
 *  支持传感器温度高低检测
 */
@property (nonatomic, assign, getter=isSensorTemperatureHighLowDetectionSupported) BOOL sensorTemperatureHighLowDetectionSupported;

/**
 *  传感器结果支持高低检测
 */
@property (nonatomic, assign, getter=isSensorResultHighLowDetectionSupported) BOOL sensorResultHighLowDetectionSupported;

/**
 *  支持低电池检测
 */
@property (nonatomic, assign, getter=isLowBatteryDetectionSupported) BOOL lowBatteryDetectionSupported;

/**
 *  支持传感器类型错误检测
 */
@property (nonatomic, assign, getter=isSensorTypeErrorDetectionSupported) BOOL sensorTypeErrorDetectionSupported;

/**
 *  支持常规设备故障
 */
@property (nonatomic, assign, getter=isGeneralDeviceFaultSupported) BOOL generalDeviceFaultSupported;

/**
 *  支持E2E-CRC
 */
@property (nonatomic, assign, getter=isE2ECRCSupported) BOOL E2ECRCSupported;

/**
 *  支持多重债券
 */
@property (nonatomic, assign, getter=isMultipleBondSupported) BOOL multipleBondSupported;

/**
 *  支持多个会话
 */
@property (nonatomic, assign, getter=isMultipleSessionsSupported) BOOL 	multipleSessionsSupported;

/**
 *  支持CGM趋势信息
 */
@property (nonatomic, assign, getter=isTrendInformationSupported) BOOL trendInformationSupported;

/**
 *  CGM质量支持
 */
@property (nonatomic, assign, getter=isQualitySupported) BOOL qualitySupported;

/**
 *  CGM类型
 *
 *  0.留作将来使用
 *  1.毛细血管全血
 *  2.毛细血管
 *  3.毛细血管全血
 *  4.静脉血浆
 *  5.动脉全血
 *  6.动脉血浆
 *  7.未确定全血
 *  8.未确定的血浆
 *  9.间质液（ISF）
 *  10.对照溶液
 *  11 - 15.留作将来使用
 */
@property (nonatomic, assign) UInt8 CGMType;

/**
 *  CGM采样位置
 *
 *  0.留作将来使用
 *  1.手指
 *  2.替代现场测试（AST）
 *  3.耳垂
 *  4.对照溶液
 *  5.皮下组织
 *  15.样品位置值不可用
 *  6 - 14.留作将来使用
 */
@property (nonatomic, assign) UInt8 CGMSampleLocation;

@end

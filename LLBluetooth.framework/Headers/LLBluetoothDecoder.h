//
//  BluetoothDecoder.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/16.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "LLBLEBPMDecoder.h"
#import "LLBLEBGMDecoder.h"
#import "LLBLECGMDecoder.h"
#import "LLBLECSCDecoder.h"
#import "LLBLEHRMDecoder.h"
#import "LLBLEHTMDecoder.h"
#import "LLBLERSCDecoder.h"
#import "LLBLEWSDecoder.h"
#import "LLBLECTDecoder.h"
#import "LLBLEBatteryDecoder.h"

#pragma mark - const

//MARK: - Battery Service Identifiers
extern NSString * const LLBluetooth_BS_Service_UUIDString;
extern NSString * const LLBluetooth_BS_Characteristic_BatteryLevel_UUIDString;

//MARK: - WS Identifiers
extern NSString * const LLBluetooth_WS_Service_UUIDString;
extern NSString * const LLBluetooth_WS_Characteristic_Feature_UUIDString;
extern NSString * const LLBluetooth_WS_Characteristic_Measurement_UUIDString;

//MARK: - CGM Identifiers
extern NSString * const LLBluetooth_CGM_Service_UUIDString;
extern NSString * const LLBluetooth_CGM_Characteristic_GlucoseMeasurement_UUIDString;
extern NSString * const LLBluetooth_CGM_Characteristic_Feature_UUIDString;
extern NSString * const LLBluetooth_CGM_Characteristic_Status_UUIDString;
extern NSString * const LLBluetooth_CGM_Characteristic_SessionStartTime_UUIDString;
extern NSString * const LLBluetooth_CGM_Characteristic_SessionRunTime_UUIDString;
extern NSString * const LLBluetooth_CGM_Characteristic_SpecificOpsControlPoint_UUIDString;

//MARK: - BGM Identifiers
extern NSString * const LLBluetooth_BGM_Service_UUIDString;
extern NSString * const LLBluetooth_BGM_Characteristic_GlucoseMeasurement_UUIDString;
extern NSString * const LLBluetooth_BGM_Characteristic_GlucoseMeasurementContext_UUIDString;
extern NSString * const LLBluetooth_BGM_Characteristic_RecordAccessControlPoint_UUIDString;

//MARK: - BPM Identifiers
extern NSString * const LLBluetooth_BPM_Service_UUIDString;
extern NSString * const LLBluetooth_BPM_Characteristic_BloodPressureMeasurement_UUIDString;
extern NSString * const LLBluetooth_BPM_Characteristic_IntermediateCuffPressure_UUIDString;

//MARK: - CSC Identifiers
extern NSString * const LLBluetooth_CSC_Service_UUIDString;
extern NSString * const LLBluetooth_CSC_Characteristic_Measurement_UUIDString;

//MARK: - RSC Identifiers
extern NSString * const LLBluetooth_RSC_Service_UUIDString;
extern NSString * const LLBluetooth_RSC_Characteristic_Measurement_UUIDString;

//MARK: - HRS Identifiers
extern NSString * const LLBluetooth_HRS_Service_UUIDString;
extern NSString * const LLBluetooth_HRS_Characteristic_HeartRate_UUIDString;
extern NSString * const LLBluetooth_HRS_Characteristic_SensorLocation_UUIDString;

//MARK: - HTS Identifiers
extern NSString * const LLBluetooth_HTS_Service_UUIDString;
extern NSString * const LLBluetooth_HTS_Characteristic_Measurement_UUIDString;

//MARK: - Current Time Identifiers
extern NSString * const LLBluetooth_CT_Service_UUIDString;
extern NSString * const LLBluetooth_CT_Characteristic_currentTime_UUIDString;
extern NSString * const LLBluetooth_CT_Characteristic_localTime_UUIDString;
extern NSString * const LLBluetooth_CT_Characteristic_referenceTime_UUIDString;

//MARK: - GLYPH Identifiers
extern NSString * const LLBluetooth_GLYPH_Service_UUIDString;
extern NSString * const LLBluetooth_GLYPH_Characteristic_Request_UUIDString;
extern NSString * const LLBluetooth_GLYPH_Characteristic_Response_UUIDString;


@interface LLBluetoothDecoder : NSObject

+ (instancetype)decoder;

- (void)discoverCharacteristic:(CBCharacteristic *)characteristic peripheral:(CBPeripheral *)peripheral;

- (id)decodeCharacteristic:(CBCharacteristic *)characteristic;
- (void)decodeCharacteristic:(CBCharacteristic *)characteristic toValue:(NSObject *)value;

@end

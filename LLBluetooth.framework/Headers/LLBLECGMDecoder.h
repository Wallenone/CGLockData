//
//  BGMDecoder.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/15.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LLBLECGMValue.h"

typedef enum {
    CGMOpcodeResponseCodeReserved_RESPONSE           = 0,
    CGMOpcodeResponseCodeSuccess                     = 1,
    CGMOpcodeResponseCodeOp_CODE_NOT_SUPPORTED       = 2,
    CGMOpcodeResponseCodeInvalid_OPERAND             = 3,
    CGMOpcodeResponseCodeProcedure_NOT_COMPLETED     = 4,
    CGMOpcodeResponseCodeParameter_OUT_OF_RANGE      = 5
}CGMOpcodeResponseCode;

/**
 *  Continuous Glucose Monitoring
 *  连续血糖监测
 */
@interface LLBLECGMDecoder : NSObject

/**
 *  解码Feature数据
 */
+ (int)decodeFeatureData:(NSData *)data toObj:(LLBLECGMValue *)obj;

/**
 *  解码Measurement数据
 */
+ (int)decodeMeasurementData:(NSData *)data toObj:(LLBLECGMValue *)obj;

/**
 *  解码SpecificOpsControlPoint数据
 */
+ (int)decodeSpecificOpsControlPointData:(NSData *)data toObj:(LLBLECGMValue *)obj;

@end

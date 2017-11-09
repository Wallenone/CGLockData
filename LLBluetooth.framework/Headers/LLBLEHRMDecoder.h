//
//  HRMDecoder.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/14.
//  Copyright © 2016年 黄强强. All rights reserved.
//
//  heart rate modi

#import <Foundation/Foundation.h>
#import "LLBLEHRMValue.h"

/**
 *  Heart Rate
 *  心率监测
 */
@interface LLBLEHRMDecoder : NSObject

/**
 *  解码详细数据
 */
+ (int)decodeMeasurementData:(NSData *)data toObj:(LLBLEHRMValue *)obj;

/**
 *  解码传感器位置
 */
+ (int)decodeHRLocation:(NSData *)data toObj:(LLBLEHRMValue *)obj;

@end

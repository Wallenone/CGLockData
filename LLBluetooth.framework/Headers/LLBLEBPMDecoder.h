//
//  BPMDecoder.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/11.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LLBLEBPMValue.h"

@interface LLBLEBPMDecoder : NSObject

/**
 解码详细数据
 
 @param data 待解析的数据
 */
+ (int)decodeMeasurementData:(NSData *)data toObj:(LLBLEBPMValue *)obj;

/**
 解码CuffPressure数据
 
 @param data 待解析的数据
 */
+ (int)decodeCuffPressureData:(NSData *)data toObj:(LLBLEBPMValue *)obj;

@end

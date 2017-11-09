//
//  BGMDecoder.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/15.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LLBLEBGMValue.h"

/**
 *  glucose
 *  葡萄糖
 */
@interface LLBLEBGMDecoder : NSObject

+ (int)decodeMeasurementData:(NSData *)data toObj:(LLBLEBGMValue *)obj;

+ (int)decodeMeasurementContextData:(NSData *)data toObj:(LLBLEBGMValue *)obj;

+ (int)decodeRecordAccessControlPointData:(NSData *)data toObj:(LLBLEBGMValue *)obj;

@end

//
//  HTSDecoder.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/14.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LLBLEHTMValue.h"

/**
 *  Health Temperature
 *  温度计，体温计
 */
@interface LLBLEHTMDecoder : NSObject

/**
 *  解码详细数据
 */
+ (int)decodeMeasurementData:(NSData *)data toObj:(LLBLEHTMValue *)obj;

@end

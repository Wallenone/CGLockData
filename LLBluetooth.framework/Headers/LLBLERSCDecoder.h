//
//  RSCDecoder.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/14.
//  Copyright © 2016年 黄强强. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "LLBLERSCValue.h"

/**
 *  running speed and cadence
 *  跑步速度和节奏
 */
@interface LLBLERSCDecoder : NSObject

/**
 *  解码详细数据
 */
+ (int)decodeMeasurementData:(NSData *)data toObj:(LLBLERSCValue *)obj;

@end

//
//  CSCDecoder.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/14.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LLBLECSCValue.h"

/**
 *  cycling speed and cadence
 *  骑自行车的速度和节奏
 */
@interface LLBLECSCDecoder : NSObject

+ (int)decodeMeasurementData:(NSData *)data toObj:(LLBLECSCValue *)obj;

@end

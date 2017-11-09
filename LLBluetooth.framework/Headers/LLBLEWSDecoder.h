//
//  WeightScaleDecoder.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/10/27.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LLBLEWSValue.h"


@interface LLBLEWSDecoder : NSObject

/**
 解码特征数据
 
 @param data 数据
 */
+ (int)decodeFeatureData:(NSData *)data toObj:(LLBLEWSValue *)obj;


/**
 解码详细数据
 
 @param data 解析的数据
 */
+ (int)decodeMeasurementData:(NSData *)data toObj:(LLBLEWSValue *)obj;

@end

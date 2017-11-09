//
//  LLBLECTDecoder.h
//  Pods
//
//  Created by 黄强强 on 17/3/24.
//
//

#import <Foundation/Foundation.h>
#import "LLBLECTValue.h"

@interface LLBLECTDecoder : NSObject

/**
 解码当前时间信息
 */
+ (int)decodeCurrentTimeData:(NSData *)data toObj:(LLBLECTValue *)obj;


/**
 解码当地时间的时区信息
 */
+ (int)decodeLocalTimeData:(NSData *)data toObj:(LLBLECTValue *)obj;


/**
 解码详细数据
 */
+ (int)decodereRerenceTimeData:(NSData *)data toObj:(LLBLECTValue *)obj;

@end

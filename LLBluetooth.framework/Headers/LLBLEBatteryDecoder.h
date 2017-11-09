//
//  LLBLEBatteryDecoder.h
//  Pods
//
//  Created by 黄强强 on 17/4/20.
//
//

#import <Foundation/Foundation.h>
#import "LLBLEBatteryValue.h"

@interface LLBLEBatteryDecoder : NSObject

+ (int)decodeBatteryLevel:(NSData *)data toObj:(LLBLEBatteryValue *)obj;
@end

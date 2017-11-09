//
//  LLBLECTValue.h
//  Pods
//
//  Created by 黄强强 on 17/3/24.
//
//

#import <Foundation/Foundation.h>

@interface LLBLECTValue : NSObject

/**
 年，0表示年份未知
 */
@property (nonatomic, assign) UInt16 year;

/**
 月,（1-12）0表示月份未知
 */
@property (nonatomic, assign) UInt8 month;

/**
 日（1-31）
 0表示日位置
 */
@property (nonatomic, assign) UInt8 day;

/**
 时
 */
@property (nonatomic, assign) UInt8 hour;

/**
 分
 */
@property (nonatomic, assign) UInt8 minute;

/**
 秒
 */
@property (nonatomic, assign) UInt8 second;

/**
 星期（1：Monday ------ 7：Sunday）,0表示星期位置
 */
@property (nonatomic, assign) UInt8 week;

/**
 1/256秒 （0-255）
 */
@property (nonatomic, assign) UInt8 fractions256;

#pragma mark - Local Time Information

/**
 时区
 */
@property (nonatomic, assign) SInt8 timeZone;

/**
 夏令时间
 */
@property (nonatomic, assign) UInt8 dstOffset;

#pragma mark - Reference Time Information

/**
 时间源（0-6）
 
 0	Unknown
 1	Network Time Protocol
 2	GPS
 3	Radio Time Signal
 4	Manual
 5	Atomic Clock
 6	Cellular Network
 */
@property (nonatomic, assign) UInt8 timeSource;

/**
 时间精度
 */
@property (nonatomic, assign) UInt8 accuracy;

/**
 自更新以来的天数
 */
@property (nonatomic, assign) UInt8 daysSinceUpdate;

/**
 自更新以来的时间
 */
@property (nonatomic, assign) UInt8 hoursSinceUpdate;


@end

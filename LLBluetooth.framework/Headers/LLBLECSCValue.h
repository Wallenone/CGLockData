//
//  CSCValue.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/16.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LLBLECSCValue : NSObject

/**
 *  是否有wheelRevolution和wheelEventTime字段
 */
@property (nonatomic, assign, getter=isWheelRevolutionDataPresent) BOOL wheelRevolutionDataPresent;

/**
 *  是否有crankRevolution和crankEventTime字段
 */
@property (nonatomic, assign, getter=isCrankRevolutionDataPresent) BOOL crankRevolutionDataPresent;

/**
 *  累计车轮转数
 */
@property (nonatomic, assign) int wheelRevolution;

/**
 *  轮子最后发生事件的时间
 */
@property (nonatomic, assign) int wheelEventTime;

/**
 *  行驶速度
 */
@property (nonatomic, assign) double travelSpeed;

/**
 *  累积曲柄转数
 */
@property (nonatomic, assign) int crankRevolution;

/**
 *
 */
@property (nonatomic, assign) int crankEventTime;

@end

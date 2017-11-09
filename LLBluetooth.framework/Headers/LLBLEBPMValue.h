//
//  BPMValue.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/16.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LLBLEBPMValue : NSObject

/**
 *  血压单位，0:mmHg 1:kPa
 */
@property (nonatomic, assign) int bloodPressureUnits;

/**
 *  收缩
 */
@property (nonatomic, assign) Float32 systolicValue;

/**
 *  舒张
 */
@property (nonatomic, assign) Float32 diastolicValue;

/**
 *  脉压差
 */
@property (nonatomic, assign) Float32 meanApValue;

/**
 *  是否有测量时间字段
 */
@property (nonatomic, assign) BOOL timestampPresent;

/**
 *  是否有脉冲率值
 */
@property (nonatomic, assign) BOOL pulseRatePresent;

/**
 *  测量的时间
 */
@property (nonatomic, strong) NSDate *date;

/**
 *  心率
 */
@property (nonatomic, assign) Float32 pulse;

@end

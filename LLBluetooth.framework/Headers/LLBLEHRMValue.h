//
//  HRMValue.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/16.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LLBLEHRMValue : NSObject

/**
 *  传感器触点状态
 *
 *  0.当前连接中不支持传感器接触功能
 *  1.当前连接不支持传感器接触功能
 *  2.支持传感器接触功能，但未检测到接触
 *  3.支持传感器接触功能并检测到接触
 */
@property (nonatomic, assign) int sensorContactStatus;

/**
 *  能耗状态
 *
 *  0.能量消耗场不存在
 *  1.存在能量消耗场
 */
@property (nonatomic, assign) int energyExpendedStatus;

/**
 *  心率
 */
@property (nonatomic, assign) int heartRate;

/**
 *  测量部位
 */
@property (nonatomic, copy) NSString *location;

@end

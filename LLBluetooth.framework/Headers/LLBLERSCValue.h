//
//  RSCValue.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/16.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LLBLERSCValue : NSObject

/**
 *  是否有步幅长度字段
 */
@property (nonatomic, assign) BOOL strideLengthPresent;

/**
 *  是否有总距离字段
 */
@property (nonatomic, assign) BOOL totalDistancePresent;

/**
 *  跑步还是走路
 */
@property (nonatomic, assign, getter=isRunning) BOOL running;

/**
 *  步幅长度
 */
@property (nonatomic, assign) int stripLength;

/**
 *  瞬时节奏
 */
@property (nonatomic, assign) int cadence;

/**
 *  瞬时速度
 */
@property (nonatomic, assign) int speed;

/**
 *  总距离，单位（米）
 */
@property (nonatomic, assign) int distance;

@end

//
//  HTMValue.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/16.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LLBLEHTMValue : NSObject

/**
 *  单位：0:摄氏度，1:华氏度
 */
@property (nonatomic, assign, getter=isTempInFahrenheit) BOOL tempInFahrenheit;

/**
 *  是否有时间戳字段
 */
@property (nonatomic, assign) BOOL timestampPresent;

/**
 *  测量的温度值
 */
@property (nonatomic, assign) double temperature;

/**
 *  是否有location字段
 */
@property (nonatomic, assign) BOOL locationPresent;

/**
 *  当前时间
 */
@property (nonatomic, strong) NSDate *date;

/**
 *  测量部位
 */
@property (nonatomic, copy) NSString *location;

@end

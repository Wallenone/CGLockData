//
//  WSValue.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/16.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    WeightScaleUnitTypeKilogramAndMeter = 0,    // kg and m
    WeightScaleUnitTypePoundAndInch             // lb and inch
} WeightScaleUnitType;

@interface LLBLEWSValue : NSObject

/**
 *  单位类型（使用千克，米还是磅，英寸）
 */
@property (nonatomic, assign) WeightScaleUnitType unit_type;

/**
 重量转换单位，千克
 */
@property (nonatomic, assign) float unit_kg;

/**
 重量转换单位，磅
 */
@property (nonatomic, assign) float unit_lb;

/**
 高度转换单位，米
 */
@property (nonatomic, assign) float unit_m;

/**
 高度转换单位，英寸
 */
@property (nonatomic, assign) float unit_inch;

/**
 *  支不支持多用户
 */
@property (nonatomic, assign) BOOL multipleUsersPresent;

/**
 *  支不支持BMI
 */
@property (nonatomic, assign) BOOL BMIPresent;

/**
 *  支不支持时间戳
 */
@property (nonatomic, assign) BOOL timeStampPresent;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) int userID;

/**
 *  <#Annotations#>
 */
@property (nonatomic, assign) float BMI;

/**
 *  重量
 */
@property (nonatomic, assign) float weight;

/**
 *  高度
 */
@property (nonatomic, assign) float height;

/**
 *  接收时间
 */
@property (nonatomic, strong) NSDate *reciveDate;

/**
 *  详细数据的保留位
 */
@property (nonatomic, assign) int weightMeasurementReservedBit;

@end

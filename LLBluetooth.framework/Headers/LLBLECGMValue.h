//
//  CGMValue.h
//  Weight_Scale
//
//  Created by 黄强强 on 16/11/16.
//  Copyright © 2016年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LLBLECGMFeature.h"

@interface LLBLECGMValue : NSObject

/**
 *  feature data
 */
@property (nonatomic, strong) LLBLECGMFeature *featureData;

/**
 *  有无CGM趋势信息
 */
@property (nonatomic, assign) BOOL sensorTrendInfoPresent;

/**
 *  趋势信息
 *  SFLOAT数据类型的（mg / dL）/ min的CGM趋势信息。如果设备支持CGM趋势信息（CGM特性中的位15设置为1），则此字段是可选的，否则排除。
 */
@property (nonatomic, assign) Float32 trendInfo;

/**
 *  CGM质量
 */
@property (nonatomic, assign) BOOL sensorQualityPresent;

/**
 *  质量信息
 *  （以％为SFLOAT数据类型）。 SFLOAT类型是一个16位字，包括带符号的4位整数指数，后跟带符号的12位尾数，每个以二进制补码的形式
 */
@property (nonatomic, assign) Float32 quality;

/**
 *  传感器状态通知字段，警告 - 八位字节
 */
@property (nonatomic, assign) BOOL sensorWarningPresent;

/**
 *  传感器状态通知字段，校准/温度八位位组
 */
@property (nonatomic, assign) BOOL sensorCalTempPresent;

/**
 *  传感器状态通知字段，状态八位位组存在
 */
@property (nonatomic, assign) BOOL sensorStatusAnnunciationPresent;

/**
 *  葡萄糖浓度
 *  SFLOAT数据类型 mg / dL的CGM葡萄糖浓度。 SFLOAT类型是16位字，包括带符号的4位整数指数，后跟带符号的12位尾数，每个以二进制补码的形式。
 */
@property (nonatomic, assign) Float32 glucoseConcentration;

/**
 *  单个CGM值与会话开始时间的相对时间差
 */
@property (nonatomic, assign) int16_t timeOffsetSinceSessionStart;

/**
 *  measurement数据大小
 */
@property (nonatomic, assign) UInt8 currentMeasurementSize;

/**
 *  传感器状态通知字段是一个可选字段，最多包含三个八位字节。仅当一个或多个位设置为“1”时，才会附加该位。只有受影响的八位字节应添加并由标志字段指示
 *  传感器状态通告字段应附加到状态适用的每个CGM测量记录。
 */
@property (nonatomic, assign) UInt32 sensorStatusAnnunciation;

@end

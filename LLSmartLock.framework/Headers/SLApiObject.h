//
//  SLApiObject.h
//  所有Api对象
//
//  Created by SmartLock on 2017/5/3.
//  Copyright © 2017年 LLHD. All rights reserved.
//

#import <Foundation/Foundation.h>

/*! @brief 该类为锁的基类,包含锁的一些基本属性
 *
 */
@interface SLBaseLock : NSObject

/** 锁id */
@property (nonatomic, copy) NSString *lockId;
/** 设备标识 */
@property (nonatomic, copy) NSString *peripheralId;
/** 锁mac地址 */
@property (nonatomic, copy) NSString *macAdress;
/** 锁电量 */
@property (nonatomic, assign) int lockBattery;

@end

/*! @brief 该类为result error类
 *
 */
@interface SLError : NSObject

/*
 * 错误码
 * SL开头的错误码是逻辑错误，纯数字的错误码是网络错误
 */
#define Error_TimeOut           @"SL300" // 操作超时

#define Error_BluetoothOff      @"SL301" // 蓝牙未开启
#define Error_ConnectFail       @"SL302" // 蓝牙连接失败

#define Error_LowBattery        @"SL310" // 电池电量过低
#define Error_DeviceStateFail   @"SL311" // 设备未断开
#define Error_DeviceFail        @"SL312" // 设备不存在

#define Error_PassWrong         @"SL320" // 密码格式有误
#define Error_TimeWrong         @"SL321" // 时间格式有误
#define Error_ModifyFail        @"SL322" // 修改失败
#define Error_DeleteFail        @"SL323" // 删除失败
#define Error_FreezeFail        @"SL324" // 冻结失败
#define Error_ThawFail          @"SL325" // 解冻失败
#define Error_WakenFail         @"SL326" // 唤醒失败
#define Error_ResumeFail        @"SL327" // 恢复失败
#define Error_IntervalFail      @"SL328" // 设置广播间隔失败

#define Error_InitSingular      @"SL330" // 初始化异常
#define Error_InitFail          @"SL331" // 初始化失败
#define Error_RepairFail        @"SL332" // 修复失败

#define Error_UpgradeFail       @"SL340" // 升级失败
#define Error_FileWrong         @"SL341" // 文件md5有误

#define Error_UnlockFail        @"SL350" // 开锁失败

#define Error_SynchroTime       @"SL360" // 同步时间失败

#define Error_ParamWrong        @"SL370" // 参数为空

#define Error_PerformWrong      @"SL380" // 当前存在未处理完的操作

/** 错误码 */
@property (nonatomic, copy) NSString *errCode;
/** 错误信息 */
@property (nonatomic, copy) NSString *errInfo;

@end

@interface SLApiObject : NSObject

/** block回调 */
typedef void(^SLResultBlock)(SLError *error, id object);

/** dfu进度回调 */
typedef void(^SLDFUProgressBlock)(float progress);

@end


//
//  SLApi.h
//  所有Api接口
//
//  Created by SmartLock on 2017/5/3.
//  Copyright © 2017年 LLHD. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SLApiObject.h"

typedef NS_ENUM(NSInteger, SLApiMode){
    SLApiModeDevelopment = 0, // 开发环境
    SLApiModeProduction  = 1, // 正式环境
};

#pragma mark - SLApi

/*! @brief 智能锁Api接口函数类
 *
 * 该类封装了智能锁SDK的所有接口
 */

@interface SLApi : NSObject

/*! @brief 初始化api。
 *
 */
+ (instancetype)api;

/*! @brief 注册api使用环境。
 *
 *  默认是开发环境
 */
- (void)registerModel:(SLApiMode)model;

/*! @brief 开始搜索周边锁具。
 *
 * @param block 操作结果的回调，多次
 * block(SLError *error, SLBaseLock)
 */
- (void)startScanResult:(SLResultBlock)block;

/*! @brief 结束搜索周边锁具。
 *
 */
- (void)stopScan;

/*! @brief 初始化锁具
 *
 * 未初始化的锁id是000000，初始化后改变成唯一，永久不变
 * 初始化后，锁的数据丢失，只保留id
 * @param lock 锁
 * @param code 根据锁的信息向服务器申请的临时code用于该锁该次初始化
 * @block 操作结果的回调
 * block(SLError *error, NSString *lockId)
 * error和lockId都不为nil时，为初始化异常，可以使用修复功能解决失败
 */
- (void)initLock:(SLBaseLock *)lock
            code:(NSString *)code
          result:(SLResultBlock)block;

/*! @brief 获取sdk支持的最新固件版本号
 *
 * 获取sdk支持最新版本号
 * @param block 获取结果的回调
 * block(SLError *error, NSString *version)
 */
- (void)getLastVersionResult:(SLResultBlock)block;

/*! @brief 检测是否需要升级固件
 *
 * 获取sdk支持的最新固件版本号、下载地址以及md5
 * @param lock 锁
 * @param block 获取结果的回调
 * block(SLError *error, NSDictionary(firmware_ver,md5,url))
 * error和dictionary若同时为nil  则当前是最新版
 */
- (void)checkUpdate:(SLBaseLock *)lock
             Result:(SLResultBlock)block;

/*! @brief 固件升级
 *
 * 为指定的锁升级固件版本
 * @param lock 锁
 * @param code 根据锁的信息向服务器申请的临时code用于该锁该次固件升级
 * @param path 已下载的固件本地路径
 * @param md5 该固件md5值
 * @param progressBlock 升级进度回调
 * @param block 升级结果回调
 * block(SLError *error, nil)
 * error为nil时，判断后一位是否为string，全为nil则为升级成功
 */
- (void)updateLockVersion:(SLBaseLock *)lock
                     code:(NSString *)code
                 filePath:(NSString *)path
                  fileMD5:(NSString *)md5
                 progress:(void(^)(float progress))progressBlock
                   result:(SLResultBlock)block;

/*! @brief 修改面板开锁密码
 *
 * 修改面板开锁的密码
 * @param lock 锁
 * @param oldPwd 旧密码
 * @param newPwd 新密码
 * @param code   操作校验码
 * @param block  操作结果的回调
 * block(SLError *error, nil)
 */
- (void)updatePassword:(SLBaseLock *)lock
           oldPassword:(NSString *)oldPwd
           newPassword:(NSString *)newPwd
                  code:(NSString *)code
                result:(SLResultBlock)block;

/*! @brief 修改面板开锁密码时效
 *
 * 延期或者提前结束面板开锁的密码
 * @param lock 锁
 * @param oldPwd 旧密码
 * @param endTime 失效时间戳
 * @param code   操作校验码
 * @param block 操作结果的回调
 * block(SLError *error, nil)
 */
- (void)updatePasswordTime:(SLBaseLock *)lock
               oldPassword:(NSString *)oldPwd
                   endTime:(NSTimeInterval)endTime
                      code:(NSString *)code
                    result:(SLResultBlock)block;

/*! @brief 删除面板开锁密码
 *
 * 删除密码
 * @param lock 锁
 * @param oldPwd 旧密码
 * @param code   操作校验码
 * @param block 操作结果的回调
 * block(SLError *error, nil)
 */
- (void)deletePassword:(SLBaseLock *)lock
           oldPassword:(NSString *)oldPwd
                  code:(NSString *)code
                result:(SLResultBlock)block;

/*! @brief 蓝牙开锁
 *
 * 蓝牙开锁
 * @param lock 锁
 * @param password 开锁密码
 * @param block 开锁结果的回调
 * block(SLError *error, nil)
 */
- (void)unlock:(SLBaseLock *)lock
      password:(NSString *)password
        result:(SLResultBlock)block;

/*! @brief 修复功能
 *
 * 专门针对初始化异常进行修复
 * @param lock 锁
 * @param block 修复结果的回调
 * block(SLError *error, nil)
 */
- (void)repairLock:(SLBaseLock *)lock
            result:(SLResultBlock)block;

/*! @brief 取消操作
 *
 * 取消sdk的调用,固件升级无法取消
 */
- (void)cancelPreviousPerformRequest;

@end


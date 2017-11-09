//
//  LLFirmwareUpgrader.h
//  Pods
//
//  Created by 黄强强 on 17/3/15.
//
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface LLBLEFirmwareUpgrader : NSObject

/**
 固件更新接口
 
 只适用于nordic默认的service和characteristic的UUID
 
 @param peripheral 需要更新固件的设备
 @param firmwarePath 固件url
 @param progressHandler 更新进度回调
 @param completeHandler 更新成功或失败的回调
 */
- (void)startUpgradeFirmwareWithCentralManager:(CBCentralManager *)cmgr peripheral:(CBPeripheral *)peripheral firmwarePath:(NSString *)firmwarePath progressHandler:(void (^)(float progress))progressHandler completeHandler:(void (^)(NSError *error))completeHandler;

@end

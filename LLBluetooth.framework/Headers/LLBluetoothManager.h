//
//  LLBluetooth.h
//  Module Demo
//
//  Created by 黄强强 on 17/2/28.
//  Copyright © 2017年 黄强强. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "LLBluetoothDecoder.h"

typedef void(^LLBLEUpdateStateHandler)(CBCentralManager *central);
typedef void(^LLBLEDiscoverPeripheralHandler)(CBPeripheral *peripheral, NSDictionary<NSString *,id> *advertisementData, NSNumber *RSSI, NSError *error);
typedef void(^LLBLEConnectPeripheralHandler)(NSError *error, CBPeripheral *peripheral);
typedef void(^LLBLEReadPeripheralHandler)(NSError *error, NSData *data);
typedef void(^LLBLEWritePeripheralHandler)(NSError *error);
typedef void(^LLBLENotificationHandler)(NSError *error, NSData *data);
typedef void(^LLBLEStopNotificationHandler)(NSError *error);

#pragma mark - const
/*
 decoder成功解码一次数据就会发一次通知
 */
extern NSString * const LLBluetoothDidDecoderWithCharacteristic;

#pragma mark - protocol

@protocol LLBluetoothDelegate <NSObject>
@optional
- (void)bleDidUpdateState:(CBCentralManager *)central;
- (void)bleDidConnectPeripheral:(CBPeripheral *)peripheral;
- (void)bleDidDisconnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;
- (void)bleDidFailToConnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;
- (void)bleDidDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary<NSString *,id> *)advertisementData RSSI:(NSNumber *)RSSI;
- (void)bleDidDiscoverServices:(CBPeripheral *)peripheral error:(NSError *)error;
- (void)bleDidDiscoverCharacteristics:(CBPeripheral *)peripheral forService:(CBService *)service error:(NSError *)error;
- (void)bleDidUpdateValueForCharacteristic:(CBPeripheral *)peripheral characteristic:(CBCharacteristic *)characteristic error:(NSError *)error;
- (void)bleDidUpdateNotificationStateForCharacteristic:(CBPeripheral *)peripheral characteristic:(CBCharacteristic *)characteristic error:(NSError *)error;
- (void)bleDidWriteValueForCharacteristic:(CBPeripheral *)peripheral characteristic:(CBCharacteristic *)characteristic error:(NSError *)error;
@end

#pragma mark - Interface

@interface LLBluetoothManager : NSObject <CBCentralManagerDelegate, CBPeripheralDelegate>

+ (instancetype)manager;


/**
 第一次使用蓝牙调用

 @param handler <#handler description#>
 */
- (void)startWithUpdateStateHandler:(LLBLEUpdateStateHandler)handler;

/**
 解码常规数据，如（CSC/RSC/BPM/HRS/体重...）
 目前支持解析的数据参考，app运行起来后-常规数据解析那一栏
 
 成功解码一次数据后会发LLBluetoothDidDecoderWithCharacteristic通知，数据在object参数中
 */
@property (nonatomic, strong) LLBluetoothDecoder *decoder;

/**
 之前所有扫描到的设备
 */
@property (nonatomic, strong) NSMutableSet *peripherals;

@property (nonatomic, strong) CBCentralManager *manager;

@property (nonatomic, weak) id<LLBluetoothDelegate> delegate;

/**
 根据peripheral UUID获取peripheral

 @param uuid peripheral的UUID
 @return peripheral
 */
- (CBPeripheral *)findPeripheralFromUUID:(NSString *)uuid;

#pragma mark scan

/**
 扫描设备

 @param serviceUUIDStrings 过滤掉serviceUUID不匹配的设备，如果为nil则扫描全部
 @param completeHandler 扫描到一个设备回调一次，同一个设备可能回调扫描到多次
 */
- (void)scanWithServiceUUIDStrings:(NSArray<NSString *> *)serviceUUIDStrings completeHandler:(LLBLEDiscoverPeripheralHandler)completeHandler;

/**
 扫描的时候会过滤掉serviceUUID不匹配的设备，如果为nil则扫描全部

 @param serviceUUIDStrings 过滤掉serviceUUID不匹配的设备，如果为nil则扫描全部
 @param timeoutSeconds 扫描超时时间，超过时间停止扫描
 @param completeHandler 扫描到一个设备回调一次，同一个设备可能回调扫描到多次
 */
- (void)scanWithServiceUUIDStrings:(NSArray<NSString *> *)serviceUUIDStrings timeoutSeconds:(NSTimeInterval)timeoutSeconds completeHandler:(LLBLEDiscoverPeripheralHandler)completeHandler;

/**
 停止扫描
 */
- (void)stopScan;

#pragma mark connect

/**
 连接设备
 
 连接上设备并且自动获取所有service和characteristic。
 所有service和characteristic发现完毕才会回调completeHandler。
 */
- (void)connectWithPeripheral:(CBPeripheral *)peripheral completeHandler:(LLBLEConnectPeripheralHandler)completeHandler;

/**
 连接设备，可设置超时时间
 
 连接上设备并且自动获取所有service和characteristic。
 所有service和characteristic发现完毕才会回调completeHandler。
 */
- (void)connectWithPeripheral:(CBPeripheral *)peripheral timeoutSeconds:(NSTimeInterval)timeoutSeconds completeHandler:(LLBLEConnectPeripheralHandler)completeHandler;

/**
 断开指定的设备
 */
- (void)disconnectWithPeripheral:(CBPeripheral *)peripheral;

/**
 断开所有已连接的设备
 */
- (void)disconnectAllPeripheral;

#pragma mark read

/**
 读取特定特征里面的数据
 
 默认使用nordic UART通信接口的service和characteristic的UUID
 @param completeHandler 成功或失败的回调
 */
- (void)readWithPeripheralForNordic:(CBPeripheral *)peripheral completeHandler:(LLBLEReadPeripheralHandler)completeHandler;

/**
 读取特定特征里面的数据
 
 不使用默认的Nordic service和characteristic
 */
- (void)readWithPeripheralUUID:(NSString *)pUUID serviceUUID:(NSString *)sUUID characteristicUUID:(NSString *)cUUID completeHandler:(LLBLEReadPeripheralHandler)completeHandler;

#pragma mark write

/**
 write
 
 默认使用nordic UART通信接口的service和characteristic的UUID
 @param completeHandler 成功或失败的回调
 */
- (void)writeWithPeripheralForNordic:(CBPeripheral *)peripheral data:(NSData *)data completeHandler:(LLBLEWritePeripheralHandler)completeHandler;

/**
 write
 
 不使用默认的Nordic service和characteristic
 */
- (void)writeWithPeripheralUUID:(NSString *)pUUID serviceUUID:(NSString *)sUUID characteristicUUID:(NSString *)cUUID data:(NSData *)data completeHandler:(LLBLEWritePeripheralHandler)completeHandler;

/**
 write，无回调
 
 默认使用nordic UART通信接口的service和characteristic的UUID
 */
- (void)writeWithoutResponseWithPeripheralForNordic:(CBPeripheral *)peripheral data:(NSData *)data;

/**
 write，无回调
 
 不使用默认的Nordic service和characteristic
 */

- (void)writeWithoutResponseWithPeripheralUUID:(NSString *)pUUID serviceUUID:(NSString *)sUUID characteristicUUID:(NSString *)cUUID data:(NSData *)data;

#pragma mark subscribe

/**
 订阅设备
 
 默认使用nordic UART通信接口的service和characteristic的UUID
 @param completeHandler 订阅成功或失败的回调
 */
- (void)subscribeWithPeripheralForNordic:(CBPeripheral *)peripheral completeHandler:(LLBLENotificationHandler)completeHandler;

/**
 订阅设备
 
 不使用默认的Nordic service和characteristic
 */
- (void)subscribeWithPeripheralUUID:(NSString *)pUUID serviceUUID:(NSString *)sUUID characteristicUUID:(NSString *)cUUID completeHandler:(LLBLENotificationHandler)completeHandler;

/**
 取消订阅
 
 默认使用nordic UART通信接口的service和characteristic的UUID
 @param completeHandler 成功或失败的回调
 */
- (void)unsubscribeWithPeripheralForNordic:(CBPeripheral *)peripheral completeHandler:(LLBLEStopNotificationHandler)completeHandler;

/**
 取消订阅
 
 不使用默认的Nordic service和characteristic
 */
- (void)unsubscribeWithPeripheralUUID:(NSString *)pUUID serviceUUID:(NSString *)sUUID characteristicUUID:(NSString *)cUUID completeHandler:(LLBLEStopNotificationHandler)completeHandler;


/**
 蓝牙是否可用
 */
- (BOOL)isEnabled;

#pragma mark - 固件更新接口

/**
 固件更新接口
 
 只适用于nordic默认的service和characteristic的UUID
 
 @param peripheral 需要更新固件的设备
 @param firmwarePath 固件url
 @param progressHandler 更新进度回调
 @param completeHandler 更新成功或失败的回调
 */
- (void)startUpgradeFirmwareWithPeripheralForNordic:(CBPeripheral *)peripheral firmwarePath:(NSString *)firmwarePath progressHandler:(void (^)(float progress))progressHandler completeHandler:(void (^)(NSError *error))completeHandler;

@end


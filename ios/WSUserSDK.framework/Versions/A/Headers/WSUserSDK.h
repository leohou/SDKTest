//
//  WSUserSDK.h
//  WSUserSDK
//
//  Created by houli on 2017/6/9.
//  Copyright © 2017年 leohou. All rights reserved.
//  v2.0.0

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WSGLoginConfigModel.h"


/**
 *
 */
typedef NS_ENUM(NSInteger, WSGUserLoginType) {
    WSGLoginTypePhoneCode = 1,
    WSGLoginTypePhonePwd = 2,
    WSGLoginTypeWeiXin = 3,
    WSGLoginTypeVisitors = 4,
    
};



/**
 *  设备方向
 **/
typedef NS_ENUM(NSInteger, WSGDeviceOrientation) {
    WSGDeviceOrientationDefaulter = 0, //默认 横屏
    WSGDeviceOrientationLandScape , //横屏
    WSGDeviceOrientationPortrait , //竖屏
};

/**
 *  设备方向
 **/
typedef NS_ENUM(NSInteger, WSGAutologinUI) {
    WSGAutologinUIDefaulter = 0, //默认 显示自动登录UI
    WSGAutologinUIHide , //  隐藏
    WSGAutologinUIShow , // 显示
};


/**
 登录 结果
 **/
typedef NS_ENUM(NSInteger,WSGLoginResultCode) {
    WSGLoginResultSucceed =0,  //登录成功
    WSGLoginResultFailed =1, // 登录失败
    WSGLoginResultMissingRequiredParameter =2, // 缺少必要参数（手机号or appid）
    WSGLoginResultInterfaceError =3,//  接口错误
    WSGLoginResutNoChannelIdAndSecret=4  //  缺少channelId或APPSecret
    
};

// 登录结果信息
@class WSUVModel;
@interface WSGUserLoginResultModel : NSObject

@property (nonatomic, strong) NSString * resultMessage; // 登录结果描述
@property (nonatomic, assign) WSGLoginResultCode code; // 登录状态码
@property (nonatomic, strong) NSString *userid;
@property (nonatomic, strong) NSString *marketid;
@property (nonatomic, strong) NSString *mobile;
@property (nonatomic, assign) WSGUserLoginType loginType; // 登录方式


@end

typedef void(^LoginResult)(WSGUserLoginResultModel * resultModel);





@interface WSUserSDK : NSObject

+ (instancetype)shardInstance;


/**
  横竖屏开关
 **/

+ (void)setSupportedInterfaceOrientations:(BOOL)on;


/**
 游客登录开关
 **/

/**
 注册用户SDK
 @param marketId 渠道ID
 @param  appSecret
 @param  appid
 @param  callbackUrl string `回调url`
 */
- (void)registerApp:(NSString *)marketId appSecret:(NSString *)appSecret appid:(NSString *)appid callbackUrl:(NSString *)callbackUrl;

/**
 注册用户SDK
 @param marketId 渠道ID
 @param  appSecret
 @param  appid
 @param  callbackUrl string `回调url`
 @param  wxappId
 @param  wxappSecret
 */
//2.0 对外暴露方法
- (void)registerApp:(NSString *)marketId appSecret:(NSString *)appSecret appid:(NSString *)appid callbackUrl:(NSString *)callbackUrl wxappId:(NSString *)wxappId wxappSecret:(NSString *)wxappSecret;

/**
 登录调取方法
 @param parameters 配置参数 现在传空
 @param controller 是显示UI用
 @param completion 登录完成的回调(成功和失败状态码)
 */
- (void)wsPresentedLoginWithParameters:(NSDictionary *)parameters withController:(UIViewController *)controller completion:(LoginResult) completion;


/**
 登录调取方法 必传参数
 @param view  登录展示界面
 @param isLandScape 是横屏 还是  竖屏  默认横屏
 @param isAutologinHideUI 是否显示 自动登录UI  默认显示
 @param completion 登录完成的回调(成功和失败状态码)
 */
- (void)wsLoginIntentView:(UIView *)view withLandScape:(WSGDeviceOrientation)orientation withAutoLoginHideUI:(WSGAutologinUI)autologinUI completion:(LoginResult) completion;


/**
 *   退出 接口
 *   view 游戏界面
 */
- (void)wsLogout:(UIView *)view;

/**
 获取当前用户ID
*/
+ (NSString *)getCurrentUserID;

/**
 获取IDFA
 */
+ (NSString *)getIDFA;
/**
 获取uuid
 */
+ (NSString *)getUUID;


/**
  tost 提示
 */
+ (void)dimmissInfo:(NSString *)info;

/**
  设置发送验证码时长
 */
+ (void)setCode:(NSInteger )code;

/**
 设置导航栏字体
 */
+ (void)setNavTitle:(NSString * )title;

/**
  取消页面
 */
+ (void)cancelViewController:(UIViewController *)viewController;

/**
  是否取消登录的返回按钮
 */
+ (void)setCloseLoginBack:(BOOL)isClose;

@end

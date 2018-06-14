//
//  PrefixHeader.h
//  RXExtenstion
//
//  Created by srx on 16/4/29.
//  Copyright © 2016年 srxboys. All rights reserved.
//

//此工程中 当前文件 是全局的

#ifndef PrefixHeader_h
#define PrefixHeader_h

#import "RXMessage.h"

#ifdef __OBJC__
//此方法隔离 OC库的导入，防止工程中添加C/C++ 文件时 这里报错
    #import <UIKit/UIKit.h>
    #import <Foundation/Foundation.h>


    //------------
    //对于汉字打印处理
    #import "RXColorLog.h"
    #import "RXCharacter.h"
    #import "NSArray+RXArrLog.h"
    #import "NSDictionary+RXDictLog.h"
//------------
#endif

/// 实时监听网络 带参数的通知--- 只有baseController和自定义的View会用
#define rxGetNetworkStatusNotification @"rxGetNetworkStatusNotification"
//实时监听的网络状态
#define RXNetworksStatusNone  @"RXNetworksStatusNone"
#define RXNetworksStatusWifi  @"RXNetworksStatusWifi"
#define RXNetworksStatusPhone @"RXNetworksStatusPhone"


/*
 * ------ 状态栏 旋转小菊花 ----
 */
#define STATUS_BAR_START() [UIApplication sharedApplication].networkActivityIndicatorVisible = YES
#define STATUS_BAR_STOP() [UIApplication sharedApplication].networkActivityIndicatorVisible = NO



/*
 * 控制器 类名
 */
#define SELF_CLASS_NAME  NSStringFromClass([self class])

#define SharedAppDelegate ((AppDelegate*)[[UIApplication sharedApplication] delegate])

///storybaord
#define RXStroyBoard(_name, _identifier) [[UIStoryboard storyboardWithName:_name bundle:nil] instantiateViewControllerWithIdentifier:_identifier]
#define RXMeStroBoard(_identifier) [self.storyboard instantiateViewControllerWithIdentifier:_identifier]
/*
 ------ 宽 高 定义 ----
 */
#pragma mark ---- 宽 高 定义 --------
#define ScreenWidth  [UIScreen mainScreen].bounds.size.width
#define ScreenHeight [UIScreen mainScreen].bounds.size.height

#define StatusHeight           ([UIApplication sharedApplication].statusBarFrame.size.height)

#define NavHeight     44+StatusHeight
#define TabbarHeight  49

//宽高比定义  roundf 四舍五入函数
#define ActureHeight(_height)  roundf(_height/375.0 * ScreenWidth)
#define ActureHeightV(_height) roundf(_height/667.0 * ScreenHeight)

/*
 简单的frame获取
 */
#define ViewWidth(v)                        v.frame.size.width
#define ViewHeight(v)                       v.frame.size.height
#define ViewX(v)                            v.frame.origin.x
#define ViewY(v)                            v.frame.origin.y
#define ViewBottom(v)                       ViewY(v)+ViewHeight(v)
#define ViewRight(v)                        ViewX(v)+ViewWidth(v)


#define SelfViewWidth                       self.view.bounds.size.width
#define SelfVi

#define RectX(rect)                            rect.origin.x
#define RectY(rect)                            rect.origin.y
#define RectWidth(rect)                        rect.size.width
#define RectHeight(rect)                       rect.size.height

#define RectSetWidth(rect, w)                  CGRectMake(RectX(rect), RectY(rect), w, RectHeight(rect))
#define RectSetHeight(rect, h)                 CGRectMake(RectX(rect), RectY(rect), RectWidth(rect), h)
#define RectSetX(rect, x)                      CGRectMake(x, RectY(rect), RectWidth(rect), RectHeight(rect))
#define RectSetY(rect, y)                      CGRectMake(RectX(rect), y, RectWidth(rect), RectHeight(rect))

#define RectSetSize(rect, w, h)                CGRectMake(RectX(rect), RectY(rect), w, h)
#define RectSetOrigin(rect, x, y)              CGRectMake(x, y, RectWidth(rect), RectHeight(rect))


#define SET_VIEW_LEFT(__view, __x) \
do{ \
    CGRect frame = __view.frame; \
    frame.origin.x = __x; \
    __view.frame = frame; \
}while(0)


#define SET_VIEW_TOP(__view, __y) \
do{ \
    CGRect frame = __view.frame; \
    frame.origin.y = __y; \
    __view.frame = frame; \
}while(0)

#define SET_VIEW_WIDTH(__view, __w) \
do{ \
    CGRect frame = __view.frame; \
    frame.size.width = __w; \
    __view.frame = frame; \
}while(0)

#define SET_VIEW_HEIGHT(__view, __h) \
do{ \
    CGRect frame = __view.frame; \
    frame.size.height = __h; \
    __view.frame = frame; \
}while(0)

#define SET_VIEW_RIGHT(__view, __right) \
do{ \
    CGRect frame = __view.frame; \
    frame.origin.x = __right - frame.size.width; \
    __view.frame = frame; \
}while(0)

#define SET_VIEW_BOTTOM(__view, __bottom) \
do{ \
    CGRect frame = __view.frame; \
    frame.origin.y = __bottom - frame.size.height; \
    __view.frame = frame; \
}while(0)

/**
 ----------------------【iOS 版本 定义】------------------------------------------
 *
 *  这里只是版本号的 获取
 ****想要详细的    //应用标识//应用名称。请到NSBundle+Extensions.h里看
 */
// 是否iPad
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
// 是否iPad
#define someThing (isPad) ? ipad : iphone

//判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
    #define SIMULATOR_TEST 1
#else
    #define SIMULATOR_TEST 0
#endif

//获取当前语言
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])


#pragma mark ---- iOS 版本 定义 --------
//操作系统版本
#define SYSTEMVERSION   [UIDevice currentDevice].systemVersion

//大于多少版本
#define iOS7OrLater ([SYSTEMVERSION floatValue] >= 7.0)
#define iOS8OrLater ([SYSTEMVERSION floatValue] >= 8.0)
#define iOS9OrLater ([SYSTEMVERSION floatValue] >= 9.0)
#define iOS10OrLater ([SYSTEMVERSION floatValue] >= 10.0)

//和上面一样
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([SYSTEMVERSION compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([SYSTEMVERSION compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL(v)  ([SYSTEMVERSION compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([SYSTEMVERSION compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([SYSTEMVERSION compare:v options:NSNumericSearch] != NSOrderedDescending)

//  iOS 支持
#define SUPPORT_IPHONE_OS_VERSION(version) ( __IPHONE_OS_VERSION_MIN_REQUIRED <= version && __IPHONE_OS_VERSION_MAX_ALLOWED >= version)

//iOS 屏幕大小
#pragma mark ---- iOS 屏幕大小 定义 --------
#define iPhone4 (CGSizeEqualToSize(CGSizeMake(320, 480), [UIScreen mainScreen].bounds.size) ? YES : NO)
#define iPhone5 (CGSizeEqualToSize(CGSizeMake(320, 568), [UIScreen mainScreen].bounds.size) ? YES : NO)
#define iPhone6 (CGSizeEqualToSize(CGSizeMake(375, 667), [UIScreen mainScreen].bounds.size) ? YES : NO)
#define iPhone6Plus (CGSizeEqualToSize(CGSizeMake(414, 736), [UIScreen mainScreen].bounds.size) ? YES : NO)

//边框 特殊处理--运行看看再有问题该frame
#define BorderWidth (iPhone6Plus ? 0.35 : 0.5)
//1.iPhone4分辨率320x480，像素640x960，@2x
//2.iPhone5分辨率320x568，像素640x1136，@2x
//3.iPhone6分辨率375x667，像素750x1334，@2x
//4.iPhone6 Plus分辨率414x736，像素1242x2208，@3x

//通用字体设置大小
#ifdef iPhone6Plus
    #define GHSFont(_fontSize) _fontSize * 1.5
#else
    #define GHSFont(_fontSize) _fontSize
#endif

//系统字体
#define FontBase(size) [UIFont systemFontOfSize:size]
#define FontBold(size) [UIFont boldSystemFontOfSize:size]


#pragma mark ---- 内存 --------
//----------------------内存----------------------------
//使用ARC和不使用ARC
#if __has_feature(objc_arc)
//compiling with ARC
#else
// compiling without ARC
#endif

#pragma mark - common functions
#define RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }

//释放一个对象
#define SAFE_DELETE(P) if(P) { [P release], P = nil; }
#define SAFE_RELEASE(x) [x release];x=nil



//#pragma mark ---- 去除 performSelector警告 --------
//去除"-(id)performSelector:(SEL)aSelector withObject:(id)object;"的警告
#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)

#pragma mark ---- GCD --------
/*
 ----- GCD -------
 */
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)


#pragma mark ---- 单例 --------
/*
   ----- 单例 -------
 */
#define DEFINE_SINGLETON_FOR_HEADER(className)\
+(className* )shared##className;
#define DEFINE_SINGLETON_FOR_CLASS(className)\
+ (className *)shared##className {\
    static className *shared##className = nil;\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        @synchronized(self){\
            shared##className = [[self alloc] init];\
        }\
    }); \
    return shared##className; \
}


/**
 ----------------------【字符串处理 定义】------------------------------------------
 *
 *  这里只是number转String
 *
 *********想要详细的.请到RXCharacter.h里看
 **** 1、判断字符串是否为空
 **** 2、对于控制符、nil、<nil>的字符处理
 **** 3、返回【判断后的数组】
 **** 4、是否是数组
 **** 5、是否是字典。
 *********
 */
#pragma mark ---- num转NSString 定义 --------
//number转String
#define STRING_OF_FLOAT(num) [NSString stringWithFormat:@"%.2f", num]
#define STRING_OF_INT(num) [NSString stringWithFormat:@"%zd", num]
#define STRING_FORMAT(str, ...) [NSString stringWithFormat:str, __VA_ARGS__]

#pragma mark ---- notifacation 通知定义 --------
/**
 ----------------------【通知 定义】------------------------------------------
 *
 * 全局通知 (不包含 kvc kvo)
 */
#define addobserver(obserObject,eumMethod,obserName,...)    [[NSNotificationCenter defaultCenter] addObserver:obserObject selector:eumMethod name:obserName object:nil]

#define postNotifacation(obserName,obserObject,dataInfo)    [[NSNotificationCenter defaultCenter] postNotificationName:obserName object:obserObject userInfo:dataInfo]


#define removeNotification(obserObject,obserName)       [[NSNotificationCenter defaultCenter] removeObserver:obserObject name:obserName object:nil]

#pragma mark ---- 沙盒 --------
//  沙盒
#define UserDefaults      [NSUserDefaults standardUserDefaults]

#define UserSaveSetting(key, value)\
NSUserDefaults *def =[NSUserDefaults standardUserDefaults];\
[def setObject:value forKey:key];\
[def synchronize];


#define UserGetSetting(key)   [[NSUserDefaults standardUserDefaults] objectForKey:key]

#define UserRemoveSetting(key) \
NSUserDefaults *def =[NSUserDefaults standardUserDefaults];\
[def removeObjectForKey:key];\
[def synchronize];

#define LibraryCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]
#define RXCacheFile(_fileName) [NSString stringWithFormat:@"%@/%@",LibraryCache,_fileName]

/**
 ----------------------【view设置 定义】------------------------------------------
 *
 * view的子类:btn、label、textField等等
 */
#pragma mark ---- view设置 --------
// View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// View 圆角
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]



/// 给 view 添加阴影
#define ViewShadow(View,color,size,opacity,radius,cRadius)\
\
[View.layer setShadowColor:[color CGColor]];\
[View.layer setShadowOffset:size];\
[View.layer setShadowOpacity:opacity];\
[View.layer setShadowRadius:radius];\
[View.layer setCornerRadius:cRadius];\

//角度转弧度
#define DEGREES_TO_RADIANS(d) (d * M_PI / 180)

/**
 ----------------------【颜色定义】------------------------------------------
 */
#pragma mark ---- 颜色定义 --------

//清除背景色
#define CLEARCOLOR [UIColor clearColor]

#ifdef __OBJC__
//此方法隔离 OC库的导入，防止工程中添加C/C++ 文件时 这里报错
    #pragma mark ---- 颜色定义 --------
    #import "RXHexColor.h"
#endif

#define UIColorHexStr(_color) [RXHexColor colorWithHexString:_color]
#define UIColorHexStrAlpha(_color,__alpha) [RXHexColor colorWithHexString:_color alpha:__alpha]

#define UIColorHex(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define UIColorHexAlpha(rgbValue,__alpha) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(__alpha)]

// 随机色
#define UIColorRandom UIColorRGB(arc4random_uniform(256), \
arc4random_uniform(256), \
arc4random_uniform(256))


#define UIColorRGB(r, g, b)     [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1.0f]
#define UIColorRGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)/255.0]
#define UIColorHSL(h, s, l)     [UIColor colorWithHue:(h)/255.0f saturation:(s)/255.0f brightness:(l)/255.0f alpha:1.0f]
#define UIColorHSLA(h, s, l, a) [UIColor colorWithHue:(h)/255.0f saturation:(s)/255.0f brightness:(l)/255.0f alpha:(a)/255.0f]

#define GHS_231_231_231_COLOR UIColorRGB(231, 231, 231)
#define GHS_666_COLOR         UIColorRGB(102, 102, 102)

#endif /* PrefixHeader_h */

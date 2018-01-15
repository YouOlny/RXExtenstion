//
//  UIViewController+RXExclusiveTouch.m
//  RXExtenstion
//
//  Created by srxboys on 2018/1/15.
//  Copyright © 2018年 https://github.com/srxboys. All rights reserved.
//
//当前页面 防止多次点击

//切记，这个最好不要 用，如果是 视频类(直播、短视频) 点赞操作 会有影响

#import "UIViewController+RXExclusiveTouch.h"
#import <objc/runtime.h>


@implementation UIViewController (RXExclusiveTouch)
+ (void)load {
    SEL oldSel = @selector(viewDidAppear:);
    SEL newSel = @selector(swizzle_viewDidAppear);
    
    Class selfClass = [self class];
    Method oldMethod = class_getInstanceMethod(selfClass, oldSel);
    Method newMethod = class_getInstanceMethod(selfClass, newSel);
    
    /**
     *  我们在这里使用class_addMethod()函数对Method Swizzling做了一层验证，如果self没有实现被交换的方法，会导致失败。
     *  而且self没有交换的方法实现，但是父类有这个方法，这样就会调用父类的方法，结果就不是我们想要的结果了。
     *  所以我们在这里通过class_addMethod()的验证，如果self实现了这个方法，class_addMethod()函数将会返回NO，我们就可以对其进行交换了。
     */
    if (!class_addMethod(selfClass, @selector(swizzle_viewDidAppear), method_getImplementation(oldMethod), method_getTypeEncoding(newMethod))) {
        method_exchangeImplementations(oldMethod, newMethod);
    }
}

- (void)swizzle_viewDidAppear {
    [self setExclusiveTouchForButtons:self.view];
    [self swizzle_viewDidAppear];
}

-(void)setExclusiveTouchForButtons:(UIView *)myView
{
    for (UIView * v in [myView subviews]) {
        if([v isKindOfClass:[UIButton class]])
            [((UIButton *)v) setExclusiveTouch:YES];
        else if ([v isKindOfClass:[UIView class]]){
            [self setExclusiveTouchForButtons:v];
        }
    }
}

@end

//
//  RXHomeController.m
//  RXExtenstion
//
//  Created by srx on 16/5/3.
//  Copyright © 2016年 srxboys. All rights reserved.
//

#import "RXHomeController.h"

#import "RXFalseDataController.h" //假数据 
#import "RXUploadImageController.h" //上传请求 例子
#import "RXNewHomeController.h"
#import "RXCaCheController.h"
#import "RXExpansionContractionController.h"
#import "RXSystemServerController.h"
#import "RXMenuController.h"
#import "RXSearchViewController.h"
#import "RXLoLInfoViewController.h"
#import "RXUseSwiftViewController.h"
#import "RXTouchIDViewController.h"

@interface RXHomeController ()<UITableViewDataSource, UITableViewDelegate>
{
    NSArray * arr;
}
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *tableHeaderHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *tableFooterHeight;
@property (weak, nonatomic) IBOutlet UITableView *tableView;

@end

@implementation RXHomeController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.tabBarItem.title = @"首页";
    
    
//    NSDictionary * dit = @{@1:@""};
//    RXLog(@"dict%@", dit);
//    RXLog(@"dict_value=%@", [dit objectForKey:[NSNumber numberWithUnsignedInteger:1]]);
//    RXLog(@"dict_2222=%@", dit[@"1"]);
    
    
    [self configUI];
}

- (void)configUI {
    
    _tableView.tableFooterView = [[UIView alloc] init];
    
    
    arr = @[@"假数据无需手动",
            @"缓存操作 - 有C代码",
            @"获取info.plist信息 使用【RXBundle】",
            @"MJ header foother",
            @"系统宏定义",
            @"上传图片/头像",
            @"AFN 请求接口",
            @"tableViewCell 展开收缩",
            @"系统中的功能",
            @"自定义点餐菜单框架",
            @"分类模块--搜索",
            @"一个完整的界面demo-coding",
            @"LOL--【我的】顶部效果-coding",
            @"OC中使用Swift方法",
            @"真机 Touch ID / Face ID",
            @"渐变",
            @"系统分段控制器",
            @"自定义分段控制器",
            @"TextField定制",
            ];
    [_tableView reloadData];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return arr.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSString * cellIdentifier = @"cellIdentifier";
    UITableViewCell * cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    cell.textLabel.text = arr[indexPath.row];
    cell.textLabel.textAlignment = NSTextAlignmentCenter;
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
//    if(indexPath.row == 0) {
////        cell.selectionStyle = UITableViewCellSelectionStyleNone;
//        cell.userInteractionEnabled = NO;
//    }
    return cell;
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    RXLog(@"%ld", (long)indexPath.row);
    NSInteger row = indexPath.row;
    if(row == 0) {
        /// 假数据无需手动
        RXFalseDataController * vc = RXStroyBoard(@"Home", @"RXFalseDataController");
        //当前页面 隐藏 TabBar
        vc.hidesBottomBarWhenPushed = YES;//可以不写，我在baseNav里有处理
        [self.navigationController pushViewController:vc animated:YES];
    }
    else if(row == 1) {
        /// 缓存操作
        RXCaCheController * upController = RXStroyBoard(@"Home", @"RXCaCheController");
        upController.hidesBottomBarWhenPushed = YES;//可以不写，我在baseNav里有处理
        [self.navigationController pushViewController:upController animated:YES];
    }
    else if (row == 4) {
        Class vcClass = NSClassFromString(@"RXSystemAlertController");
        UIViewController * vc = (UIViewController *)[vcClass new];
        [self.navigationController pushViewController:vc animated:YES];
    }
    else if(row == 5) {
        /// 上传图片/头像
        RXUploadImageController * upController = RXStroyBoard(@"Home", @"RXUploadImageController");
        //两种方法都行
//        RXUploadImageController * upController = RXMeStroBoard(@"RXUploadImageController");
        upController.hidesBottomBarWhenPushed = YES;//可以不写，我在baseNav里有处理
        [self.navigationController pushViewController:upController animated:YES];
    }
    else if(row == 7) {
        /// tableViewCell 展开收缩 【存代码】
        RXExpansionContractionController * ecController = [[RXExpansionContractionController alloc] init];
        ecController.hidesBottomBarWhenPushed = YES;//可以不写，我在baseNav里有处理
        [self.navigationController pushViewController:ecController animated:YES];
    }
    else if(row == 8) {
        /// 系统中的功能【storyboard 写的】
        RXSystemServerController * systemSeverController = RXStroyBoard(@"Home", @"RXSystemServerController");
        systemSeverController.hidesBottomBarWhenPushed = YES;//可以不写，我在baseNav里有处理
        [self.navigationController pushViewController:systemSeverController animated:YES];
    }
    else if(row == 9) {
        /// 自定义点餐菜单框架
        RXMenuController * menuController = [[RXMenuController alloc] init];
        menuController.hidesBottomBarWhenPushed = YES;//可以不写，我在baseNav里有处理
        [self.navigationController pushViewController:menuController animated:YES];
    }
    else if(row == 10) {
        /// 分类模块--搜索
        RXSearchViewController * searchController = [[RXSearchViewController alloc] init];
        searchController.hidesBottomBarWhenPushed = YES;//可以不写，我在baseNav里有处理
        [self.navigationController pushViewController:searchController animated:YES];
    }
    else if(row == 11) {
        //完整的界面demo
        RXNewHomeController * homeControll = [[RXNewHomeController alloc] init];
        homeControll.hidesBottomBarWhenPushed = YES;//可以不写，我在baseNav里有处理
        [self.navigationController pushViewController:homeControll animated:YES];
    }
    else if(row == 12) {
        /// LOL--【我的】顶部效果
        RXLoLInfoViewController * lolInfo = [[RXLoLInfoViewController alloc] init];
        [self.navigationController pushViewController:lolInfo animated:YES];
    }
    else if(row == 13) {
        /// OC中使用Swift方法
        RXUseSwiftViewController * useSwiftVC = [[RXUseSwiftViewController alloc] init];
        [self.navigationController pushViewController:useSwiftVC animated:YES];
    }
    else if(row == 14) {
        /// Touch ID / Face ID
        RXTouchIDViewController * touchIDVC = [[RXTouchIDViewController alloc] init];
        [self.navigationController pushViewController:touchIDVC animated:YES];
    }
    else if (row == 15) {
        /// 渐变
        [self pushViewControllWithVCName:@"RXGradientViewController"];
    }
    else if(row == 16) {
        /// 系统分段控制器
        [self pushViewControllWithVCName:@"RXSegmentController"];
    }
    else if(row == 17) {
        /// 自定义分段控制器
        [self pushViewControllWithVCName:@"RXSegmentController"];
    }
    else if(row == 18) {
        /// TextField定制
        [self pushViewControllWithVCName:@"RXTextFieldViewController"];
    }
}

- (void)pushViewControllWithVCName:(NSString *)vcName {
    //危险的写法(不推荐)
    Class vcClass = NSClassFromString(vcName);
    if(!vcClass) return;
    UIViewController * vc = (UIViewController *)[vcClass new];
    if(!vc) return;
    [self.navigationController pushViewController:vc animated:YES];
}


- (void)networkChange:(NSString *)status {
    RXLog(@"net_change=%@", status);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end

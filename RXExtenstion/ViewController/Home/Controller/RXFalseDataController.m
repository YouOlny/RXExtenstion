//
//  RXFalseDataController.m
//  RXExtenstion
//
//  Created by srx on 16/5/3.
//  Copyright © 2016年 srxboys. All rights reserved.
//

#import "RXFalseDataController.h"
#import "RXRandom.h"
#import "MJRefresh.h"
#import "RXMJHeaderGif.h"

@interface RXFalseDataController ()<UITableViewDelegate, UITableViewDataSource>
{
    NSArray * arr;
}
@property (weak, nonatomic) IBOutlet UITableView *tableView;

@end

@implementation RXFalseDataController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"下拉刷新、假数据";
    [self configUI];
}

- (void)configUI {
    _tableView.tableFooterView = [[UIView alloc] init];
    _tableView.mj_header = [RXMJHeaderGif headerWithRefreshingTarget:self refreshingAction:@selector(changeTableSourceArr)];
    [self changeTableSourceArr];
}
- (void)changeTableSourceArr {
    arr = @[[NSString stringWithFormat:@"日期=%@",[RXRandom randomDateString]],
            [NSString stringWithFormat:@"汉字=%@",[RXRandom randomChinas]],
            [NSString stringWithFormat:@"字符串=%@",[RXRandom randomChinas]],
            [NSString stringWithFormat:@"字母=%@",[RXRandom randomChinas]],
            [NSString stringWithFormat:@"图片=%@",[RXRandom randomImageURL]],
            ];
    [_tableView.mj_header endRefreshing];
    [_tableView reloadData];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return arr.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString * cellIdentifier = @"cell";
    UITableViewCell * cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    cell.textLabel.text = arr[indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end

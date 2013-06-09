//
//  ButtonTest.h
//  Button
//
//  Created by 藤澤　健治 on 2013/06/08.
//
//

#import <SenTestingKit/SenTestingKit.h>
#import "cocos2d.h"

@interface ButtonTest : SenTestCase

@end

class MenuHandlerMock : public cocos2d::CCObject
{
public:
    bool called;
    MenuHandlerMock();
    void tapped();
};

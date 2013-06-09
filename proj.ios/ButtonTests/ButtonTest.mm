//
//  ButtonTest.m
//  Button
//
//  Created by 藤澤　健治 on 2013/06/08.
//
//

#import "ButtonTest.h"
#import "Button.h"

@implementation ButtonTest

- (void)testText
{
    Button* button = Button::create();
    STAssertTrue(strcmp(button->getText(), "") == 0, @"text expected %s, but was %s", @"", button->getText());
    
    button->setText("foo");
    STAssertTrue(strcmp(button->getText(), "foo") == 0, @"text expected %s, but was %s", @"foo", button->getText());
}

- (void)testTapped
{
    MenuHandlerMock mock;
    
    Button* button = Button::create();
    button->setTarget(&mock, menu_selector(MenuHandlerMock::tapped));
    button->setPosition(ccp(100, 100));
    button->setContentSize(CCSize(100, 100));
    
    STAssertFalse(mock.called, @"called expected false, but was true");
    
    CCPoint p1 = CCDirector::sharedDirector()->convertToGL(ccp(0, 0));
    CCTouch t1;
    t1.setTouchInfo(0, p1.x, p1.y);
    button->ccTouchEnded(&t1, NULL);
    
    STAssertFalse(mock.called, @"called expected false, but was true");
    
    CCPoint p2 = CCDirector::sharedDirector()->convertToGL(ccp(100, 100));
    CCTouch t2;
    t2.setTouchInfo(1, p2.x, p2.y);
    button->ccTouchEnded(&t2, NULL);
    
    STAssertTrue(mock.called, @"called expected true, but was false");
}

@end

MenuHandlerMock::MenuHandlerMock()
: called(false)
{
}

void MenuHandlerMock::tapped()
{
    this->called = true;
}

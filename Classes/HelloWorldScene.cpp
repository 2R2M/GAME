#include "HelloWorldScene.h"
#include <cstdlib>
#include "GameOverScene.h"


USING_NS_CC; // макрос использования пространства имён cocos2d::

Scene* HelloWorld::createScene()
{
    // все указатели, которые порождает Cocos - 2dx уже находятся под контролем выделенной памяти. Поэтому они не требуют явного удаления через delete или обертки в интеллектуальный указатель
    auto scene = Scene::create(); // создаем сцену
    auto layer = HelloWorld::create(); // создаем слой сцены

    scene->addChild(layer); // добавляем слой как ребенка на сцену

    return scene;
}

bool HelloWorld::init()
{
    if (!Layer::init()) // если мы не можем проинициализировать - просто выходим
    {
        return false;
    }

    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto spriteBack = cocos2d::Sprite::create("C:\\Users\\User\\Desktop\\TESTGAME_1\\Resources\\grass.png");
    spriteBack->setPosition(cocos2d::Vec2(350, 350));
    this->addChild(spriteBack);
    sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    this->addChild(sprite);
    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {

        onKeyPressed(keyCode, event);
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);
 
    auto randomPoint = Vec2(rand() % 500, rand() % 700);
    sprite2->setPosition(randomPoint);
    this->addChild(sprite2);
    this->scheduleUpdate();
    return true;

}



void HelloWorld::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event) {
   
    if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_W || keyCode == cocos2d::EventKeyboard::KeyCode::KEY_W)
    {
        pressedW = true;
    }
    else
    {
        pressedW = false;
    }
    if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_S || keyCode == cocos2d::EventKeyboard::KeyCode::KEY_S)
    {
        pressedS = true;
    }
    else
    {
        pressedS = false;
    }
    if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_D || keyCode == cocos2d::EventKeyboard::KeyCode::KEY_D)
    {
        pressedD = true;
    }
    else
    {
        pressedD = false;
    }
    if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_A || keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A)
    {
        pressedA = true;
    }
    else
    {
        pressedA = false;
    }

}


void HelloWorld::update(float dt)
{
    
    if (pressedW) {
        sprite->setRotation(-90.0f);
        if (sprite->getPosition().y < 550 + sprite_speed) 
            sprite->setPosition(sprite->getPosition().x, sprite->getPosition().y + sprite_speed);
    }
    if (pressedS) {
        sprite->setRotation(90.0f);
        if (sprite->getPosition().y > 50 - sprite_speed) 
            sprite->setPosition(sprite->getPosition().x, sprite->getPosition().y - sprite_speed);
    }
    if (pressedA) {
        if (sprite->getPosition().x > 50 - sprite_speed) 
            sprite->setPosition(sprite->getPosition().x - sprite_speed, sprite->getPosition().y);
        sprite->setRotation(180.0f);
        if (pressedW) sprite->setRotation(-135.0f);
        if (pressedS) sprite->setRotation(135.0f);
    }
    if (pressedD) {
        if (sprite->getPosition().x < 750 + sprite_speed) 
            sprite->setPosition(sprite->getPosition().x + sprite_speed, sprite->getPosition().y);
        sprite->setRotation(0.0f);
        if (pressedW) sprite->setRotation(-45.0f);
        if (pressedS) sprite->setRotation(45.0f);
    }
    Rect rect1 = sprite->getBoundingBox();
    Rect rect2 = sprite2->getBoundingBox();
    float temp = 0.25f;
    int i=0;
    if (rect1.intersectsRect(rect2))
    {
        
        sprite_speed += temp;
        auto randomPoint = Vec2(rand() % 700, rand() % 500);
        sprite2->setPosition(randomPoint);
        i++;
    }
   
    cocos2d::Sprite* spriteWall1 = cocos2d::Sprite::create("Left_right.png");
    cocos2d::Sprite* spriteWall2 = cocos2d::Sprite::create("Left_right.png");
    cocos2d::Sprite* spriteWall3 = cocos2d::Sprite::create("Top.png");
    cocos2d::Sprite* spriteWall4 = cocos2d::Sprite::create("Top.png");
    spriteWall1->setPosition(-4, 300);
    spriteWall2->setPosition(804, 300);
    spriteWall3->setPosition(400, 595);
    spriteWall4->setPosition(400, -3);
    Rect rectWall1 = spriteWall1->getBoundingBox();
    Rect rectWall2 = spriteWall2->getBoundingBox();
    Rect rectWall3 = spriteWall3->getBoundingBox();
    Rect rectWall4 = spriteWall4->getBoundingBox();
    if (rectWall1.intersectsRect(rect1) || rectWall2.intersectsRect(rect1)|| rectWall3.intersectsRect(rect1) || rectWall4.intersectsRect(rect1))
    {
        Sleep(1000);
        auto scene = GameOverScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
   

}


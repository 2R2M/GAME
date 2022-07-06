#pragma once

#include "cocos2d.h"
#include <string>

class HelloWorld : public cocos2d::Layer // класс сцены
{
public:
    bool pressedW, pressedS, pressedA, pressedD;
    float sprite_speed = 3.0f;
    cocos2d::Sprite* sprite = cocos2d::Sprite::create("car.png");
    cocos2d::Sprite* sprite2 = cocos2d::Sprite::create("kanistra.png");
    static cocos2d::Scene* createScene(); // метод создания сцены
    bool init() override; // метод инициализации
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event);
    //public:void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
public:   void update(float dt);
      CREATE_FUNC(HelloWorld); // макрос, который раскрывается и генерирует экземпляр класса подконтрольный GC (GarbageCollector движка cocos-2dx)
};

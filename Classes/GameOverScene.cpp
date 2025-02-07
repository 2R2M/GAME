﻿#include "GameOverScene.h"

USING_NS_CC; // макрос использования пространства имён cocos2d::

Scene* GameOverScene::createScene()
{
    // все указатели, которые порождает Cocos - 2dx уже находятся под контролем выделенной памяти. Поэтому они не требуют явного удаления через delete или обертки в интеллектуальный указатель
    auto scene = Scene::create(); // создаем сцену
    auto layer = GameOverScene::create(); // создаем слой сцены

    scene->addChild(layer); // добавляем слой как ребенка на сцену

    return scene;
}

bool GameOverScene::init()
{
    if (!Layer::init()) // если мы не можем проинициализировать - просто выходим
    {
        return false;
    }

    auto label = Label::createWithSystemFont("GameOver", "Arial", 48); // создаем метку для вывода текста. 
    auto visibleSize = Director::getInstance()->getVisibleSize(); // получаем размеры вида просмотра (то, где будем рисовать)
    Vec2 origin = Director::getInstance()->getVisibleOrigin(); // получаем вектор смещения, для рисования на разных координатах


    label->setPosition(cocos2d::Vec2(320, 240)); // рисуем по заданным координатам. По - умолчанию у всех компонентов Cocos - 2dx точка отрисовки находится в середине, не слева сверху!
    this->addChild(label, 1);
    // наконец добавляем метку как ребенка. второй параметр - это z - последовательность
    return true;
}


#ifndef __GAMEMANAGER_SCENE_H__
#define __GAMEMANAGER_SCENE_H__

#include "cocos2d.h"

class CCBlade;

class GameManager : public cocos2d::CCLayer
{
private:

	cocos2d::CCArray*				myCats;
	bool							comboOn;
	float							comboTimer;
	int								comboCounter;

	//Update function
	void 							update(float dt);
	void 							updateComboCounter();
    std::map< cocos2d::CCTouch *, CCBlade * >  _map;

public:
	GameManager(void);
	~GameManager(void);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool 					init();

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* 		scene();
    
    // a selector callback
    void 							menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(GameManager);

    void							loadGame();

    //Touch methods
    virtual void 					ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual void 					ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual void 					ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);

    void 							createNewCat();
    void 							removeCat(cocos2d::CCNode* object);
};

#endif // __GAMEMANAGER_SCENE_H__

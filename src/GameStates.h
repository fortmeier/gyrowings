#ifndef _GAMESTATES_H_
#define _GAMESTATES_H_


#include <SDL_opengl.h>

#include "YGEGameState.h"
#include "YGELogger.h"
#include "YGEScene.h"
#include "YGEEntity.h"
#include "YGEEntityAsset.h"
#include "YGEHeightmap.h"
#include "YGEGraphicsAsset.h"
#include "YGEParticleSystem.h"
#include "YGEQuaternion.h"
#include "YGEKeyDownListener.h"
#include "YGEMouseMoveListener.h"

#include "GameGyrocopter.h"
#include "Camera.h"

using namespace YGETimeSpace;
using namespace YGEGraphics;
using namespace YGEInput;

class GameStateX : public YGEGame::YGEGameState {
public:
	YGESpace *space;


	YGEEntity* smallBoxPos;

	GameStateX();

	virtual YGESceneList& getScenesToRender();
	virtual YGESpaceList& getSpacesToUpdate();

	virtual void update();

	virtual void draw(YGECore::YGEEngineCore* core);

	GameGyrocopter* gyro;

};


class GameStateY : 
	public YGEGame::YGEGameState,
	public YGEKeyDownListener,
	public YGEMouseMoveListener 
{
public:
	YGESpace *space;

	Camera* camera;

	float pitch;
	float yaw;

	GameStateY();

	virtual YGESceneList& getScenesToRender();

	virtual void update();

	virtual void draw(YGECore::YGEEngineCore* core);

	virtual void keyDown(SDLKey key);

	virtual void mouseMoved(int x, int y);

};


class GameStateZ : public YGEGame::YGEGameState, public YGEKeyDownListener {
public:
	YGESpace *space;
	YGEObserver* camera;
	YGEParticleSystem* ps;

	GameStateZ();

	virtual YGESceneList& getScenesToRender();

	virtual void update();

	virtual void draw(YGECore::YGEEngineCore* core);

	virtual void keyDown(SDLKey key);

};

#endif
#ifndef COREENGINE_H
#define COREENGINE_H
#include <memory>
#include "Window.h"
#include "Timer.h"
#include "Debug.h"
#include "GameInterface.h"
#include "Scene.h"

#include "../Rendering/3D/GameObject.h"
#include "../Graphics//ShaderHandler.h"
#include "../Camera/Camera.h"
class CoreEngine
{
public:
	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;
	CoreEngine& operator=(const CoreEngine&) = delete;
	CoreEngine& operator=(CoreEngine&&) = delete;
	static CoreEngine* GetInstance();
	
	bool OnCreate(std::string name_, int wight_, int height_);
	void Run();
	void Exit();
	bool GetIsRunning();
	int GetCurrentScene() const;
	float GetScreenWidth() const;
	float GetScreenHeight() const;
	Camera* GetCamera() const;
	void SetGameInterface(GameInterface* gameInterface_);
	void SetCurrentScene(int sceneNum_);
	void SetCamera(Camera* camera_);
private:
	CoreEngine();
	~CoreEngine();
	void Update(const float deltaTime_);
	void Render();
	void OnDestroy();
	Window* window;
	bool isRunning;
	Timer timer;
	unsigned int fps;
	static std::unique_ptr<CoreEngine> engineInstance;
	friend std::default_delete<CoreEngine>;
	GameInterface* gameInterface;
	int currentSceneNum;
	Camera* camera;
};

#endif

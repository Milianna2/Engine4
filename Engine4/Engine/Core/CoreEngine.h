#ifndef COREENGINE_H
#define COREENGINE_H
#include "Window.h"
#include <memory>
class CoreEngine
{
public:
	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;
	CoreEngine& operator=(const CoreEngine&) = delete;
	CoreEngine& operator=(CoreEngine&&) = delete;
	static CoreEngine* GetInstance();
	CoreEngine();
	~CoreEngine();
	bool OnCreate(std::string name_, int wight_, int height_);
	void Run();
	bool GetIsRunning();
private:
	void Update(const float deltaTime_);
	void Render();
	void OnDestroy();
	Window* window;
	bool isRunning;
	static std::unique_ptr<CoreEngine> engineInstance;
	friend std::default_delete<CoreEngine>;
};

#endif

#include "CoreEngine.h"

std::unique_ptr<CoreEngine> CoreEngine::engineInstance = nullptr;
CoreEngine::CoreEngine() : window(nullptr), isRunning(false), fps(60), gameInterface(nullptr), currentSceneNum(0) {

}
CoreEngine::~CoreEngine() {

}
CoreEngine* CoreEngine::GetInstance() {
	if (engineInstance.get() == nullptr) {
		engineInstance.reset(new CoreEngine);
		Debug::Info("Engine Instance was reseted", "CoreEngine.cpp", __LINE__);
	}
	return engineInstance.get();
}
bool CoreEngine::OnCreate(std::string name_, int wight_, int height_) {
	Debug::onCreate();
	window = new Window();
	if (!window->OnCreate(name_, wight_, height_)) {
		Debug::Error("Window failed to initialize", "CoreEngine.cpp", __LINE__);
		OnDestroy();
		return isRunning = false;
	}

	SDL_WarpMouseInWindow(window->GetWindow(),
		window->GetWidht() / 2,
		window->GetHeight() / 2);

	MouseEventListener::RegisterEngineObject(this);

	ShaderHandler::GetInstance()->CreateProgram("colourShader",
		"Engine/Shaders/ColourVertexShader.glsl",
		"Engine/Shaders/ColourFragmentShader.glsl");
	ShaderHandler::GetInstance()->CreateProgram("basicShader",
		"Engine/Shaders/VertexShader.glsl",
		"Engine/Shaders/FragmentShader.glsl");
	if (gameInterface) {
		if (!gameInterface->OnCreate()) {
			Debug::Error("Game failed to initialize", "CoreEngine.cpp", __LINE__);
			OnDestroy();
			return isRunning = false;
		}
	}
	Debug::Info("Everything worked", "CoreEngine.cpp", __LINE__);
	timer.Start();
	return isRunning = true;
}
void CoreEngine::Run() {
	while (isRunning) {
		timer.UpdateFrameTicks();
		EventListener::Update();
		Update(timer.GetDeltaTime());
		Render();
		SDL_Delay(timer.GetSleepTime(fps));
	}
	//if (!isRunning)
		OnDestroy();
}
void CoreEngine::Exit() {
	isRunning = false;
}
bool CoreEngine::GetIsRunning() {
	return isRunning;
}
int CoreEngine::GetCurrentScene() const {
	return currentSceneNum;
}

Camera* CoreEngine::GetCamera() const {
	return camera;
}

void CoreEngine::SetGameInterface(GameInterface* gameInterface_) {
	gameInterface = gameInterface_;
}
void CoreEngine::SetCurrentScene(int sceneNum_) {
	currentSceneNum = sceneNum_;
}

void CoreEngine::SetCamera(Camera* camera_) {
	camera = camera_;

}

float CoreEngine::GetScreenWidth() const {
	return static_cast<float>(window->GetWidht());
}
float CoreEngine::GetScreenHeight() const {
	return static_cast<float>(window->GetHeight());
}
void CoreEngine::Update(const float deltaTime_) {
	if (gameInterface) {
		gameInterface->Update(deltaTime_);
	}
}
void CoreEngine::Render() {
	glClearColor(0.0f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (gameInterface) {
		gameInterface->Render();
	}
	SDL_GL_SwapWindow(window->GetWindow());
}
void CoreEngine::OnDestroy() {

	ShaderHandler::GetInstance()->OnDestroy();
	TextureHandler::GetInstance()->OnDestroy();
	MaterialHandler::GetInstance()->OnDestroy();
	SceneGraph::GetInstance()->OnDestroy();

	delete gameInterface;
	gameInterface = nullptr;

	delete camera;
	camera = nullptr;

	delete window;
	window = nullptr;

	SDL_Quit();
	exit(0);
}

void CoreEngine::NotifyOfMousePressed(glm::ivec2 mouse_, int buttonType_) {

}
void CoreEngine::NotifyOfMouseReleased(glm::ivec2 mouse_, int buttonType_) {

}
void CoreEngine::NotifyOfMouseMove(glm::ivec2 mouse_) {
	if (camera) {
		camera->ProcessMouseMovement(MouseEventListener::GetMouseOffset());
	}
}
void CoreEngine::NotifyOfMouseScroll(int y_) {
	if (camera) {
		camera->ProcessMouseZoom(y_);
	}
}
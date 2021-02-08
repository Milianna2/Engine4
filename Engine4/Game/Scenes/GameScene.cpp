#include "GameScene.h"
GameScene::GameScene() {

}
GameScene::~GameScene() {

}
bool GameScene::OnCreate() {
	std::cout << "We switched to the game scene" << std::endl;
	Debug::Info("We switched to the game scene", "GameScene.cpp", __LINE__);
	return true;
}
void GameScene::Update(const float deltaTime_) {

}
void GameScene::Render() {

}
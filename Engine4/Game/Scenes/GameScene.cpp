#include "GameScene.h"
GameScene::GameScene() : shape(nullptr), model(nullptr)
{

}
GameScene::~GameScene() {
	model = nullptr;
	delete shape;
	shape = nullptr;
}
bool GameScene::OnCreate() {
	Debug::Info("We switched to the game scene", "GameScene.cpp", __LINE__);
	CoreEngine::GetInstance()->SetCamera(new Camera());
	CoreEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.0f, 4.0f));
	Vertex v;
	std::vector<Vertex> vertexList;
	vertexList.reserve(3);

	v.position = glm::vec3(0.0f, 0.5f, 0.0f);
	v.colour = glm::vec3(0.0f, 0.0f, 1.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	v.colour = glm::vec3(0.0f, 1.0f, 0.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	v.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	vertexList.push_back(v);

	model = new Model(ShaderHandler::GetInstance()->GetShader("colourShader"));
	model->AddMesh(new Mesh(vertexList, ShaderHandler::GetInstance()->GetShader("colourShader")));
	//model->SetScale()glm::vec3(0.5f));
	shape = new GameObject(model);
	return true;
}
void GameScene::Update(const float deltaTime_) {
	model->SetAngle(model->GetAngle() + 0.005f);
}
void GameScene::Render() {
	shape->Render(CoreEngine::GetInstance()->GetCamera());
}
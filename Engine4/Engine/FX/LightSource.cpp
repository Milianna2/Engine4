#include "LightSource.h"

LightSource::LightSource(glm::vec3 position_, float ambientV_, float diffuseV_,
	float specularV_, glm::vec3 lightColour_) : position(glm::vec3(0.0f, 0.0f, 2.0f)), ambientV(0.1f), 
	diffuseV(0.1f), specularV(0.1f), lightColour(glm::vec3(1.0f, 1.0f, 1.0f)){
	position = position_;
	ambientV = ambientV_;
	diffuseV = diffuseV_;
	specularV = specularV_;
	lightColour = lightColour_;
}
LightSource::~LightSource() {

}
void LightSource::SetPosition(glm::vec3 position_) {
	position = position_;
}
void LightSource::SetAmbientV(float ambientV_) {
	ambientV = ambientV_;
}
void LightSource::SetDiffuseV(float diffuseV_) {
	diffuseV = diffuseV_;
}
void LightSource::SetSpecularV(float specularV_) {
	specularV = specularV_;
}
void LightSource::SetLightColour(glm::vec3 lightColour_) {
	lightColour = lightColour_;
}
glm::vec3 LightSource::GetPosition() const {
	return position;
}
float LightSource::GetAmbientV() const {
	return ambientV;
}
float LightSource::GetDiffuseV() const {
	return diffuseV;
}
float LightSource::GetSpecularV() const {
	return specularV;
}
glm::vec3 LightSource::GetLightColour() const {
	return lightColour;
}
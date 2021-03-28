#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H
#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
class LightSource
{
private:
	glm::vec3 position;
	float ambientV;
	float diffuseV;
	float specularV;
	glm::vec3 lightColour;
public:
	void SetPosition(glm::vec3 position_);
	void SetAmbientV(float ambientV_);
	void SetDiffuseV(float diffuseV_);
	void SetSpecularV(float specularV_);
	void SetLightColour(glm::vec3 lightColour_);
	glm::vec3 GetPosition() const;
	float GetAmbientV() const;
	float GetDiffuseV() const;
	float GetSpecularV() const;
	glm::vec3 GetLightColour() const;
	LightSource(glm::vec3 position_, float ambientV_, float diffuseV_,
	float specularV_, glm::vec3 lightColour_);
	~LightSource();
};
#endif
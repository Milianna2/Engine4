#version 450 core

in vec3 Normal;
in vec2 TexCoords;

in vec3 FragPosition;


//uniform sampler2D inputTexture;
uniform vec3 CameraPosition;

out vec4 fColour;

struct Light{
	vec3 lightPos;
	float ambientV;
	float diffuseV;
	float specularV;
	vec3 lightColour;
};

struct Material 
{
	sampler2D diffuseMap;//newmtl

	float shininess;//NS
	float transparency;//d

	vec3 ambient;//ka
	vec3 diffuse;//kd
	vec3 specular;//ks
};

uniform Material material;

uniform Light light;

void main(){
	vec3 ambient = light.ambientV * material.ambient * texture(material.diffuseMap, TexCoords).rgb * light.lightColour;
	vec3 norm  = normalize(Normal);
	vec3 lightDir = normalize(light.lightPos * FragPosition);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = (diff  * material.diffuse) * texture(material.diffuseMap, TexCoords).rgb * light.lightColour;
	vec3 viewDir = normalize(CameraPosition * FragPosition);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 specular = (spec * material.specular) * light.lightColour;
	vec3 result = ambient + diffuse + specular;
	fColour = vec4(result, material.transparency);
}
#version 450 core

in vec3 Normal;
in vec2 TexCoords;
in vec3 Colour;
in vec3 FragPosition;


uniform sampler2D inputTexture;
uniform vec3 CameraPosition;

out vec4 fColour;

struct Light{
	vec3 lightPos;
	float ambientV;
	float diffuseV;
	float specularV;
	vec3 lightColour;
};

uniform Light light;

void main(){
	vec3 ambient = light.ambientV * texture(inputTexture, TexCoords).rgb * light.lightColour;
	vec3 norm  = normalize(Normal);
	vec3 lightDir = normalize(light.lightPos * FragPosition);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = (diff * light.diffuseV) * texture(inputTexture, TexCoords).rgb * light.lightColour;
	vec3 viewDir = normalize(CameraPosition * FragPosition);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
	vec3 specular = (spec * light.specularV) * light.lightColour;
	vec3 result = ambient + diffuse + specular;
	fColour = vec4(result, 1.0f);
}
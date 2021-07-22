#version 330 core
layout(location=0) in vec3 position;
layout(location=1) in vec2 texCoord;
layout(location=2) in float index;
uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;
out vec2 TexCoord;
out float Index;
void main()
{
  gl_Position = perspective * view * model * vec4(position.x, position.y, position.z, 1.0f);
  //gl_Position = vec4(position.x, position.y, position.z, 1.0f);
  TexCoord = vec2(texCoord.x, 1-texCoord.y);
  Index = index;
}
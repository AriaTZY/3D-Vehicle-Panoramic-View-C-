#version 330 core
layout(location=0) in vec3 position;
layout(location=1) in vec2 texCoord0;
layout(location=2) in vec2 texCoord1;
layout(location=3) in float index;
uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;
out vec2 TexCoord0;
out vec2 TexCoord1;
out float Index;
void main()
{
  gl_Position = perspective * view * model * vec4(position.x, position.y, position.z, 1.0f);
  TexCoord0 = vec2(texCoord0.x, 1-texCoord0.y);
  TexCoord1 = vec2(texCoord1.x, 1-texCoord1.y);
  Index = index;
}
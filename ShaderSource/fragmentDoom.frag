#version 330 core
in vec2 TexCoord;
in float Index;
out vec4 color;
uniform sampler2D ourTexture0;  //ground
uniform sampler2D ourTexture1;  //front
uniform sampler2D ourTexture2;  //left
uniform sampler2D ourTexture3;  //back
uniform sampler2D ourTexture4;  //right
void main()
{
  if(Index == 0)
  {
     color = texture(ourTexture0, TexCoord);
  }
  else if(Index == 1)
  {
     color = texture(ourTexture1, TexCoord);
  }
  else if(Index == 2)
  {
     color = texture(ourTexture2, TexCoord);
  }
  else if(Index == 3)
  {
     color = texture(ourTexture3, TexCoord);
  }
  else
  {
     color = texture(ourTexture4, TexCoord);
  }
  //color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
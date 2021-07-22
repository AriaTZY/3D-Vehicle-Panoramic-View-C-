#version 330 core
in vec2 TexCoord0;
in vec2 TexCoord1;
in float Index;
out vec4 color;
uniform sampler2D ourTexture0; //前图
uniform sampler2D ourTexture1; //左图
uniform sampler2D ourTexture2; //后图
uniform sampler2D ourTexture3; //右图
void main()
{
  if (Index == 0)
  {
     color = mix(texture(ourTexture0, TexCoord0), texture(ourTexture1, TexCoord1), 0.3);
  }
  else if (Index == 1)
  {
     color = mix(texture(ourTexture1, TexCoord0), texture(ourTexture2, TexCoord1), 0.3);
  }
  else if (Index == 2)
  {
     //color =  texture(ourTexture2, TexCoord0);
     color = mix(texture(ourTexture2, TexCoord0), texture(ourTexture3, TexCoord1), 0.3);
  }
  else if (Index == 3)
  {
     //color = vec4(1.0f, 0.5f, 0.8f, 1.0f); 
    color = texture(ourTexture0, TexCoord1);
    //color = mix(texture(ourTexture3, TexCoord0), texture(ourTexture0, TexCoord1), 0.3);
  }
  //color = vec4(1.0f, 0.5f, 0.8f, 1.0f); 
  //color = vec4(1.0f, 1.0f, 1.0f, 1.0f); 
}
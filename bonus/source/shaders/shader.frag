#version 330 core

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D tex;

out vec4 FragColor;

void main()
{
    FragColor = texture(tex, TexCoord)* vec4(ourColor, 1.0);
}

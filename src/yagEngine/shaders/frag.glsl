#version 330 core

// Base Color
uniform vec4 base_color;
// Texture sampler
uniform sampler2D base_texture;

in vec2 TexCoord;
out vec4 FragColor;

void main() 
{
    //FragColor = base_color;
    FragColor = texture(base_texture, TexCoord);
}
 

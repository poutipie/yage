#version 330 core

// Base Color
uniform vec4 base_color;
// Texture sampler
uniform sampler2D base_texture;

// Choose either texture or Color
uniform bool use_texture = false;

in vec2 TexCoord;
out vec4 FragColor;

void main() 
{
    if (use_texture) {
        FragColor = texture(base_texture, TexCoord);
    }
    else {
        FragColor = base_color;
    }
}
 

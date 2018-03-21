#version 330 core

layout(location = 0) in vec3 vpos;
layout(location = 1) in vec2 vtexcoord;
layout(location = 2) in vec3 vnormal;
layout(location = 3) in vec3 vtangent;
layout(location = 4) in vec3 vbitangent;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(vpos, 1.0f);
}
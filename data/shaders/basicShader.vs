#version 120

attribute vec3 position;
attribute vec2 uv;
attribute vec3 normal;

varying vec2 uv0;
varying vec3 normal0;

uniform mat4 transform;

void main() {
	gl_Position = transform * vec4(position,1.0);
	uv0 =uv;
	normal0 = (transform * vec4(normal,0.0f)).xyz; //Ignore Translation in Normal
}
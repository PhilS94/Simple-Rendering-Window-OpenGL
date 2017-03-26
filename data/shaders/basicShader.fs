#version 120

varying vec2 uv0;
varying vec3 normal0;

uniform sampler2D diffuse;

void main() {
	gl_FragColor = texture2D(diffuse,uv0) 
			* clamp(dot(-vec3(-0.5f,0,0.5f),normal0),0.0,1.0); //lambert, make uniform
}
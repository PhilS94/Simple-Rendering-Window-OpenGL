#version 120

varying vec2 uv0;
uniform sampler2D diffuse;

void main() {
	gl_FragColor = texture2D(diffuse,uv0);
}
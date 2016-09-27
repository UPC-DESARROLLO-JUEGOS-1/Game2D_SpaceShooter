#version 130

in vec3 vertexPosition;
in vec4 vertextColor;

out vec3 fragmentPosition;
out vec4 fragmentColor;

uniform mat4 wvp;

void main() {
	gl_Position.xyz = (wvp * vec4(vertexPosition, 1.0)).xyz;
	gl_Position.w = 1.0;
	
	fragmentPosition = vertexPosition;
	fragmentColor = vertextColor;
}
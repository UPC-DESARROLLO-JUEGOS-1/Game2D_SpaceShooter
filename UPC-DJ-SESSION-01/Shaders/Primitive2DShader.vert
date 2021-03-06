#version 130

in vec2 vertexPosition;
in vec4 vertextColor;

out vec2 fragmentPosition;
out vec4 fragmentColor;

uniform mat4 wvp;

void main() {
	gl_Position.xy = (wvp * vec4(vertexPosition, 0.0, 1.0)).xy;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;
	
	fragmentPosition = vertexPosition;
	fragmentColor = vertextColor;
}
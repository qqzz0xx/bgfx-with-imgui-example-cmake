$input v_texcoord0

/*
 * Copyright 2011-2021 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */

#include "common.sh"

USAMPLER2D(s_texColor, 0);

uniform float u_width;
uniform float u_height;
uniform float u_width_d2;
uniform float u_height_d2;


void main()
{
	ivec2 pos = ivec2(v_texcoord0.x * u_width, v_texcoord0.y * u_height);
	uvec4 y2uv = texelFetch(s_texColor, pos, int(0));

	vec3 _yuv = vec3((pos.y > 0.5 ? y2uv.z : y2uv.x) / 255.0, y2uv.y / 255.0, y2uv.w / 255.0);
	vec3 rgb;
	rgb.x = _yuv.x + 1.403*(_yuv.y-0.5);
	rgb.y = _yuv.x - 0.344*(_yuv.y-0.5) - 0.714*(_yuv.z-0.5);
	rgb.z = _yuv.x + 1.773*(_yuv.z-0.5);
	gl_FragColor = vec4(rgb, 1.0);
	//gl_FragColor = vec4(1.0 ,0.0 ,0.0 ,1.0);
}

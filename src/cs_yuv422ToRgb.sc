#include "bgfx_compute.sh"
#include "shaderlib.sh"

USAMPLER2D(s_texColor, 0);
IMAGE2D_RW(s_texRgba, rgba8, 1);

uniform float u_width;
uniform float u_height;

NUM_THREADS(8, 8, 1)
void main() 
{
    ivec2 coord = ivec2(gl_GlobalInvocationID.xy);
    uvec4 color = texelFetch(s_texColor, coord.xy, 0);
    int i = coord.x * coord.y * 2;


    vec3 _yuv = vec3(color.x, color.y, color.w);
    vec3 rgb;
	rgb.x = _yuv.x + 1.403*(_yuv.y-0.5);
	rgb.y = _yuv.x - 0.344*(_yuv.y-0.5) - 0.714*(_yuv.z-0.5);
	rgb.z = _yuv.x + 1.773*(_yuv.z-0.5);
    ivec2 coord_d2 = ivec2(i % u_width,  i / u_width);
	imageStore(s_texRgba, coord_d2, vec4(rgb, 1.0) );

    _yuv = vec3(color.z, color.y, color.w);
	rgb.x = _yuv.x + 1.403*(_yuv.y-0.5);
	rgb.y = _yuv.x - 0.344*(_yuv.y-0.5) - 0.714*(_yuv.z-0.5);
	rgb.z = _yuv.x + 1.773*(_yuv.z-0.5);
    i = i + 1;
    coord_d2 = ivec2(i % u_width,  i / u_width);
    imageStore(s_texRgba, coord_d2, vec4(rgb, 1.0) );
}
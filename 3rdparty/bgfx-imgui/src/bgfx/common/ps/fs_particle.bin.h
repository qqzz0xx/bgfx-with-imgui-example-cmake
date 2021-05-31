static const uint8_t fs_particle_glsl[409] =
{
	0x46, 0x53, 0x48, 0x09, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, // _texColor.......
	0x00, 0x73, 0x01, 0x00, 0x00, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, 0x69, 0x67, // .s...varying hig
	0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, // hp vec4 v_color0
	0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, 0x20, // ;.varying highp 
	0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, // vec4 v_texcoord0
	0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, // ;.uniform sample
	0x72, 0x32, 0x44, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x3b, 0x0a, // r2D s_texColor;.
	0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, // void main ().{. 
	0x20, 0x6c, 0x6f, 0x77, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x72, 0x67, 0x62, 0x61, 0x5f, //  lowp vec4 rgba_
	0x31, 0x3b, 0x0a, 0x20, 0x20, 0x6c, 0x6f, 0x77, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, // 1;.  lowp vec4 t
	0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, // mpvar_2;.  tmpva
	0x72, 0x5f, 0x32, 0x20, 0x3d, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x44, 0x20, // r_2 = texture2D 
	0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2c, 0x20, 0x76, 0x5f, 0x74, // (s_texColor, v_t
	0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, 0x78, 0x79, 0x29, 0x3b, 0x0a, 0x20, 0x20, // excoord0.xy);.  
	0x72, 0x67, 0x62, 0x61, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x28, 0x28, 0x74, // rgba_1.xyz = ((t
	0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x2e, 0x78, 0x78, 0x78, 0x20, 0x2a, 0x20, 0x76, 0x5f, // mpvar_2.xxx * v_
	0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x2e, 0x78, 0x79, 0x7a, 0x29, 0x20, 0x2a, 0x20, 0x28, 0x74, // color0.xyz) * (t
	0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x2e, 0x78, 0x20, 0x2a, 0x20, 0x76, 0x5f, 0x63, 0x6f, // mpvar_2.x * v_co
	0x6c, 0x6f, 0x72, 0x30, 0x2e, 0x77, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x72, 0x67, 0x62, 0x61, // lor0.w));.  rgba
	0x5f, 0x31, 0x2e, 0x77, 0x20, 0x3d, 0x20, 0x28, 0x28, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, // _1.w = ((tmpvar_
	0x32, 0x2e, 0x78, 0x20, 0x2a, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x2e, 0x77, // 2.x * v_color0.w
	0x29, 0x20, 0x2a, 0x20, 0x28, 0x31, 0x2e, 0x30, 0x20, 0x2d, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, // ) * (1.0 - v_tex
	0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, 0x7a, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, // coord0.z));.  gl
	0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x72, 0x67, 0x62, // _FragColor = rgb
	0x61, 0x5f, 0x31, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                           // a_1;.}...
};
static const uint8_t fs_particle_spv[1353] =
{
	0x46, 0x53, 0x48, 0x09, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x11, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, // _texColorSampler
	0x11, 0x01, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x11, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, // .........s_texCo
	0x6c, 0x6f, 0x72, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x11, 0x01, 0xff, 0xff, 0x01, 0x00, // lorTexture......
	0x00, 0x00, 0x0a, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x00, 0x40, // ...s_texColor0.@
	0x00, 0x00, 0x00, 0x00, 0x02, 0xec, 0x04, 0x00, 0x00, 0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, // ...........#....
	0x00, 0x0a, 0x00, 0x08, 0x00, 0xd5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, // ................
	0x00, 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x4c, 0x53, // .............GLS
	0x4c, 0x2e, 0x73, 0x74, 0x64, 0x2e, 0x34, 0x35, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, // L.std.450.......
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x09, 0x00, 0x04, 0x00, 0x00, // ................
	0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x6a, 0x00, 0x00, // .....main....j..
	0x00, 0x6d, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x7d, 0x00, 0x00, 0x00, 0x10, 0x00, 0x03, // .m...p...}......
	0x00, 0x04, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, // ................
	0x00, 0xf4, 0x01, 0x00, 0x00, 0x05, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, // .............mai
	0x6e, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x07, 0x00, 0x23, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, // n........#...s_t
	0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x00, 0x00, // exColorSampler..
	0x00, 0x05, 0x00, 0x07, 0x00, 0x26, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, // .....&...s_texCo
	0x6c, 0x6f, 0x72, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x00, 0x00, 0x05, 0x00, 0x06, // lorTexture......
	0x00, 0x6a, 0x00, 0x00, 0x00, 0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6f, 0x72, // .j...gl_FragCoor
	0x64, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x76, 0x5f, 0x63, // d........m...v_c
	0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x70, 0x00, 0x00, // olor0........p..
	0x00, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x00, 0x05, 0x00, 0x06, // .v_texcoord0....
	0x00, 0x7d, 0x00, 0x00, 0x00, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61, // .}...bgfx_FragDa
	0x74, 0x61, 0x30, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x23, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, // ta0..G...#..."..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x23, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, // .....G...#...!..
	0x00, 0x50, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x26, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, // .P...G...&..."..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x26, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, // .....G...&...!..
	0x00, 0x40, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x6a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, // .@...G...j......
	0x00, 0x0f, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, // .....G...m......
	0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x70, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, // .....G...p......
	0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x7d, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, // .....G...}......
	0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x21, 0x00, 0x03, // .............!..
	0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x02, 0x00, 0x06, 0x00, 0x00, // ................
	0x00, 0x16, 0x00, 0x03, 0x00, 0x07, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x19, 0x00, 0x09, // ......... ......
	0x00, 0x08, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x17, 0x00, 0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, // ................
	0x00, 0x17, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, // ................
	0x00, 0x20, 0x00, 0x04, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, // . ..."..........
	0x00, 0x3b, 0x00, 0x04, 0x00, 0x22, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // .;..."...#......
	0x00, 0x20, 0x00, 0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, // . ...%..........
	0x00, 0x3b, 0x00, 0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // .;...%...&......
	0x00, 0x1b, 0x00, 0x03, 0x00, 0x32, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, // .....2..........
	0x00, 0x4b, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, // .K...........+..
	0x00, 0x07, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x20, 0x00, 0x04, // .....`......? ..
	0x00, 0x69, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, // .i...........;..
	0x00, 0x69, 0x00, 0x00, 0x00, 0x6a, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, // .i...j.......;..
	0x00, 0x69, 0x00, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, // .i...m.......;..
	0x00, 0x69, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, // .i...p....... ..
	0x00, 0x7c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, // .|...........;..
	0x00, 0x7c, 0x00, 0x00, 0x00, 0x7d, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2e, 0x00, 0x03, // .|...}..........
	0x00, 0x0d, 0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, 0x00, 0x36, 0x00, 0x05, 0x00, 0x02, 0x00, 0x00, // .........6......
	0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x02, // ................
	0x00, 0x05, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, // .....=.......$..
	0x00, 0x23, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x08, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, // .#...=.......'..
	0x00, 0x26, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x6e, 0x00, 0x00, // .&...=.......n..
	0x00, 0x6d, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x71, 0x00, 0x00, // .m...=.......q..
	0x00, 0x70, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x07, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x9d, 0x00, 0x00, // .p...O..........
	0x00, 0x71, 0x00, 0x00, 0x00, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // .q...q..........
	0x00, 0x56, 0x00, 0x05, 0x00, 0x32, 0x00, 0x00, 0x00, 0xc5, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, // .V...2.......'..
	0x00, 0x24, 0x00, 0x00, 0x00, 0x57, 0x00, 0x05, 0x00, 0x0d, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, // .$...W..........
	0x00, 0xc5, 0x00, 0x00, 0x00, 0x9d, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x08, 0x00, 0x4b, 0x00, 0x00, // .........O...K..
	0x00, 0xa1, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x08, 0x00, 0x4b, 0x00, 0x00, // .........O...K..
	0x00, 0xa3, 0x00, 0x00, 0x00, 0x6e, 0x00, 0x00, 0x00, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // .....n...n......
	0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00, 0x4b, 0x00, 0x00, // .............K..
	0x00, 0xa4, 0x00, 0x00, 0x00, 0xa1, 0x00, 0x00, 0x00, 0xa3, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, // .............Q..
	0x00, 0x07, 0x00, 0x00, 0x00, 0xa6, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x8e, 0x00, 0x05, 0x00, 0x4b, 0x00, 0x00, 0x00, 0xa7, 0x00, 0x00, 0x00, 0xa4, 0x00, 0x00, // .....K..........
	0x00, 0xa6, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xa9, 0x00, 0x00, // .....Q..........
	0x00, 0x6e, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x8e, 0x00, 0x05, 0x00, 0x4b, 0x00, 0x00, // .n...........K..
	0x00, 0xaa, 0x00, 0x00, 0x00, 0xa7, 0x00, 0x00, 0x00, 0xa9, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x09, // .............O..
	0x00, 0x0d, 0x00, 0x00, 0x00, 0xac, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0xaa, 0x00, 0x00, // ................
	0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x51, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xae, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, // .Q..............
	0x00, 0x00, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xb0, 0x00, 0x00, // .....Q..........
	0x00, 0x6e, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, // .n..............
	0x00, 0xb1, 0x00, 0x00, 0x00, 0xae, 0x00, 0x00, 0x00, 0xb0, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, // .............Q..
	0x00, 0x07, 0x00, 0x00, 0x00, 0xb3, 0x00, 0x00, 0x00, 0x71, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, // .........q......
	0x00, 0x83, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xb4, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, // .............`..
	0x00, 0xb3, 0x00, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xb5, 0x00, 0x00, // ................
	0x00, 0xb1, 0x00, 0x00, 0x00, 0xb4, 0x00, 0x00, 0x00, 0x52, 0x00, 0x06, 0x00, 0x0d, 0x00, 0x00, // .........R......
	0x00, 0xd2, 0x00, 0x00, 0x00, 0xb5, 0x00, 0x00, 0x00, 0xac, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, // ................
	0x00, 0x3e, 0x00, 0x03, 0x00, 0x7d, 0x00, 0x00, 0x00, 0xd2, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x01, // .>...}..........
	0x00, 0x38, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,                                           // .8.......
};
static const uint8_t fs_particle_dx9[334] =
{
	0x46, 0x53, 0x48, 0x09, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, // _texColor0......
	0x00, 0x28, 0x01, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0xff, 0x20, 0x00, 0x43, 0x54, 0x41, // .(......... .CTA
	0x42, 0x1c, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0x01, 0x00, 0x00, // B....S..........
	0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, // .........L...0..
	0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // .........<......
	0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0xab, 0x04, 0x00, 0x0c, // .s_texColor.....
	0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x73, 0x5f, // .............ps_
	0x33, 0x5f, 0x30, 0x00, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x20, 0x28, 0x52, // 3_0.Microsoft (R
	0x29, 0x20, 0x48, 0x4c, 0x53, 0x4c, 0x20, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x20, 0x43, 0x6f, // ) HLSL Shader Co
	0x6d, 0x70, 0x69, 0x6c, 0x65, 0x72, 0x20, 0x31, 0x30, 0x2e, 0x31, 0x00, 0xab, 0x51, 0x00, 0x00, // mpiler 10.1..Q..
	0x05, 0x00, 0x00, 0x0f, 0xa0, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........?.......
	0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x02, 0x0a, 0x00, 0x00, 0x80, 0x00, 0x00, 0x0f, // ................
	0x90, 0x1f, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x80, 0x01, 0x00, 0x07, 0x90, 0x1f, 0x00, 0x00, // ................
	0x02, 0x00, 0x00, 0x00, 0x90, 0x00, 0x08, 0x0f, 0xa0, 0x42, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0f, // .........B......
	0x80, 0x01, 0x00, 0xe4, 0x90, 0x00, 0x08, 0xe4, 0xa0, 0x05, 0x00, 0x00, 0x03, 0x00, 0x00, 0x02, // ................
	0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x05, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0f, // ................
	0x80, 0x00, 0x00, 0x54, 0x80, 0x00, 0x00, 0x93, 0x90, 0x05, 0x00, 0x00, 0x03, 0x00, 0x08, 0x07, // ...T............
	0x80, 0x00, 0x00, 0xf9, 0x80, 0x00, 0x00, 0xff, 0x90, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x02, // ................
	0x80, 0x00, 0x00, 0x00, 0xa0, 0x01, 0x00, 0xaa, 0x91, 0x05, 0x00, 0x00, 0x03, 0x00, 0x08, 0x08, // ................
	0x80, 0x00, 0x00, 0x55, 0x80, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00,             // ...U..........
};
static const uint8_t fs_particle_dx11[544] =
{
	0x46, 0x53, 0x48, 0x09, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0a, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, // _texColor0......
	0x00, 0x0a, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x01, 0x00, 0x00, // ..s_texColor0...
	0x01, 0x00, 0x00, 0x00, 0xe4, 0x01, 0x00, 0x00, 0x44, 0x58, 0x42, 0x43, 0xdd, 0x04, 0xf1, 0x4a, // ........DXBC...J
	0xaa, 0xb0, 0xdf, 0xe0, 0xf5, 0x18, 0x2f, 0x3b, 0x6e, 0xa9, 0x0e, 0x0a, 0x01, 0x00, 0x00, 0x00, // ....../;n.......
	0xe4, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x00, // ........,.......
	0xd4, 0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x4e, 0x6c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, // ....ISGNl.......
	0x08, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, // ....P...........
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, // ................
	0x0f, 0x0f, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ....b...........
	0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0f, 0x07, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, // ............SV_P
	0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00, 0x43, 0x4f, 0x4c, 0x4f, 0x52, 0x00, 0x54, 0x45, // OSITION.COLOR.TE
	0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab, 0x4f, 0x53, 0x47, 0x4e, 0x2c, 0x00, 0x00, 0x00, // XCOORD..OSGN,...
	0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........ .......
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, // ................
	0x53, 0x56, 0x5f, 0x54, 0x41, 0x52, 0x47, 0x45, 0x54, 0x00, 0xab, 0xab, 0x53, 0x48, 0x44, 0x52, // SV_TARGET...SHDR
	0x08, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x5a, 0x00, 0x00, 0x03, // ....@...B...Z...
	0x00, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x18, 0x00, 0x04, 0x00, 0x70, 0x10, 0x00, // .`......X....p..
	0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x62, 0x10, 0x00, 0x03, 0xf2, 0x10, 0x10, 0x00, // ....UU..b.......
	0x01, 0x00, 0x00, 0x00, 0x62, 0x10, 0x00, 0x03, 0x72, 0x10, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, // ....b...r.......
	0x65, 0x00, 0x00, 0x03, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x02, // e.... ......h...
	0x01, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x09, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, // ....E...........
	0x46, 0x10, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x46, 0x7e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, // F.......F~......
	0x00, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x07, 0x22, 0x00, 0x10, 0x00, // .`......8..."...
	0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x10, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x07, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, // ....8...........
	0x46, 0x05, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x19, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, // F.......6.......
	0x38, 0x00, 0x00, 0x07, 0x72, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x96, 0x07, 0x10, 0x00, // 8...r ..........
	0x00, 0x00, 0x00, 0x00, 0xf6, 0x1f, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, // ................
	0x22, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0x10, 0x10, 0x80, 0x41, 0x00, 0x00, 0x00, // ".......*...A...
	0x02, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x38, 0x00, 0x00, 0x07, // .....@.....?8...
	0x82, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, // . ..............
	0x0a, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, // ........>.......
};
static const uint8_t fs_particle_mtl[850] =
{
	0x46, 0x53, 0x48, 0x09, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x11, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, // _texColorSampler
	0x11, 0x01, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x11, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, // .........s_texCo
	0x6c, 0x6f, 0x72, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x11, 0x01, 0xff, 0xff, 0x01, 0x00, // lorTexture......
	0x00, 0x00, 0x0a, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x10, 0x00, 0x00, // ...s_texColor...
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf5, 0x02, 0x00, 0x00, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, // .........#includ
	0x65, 0x20, 0x3c, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x5f, 0x73, 0x74, 0x64, 0x6c, 0x69, 0x62, 0x3e, // e <metal_stdlib>
	0x0a, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x3c, 0x73, 0x69, 0x6d, 0x64, 0x2f, // .#include <simd/
	0x73, 0x69, 0x6d, 0x64, 0x2e, 0x68, 0x3e, 0x0a, 0x0a, 0x75, 0x73, 0x69, 0x6e, 0x67, 0x20, 0x6e, // simd.h>..using n
	0x61, 0x6d, 0x65, 0x73, 0x70, 0x61, 0x63, 0x65, 0x20, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x3b, 0x0a, // amespace metal;.
	0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, // .struct xlatMtlM
	0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, // ain_out.{.    fl
	0x6f, 0x61, 0x74, 0x34, 0x20, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61, // oat4 bgfx_FragDa
	0x74, 0x61, 0x30, 0x20, 0x5b, 0x5b, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, // ta0 [[color(0)]]
	0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, // ;.};..struct xla
	0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x69, 0x6e, 0x0a, 0x7b, 0x0a, 0x20, 0x20, // tMtlMain_in.{.  
	0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, //   float4 v_color
	0x30, 0x20, 0x5b, 0x5b, 0x75, 0x73, 0x65, 0x72, 0x28, 0x6c, 0x6f, 0x63, 0x6e, 0x30, 0x29, 0x5d, // 0 [[user(locn0)]
	0x5d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x76, 0x5f, // ];.    float4 v_
	0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x5b, 0x5b, 0x75, 0x73, 0x65, 0x72, // texcoord0 [[user
	0x28, 0x6c, 0x6f, 0x63, 0x6e, 0x31, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x66, // (locn1)]];.};..f
	0x72, 0x61, 0x67, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, // ragment xlatMtlM
	0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, // ain_out xlatMtlM
	0x61, 0x69, 0x6e, 0x28, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, // ain(xlatMtlMain_
	0x69, 0x6e, 0x20, 0x69, 0x6e, 0x20, 0x5b, 0x5b, 0x73, 0x74, 0x61, 0x67, 0x65, 0x5f, 0x69, 0x6e, // in in [[stage_in
	0x5d, 0x5d, 0x2c, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x64, 0x3c, 0x66, 0x6c, // ]], texture2d<fl
	0x6f, 0x61, 0x74, 0x3e, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, // oat> s_texColor 
	0x5b, 0x5b, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x2c, 0x20, // [[texture(0)]], 
	0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, // sampler s_texCol
	0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x20, 0x5b, 0x5b, 0x73, 0x61, 0x6d, 0x70, // orSampler [[samp
	0x6c, 0x65, 0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, // ler(0)]]).{.    
	0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20, // xlatMtlMain_out 
	0x6f, 0x75, 0x74, 0x20, 0x3d, 0x20, 0x7b, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, // out = {};.    fl
	0x6f, 0x61, 0x74, 0x34, 0x20, 0x5f, 0x31, 0x39, 0x30, 0x20, 0x3d, 0x20, 0x73, 0x5f, 0x74, 0x65, // oat4 _190 = s_te
	0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x28, 0x73, 0x5f, // xColor.sample(s_
	0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x2c, // texColorSampler,
	0x20, 0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, //  in.v_texcoord0.
	0x78, 0x79, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x33, 0x20, // xy);.    float3 
	0x5f, 0x31, 0x36, 0x31, 0x20, 0x3d, 0x20, 0x28, 0x28, 0x5f, 0x31, 0x39, 0x30, 0x2e, 0x78, 0x78, // _161 = ((_190.xx
	0x78, 0x20, 0x2a, 0x20, 0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x2e, // x * in.v_color0.
	0x78, 0x79, 0x7a, 0x29, 0x20, 0x2a, 0x20, 0x5f, 0x31, 0x39, 0x30, 0x2e, 0x78, 0x29, 0x20, 0x2a, // xyz) * _190.x) *
	0x20, 0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x2e, 0x77, 0x3b, 0x0a, //  in.v_color0.w;.
	0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x5f, 0x32, 0x30, 0x31, 0x20, //     float4 _201 
	0x3d, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x28, 0x5f, 0x31, 0x36, 0x31, 0x2e, 0x78, 0x2c, // = float4(_161.x,
	0x20, 0x5f, 0x31, 0x36, 0x31, 0x2e, 0x79, 0x2c, 0x20, 0x5f, 0x31, 0x36, 0x31, 0x2e, 0x7a, 0x2c, //  _161.y, _161.z,
	0x20, 0x5f, 0x31, 0x39, 0x30, 0x2e, 0x78, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x5f, 0x32, //  _190.x);.    _2
	0x30, 0x31, 0x2e, 0x77, 0x20, 0x3d, 0x20, 0x28, 0x5f, 0x31, 0x39, 0x30, 0x2e, 0x78, 0x20, 0x2a, // 01.w = (_190.x *
	0x20, 0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x2e, 0x77, 0x29, 0x20, //  in.v_color0.w) 
	0x2a, 0x20, 0x28, 0x31, 0x2e, 0x30, 0x20, 0x2d, 0x20, 0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x74, 0x65, // * (1.0 - in.v_te
	0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, 0x7a, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, // xcoord0.z);.    
	0x6f, 0x75, 0x74, 0x2e, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61, 0x74, // out.bgfx_FragDat
	0x61, 0x30, 0x20, 0x3d, 0x20, 0x5f, 0x32, 0x30, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x72, // a0 = _201;.    r
	0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x6f, 0x75, 0x74, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00, 0x00, // eturn out;.}....
	0x20, 0x00,                                                                                     //  .
};
extern const uint8_t* fs_particle_pssl;
extern const uint32_t fs_particle_pssl_size;

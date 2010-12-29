#ifndef __NV_SHADERS_H__
#define __NV_SHADERS_H__

#include <rsx/commands.h>

/*******************************************************************************
 * NV30/NV40/G70 fragment shaders
 */

// color0 only

static realityFragmentProgram nv30_fp_color = {
.num_regs = 2,
.size = (1*4),
.data = {
// MOV  o[COLH], f[COL0];
0x1003e81, 0x1c9dc801, 0x0, 0x0
}
};

// texture0 only

static realityFragmentProgram nv30_fp_texture = {
.num_regs = 2,
.size = (1*4),
.data = {
//TEXX   o[COLH], f[TEX0], TEX0, 2D;
0x17809e81, 0x1c9dc801, 0x0, 0x0
}
};

// color0 and texture0

static realityFragmentProgram nv30_fp_texture_color = {
.num_regs = 2,
.size = (2*4),
.data = {
// TEXX   R0, f[TEX0], TEX0, 2D;
0x17809e00, 0x1c9dc801, 0x0, 0x0,
// MULX   o[COLH], R0, f[COL0];
0x2803e81, 0x1c9dc800, 0x1c801, 0x0
}
};

// texture0 + texture1
static realityFragmentProgram nv30_fp_texture2 = {
.num_regs = 3,
.size = (3*4),
.data = {
// TEX   R0, f[TEX0], TEX0, 2D;
0x17009e00, 0x1c9dc801, 0x0, 0x0,
// TEX   R1, f[TEX1], TEX1, 2D;
0x1702be02, 0x1c9dc805, 0x0, 0x0,
// MULX  o[COLH], R0, R1;
0x2801e81, 0x1c9dc800, 0x1c804, 0x0
}
};

// texture0 + texture1 alternative
static realityFragmentProgram nv30_fp_texture2_alt = {
.num_regs = 3,
.size = (6*4),
.data = {
// TEX   R0, f[TEX0], TEX0, 2D;
0x17009e00, 0x1c9dc801, 0x0, 0x0,
// TEX   R1, f[TEX1], TEX1, 2D;
0x1702be02, 0x1c9dc805, 0x0, 0x0,
// ADDR  R1.xyz, R1, -R0;
0x3000e02, 0x1c9dc804, 0x1c800, 0x0,
// MADR  o[COLH].xyz, R1, {0.5}.x, R0;
0x4000e80, 0x1c9dc804, 0x6, 0x1c800,
// {0.5 , 0.0, 0.0, 0.0}
0x3f000000, 0x0, 0x0, 0x0,
// MULX  o[COLH].w, R0.w, R1.w;
0x2801081, 0x1c9dfe00, 0x1fe04, 0x0
}
};

// texture0 + texture1 alternative2
static realityFragmentProgram nv30_fp_texture2_alt2 = {
.num_regs = 3,
.size = (5*4),
.data = {
// TEX   R0, f[TEX0], TEX0, 2D;
0x17009e00, 0x1c9dc801, 0x0, 0x0,
// TEX   R1, f[TEX1], TEX1, 2D;
0x1702be02, 0x1c9dc805, 0x0, 0x0,
// ADDR  R1, R1, -R0;
0x3001e02, 0x1c9dc804, 0x1c800, 0x0,
// MADR  o[COLH], R1, {0.5}.x, R0;
0x4001e81, 0x1c9dc804, 0x6, 0x1c800,
// {0.5 , 0.0, 0.0, 0.0}
0x3f000000, 0x0, 0x0, 0x0,
}
};

// color0 + texture0 + texture1
static realityFragmentProgram nv30_fp_texture_color2 = {
.num_regs = 3,
.size = (4*4),
.data = {
// TEX   R0, f[TEX0], TEX0, 2D;
0x17009e00, 0x1c9dc801, 0x0, 0x0,
// TEX   R1, f[TEX1], TEX1, 2D;
0x1702be02, 0x1c9dc805, 0x0, 0x0,
// MUL   R0, R0, R1;
0x2001e00, 0x1c9dc800, 0x1c804, 0x0,
// MULX  o[COLH], R0, f[COL0];
0x2803e81, 0x1c9dc800, 0x1c801, 0x0
}
};

// color0 + texture0 + texture1 alternative
static realityFragmentProgram nv30_fp_texture_color2_alt = {
.num_regs = 3,
.size = (7*4),
.data = {
// TEX   R0, f[TEX0], TEX0, 2D;
0x17009e00, 0x1c9dc801, 0x0, 0x0,
// TEX   R1, f[TEX1], TEX1, 2D;
0x1702be02, 0x1c9dc805, 0x0, 0x0,
// ADDR  R1.xyz, R1, -R0;
0x3000e02, 0x1c9dc804, 0x1c800, 0x0,
// MADR  R0.xyz, R1, {0.5}.x, R0;
0x4000e00, 0x1c9dc804, 0x6, 0x1c800,
// {0.5 , 0.0, 0.0, 0.0}
0x3f000000, 0x0, 0x0, 0x0,
// MUL   R0.w, R0.w, R1.w;
0x2001000, 0x1c9dfe00, 0x1fe04, 0x0,
// MULX  o[COLH], R0, f[COL0];
0x2803e81, 0x1c9dc800, 0x1c801, 0x0
}
};

// color0 + texture0 + texture1 alternative2
static realityFragmentProgram nv30_fp_texture_color2_alt2 = {
.num_regs = 3,
.size = (6*4),
.data = {
// TEX   R0, f[TEX0], TEX0, 2D;
0x17009e00, 0x1c9dc801, 0x0, 0x0,
// TEX   R1, f[TEX1], TEX1, 2D;
0x1702be02, 0x1c9dc805, 0x0, 0x0,
// ADDR  R1, R1, -R0;
0x3001e02, 0x1c9dc804, 0x1c800, 0x0,
// MADR  R0, R1, {0.5}.x, R0;
0x4001e00, 0x1c9dc804, 0x6, 0x1c800,
// {0.5 , 0.0, 0.0, 0.0}
0x3f000000, 0x0, 0x0, 0x0,
// MULX  o[COLH], R0, f[COL0];
0x2803e81, 0x1c9dc800, 0x1c801, 0x0
}
};

#endif

#include "marker-1.h"
#include "marker-2-downleft.h"
#include "marker-2-downright.h"
#include "marker-2-horizontal.h"
#include "marker-2-vertical.h"
#include "marker-3-downleft.h"
#include "marker-3-downright.h"
#include "marker-3-horizontal.h"
#include "marker-3-vertical.h"
#include "ids.h"

Rage::SpriteDefinition largeMarkerDef;

Rage::Animation largeMarkerAnimations[9];

largeMarkerDef.version = 2;
largeMarkerDef.spriteID = LARGE_MARKER;
largeMarkerDef.animationCount = 9;
largeMarkerDef.animations = largeMarkerAnimations;

// Marker 1 (16x16 sprite)
Rage::Frame marker1Frames[1];

marker1Frames[0].index = 0; marker1Frames[0].duration = 30;

largeMarkerAnimations[MARKER_1].image.gfx = marker_1Tiles;
largeMarkerAnimations[MARKER_1].image.gfxLen = marker_1TilesLen;
largeMarkerAnimations[MARKER_1].image.pal = marker_1Pal;
largeMarkerAnimations[MARKER_1].image.palLen = marker_1PalLen;
largeMarkerAnimations[MARKER_1].size = SpriteSize_16x16;
largeMarkerAnimations[MARKER_1].looping = true;
largeMarkerAnimations[MARKER_1].frameCount = 1;
largeMarkerAnimations[MARKER_1].frames = marker1Frames;

// Marker 2 down left (diagonal) (64x64 sprite)
Rage::Frame marker2DownLeftFrames[1];

marker2DownLeftFrames[0].index = 0; marker2DownLeftFrames[0].duration = 30;

largeMarkerAnimations[MARKER_2_DOWNLEFT].image.gfx = marker_2_downleftTiles;
largeMarkerAnimations[MARKER_2_DOWNLEFT].image.gfxLen = marker_2_downleftTilesLen;
largeMarkerAnimations[MARKER_2_DOWNLEFT].image.pal = marker_2_downleftPal;
largeMarkerAnimations[MARKER_2_DOWNLEFT].image.palLen = marker_2_downleftPalLen;
largeMarkerAnimations[MARKER_2_DOWNLEFT].size = SpriteSize_64x64;
largeMarkerAnimations[MARKER_2_DOWNLEFT].looping = true;
largeMarkerAnimations[MARKER_2_DOWNLEFT].frameCount = 1;
largeMarkerAnimations[MARKER_2_DOWNLEFT].frames = marker2DownLeftFrames;

// Marker 2 down right (diagonal) (64x64 sprite)
Rage::Frame marker2DownRightFrames[1];

marker2DownRightFrames[0].index = 0; marker2DownRightFrames[0].duration = 30;

largeMarkerAnimations[MARKER_2_DOWNRIGHT].image.gfx = marker_2_downrightTiles;
largeMarkerAnimations[MARKER_2_DOWNRIGHT].image.gfxLen = marker_2_downrightTilesLen;
largeMarkerAnimations[MARKER_2_DOWNRIGHT].image.pal = marker_2_downrightPal;
largeMarkerAnimations[MARKER_2_DOWNRIGHT].image.palLen = marker_2_downrightPalLen;
largeMarkerAnimations[MARKER_2_DOWNRIGHT].size = SpriteSize_64x64;
largeMarkerAnimations[MARKER_2_DOWNRIGHT].looping = true;
largeMarkerAnimations[MARKER_2_DOWNRIGHT].frameCount = 1;
largeMarkerAnimations[MARKER_2_DOWNRIGHT].frames = marker2DownRightFrames;

// Marker 2 horizontal (64x32 sprite)
Rage::Frame marker2HorizontalFrames[1];

marker2HorizontalFrames[0].index = 0; marker2HorizontalFrames[0].duration = 30;

largeMarkerAnimations[MARKER_2_HORIZONTAL].image.gfx = marker_2_horizontalTiles;
largeMarkerAnimations[MARKER_2_HORIZONTAL].image.gfxLen = marker_2_horizontalTilesLen;
largeMarkerAnimations[MARKER_2_HORIZONTAL].image.pal = marker_2_horizontalPal;
largeMarkerAnimations[MARKER_2_HORIZONTAL].image.palLen = marker_2_horizontalPalLen;
largeMarkerAnimations[MARKER_2_HORIZONTAL].size = SpriteSize_64x32;
largeMarkerAnimations[MARKER_2_HORIZONTAL].looping = true;
largeMarkerAnimations[MARKER_2_HORIZONTAL].frameCount = 1;
largeMarkerAnimations[MARKER_2_HORIZONTAL].frames = marker2HorizontalFrames;

// Marker 2 vertical (32x64 sprite)
Rage::Frame marker2VerticalFrames[1];

marker2VerticalFrames[0].index = 0; marker2VerticalFrames[0].duration = 30;

largeMarkerAnimations[MARKER_2_VERTICAL].image.gfx = marker_2_verticalTiles;
largeMarkerAnimations[MARKER_2_VERTICAL].image.gfxLen = marker_2_verticalTilesLen;
largeMarkerAnimations[MARKER_2_VERTICAL].image.pal = marker_2_verticalPal;
largeMarkerAnimations[MARKER_2_VERTICAL].image.palLen = marker_2_verticalPalLen;
largeMarkerAnimations[MARKER_2_VERTICAL].size = SpriteSize_32x64;
largeMarkerAnimations[MARKER_2_VERTICAL].looping = true;
largeMarkerAnimations[MARKER_2_VERTICAL].frameCount = 1;
largeMarkerAnimations[MARKER_2_VERTICAL].frames = marker2VerticalFrames;

// Marker 3 down left (diagonal) (64x64 sprite)
Rage::Frame marker3DownLeftFrames[1];

marker3DownLeftFrames[0].index = 0; marker3DownLeftFrames[0].duration = 30;

largeMarkerAnimations[MARKER_3_DOWNLEFT].image.gfx = marker_3_downleftTiles;
largeMarkerAnimations[MARKER_3_DOWNLEFT].image.gfxLen = marker_3_downleftTilesLen;
largeMarkerAnimations[MARKER_3_DOWNLEFT].image.pal = marker_3_downleftPal;
largeMarkerAnimations[MARKER_3_DOWNLEFT].image.palLen = marker_3_downleftPalLen;
largeMarkerAnimations[MARKER_3_DOWNLEFT].size = SpriteSize_64x64;
largeMarkerAnimations[MARKER_3_DOWNLEFT].looping = true;
largeMarkerAnimations[MARKER_3_DOWNLEFT].frameCount = 1;
largeMarkerAnimations[MARKER_3_DOWNLEFT].frames = marker3DownLeftFrames;

// Marker 3 down right (diagonal) (64x64 sprite)
Rage::Frame marker3DownRightFrames[1];

marker3DownRightFrames[0].index = 0; marker3DownRightFrames[0].duration = 30;

largeMarkerAnimations[MARKER_3_DOWNRIGHT].image.gfx = marker_3_downrightTiles;
largeMarkerAnimations[MARKER_3_DOWNRIGHT].image.gfxLen = marker_3_downrightTilesLen;
largeMarkerAnimations[MARKER_3_DOWNRIGHT].image.pal = marker_3_downrightPal;
largeMarkerAnimations[MARKER_3_DOWNRIGHT].image.palLen = marker_3_downrightPalLen;
largeMarkerAnimations[MARKER_3_DOWNRIGHT].size = SpriteSize_64x64;
largeMarkerAnimations[MARKER_3_DOWNRIGHT].looping = true;
largeMarkerAnimations[MARKER_3_DOWNRIGHT].frameCount = 1;
largeMarkerAnimations[MARKER_3_DOWNRIGHT].frames = marker3DownRightFrames;

// Marker 3 horizontal (64x32 sprite)
Rage::Frame marker3HorizontalFrames[1];

marker3HorizontalFrames[0].index = 0; marker3HorizontalFrames[0].duration = 30;

largeMarkerAnimations[MARKER_3_HORIZONTAL].image.gfx = marker_3_horizontalTiles;
largeMarkerAnimations[MARKER_3_HORIZONTAL].image.gfxLen = marker_3_horizontalTilesLen;
largeMarkerAnimations[MARKER_3_HORIZONTAL].image.pal = marker_3_horizontalPal;
largeMarkerAnimations[MARKER_3_HORIZONTAL].image.palLen = marker_3_horizontalPalLen;
largeMarkerAnimations[MARKER_3_HORIZONTAL].size = SpriteSize_64x32;
largeMarkerAnimations[MARKER_3_HORIZONTAL].looping = true;
largeMarkerAnimations[MARKER_3_HORIZONTAL].frameCount = 1;
largeMarkerAnimations[MARKER_3_HORIZONTAL].frames = marker3HorizontalFrames;

// Marker 3 vertical (32x64 sprite)
Rage::Frame marker3VerticalFrames[1];

marker3VerticalFrames[0].index = 0; marker3VerticalFrames[0].duration = 30;

largeMarkerAnimations[MARKER_3_VERTICAL].image.gfx = marker_3_verticalTiles;
largeMarkerAnimations[MARKER_3_VERTICAL].image.gfxLen = marker_3_verticalTilesLen;
largeMarkerAnimations[MARKER_3_VERTICAL].image.pal = marker_3_verticalPal;
largeMarkerAnimations[MARKER_3_VERTICAL].image.palLen = marker_3_verticalPalLen;
largeMarkerAnimations[MARKER_3_VERTICAL].size = SpriteSize_32x64;
largeMarkerAnimations[MARKER_3_VERTICAL].looping = true;
largeMarkerAnimations[MARKER_3_VERTICAL].frameCount = 1;
largeMarkerAnimations[MARKER_3_VERTICAL].frames = marker3VerticalFrames;


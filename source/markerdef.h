#include "marker.h"

Rage::ImageDefinition markerImage;

markerImage.gfx = markerTiles;
markerImage.gfxLen = markerTilesLen;
markerImage.pal = markerPal;
markerImage.palLen = markerPalLen;

Rage::SpriteDefinition markerDef;

Rage::Animation markerAnimation;

markerDef.version = 1;
markerDef.spriteID = 1;
markerDef.animationCount = 1;
markerDef.animations = &markerAnimation;

Rage::Frame markerFrames[2];

markerFrames[0].index = 0; markerFrames[0].duration = 30;
markerFrames[1].index = 1; markerFrames[1].duration = 30;

markerAnimation.image = markerImage;
markerAnimation.size = SpriteSize_16x16;
markerAnimation.looping = true;
markerAnimation.frameCount = 2;
markerAnimation.frames = markerFrames;

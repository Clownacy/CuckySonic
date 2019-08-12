#pragma once
enum COLLISIONLAYER
{
	COLLISIONLAYER_NORMAL_TOP,
	COLLISIONLAYER_NORMAL_LRB,
	COLLISIONLAYER_ALTERNATE_TOP,
	COLLISIONLAYER_ALTERNATE_LRB,
};

#define LAYER_IS_ALT(layer)	(layer == COLLISIONLAYER_ALTERNATE_TOP || layer == COLLISIONLAYER_ALTERNATE_LRB)
#define LAYER_IS_LRB(layer)	(layer == COLLISIONLAYER_NORMAL_LRB || layer == COLLISIONLAYER_ALTERNATE_LRB)

int16_t FindFloor(int16_t x, int16_t y, COLLISIONLAYER layer, bool flipped, uint8_t *angle);
int16_t FindWall(int16_t x, int16_t y, COLLISIONLAYER layer, bool flipped, uint8_t *angle);

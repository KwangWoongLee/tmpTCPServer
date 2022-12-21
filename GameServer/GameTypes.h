#pragma once
#include "Struct.pb.h"

using Position = std::pair<float, float>;

enum class BlockType
{
	BLOCK_TYPE_NONE = 0,
	BLOCK_TYPE_BUSH1 = 3,
	BLOCK_TYPE_BUSH2 = 4,
	BLOCK_TYPE_BUSH3 = 8,
	BLOCK_TYPE_BUSH4 = 9,
	BLOCK_TYPE_BUSH5 = 16,
	BLOCK_TYPE_BUSH6 = 17,
	BLOCK_TYPE_BUSH7 = 18,

};
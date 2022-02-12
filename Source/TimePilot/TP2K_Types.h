#pragma once

#define TEST_BIT(Bitmask, BitFlag) (Bitmask & static_cast<uint64>(BitFlag))
#define SET_BIT(Bitmask, BitFlag) (Bitmask |= static_cast<uint64>(BitFlag))
#define CLEAR_BIT(Bitmask, BitFlag) (Bitmask ^= static_cast<uint64>(BitFlag))

static  constexpr float s_fNewThrustDetectedSeconds = 0.1f;
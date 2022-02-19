// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TP2K_Types.h"

#define _LOG_TO_SCREEN true
static constexpr EDebugLevels s_BUILD_DEBUG_LEVEL = EDebugLevels::DEBUGTEXTANDSHAPES;

DECLARE_LOG_CATEGORY_EXTERN(TP2K_INFO, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(TP2K_INIT, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(TP2K_CRIT, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(TP2K_WARN, Log, All);
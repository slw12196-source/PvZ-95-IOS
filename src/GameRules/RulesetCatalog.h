/*
 * Copyright (C) 2026 LangQi99
 *
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <string_view>

namespace PvzRules
{
	enum class RulesetId : uint8_t
	{
		ORIGINAL,
		PVZ95,
		COUNT
	};

	struct RulesetDescriptor
	{
		RulesetId mId;
		std::string_view mKey;
		std::string_view mDisplayName;
		uint32_t mProtocolId;
	};

	inline constexpr std::array<RulesetDescriptor, static_cast<std::size_t>(RulesetId::COUNT)> RULESET_CATALOG{{
		{RulesetId::ORIGINAL, "original", "Original", 0x4F524947}, // ORIG
		{RulesetId::PVZ95, "pvz95", "PvZ 95", 0x50393532}          // P952
	}};

	constexpr const RulesetDescriptor* FindRulesetDescriptor(RulesetId theRuleset)
	{
		for (const RulesetDescriptor& aDescriptor : RULESET_CATALOG)
			if (aDescriptor.mId == theRuleset)
				return &aDescriptor;
		return nullptr;
	}

	constexpr const RulesetDescriptor* FindRulesetDescriptor(uint32_t theProtocolId)
	{
		for (const RulesetDescriptor& aDescriptor : RULESET_CATALOG)
			if (aDescriptor.mProtocolId == theProtocolId)
				return &aDescriptor;
		return nullptr;
	}

	constexpr std::string_view GetRulesetDisplayName(uint32_t theProtocolId)
	{
		const RulesetDescriptor* aDescriptor = FindRulesetDescriptor(theProtocolId);
		return aDescriptor ? aDescriptor->mDisplayName : "Unknown ruleset";
	}
}

#pragma once

#include "tag_base.h"
#include "Blam/Reflexive/Reflexive.h"

namespace Blam
{
	namespace Cache
	{
		namespace Tags
		{
			struct itmc : tag_base
			{
				struct ItemPermutations : tag_base
				{
					float Weight;
					tag_reference Item;
					string_id VariantName;
				};
				TAG_BLOCK_SIZE_ASSERT(ItemPermutations, 0x10);
				Blam::Cache::DataTypes::Reflexive<ItemPermutations> itemPermutations;
				__int32 UnusedSpawnTime;

				//override
				void Open();
				void Close();
			};
			TAG_GROUP_SIZE_ASSERT(itmc, 0xC);

		}
	}
}
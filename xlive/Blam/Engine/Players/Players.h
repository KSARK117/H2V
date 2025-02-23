#pragma once
#include "Blam\Engine\DataArray\DataArray.h"
#include "Blam\Engine\Objects\Objects.h"

#define ENGINE_MAX_PLAYERS 16

#pragma pack(push, 1)
struct s_player
{
	enum class e_color : BYTE
	{
		White,
		Steel,
		Red,
		Orange,
		Gold,
		Olive,
		Green,
		Sage,
		Cyan,
		Teal,
		Colbat,
		Blue,
		Violet,
		Purple,
		Pink,
		Crimson,
		Brown,
		Tan
	};

	enum class e_character_type : BYTE
	{
		MasterChief = 0,
		Dervish = 1,
		Spartan = 2,
		Elite = 3,
		Skeleton = 4,
		Flood = 5,
		Lmao = 6
	};

	enum class e_emblem_foreground : BYTE
	{
		SeventhColumn = 0,
		Bullseye = 1,
		Vortex = 2,
		Halt = 3,
		Spartan = 4,
		DaBomb = 5,
		Trinity = 6,
		Delta = 7,
		Rampancy = 8,
		Sergeant = 9,
		Phenoix = 10,
		Champion = 11,
		JollyRoger = 12,
		Marathon = 13,
		Cube = 14,
		Radioactive = 15,
		Smiley = 16,
		Frowney = 17,
		Spearhead = 18,
		Sol = 19,
		Waypoint = 20,
		YingYang = 21,
		Helmet = 22,
		Triad = 23,
		GruntSymbol = 24,
		Cleave = 25,
		Thor = 26,
		SkullKing = 27,
		Triplicate = 28,
		Subnova = 29,
		FlamingNinja = 30,
		DoubleCresent = 31,
		Spades = 32,
		Clubs = 33,
		Diamonds = 34,
		Hearts = 35,
		Wasp = 36,
		MarkOfShame = 37,
		Snake = 38,
		Hawk = 39,
		Lips = 40,
		Capsule = 41,
		Cancel = 42,
		GasMask = 43,
		Grenade = 44,
		Tsanta = 45,
		Race = 46,
		Valkyire = 47,
		Drone = 48,
		Grunt = 49,
		GruntHead = 50,
		BruteHead = 51,
		Runes = 52,
		Trident = 53,
		Number0 = 54,
		Number1 = 55,
		Number2 = 56,
		Number3 = 57,
		Number4 = 58,
		Number5 = 59,
		Number6 = 60,
		Number7 = 61,
		Number8 = 62,
		Number9 = 63
	};

	enum class e_emblem_background : BYTE
	{
		Solid = 0,
		VerticalSplit = 1,
		HorizontalSplit1 = 2,
		HorizontalSplit2 = 3,
		VerticalGradient = 4,
		HorizontalGradient = 5,
		TripleColumn = 6,
		TripleRow = 7,
		Quadrants1 = 8,
		Quadrants2 = 9,
		DiagonalSlice = 10,
		Cleft = 11,
		X1 = 12,
		X2 = 13,
		Circle = 14,
		Diamond = 15,
		Cross = 16,
		Square = 17,
		DualHalfCircle = 18,
		Triangle = 19,
		DiagonalQuadrant = 20,
		ThreeQuaters = 21,
		Quarter = 22,
		FourRows1 = 23,
		FourRows2 = 24,
		SplitCircle = 25,
		OneThird = 26,
		TwoThirds = 27,
		UpperField = 28,
		TopandBottom = 29,
		CenterStripe = 30,
		LeftandRight = 31
	};

	enum class e_emblem_toggle : BYTE
	{
		Off = 0,
		On
	};

	enum class e_handicap : BYTE
	{
		None = 0,
		Minor = 1,
		Moderate = 2,
		Severe = 3
	};

	enum flags : int
	{
		player_inactive = 9,
	};

	struct s_player_properties
	{
		wchar_t player_name[16];
		char unk[32];

		struct s_player_profile
		{
			e_color primary_color;
			e_color secondary_color;
			e_color tertiary_color;
			e_color quaternary_color;
			e_character_type player_character_type;
			e_emblem_foreground foreground_emblem;
			e_emblem_background background_emblem;
			char emblem_flags;
		} profile;

		BYTE gap48[8];
		wchar_t clan_name[16];
		struct {
			DWORD ID_1;
			DWORD ID_2;
			DWORD ID_3;
		} clan_identifiers;

		e_object_team player_team;
		e_handicap player_handicap_level;
		byte player_displayed_skill;
		byte player_overall_skill;
		char player_is_griefer;
		char bungie_user_role;
		char achievement_flags;
		byte unk2;
	};
	CHECK_STRUCT_SIZE(s_player_properties, 132);

	WORD datum_salt;
	WORD flags;
	unsigned long long identifier;
	DWORD player_creation_tick;
	BYTE abNet[6];
	__int16 machine_index;
	int unk_user_index_2;
	int unk_user_index;
	int controller_index;
	__int16 user_index;
	__int16 player_bsp_location_index;
	datum unit_index;
	datum dead_unit_index;
	datum possibly_datum;
	DWORD InputFlags;
	DWORD InputFlags2;
	char field_3C[4];
	s_player_properties properties[2];
	DWORD field_148;
	DWORD respawn_penalty;
	DWORD teleporter_blocked_tick_count;
	int respawn_time;
	int unk_12;
	BYTE gap_15C[4];
	DWORD field_160;
	WORD field_164;
	BYTE gap_166[14];
	DWORD betrayal_encountered_tick;
	int spawn_protection_time;
	WORD field_17C[2];
	float unit_speed;
	DWORD field_184;
	BYTE gap_188[2];
	WORD field_18A;
	BYTE gap_18C[2];
	WORD field_18E;
	WORD player_lives_count;
	BYTE gap_192[2];
	DWORD betraying_player_index;
	BYTE gap198[2];
	int field_19C;
	BYTE gap_19E[30];
	DWORD field_1BC;
	BYTE gap_1C0[60];
	WORD random_index;
	BYTE gap_1FE[2];
	DWORD is_chatting;

	/*
	- TO NOTE: 
	- This functions work only after game has started, if you need to do something in the pregame lobby, use the functions available in Network Session (H2MOD/Modules/Networking/NetworkSession)
	*/

	static s_data_array* GetArray();
	static bool IndexValid(int playerIndex);
	static s_player* GetPlayer(int playerIndex);
	static e_object_team GetTeam(int playerIndex);
	static void SetTeam(int playerIndex, e_object_team team);
	static void SetUnitBipedType(int playerIndex, s_player::e_character_type bipedType);
	static void SetUnitBipedType(int playerIndex, byte representationIndex);
	static void SetBipedSpeed(int playerIndex, float speed);
	static const wchar_t* GetName(int playerIndex);
	static datum GetPlayerUnitDatumIndex(int playerIndex);
	static unsigned long long GetId(int playerIndex);
};
CHECK_STRUCT_SIZE(s_player, 0x204);
#pragma pack(pop)

class PlayerIterator : public s_data_iterator<s_player>
{
public:

	PlayerIterator();

	bool get_next_active_player();

	s_player* get_current_player_data();

	int get_current_player_index();

	wchar_t* get_current_player_name();

	unsigned long long get_current_player_id();

private:
	s_player* m_current_player = nullptr;
};
/// @symbols
#pragma once
#include <amethyst/Imports.hpp>
#include <mc/src/common/world/level/dimension/Dimension.hpp>

class EndDragonFight;

/**@vptr {0x4EE87B8} */
/**@vptr {0x4EE86C0, SavedData} */
/**@vptr {0x4EE86D8, LevelListener} */
class TheEndDimension : public Dimension {
public:

	/* this + 1576 */ EndDragonFight* mDragonFight;

public:
    /** @vidx {i} */
	MC virtual ~TheEndDimension() override;

	/** @vidx {i} */
    MC virtual bool isNaturalDimension() const override;

    /** @vidx {i} */
	MC virtual Vec3 translatePosAcrossDimension(const Vec3&, DimensionType) const override;

    /** @vidx {i} */
	MC virtual void init(const br::worldgen::StructureSetRegistry&);

    /** @vidx {i} */
	MC virtual void tick();

    /** @vidx {i} */
	MC virtual std::unique_ptr<class WorldGenerator> createGenerator(const br::worldgen::StructureSetRegistry&) override;

	/** @vidx {i} */
    MC virtual void upgradeLevelChunk(class ChunkSource& source, class LevelChunk& lc, class LevelChunk& generatedChunk) override;

	/** @vidx {i} */
    MC virtual void fixWallChunk(class ChunkSource&, class LevelChunk&) override;

	/** @vidx {i} */
    MC virtual bool levelChunkNeedsUpgrade(const LevelChunk&) const override;

    /** @vidx {i} */
	MC virtual class mce::Color getBrightnessDependentFogColor(const mce::Color& baseColor, float brightness) const override;

    /** @vidx {i} */
	MC virtual short getCloudHeight() const override;

    /** @vidx {i} */
	MC virtual class HashedString getDefaultBiome() const override;

    /** @vidx {31} */
	MC virtual bool mayRespawnViaBed() const override;

    /** @vidx {i} */
	MC virtual bool isValidSpawn(int x, int z) const override;

    /** @vidx {i} */
	MC virtual class BlockPos getSpawnPos() const override;

    /** @vidx {i} */
	MC virtual int getSpawnYPosition() const override;

    /** @vidx {i} */
	MC virtual bool isDay() const override;

    /** @vidx {i} */
	MC virtual float getTimeOfDay(int time, float a) const override;

    /** @vidx {i} */
	MC virtual float getSunIntensity(float a, const Vec3& viewVector, float minInfluenceAngle) const override;

    /** @vidx {i} */
	MC virtual bool hasGround() const override;

    /** @vidx {i} */
	MC virtual void startLeaveGame() override;

    /** @vidx {i} */
	MC virtual void _upgradeOldLimboEntity(class CompoundTag& tag, LimboEntitiesVersion vers) override;

    /** @vidx {i} */
	MC virtual std::unique_ptr<class ChunkSource> _wrapStorageForVersionCompatibility(std::unique_ptr<class ChunkSource> storageSource, StorageVersion levelVersion) override;

    /** @vidx {1, SavedData} */
	MC virtual void deserialize(const CompoundTag&) override;

    /** @vidx {2, SavedData} */
	MC virtual void serialize(CompoundTag&) const override;

	/// @sig {48 89 5C ? ? 56 57 41 56 48 83 EC ? 49 8B D8 48 8B FA 4C 8B F1 48 89 4C 24 ?}
	MC TheEndDimension(ILevel& level, Scheduler& callbackContext);

	// made up constructor to set a custom dimID
    TheEndDimension(ILevel& level, DimensionType dimId, DimensionHeightRange heightRange, Scheduler& callbackContext, std::string dimensionName) 
		: Dimension(level, dimId, heightRange, callbackContext, dimensionName) {
			mDragonFight = nullptr;
		}
};
/// @symbols
#pragma once
#include <amethyst/Imports.hpp>
#include <memory>
#include <atomic>
#include <unordered_map>

#include <mc/src-deps/core/utility/NonOwnerPointer.hpp>
#include <mc/src-deps/core/utility/pubsub/Subscription.hpp>

class Level;
class LevelChunk;
class LevelChunkBuilderData;
class LevelChunkMetaDataDictionary;
class ChunkPos;
class Dimension;
class Random;
class ChunkKey;
struct ActorUnloadedChunkTransferEntry;
class BlendingDataProvider;
class ChunkViewSource;

/**@vptr {0x4E5C670} */
class ChunkSource : public Bedrock::EnableNonOwnerReferences {
public:
    enum class LoadMode : int {
        None = 0x0,
        Deferred = 0x1,
    };

public:
    int mChunkSide;                             
    Level* mLevel;                        
    Dimension* mDimension;               
    ChunkSource* mParent;                           
    std::unique_ptr<ChunkSource> mOwnedParent;     
    LevelChunkBuilderData* mLevelChunkBuilderData; 
    std::atomic<bool> mShuttingDown;               
    Bedrock::PubSub::Subscription mOnSaveSubscription;
    Bedrock::PubSub::Subscription mOnLevelStorageAppSuspendSubscription;                     

public:
	/**
	* @symbol {??1ChunkSource@@UEAA@XZ}
	* @vidx {0} 
	*/
	MC virtual ~ChunkSource();
    
	/**@vidx {1} */
	MC virtual void shutdown();
    
	/**@vidx {2} */
	MC virtual bool isShutdownDone();
    
	/**@vidx {3} */
	MC virtual std::shared_ptr<LevelChunk> getExistingChunk(const ChunkPos&);
    
	/**@vidx {4} */
	MC virtual std::shared_ptr<LevelChunk> getRandomChunk(Random& random);
    
	/**@vidx {5} */
	MC virtual bool isChunkKnown(const ChunkPos& chunkPos);
    
	/**@vidx {6} */
	MC virtual bool isChunkSaved(const ChunkPos& chunkPos);
    
	/**@vidx {7} */
	MC virtual std::shared_ptr<LevelChunk> createNewChunk(const ChunkPos& cp, ChunkSource::LoadMode lm, bool readOnly);
    
	/**@vidx {8} */
	MC virtual std::shared_ptr<LevelChunk> getOrLoadChunk(const ChunkPos& cp, ChunkSource::LoadMode lm, bool readOnly);
    
	/**@vidx {9} */
	MC virtual bool postProcess(ChunkViewSource& neighborhood);
    
	/**@vidx {10} */
	MC virtual void checkAndReplaceChunk(ChunkViewSource& neighborhood, LevelChunk& lc);
    
	/**@vidx {11} */
	MC virtual void loadChunk(LevelChunk& lc, bool forceImmediateReplacementDataLoad);
    
	/**@vidx {12} */
	MC virtual void postProcessMobsAt(class BlockSource& region, int chunkWestBlock, int chunkNorthBlock, Random& random);
    
	/**@vidx {13} */
	MC virtual bool saveLiveChunk(LevelChunk& lc);
    
	/**@vidx {14} */
	MC virtual void writeEntityChunkTransfer(LevelChunk& levelChunk);
    
	/**@vidx {15} */
	MC virtual void writeEntityChunkTransfersToUnloadedChunk(const ChunkKey&, const std::vector<ActorUnloadedChunkTransferEntry>&);
    
	/**@vidx {16} */
	MC virtual void deserializeActorStorageToLevelChunk(LevelChunk&);
    
	/**@vidx {17} */
	MC virtual void hintDiscardBatchBegin();
    
	/**@vidx {18} */
	MC virtual void hintDiscardBatchEnd();
    
	/**@vidx {19} */
	MC virtual void acquireDiscarded(std::unique_ptr<LevelChunk, struct LevelChunkFinalDeleter> ptr);
    
	/**@vidx {20} */
	MC virtual void compact();
    
	/**@vidx {21} */
	MC virtual void flushPendingDiscardedChunkWrites();
    
	/**@vidx {22} */
	MC virtual void flushThreadBatch();
    
	/**@vidx {23} */
	MC virtual bool isWithinWorldLimit(const ChunkPos& cp) const;
    
	/**@vidx {24} */
	MC virtual const std::unordered_map<ChunkPos, std::weak_ptr<LevelChunk>>* getChunkMap();
    
	/**@vidx {25} */
	MC virtual const std::unordered_map<ChunkPos, std::weak_ptr<LevelChunk>>& getStorage() const;
    
	/**@vidx {26} */
	MC virtual void clearDeletedEntities();
    
	/**@vidx {27} */
	MC virtual bool canCreateViews() const;
    
	/**@vidx {28} */
	MC virtual std::unique_ptr<BlendingDataProvider> tryGetBlendingDataProvider();
    
	/**@vidx {29} */
	MC virtual std::shared_ptr<LevelChunkMetaDataDictionary> loadLevelChunkMetaDataDictionary();
    
	/**@vidx {30} */
	MC virtual void setLevelChunk(std::shared_ptr<LevelChunk>);
    
	/**@vidx {31} */
	MC virtual bool canLaunchTasks() const;
    
	/**@vidx {32} */
	MC virtual bool chunkPosNeedsBlending(const ChunkPos& cp);

public:
    ChunkSource(Dimension* dimension, int side);
};

static_assert(sizeof(ChunkSource) == 0x70, "ChunkSource size is incorrect");
/// @symbols
#pragma once
#include <amethyst/Imports.hpp>
#include <mc/src/common/world/level/chunk/ChunkGeneratorStructureState.hpp>
#include <mc/src/common/world/level/levelgen/structure/StructureCache.hpp>

class StructureFeatureRegistry {
public:
    std::byte padding0[208];

    //{StructureFeatureRegistry_ctor}
    /// @sig {48 89 5C 24 ? 48 89 74 24 ? 48 89 4C 24 ? 57 48 83 EC ? 48 8B F9 33 F6 48 89 31 48 89 71 ? 48 89 71 ? 48 89 71 ? 48 89 71 ? 48 89 71 ? 48 89 71 ? 48 89 71 ? 48 89 71 ? 48 8D 59 ? 0F 57 C0}
    MC StructureFeatureRegistry();

    ~StructureFeatureRegistry(){};
};



    // ChunkGeneratorStructureState mChunkGeneratorStructureState; // 0x0
// std::byte filler30[sizeof(std::vector<int>)];               // 0x30 // This should be a vector of unqiue_ptr<StructureFeature> but I'm too lazy to implement that xD its 1:10 am and I'm tired
// StructureCache mStructureCache;                             // 0x48